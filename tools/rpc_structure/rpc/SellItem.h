

#ifndef _RPCFUNCTIONS_SELLITEM_H
#define _RPCFUNCTIONS_SELLITEM_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class SellItem : public RpcFunctionBase
        { 
        public:
                void invoke (int itemPos);

                void return_result (int money, int badge, IntIntBase item)
                {
                        std::string mainstr;
                        std::string substr;

                        RPCS::SRPCSellItemRlt tmpobj;
                        tmpobj.set_money (money);
                        tmpobj.set_badge (badge);
                        tmpobj.SerializeToString (&substr);

                        AppendObjectToString (mainstr, substr);

                        item.SerializeObjectToStringForNet (mainstr);

                        m_result = mainstr;
                }
        };

};

#endif  //_RPCFUNCTIONS_SELLITEM_H
