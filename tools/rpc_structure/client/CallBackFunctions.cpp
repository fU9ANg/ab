
#include "CallBackFunctions.h"

///////////////////////////////////////////////////////////////////
void UpdateOneBagItem_CallBack (int pos, ItemBase item)
{
        // TODO: write client source code, here
        printf ("pos = %d\n", pos);
        printf ("item.id = %d\n", item.getId ());
        printf ("item.price = %f\n", item.getPrice ());
}

void UpdateOneEquipedItem_CallBack (int pos, ItemBase item)
{
        // TODO: write client source code, here
}

void UpdateBagItems_CallBack (std::vector<ItemBase> items)
{
        // TODO: write client source code, here
}

///////////////////////////////////////////////////////////////////
void EquipEquipment_CallBack (int rs)
{
        // TODO: write client source code, here
}

void UnEquipEquipment_CallBack (int rs)
{
        // TODO: write client source code, here
}

void SellItem_CallBack (int money, int badge, IntIntBase item)
{
        // TODO: write client source code, here
}

void UseItem_CallBack (int rs, std::vector<ResourceBase> resources)
{
        // TODO: write client source code, here
}

void ComposeItem_CallBack (int rs)
{
        // TODO: write client source code, here
}
