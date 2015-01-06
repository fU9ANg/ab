
#include "ServerRpcFunctions.h"

void CALL_SERVERRPC (std::string mainstr)
{
        // TODO: post mainstr to server.
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
