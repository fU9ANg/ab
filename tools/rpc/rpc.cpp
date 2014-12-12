
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

#include "rpcProcess.h"

#define XML_FILENAME    "./rpc.xml"

using namespace std;

int main ()
{
        const std::string strFile = XML_FILENAME;
        RpcProcess RP;
        RP.LoadRpcContentFromXml (strFile);
#ifdef _DUMP_OBJECT_INFO
        RP.dumpRPCContent ();
#endif

        return (0);
}
