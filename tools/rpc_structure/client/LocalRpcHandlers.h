
#ifndef _LOCALRPCHANDLERS_H
#define _LOCALRPCHANDLERS_H

#include "Platform.h"

namespace LocalRpcHandlers
{
        void UpdateOneBagItem_HANDLER (std::string mainstr);
        void UpdateOneEquipedItem_HANDLER (std::string mainstr);
        void UpdateBagItems_HANDLER (std::string mainstr);

        void EquipEquipment_HANDLER (std::string mainstr);
        void UnEquipEquipment_HANDLER (std::string mainstr);
        void SellItem_HANDLER (std::string mainstr);
        void UseItem_HANDLER (std::string mainstr);
        void ComposeItem_HANDLER (std::string mainstr);
        void SortItems (std::string mainstr);
};

#endif //_LOCALRPCHANDLERS_H
