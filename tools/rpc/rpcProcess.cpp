
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

#include "pugixml.hpp"
#include "rpcStructure.h"
#include "rpcProcess.h"

using namespace std;

int RpcProcess::LoadRpcContentFromXml (const std::string strFile)
{
        if (strFile.empty())
                return (-1);

        pugi::xml_document doc;
        if (!doc.load_file (strFile.c_str())) {
                std::cout << "[ERROR]: can't open xml file - \"" << strFile << "\"" << std::endl;
                return (-1);
        }

        // client rpc
        pugi::xml_node xml_as3 = doc.child("RPC").child("AS3");
        for (pugi::xml_node xml_function = xml_as3.first_child(); xml_function;
                        xml_function = xml_function.next_sibling())
        {
                xmlRpcFunction tmpRpcFunction;
                std::string xml_function_name = xml_function.attribute("name").value();
                std::string xml_function_doc = xml_function.attribute("doc").value();
                std::string xml_function_local = xml_function.attribute("local").value();
                std::string xml_function_requirestate = xml_function.attribute("requireState").value();

                if (!xml_function_name.empty())
                        tmpRpcFunction.name = xml_function_name;
                if (!xml_function_doc.empty())
                        tmpRpcFunction.doc = xml_function_doc;
                if (!xml_function_local.empty())
                        tmpRpcFunction.local = xml_function_local;
                if (!xml_function_requirestate.empty()) {
                        tmpRpcFunction.requireState = xml_function_requirestate;
                }

                for (pugi::xml_node xml_arg = xml_function.first_child(); xml_arg;
                                xml_arg = xml_arg.next_sibling())
                {
                        xmlRpcArg tmpRpcArg;
                        std::string xml_arg_name = xml_arg.attribute("name").value();
                        std::string xml_arg_type = xml_arg.attribute("type").value();
                        std::string xml_arg_doc  = xml_arg.attribute("doc").value();

                        if (!xml_arg_name.empty())
                                tmpRpcArg.name = xml_arg_name;
                        if (!xml_arg_type.empty())
                                tmpRpcArg.type = xml_arg_type;
                        if (!xml_arg_doc.empty())
                                tmpRpcArg.doc = xml_arg_doc;

                        if (strcmp (xml_arg.name(), "arg") == 0)
                                tmpRpcFunction.insertArgToFunction (tmpRpcArg);
                        else if (strcmp (xml_arg.name(), "ret") == 0)
                                tmpRpcFunction.insertRetToFunction (tmpRpcArg);
                }
                m_rpcFunctions.insertFunctionToClientRpc (tmpRpcFunction);
        }

        // server rpc
        pugi::xml_node xml_cpp = doc.child("RPC").child("cpp");
        for (pugi::xml_node xml_function = xml_cpp.first_child(); xml_function;
                        xml_function = xml_function.next_sibling())
        {
                xmlRpcFunction tmpRpcFunction;
                std::string xml_function_name = xml_function.attribute("name").value();
                std::string xml_function_doc = xml_function.attribute("doc").value();
                std::string xml_function_local = xml_function.attribute("local").value();
                std::string xml_function_requirestate = xml_function.attribute("requireState").value();

                if (!xml_function_name.empty())
                        tmpRpcFunction.name = xml_function_name;
                if (!xml_function_doc.empty())
                        tmpRpcFunction.doc = xml_function_doc;
                if (!xml_function_local.empty())
                        tmpRpcFunction.local = xml_function_local;
                if (!xml_function_requirestate.empty()) {
                        tmpRpcFunction.requireState = xml_function_requirestate;
                }

                for (pugi::xml_node xml_arg = xml_function.first_child(); xml_arg;
                                xml_arg = xml_arg.next_sibling())
                {
                        xmlRpcArg tmpRpcArg;
                        std::string xml_arg_name = xml_arg.attribute("name").value();
                        std::string xml_arg_type = xml_arg.attribute("type").value();
                        std::string xml_arg_doc  = xml_arg.attribute("doc").value();

                        if (!xml_arg_name.empty())
                                tmpRpcArg.name = xml_arg_name;
                        if (!xml_arg_type.empty())
                                tmpRpcArg.type = xml_arg_type;
                        if (!xml_arg_doc.empty())
                                tmpRpcArg.doc = xml_arg_doc;

                        if (strcmp (xml_arg.name(), "arg") == 0)
                                tmpRpcFunction.insertArgToFunction (tmpRpcArg);
                        else if (strcmp (xml_arg.name(), "ret") == 0)
                                tmpRpcFunction.insertRetToFunction (tmpRpcArg);
                }
                m_rpcFunctions.insertFunctionToServerRpc (tmpRpcFunction);
        }

        return (0);
}

void RpcProcess::dumpRPCContent (void)
{
        m_rpcFunctions.dump ();
}
