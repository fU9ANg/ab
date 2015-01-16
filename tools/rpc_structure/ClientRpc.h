
#ifndef _CLIENT_RPC_H
#define _CLIENT_RPC_H

#include "ChenyuanTypes.pb.h"
#include "Rpc.pb.h"
#include "common.h"

#include "Item.h"   //FIXME: move this line code to xxxxx.h header file.

using namespace std;

class ClientRpc
{
public:
#if 1
        void UpdateOneBagItem (int fd, int pos, ItemBase& item);
        void UpdateOneEquipedItem (int fd, int pos, ItemBase& item);
        void UpdateBagItems (int fd, std::vector<ItemBase> items);
#else
        void UpdateOneBagItem (int pos, ItemBase& item);
        void UpdateOneEquipedItem (int pos, ItemBase& item);
        void UpdateBagItems (std::vector<ItemBase> items);
#endif
};

#endif  //_CLIENT_RPC_H
