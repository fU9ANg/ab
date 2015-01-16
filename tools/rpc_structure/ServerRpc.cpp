
#include "ServerRpc.h"

using namespace rpcfunctions;

RpcFunctionBase* ServerRpc::EquipEquipment_HANDLER (std::string mainstr)
{
        if (mainstr.empty()) return NULL;
        RPCS::SRPCEquipEquipmentArg tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        rpcfunctions::EquipEquipment *fnobj = new rpcfunctions::EquipEquipment();
        //EquipEquipment *fnobj = new EquipEquipment();
        fnobj->invoke (tmpobj.itempos());

        return (fnobj);
}

RpcFunctionBase* ServerRpc::UnEquipEquipment_HANDLER (std::string mainstr)
{
        if (mainstr.empty()) return NULL;
        RPCS::SRPCUnEquipEquipmentArg tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        rpcfunctions::UnEquipEquipment *fnobj = new rpcfunctions::UnEquipEquipment();
        fnobj->invoke (tmpobj.pos());

        return (fnobj);
}

RpcFunctionBase* ServerRpc::SellItem_HANDLER (std::string mainstr)
{
        if (mainstr.empty()) return NULL;
        RPCS::SRPCSellItemArg tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int itemPos = tmpobj.itempos();
        rpcfunctions::SellItem *fnobj = new rpcfunctions::SellItem();
        fnobj->invoke (itemPos);

        return (fnobj);
}

RpcFunctionBase* ServerRpc::UseItem_HANDLER (std::string mainstr)
{
        if (mainstr.empty()) return NULL;
        RPCS::SRPCUseItemArg tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int pos = tmpobj.pos();
        rpcfunctions::UseItem *fnobj = new rpcfunctions::UseItem();
        fnobj->invoke (pos);

        return (fnobj);
}

RpcFunctionBase* ServerRpc::ComposeItem_HANDLER (std::string mainstr)
{
        if (mainstr.empty()) return NULL;
        RPCS::SRPCComposeItemArg tmpobj;
        std::string substr;
        unsigned short nsize;

        ExtractObjectFromString (mainstr, substr, nsize);
        tmpobj.ParseFromString (substr);

        int type;
        std::vector<int> indexs;
        type = tmpobj.type();
        for (int i=0; i<tmpobj.indexs().size(); ++i) {
                indexs.push_back (tmpobj.indexs(i));
        }

        rpcfunctions::ComposeItem *fnobj = new rpcfunctions::ComposeItem();
        fnobj->invoke (type, indexs);

        return (fnobj);
}

RpcFunctionBase* ServerRpc::SortItems_HANDLER (void)
{
        //std::string substr;
        //unsigned short nsize;

        rpcfunctions::SortItems *fnobj = new rpcfunctions::SortItems();
        fnobj->invoke ();

        return (fnobj);
}
