
#include "CallBackFunctions.h"
#include "ServerRpcFunctions.h"

using namespace ServerRpcFunctions;

///////////////////////////////////////////////////////////////////
void UpdateOneBagItem_CallBack (int pos, ItemBase item)
{
        // TODO: write client source code, here
        printf ("UpdateOneBagItem_CallBack: pos = %d\n", pos);
        printf ("UpdateOneBagItem_CallBack: item.id = %d\n", item.getId ());
        printf ("UpdateOneBagItem_CallBack: item.price = %f\n", item.getPrice ());

        EquipEquipment (999);
}

void UpdateOneEquipedItem_CallBack (int pos, ItemBase item)
{
        // TODO: write client source code, here
		printf ("UpdateOneEquipedItem_CallBack: pos = %d\n", pos);
		printf ("UpdateOneEquipedItem_CallBack: item.id = %d\n", item.getId ());
		printf ("UpdateOneEquipedItem_CallBack: item.price = %f\n", item.getPrice ());

		EquipEquipment (999);
}

void UpdateBagItems_CallBack (std::vector<ItemBase> items)
{
        // TODO: write client source code, here
		int i = 1;
		for (std::vector<ItemBase>::iterator it = items.begin(); it != items.end(); ++it) {
				printf ("UpdateBagItems_CallBack: item[%d].id = %d\n", i, it->getId ());
				printf ("UpdateBagItems_CallBack: item[%d].price = %f\n", i, it->getPrice ());
				i++;
		}
}

///////////////////////////////////////////////////////////////////
void EquipEquipment_CallBack (int rs)
{
        printf ("EquipEquipment_CallBack rs=%d\n", rs);
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
