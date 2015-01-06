
#ifndef _CALLBACKFUNCTIONS_H
#define _CALLBACKFUNCTIONS_H

#include "Platform.h"

#include "ItemBase.h"
#include "IntInt.h"
#include "ResourceBase.h"

using namespace std;

extern void UpdateOneBagItem_CallBack (int pos, ItemBase item);
extern void UpdateOneEquipedItem_CallBack (int pos, ItemBase item);
extern void UpdateBagItems_CallBack (std::vector<ItemBase> items);

extern void EquipEquipment_CallBack (int rs);
extern void UnEquipEquipment_CallBack (int rs);
extern void SellItem_CallBack (int money, int badge, IntInt item);
extern void UseItem_CallBack (int rs, std::vector<ResourceBase> resources);
extern void ComposeItem_CallBack (int rs);

#endif  //_CALLBACKFUNCTIONS_H
