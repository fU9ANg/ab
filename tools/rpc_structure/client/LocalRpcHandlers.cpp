
#include "LocalRpcHandlers.h"
#include "CallBackFunctions.h"

///////////////////////////////////////////////////////////////////
void LocalRpcHandlers::UpdateOneBagItem_HANDLER (std::string mainstr)
{
        CRPCUpdateOneBagItem args;
        std::string substr;
        int nsize;

        PopObjectFromString (mainstr, substr, nsize);
        args.ParseFromString (substr);
        int pos;
        ItemBase item;
        pos = args.pos();
        item.PopObjectFromStringForDB (mainstr);

        UpdateOneBagItem_CallBack (pos, item);
}

void LocalRpcHandlers::UpdateOneEquipedItem_HANDLER (std::string mainstr)
{
        CRPCUpdateOneEquipedItem args;
        std::string substr;
        int nsize;

        PopObjectFromString (mainstr, substr, nsize);
        args.ParseFromString (substr);
        int pos;
        ItemBase item;
        pos = args.pos();
        item.PopObjectFromStringForDB (mainstr);

        UpdateOneEquipedItem_CallBack (pos, item);
}

void LocalRpcHandlers::UpdateBagItems_HANDLER (std::string mainstr)
{
        CRPCUpdateBagItems args;
        std::string substr;
        int nsize;

        std::vector<ItemBase> items;
        nsize = PopSizeFromString (mainstr, nsize);

        for (int i=0; i<nsize; ++i) {
                ItemBase item;
                item.PopObjectFromStringForDB (mainstr);
                items.push_back (item);
        }

        UpdateBagItems_CallBack (items);
}

///////////////////////////////////////////////////////////////////
void LocalRpcHandlers::EquipEquipment_HANDLER (std::string mainstr)
{
        SRPCEquipEquipmentRlt tmpobj;
        std::string substr;
        int nsize;

        PopObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();

        EquipEquipment_CallBack (rs);
}

void LocalRpcHandlers::UnEquipEquipment_HANDLER (std::string mainstr)
{
        SRPCUnEquipEquipmentRlt tmpobj;
        std::string substr;
        int nsize;

        PopObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();

        UnEquipEquipment_CallBack (rs);
}

void LocalRpcHandlers::SellItem_HANDLER (std::string mainstr)
{
        SRPCSellItemRlt tmpobj;
        std::string substr;
        int nsize;

        PopObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int money = tmpobj.money();
        int badge = tmpobj.badge();

        IntInt item;
        item.PopObjectFromStringForDB (mainstr);

        SellItem_CallBack (money, badge, item);
}

void LocalRpcHandlers::UseItem_HANDLER (std::string mainstr)
{
        SRPCUseItemRlt tmpobj;
        std::string substr;
        int nsize;

        PopObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();
        std::vector<ResourceBase> resources;
        PopSizeFromString (mainstr, nsize);
        for (int i=0; i<nsize; ++i) {
                ResourceBase resource;
                resource.PopObjectFromString (mainstr);
                resources.push_back (resource);
        }

        UseItem_CallBack (rs, resources);
}

void LocalRpcHandlers::ComposeItem_HANDLER (std::string mainstr)
{
        SRPCComposeItemRlt tmpobj;
        std::string substr;
        int nsize;

        PopObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();

        ComposeItem_CallBack (rs);
}

void LocalRpcHandlers::SortItems (std::string mainstr)
{
        // nothing
}
