
#include "ClientRpc.h"

void ClientRpc::UpdateOneBagItem (int pos, ItemBase& item)
{
        std::string mainstr;
        std::string substr;

        CRPCUpdateOneBagItem args;
        args.set_pos (pos);
        
        args.SerializeToString (&substr);
        PushObjectToString (mainstr, substr);

        item.SerializeObjectToStringForDB (mainstr);

        //CALL_CLIENT_RPC (110, mainstr);
}

void ClientRpc::UpdateOneEquipedItem (int pos, ItemBase& item)
{
        std::string mainstr;
        std::string substr;

        CRPCUpdateOneEquipedItem args;
        args.set_pos (pos);
        
        args.SerializeToString (&substr);
        PushObjectToString (mainstr, substr);

        item.SerializeObjectToStringForDB (mainstr);

        //CALL_CLIENT_RPC (111, mainstr);
}

void ClientRpc::UpdateBagItems (std::vector<ItemBase> items)
{
        std::string mainstr;
        std::string substr;

        for (std::vector<ItemBase>::iterator it = items.begin(); it != items.end(); ++it) {
            (*it).SerializeObjectToStringForDB (mainstr);
        }

        //CALL_CLIENT_RPC (112, mainstr);
}
