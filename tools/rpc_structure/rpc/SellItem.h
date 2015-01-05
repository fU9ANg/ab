

#ifndef _RPCFUNCTIONS_SELLITEM_H
#define _RPCFUNCTIONS_SELLITEM_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class SellItem : public RpcFunctionBase
        { 
                void invoke (int itemPos);

                void return_result (int money, int badge, IntInt item)
                {
                        std::string mainstr;
                        std::string substr;

                        // SRPCSellItemRlt tmpobj;
                        // tmpobj.set_money (money);
                        // tmpobj.set_badge (badge);
                        // tmpobj.SerializeToString (&substr);

                        AppendObjectToString (mainstr, substr);

                        item.SerializeObjectToString (mainstr);

                        m_result = mainstr;
                }
        };

};

#endif  //_RPCFUNCTIONS_SELLITEM_H
