
#ifndef _RPC_PROCESS_H
#define _RPC_PROCESS_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

#include "pugixml.hpp"
#include "rpcStructure.h"

using namespace std;

class RpcProcess
{
public:
        int LoadRpcContentFromXml (const std::string strFile);
        void dumpRPCContent (void);

private:
        xmlRpcFunctions m_rpcFunctions;
};

#endif  //_RPC_PROCESS_H
