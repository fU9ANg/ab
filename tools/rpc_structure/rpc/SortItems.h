

#ifndef _RPCFUNCTIONS_SORTITEMS_H
#define _RPCFUNCTIONS_SORTITEMS_H

#include "RpcFunctionBase.h"

namespace rpcfunctions
{
        class SortItems : public RpcFunctionBase
        { 
                void invoke (void);

                void return_result (void)
                {
                }
        };

};

#endif  //_RPCFUNCTIONS_SORTITEMS_H
