
#ifndef _RPCFUNCTIONS_EQUIPEQUIPMENT_H
#define _RPCFUNCTIONS_EQUIPEQUIPMENT_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class EquipEquipment : public RpcFunctionBase
        { 
        public:
                void invoke (int itemPos);

                void return_result (int rs)
                {
                        std::string mainstr;
                        std::string substr;

                        RPCS::SRPCEquipEquipmentRlt tmpobj;
                        tmpobj.set_rs (rs);
                        tmpobj.SerializeToString (&substr);

                        AppendObjectToString (mainstr, substr);

                        m_result = mainstr;
                }
        };

}

#endif  //_RPCFUNCTIONS_EQUIPEQUIPMENT_H
