
#ifndef _SERVERRPC_H
#define _SERVERRPC_H

#include "ComposeItem.h"
#include "EquipEquipment.h"
#include "SellItem.h"
#include "SortItems.h"
#include "UnEquipEquipment.h"
#include "UseItem.h"

class ServerRpc
{
public:
        static RpcFunctionBase* EquipEquipment_HANDLER (std::string mainstr);
        static RpcFunctionBase* UnEquipEquipment_HANDLER (std::string mainstr);
        static RpcFunctionBase* SellItem_HANDLER (std::string mainstr);
        static RpcFunctionBase* UseItem_HANDLER (std::string mainstr);
        static RpcFunctionBase* ComposeItem_HANDLER (std::string mainstr);
        static RpcFunctionBase* SortItems_HANDLER (void);
};

#endif  //_SERVERRPC_H
