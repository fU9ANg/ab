
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

#include "rpcStructure.h"

using namespace std;

xmlRpcArg::xmlRpcArg (void)
{
        name = "NULL";
        type = "NULL";
        arraySize = "NULL";
        doc = "NULL";
}

void xmlRpcArg::dump (eRpcArgRet eAorR)
{
        if (eAorR == RAR_ARG)
                std::cout << "\t\t\t<arg";
        else if (eAorR == RAR_RET)
                std::cout << "\t\t\t<ret";
        if (name != "NULL")
                std::cout << " name=\"" << name << "\"";
        if (type != "NULL")
                std::cout << " type=\"" << type << "\"";
        if (arraySize != "NULL")
                std::cout << " arraySize=\"" << arraySize << "\"";
        if (doc != "NULL")
                std::cout << " doc=\"" << doc << "\"";
        std::cout << "/>" << std::endl;
}

void xmlRpcFunction::insertArgToFunction (xmlRpcArg arg)
{
        vArgs.insert (std::make_pair<std::string, xmlRpcArg> (arg.name, arg));
}

void xmlRpcFunction::insertRetToFunction (xmlRpcRet ret)
{
        vRets.insert (std::make_pair<std::string, xmlRpcRet> (ret.name, ret));
}

xmlRpcFunction::xmlRpcFunction (void)
{
        name = "NULL";
        doc = "NULL";
        requireState = "NULL";
        local = "NULL";
        vArgs.clear();
        vRets.clear();
}

void xmlRpcFunction::dump (void)
{
        std::cout << "\t\t<function";
        if (name != "NULL")
                std::cout << " name=\"" << name << "\"";
        if (doc != "NULL")
                std::cout << " doc=\"" << doc << "\"";
        if (requireState != "NULL")
                std::cout << " requireState=\"" << requireState << "\"";

        if (vArgs.size() > 0 || vRets.size() > 0)
                std::cout << ">" << std::endl;
        else
                std::cout << "/>" << std::endl;

        std::map<std::string, xmlRpcArg>::iterator itArg;
        std::map<std::string, xmlRpcRet>::iterator itRet;
        for (itArg=vArgs.begin(); itArg!=vArgs.end(); ++itArg) {
                itArg->second.dump (RAR_ARG);
        }
        for (itRet=vRets.begin(); itRet!=vRets.end(); ++itRet) {
                itRet->second.dump (RAR_RET);
        }

        if (vArgs.size() > 0 || vRets.size() > 0)
                std::cout << "\t\t</function>" << std::endl;
}

xmlRpcFunctions::xmlRpcFunctions (void)
{
        vClientRpc.clear ();
        vServerRpc.clear ();
}

void xmlRpcFunctions::insertFunctionToClientRpc (xmlRpcFunction func)
{
        vClientRpc.insert (std::make_pair<std::string, xmlRpcFunction> (func.name, func));
}

void xmlRpcFunctions::insertFunctionToServerRpc (xmlRpcFunction func)
{
        vServerRpc.insert (std::make_pair<std::string, xmlRpcFunction> (func.name, func));
}

void xmlRpcFunctions::dump (void)
{
        std::map<std::string, xmlRpcFunction>::iterator it;

        std::cout << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
        std::cout << "<RPC>" << std::endl;

        // AS3
        if (vClientRpc.size() > 0)
                std::cout << "\t<AS3>" << std::endl;
        for (it = vClientRpc.begin(); it != vClientRpc.end(); ++it) {
                it->second.dump();
        }
        if (vClientRpc.size() > 0)
                std::cout << "\t</AS3>" << std::endl;

        // cpp
        if (vServerRpc.size() > 0)
                std::cout << "\t<cpp>" << std::endl;
        for (it = vServerRpc.begin(); it != vServerRpc.end(); ++it) {
                it->second.dump();
        }
        if (vServerRpc.size() > 0)
                std::cout << "\t</cpp>" << std::endl;

        std::cout << "</RPC>" << std::endl;
}
