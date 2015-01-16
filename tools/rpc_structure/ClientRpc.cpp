
#include "ClientRpc.h"
#include "common.h"

#if 1
void ClientRpc::UpdateOneBagItem (int fd, int pos, ItemBase& item)
#else
void ClientRpc::UpdateOneBagItem (int pos, ItemBase& item)
#endif
{
        std::string mainstr;
        std::string substr;

        RPCS::CRPCUpdateOneBagItem args;
        args.set_pos (pos);
        
        args.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        item.SerializeObjectToStringForNet (mainstr);

#ifdef __TEST__
        CALL_CLIENT_RPC (fd, 110, mainstr);
#endif
}

#if 1
void ClientRpc::UpdateOneEquipedItem (int fd, int pos, ItemBase& item)
#else
void ClientRpc::UpdateOneEquipedItem (int pos, ItemBase& item)
#endif
{
        std::string mainstr;
        std::string substr;

        RPCS::CRPCUpdateOneEquipedItem args;
        args.set_pos (pos);
        
        args.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        item.SerializeObjectToStringForNet (mainstr);

#ifdef __TEST__
        CALL_CLIENT_RPC (fd, 111, mainstr);
#endif
}

#if 1
void ClientRpc::UpdateBagItems (int fd, std::vector<ItemBase> items)
#else
void ClientRpc::UpdateBagItems (std::vector<ItemBase> items)
#endif
{
        std::string mainstr;
        std::string substr;

        AppendSizeToString (mainstr, items.size());
        for (std::vector<ItemBase>::iterator it = items.begin(); it != items.end(); ++it) {
            (*it).SerializeObjectToStringForNet (mainstr);
        }

#ifdef __TEST__
        CALL_CLIENT_RPC (fd, 112, mainstr);
#endif
}
