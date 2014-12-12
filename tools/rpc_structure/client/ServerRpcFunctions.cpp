
#include "ServerRpcFunctions.h"

void CALL_SERVERRPC (std::string mainstr)
{
        // TODO: post mainstr to server.
}

void ServerRpcFunctions::EquipEquipment (int itemPos);
{
        SREquipEquipmentArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_itempos (itemPos);

        tmpobj.SerializeToString (&substr);
        PushObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);
}

void ServerRpcFunctions::UnEquipEquipment (int pos)
{
        SRUnEquipEquipmentArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_pos (pos);

        tmpobj.SerializeToString (&substr);
        PushObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);
}

void ServerRpcFunctions::SellItem (int itemPos)
{
        SRSellItemArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_itempos (itemPos);

        tmpobj.SerializeToString (&substr);
        PushObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);
}

void ServerRpcFunctions::UseItem (int pos)
{
        SRUseItemArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_pos (pos);

        tmpobj.SerializeToString (&substr);
        PushObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);
}

void ServerRpcFunctions::ComposeItem (int type, std::vector<int> indexs)
{
        SRComposeItemArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.set_type (type);
        for (std::vector<int>::iterator it = indexs.begin(); it != indexs.end(); ++it) {
                tmpobj.add_indexs (*it);
        }

        tmpobj.SerializeToString (&substr);
        PushObjectToString (mainstr, substr);

        CALL_SERVERRPC (mainstr);
}

void ServerRpcFunctions::SortItems (void)
{
        SRSortItemsArg tmpobj;
        std::string mainstr;
        std::string substr;

        tmpobj.SerializeToString (&substr);
        PushObjectToStringForDB (mainstr, substr);

        CALL_SERVERRPC (mainstr);
}
