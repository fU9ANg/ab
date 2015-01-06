
#ifndef _RPC_FUNCTION_BASE_H
#define _RPC_FUNCTION_BASE_H

#include <iostream>
#include <vector>
#include <string>

#include "common.h"

#include "IntIntBase.h"
#include "PlayerBase.h"
#include "PosBase.h"
#include "ResourceBase.h"
#include "TalentNodeBase.h"
#include "TalentPropBase.h"

#include "ChenyuanTypes.pb.h"
#include "Rpc.pb.h"

using namespace std;

namespace rpcfunctions
{
class RpcFunctionBase
{
        private:
        protected:
                std::string m_result;
        public:
};
}

#endif  //_RPC_FUNCTION_BASE_H
