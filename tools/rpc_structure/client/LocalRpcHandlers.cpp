
#include "LocalRpcHandlers.h"
#include "CallBackFunctions.h"

///////////////////////////////////////////////////////////////////
void LocalRpcHandlers::UpdateOneBagItem_HANDLER (std::string mainstr)
{
        RPCS::CRPCUpdateOneBagItem args;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        args.ParseFromString (substr);
        int pos;
        ItemBase item;
        pos = args.pos();
        item.ParseObjectFromStringForNet (mainstr);

        UpdateOneBagItem_CallBack (pos, item);
}

void LocalRpcHandlers::UpdateOneEquipedItem_HANDLER (std::string mainstr)
{
        RPCS::CRPCUpdateOneEquipedItem args;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        args.ParseFromString (substr);
        int pos;
        ItemBase item;
        pos = args.pos();
        item.ParseObjectFromStringForNet (mainstr);

        UpdateOneEquipedItem_CallBack (pos, item);
}

void LocalRpcHandlers::UpdateBagItems_HANDLER (std::string mainstr)
{
        RPCS::CRPCUpdateBagItems args;
        std::string substr;
        unsigned short nsize;

        std::vector<ItemBase> items;
        nsize = ExtractSizeFromString (mainstr, nsize);

        for (int i=0; i<nsize; ++i) {
                ItemBase item;
                item.ParseObjectFromStringForNet (mainstr);
                items.push_back (item);
        }

        UpdateBagItems_CallBack (items);
}

///////////////////////////////////////////////////////////////////
void LocalRpcHandlers::EquipEquipment_HANDLER (std::string mainstr)
{
        RPCS::SRPCEquipEquipmentRlt tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();

        EquipEquipment_CallBack (rs);
}

void LocalRpcHandlers::UnEquipEquipment_HANDLER (std::string mainstr)
{
        RPCS::SRPCUnEquipEquipmentRlt tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();

        UnEquipEquipment_CallBack (rs);
}

void LocalRpcHandlers::SellItem_HANDLER (std::string mainstr)
{
        RPCS::SRPCSellItemRlt tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int money = tmpobj.money();
        int badge = tmpobj.badge();

        IntInt item;
        item.ParseObjectFromStringForNet (mainstr);

        SellItem_CallBack (money, badge, item);
}

void LocalRpcHandlers::UseItem_HANDLER (std::string mainstr)
{
        RPCS::SRPCUseItemRlt tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();
        std::vector<ResourceBase> resources;
        ExtractSizeFromString (mainstr, nsize);
        for (int i=0; i<nsize; ++i) {
                ResourceBase resource;
                resource.ParseObjectFromStringForNet (mainstr);
                resources.push_back (resource);
        }

        UseItem_CallBack (rs, resources);
}

void LocalRpcHandlers::ComposeItem_HANDLER (std::string mainstr)
{
        RPCS::SRPCComposeItemRlt tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int rs = tmpobj.rs();

        ComposeItem_CallBack (rs);
}

void LocalRpcHandlers::SortItems (std::string mainstr)
{
        // nothing
}
