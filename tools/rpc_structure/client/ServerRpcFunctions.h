
#include "Platform.h"
#include "ChenyuanTypes.pb.h"
#include "Rpc.pb.h"

extern void CALL_SERVERRPC (std::string mainstr);

namespace ServerRpcFunctions
{
        void EquipEquipment (int itemPos);
        void UnEquipEquipment (int pos);
        void SellItem (int itemPos);
        void UseItem (int pos);
        void ComposeItem (int type, std::vector<int> indexs);
        void SortItems (void);
}
