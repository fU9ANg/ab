

#ifndef _RPCFUNCTIONS_USEITEM_H
#define _RPCFUNCTIONS_USEITEM_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class UseItem : public RpcFunctionBase
        { 
        public:
                void invoke (int pos);

                void return_result (int rs, std::vector<ResourceBase> resources)
                {
                        std::string mainstr;
                        std::string substr;

                        RPCS::SRPCUseItemRlt tmpobj;
                        tmpobj.set_rs (rs);
                        tmpobj.SerializeToString (&substr);
                        AppendObjectToString (mainstr, substr);

                        for (std::vector<ResourceBase>::iterator it = resources.begin(); it != resources.end(); ++it) {
                                (*it).SerializeObjectToStringForNet (mainstr);
                        }

                        m_result = mainstr;
                }
        };

};

#endif  //_RPCFUNCTIONS_USEITEM_H
