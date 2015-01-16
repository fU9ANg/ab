/**
* @file RecvTask.cpp
* @brief 
* @author nvng and fU9ANg
* @version v1.0
* @date 2014-01-03
*/

#include "RecvTask.h"
#include "ServerRpc.h"
#include <iostream>
#include <string>

using namespace std;

/**
* @brief 
*
* @return 
*/
int RecvTask::work ()
{
    while (true)
    {
        Buf* p = NULL;
        ServerRpc sr;
        if (SINGLE->recvqueue.dequeue (p, 3) != 0) {
            continue;
        }

        if (p == NULL) {
            cout << "ERROR: p==NULL in RecvTask::work()" << endl;
            return (0);
        }
#if 1
        int clientfd = p->getfd ();
        MSG_HEAD* head = (MSG_HEAD*) p->ptr();
        if (head != NULL) {
            unsigned int len      = head->cLen;
            //enum CommandType type = head->cType;
            unsigned int funcid   = head->cFuncId;
            std::string msgstr;

            if (len > MSG_HEAD_LEN)
                msgstr.assign ((char*) p->ptr() + MSG_HEAD_LEN, len - MSG_HEAD_LEN);

            RpcFunctionBase* phandler = NULL;
            switch (funcid) {
            case 110:
                phandler = sr.EquipEquipment_HANDLER (msgstr);
                break;
            case 111:
                phandler = sr.UnEquipEquipment_HANDLER (msgstr);
                break;
            case 112:
                phandler = sr.SellItem_HANDLER (msgstr);
                break;
            case 113:
                phandler = sr.UseItem_HANDLER (msgstr);
                break;
            case 114:
                phandler = sr.ComposeItem_HANDLER (msgstr);
                break;
            case 115:
                phandler = sr.SortItems_HANDLER ();
                break;
            default:
                printf ("[RecvTask]: not found handler.\n");
                p->reset ();
                phandler = NULL;
                SINGLE->bufpool.free (p);
                break;
            }
            if (phandler) {
                std::string rltstr = phandler->m_result;
                // TODO:
                // packet result data, and send to client. for example:
                if (!rltstr.empty ()) {
                    Buf* send_buff = SINGLE->bufpool.malloc ();
                    if (!send_buff) {
                        send_buff = new Buf (MAX_BUF);
                    }
                    MSG_HEAD* send_head = (MSG_HEAD*) send_buff->ptr();
                    send_head->cLen = MSG_HEAD_LEN + rltstr.size ();
                    send_head->cFuncId = funcid;
                    (void) memcpy ((char*) send_buff + MSG_HEAD_LEN, rltstr.c_str(), rltstr.size());
                    send_buff->setfd (clientfd);
                    send_buff->setsize (send_head->cLen);

                    SINGLE->sendqueue.enqueue (send_buff);
                }
                delete phandler;
            }
        }
#else
        MSG_HEAD* head = (MSG_HEAD*) p->ptr();
        if (head != NULL)
        {
            // cout << "recvTask: cType=" << head->cType << endl;
            handlefunc pfun = CHandleMessage::getHandler (head->cType); 
            if (NULL == pfun)
            {
                printf ("ERROR: the pointer of callback, cType=[%d]\n", head->cType);
                p->reset ();
                SINGLE->bufpool.free (p);
                continue;
            }
            pfun (p);
        }
#endif
    }
    return 0;
}

/**
* @brief 
*/
RecvTask::RecvTask () {
}

/**
* @brief 
*/
RecvTask::~RecvTask () {
}
