
#include "Platform.h"
#include "ChenyuanTypes.pb.h"
#include "Rpc.pb.h"

extern void CALL_SERVERRPC (std::string mainstr);

namespace ServerRpcFunctions
{
        static void EquipEquipment (int itemPos);
        static void UnEquipEquipment (int pos);
        static void SellItem (int itemPos);
        static void UseItem (int pos);
        static void ComposeItem (int type, std::vector<int> indexs);
        static void SortItems (void);
}
