
#ifndef _CLIENT_RPC_H
#define _CLIENT_RPC_H

class ClientRpc
{
        void UpdateOneBagItem (int pos, ItemBase& item);
        void UpdateOneEquipedItem (int pos, ItemBase& item);
        void UpdateBagItems (std::vector<ItemBase> items);
};

#endif  //_CLIENT_RPC_H
