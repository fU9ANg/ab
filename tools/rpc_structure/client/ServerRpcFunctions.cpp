
#include "ServerRpcFunctions.h"

#include "protocol.h" // for test..
#include "unistd.h"   // for test..
#include "MsgReceiver.h" // for test..
#define GLOBAL_FUNC_INVALIED_FD \
        (MsgReceiver::g_socket.getSocketFd())
#define GLOBAL_FUNC_INVALIED \
        (MsgReceiver::g_socket)

void CALL_SERVERRPC (std::string mainstr)
{
#define MAX_BUFFER_SIZE 1024
        // TODO: post mainstr to server.
        int fd = GLOBAL_FUNC_INVALIED_FD;
        char buff[MAX_BUFFER_SIZE];
        (void) memset (buff, 0x00, MAX_BUFFER_SIZE);
        MSG_HEAD* phead = (MSG_HEAD*) buff;
        phead->cFuncId = 888;
        phead->cLen = MSG_HEAD_LEN + mainstr.size();
        (void) memcpy ((char*) buff + MSG_HEAD_LEN, mainstr.c_str(), mainstr.size());

        printf ("cLen=%d, cFuncId=%d, mainstr.size=%ld\n", phead->cLen, phead->cFuncId, mainstr.size());
        write (fd, buff, phead->cLen);
        
}

void ServerRpcFunctions::EquipEquipment (int itemPos)
{
        RPCS::SRPCEquipEquipmentArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_itempos (itemPos);

        tmpobj.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);

        return;
}

void ServerRpcFunctions::UnEquipEquipment (int pos)
{
        RPCS::SRPCUnEquipEquipmentArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_pos (pos);

        tmpobj.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);

        return;
}

void ServerRpcFunctions::SellItem (int itemPos)
{
        RPCS::SRPCSellItemArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_itempos (itemPos);

        tmpobj.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);

        return;
}

void ServerRpcFunctions::UseItem (int pos)
{
        RPCS::SRPCUseItemArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_pos (pos);

        tmpobj.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);

        return;
}

void ServerRpcFunctions::ComposeItem (int type, std::vector<int> indexs)
{
        RPCS::SRPCComposeItemArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_type (type);
        for (std::vector<int>::iterator it = indexs.begin(); it != indexs.end(); ++it) {
                tmpobj.add_indexs (*it);
        }

        tmpobj.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);

        return;
}

void ServerRpcFunctions::SortItems (void)
{
        RPCS::SRPCSortItemsArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);

        return;
}
