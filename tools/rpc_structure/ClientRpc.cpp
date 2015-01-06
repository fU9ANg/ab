
#include "ClientRpc.h"

void ClientRpc::UpdateOneBagItem (int pos, ItemBase& item)
{
        std::string mainstr;
        std::string substr;

        RPCS::CRPCUpdateOneBagItem args;
        args.set_pos (pos);
        
        args.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        item.SerializeObjectToStringForNet (mainstr);

        //CALL_CLIENT_RPC (110, mainstr);
}

void ClientRpc::UpdateOneEquipedItem (int pos, ItemBase& item)
{
        std::string mainstr;
        std::string substr;

        RPCS::CRPCUpdateOneEquipedItem args;
        args.set_pos (pos);
        
        args.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        item.SerializeObjectToStringForNet (mainstr);

        //CALL_CLIENT_RPC (111, mainstr);
}

void ClientRpc::UpdateBagItems (std::vector<ItemBase> items)
{
        std::string mainstr;
        std::string substr;

        for (std::vector<ItemBase>::iterator it = items.begin(); it != items.end(); ++it) {
            (*it).SerializeObjectToStringForNet (mainstr);
        }

        //CALL_CLIENT_RPC (112, mainstr);
}
