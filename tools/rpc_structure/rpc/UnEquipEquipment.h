
#ifndef _RPCFUNCTIONS_UNEQUIPEQUIPMENT_H
#define _RPCFUNCTIONS_UNEQUIPEQUIPMENT_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class UnEquipEquipment : public RpcFunctionBase
        { 
                void invoke (int pos);

                void return_result (int rs)
                {
                        std::string mainstr;
                        std::string substr;

                        SRPCUnEquipEquipmentRlt tmpobj;
                        tmpobj.set_rs (rs);
                        tmpobj.SerializeToString (&substr);

                        SerializeObjectToString (mainstr, substr);

                        m_result = mainstr;
                }
        };

};

#endif  //_RPCFUNCTIONS_UNEQUIPEQUIPMENT_H
