
#ifndef _RPCFUNCTIONS_UNEQUIPEQUIPMENT_H
#define _RPCFUNCTIONS_UNEQUIPEQUIPMENT_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class UnEquipEquipment : public RpcFunctionBase
        { 
        public:
                void invoke (int pos);

                void return_result (int rs)
                {
                        std::string mainstr;
                        std::string substr;

                        RPCS::SRPCUnEquipEquipmentRlt tmpobj;
                        tmpobj.set_rs (rs);
                        tmpobj.SerializeToString (&substr);

                        AppendObjectToString (mainstr, substr);

                        m_result = mainstr;
                }
        };

};

#endif  //_RPCFUNCTIONS_UNEQUIPEQUIPMENT_H
