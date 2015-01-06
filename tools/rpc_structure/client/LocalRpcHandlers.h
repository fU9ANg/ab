
#ifndef _LOCALRPCHANDLERS_H
#define _LOCALRPCHANDLERS_H

#include "Platform.h"

namespace LocalRpcHandlers
{
        static void UpdateOneBagItem_HANDLER (std::string mainstr);
        static void UpdateOneEquipedItem_HANDLER (std::string mainstr);
        static void UpdateBagItems_HANDLER (std::string mainstr);

        static void EquipEquipment_HANDLER (std::string mainstr);
        static void UnEquipEquipment_HANDLER (std::string mainstr);
        static void SellItem_HANDLER (std::string mainstr);
        static void UseItem_HANDLER (std::string mainstr);
        static void ComposeItem_HANDLER (std::string mainstr);
        static void SortItems (std::string mainstr);
};

#endif //_LOCALRPCHANDLERS_H
