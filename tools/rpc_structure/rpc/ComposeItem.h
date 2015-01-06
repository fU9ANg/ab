
#ifndef _RPCFUNCTIONS_COMPOSEITEM_H
#define _RPCFUNCTIONS_COMPOSEITEM_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class ComposeItem : public RpcFunctionBase
        { 
        public:
                void invoke (int type, std::vector<int> indexs);

                void return_result (int rs)
                {
                        std::string mainstr;
                        std::string substr;

                        RPCS::SRPCComposeItemRlt tmpobj;
                        tmpobj.set_rs (rs);
                        tmpobj.SerializeToString (&substr);

                        AppendObjectToString (mainstr, substr);

                        m_result = mainstr;
                }
        };

};

#endif  //_RPCFUNCTIONS_COMPOSEITEM_H
