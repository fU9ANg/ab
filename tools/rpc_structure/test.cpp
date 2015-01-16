
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include "ChenyuanTypes.pb.h"
#include "common.h"

#include "Player.h"
#include "Pos.h"
#include "TalentNode.h"
#include "TalentProp.h"

using namespace std;

#define SPELL_NUMBER        5
#define TALENTNODE_NUMBER   2
#define TALENTPROP_NUMBER   1

int main ()
{
    std::string             sName = "玩家________________1111111111111111=========================玩家1";
    int                     iRoleId = 9999;
    Pos                     oPos;
    int                     iX = 8130;
    int                     iY = 82230;
    std::vector<int>        vSpellList;
    std::vector<TalentNodeBase> vTalentNodes;
    std::vector<TalentPropBase> vTalentProps;
    std::string             mainstr;

    Player p;

    oPos.setX(iX);
    oPos.setY(iY);

    for (int i=1; i<=SPELL_NUMBER; i++) {
        vSpellList.push_back (i+10);
    }

    vTalentNodes.clear();
    for (int i=1; i<=TALENTNODE_NUMBER; i++) {
        TalentNode objNode;

        // begin
        vTalentProps.clear();
        for (int j=1; j<=TALENTPROP_NUMBER; j++) {

            TalentProp objProp;
            objProp.setPropId (j+4);
            objProp.setPropVal(j+6);
            objProp.setLocked (j+8);
            vTalentProps.push_back(objProp);
        }
        objNode.setTalentProps(vTalentProps);
        // end

        vTalentNodes.push_back (objNode);
    }

    p.setName(sName);
    p.setRoleId(iRoleId);
    p.setPos(oPos);
    p.setSpellList(vSpellList);
    p.setTalentNodes(vTalentNodes);

    ////////////////////////// dump object ///////////////////////////
    //
    p.SerializeObjectToStringForNet (mainstr);
    p.dumpObject();

    std::cout << "---------------- mainstr.size() = " << mainstr.size() << " ----------------" << std::endl;
#if 1
    // Parse to other_object from string
    Player p1;
    p1.ParseObjectFromStringForNet (mainstr);
    p1.dumpObject();
#endif

    return (0);
}

/*
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "MsgReceiver.h"
#include "ODSocket.h"

#include "ClientRpc.h" // for test..
#include "Item.h"      // for test..
#include "ServerRpc.h" // for test..
#include "protocol.h"  // for test..
#include "RpcFunctionBase.h" // for test..

using namespace std;

#define GLOBAL_FUNC_INVALIED_FD \
        (MsgReceiver::g_socket.getSocketFd())
#define GLOBAL_FUNC_INVALIED \
        (MsgReceiver::g_socket)

#define MAX_BUFFER_SIZE 1024

bool restartNetwork ()
{
        //MsgReceiver::close ();

        if (MsgReceiver::start (true)) {
                printf ("[DEBUG]: start success!\n");
                return (true);
        } else {
                printf ("[DEBUG]: can't start!\n");
                return (false);
        }
}

int vmain ()
{
        restartNetwork ();

        while (1) {
            printf ("... WHILE-1: wait client connection ...\n");
            ODSocket clientSocket;
            char clientIpaddr[MAX_BUFFER_SIZE];
            GLOBAL_FUNC_INVALIED.Accept (clientSocket, clientIpaddr);
            printf ("CLIENT IP ADDRESS IS: %s\n", clientIpaddr);

            // TODO:
#if 1
#if 1
            ClientRpc cRpc;
            Item item;
            item.setId (800);
            item.setPrice (13000);
            cRpc.UpdateOneEquipedItem (clientSocket.getSocketFd(), 56, item);//int pos, ItemBase& item)
#else
            ClientRpc cRpc;
            vector<ItemBase> vItem;
            Item item;
            vItem.clear ();
            for (int i=0; i<3; ++i) {
            		int j = i+1;
            		item.setId (j);
            		item.setPrice (j + 10000);
            		vItem.push_back (item);
            }
            cRpc.UpdateBagItems (clientSocket.getSocketFd(), vItem);
#endif
#else
            ClientRpc cRpc;
            Item item;
            item.setId (900);
            item.setPrice (14000);
            cRpc.UpdateOneBagItem (clientSocket.getSocketFd(), 34, item);//int pos, ItemBase& item)

            char buff[MAX_BUFFER_SIZE];
            (void) memset (buff, 0x00, sizeof (MAX_BUFFER_SIZE));
            int len = read (clientSocket.getSocketFd(), buff, MAX_BUFFER_SIZE);
            buff[len] = 0x00;

            MSG_HEAD* phead = (MSG_HEAD*) buff;
            printf ("datalen = %d, cLen = %d, cFuncId = %d\n", len, phead->cLen, phead->cFuncId);
            std::string tmpstr;
            tmpstr.assign ((char*)buff + MSG_HEAD_LEN, phead->cLen - MSG_HEAD_LEN);
            RpcFunctionBase* pbase = ServerRpc::EquipEquipment_HANDLER (tmpstr);
            if (pbase) {
                std::string rlt = pbase->m_result;
                write (clientSocket.getSocketFd(), rlt.c_str(), rlt.size());
            }
#endif
            ////////
            clientSocket.Close();
        }

        return (0);
}
*/
