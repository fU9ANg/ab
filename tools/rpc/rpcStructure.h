
#ifndef _RPC_STRUCTURE_H
#define _RPC_STRUCTURE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

using namespace std;

enum eRpcArgRet
{
        RAR_ARG = 1,
        RAR_RET = 2,
};

class xmlRpcArg
{
public:
        xmlRpcArg (void);
        void dump (eRpcArgRet eAorR);
        std::string name;                                   // 此参数或者返回值的名称
        std::string type;                                   // 此参数或者返回值的数据类型
        std::string arraySize;                              // 此参数或者返回值的数据类型大小
        std::string doc;                                    // 此参数或者返回值的注释
};
typedef xmlRpcArg xmlRpcRet;

class xmlRpcFunction
{
public:
        xmlRpcFunction (void);
        void dump (void);
        void insertArgToFunction (xmlRpcArg arg);
        void insertRetToFunction (xmlRpcRet ret);

        std::string name;                                   // 此Rpc函数的名称
        std::string doc;                                    // 此Rpc函数的注释
        std::string requireState;                           // 执行此Rpc函数所需的客服端的状态
        std::string local;                                  //
        std::map<std::string, xmlRpcArg> vArgs;             // 此Rpc函数的所有参数
        std::map<std::string, xmlRpcRet> vRets;             // 此Rpc函数的所有返回值
};

class xmlRpcFunctions
{
public:
        xmlRpcFunctions (void);
        void dump (void);
        void insertFunctionToClientRpc (xmlRpcFunction func);
        void insertFunctionToServerRpc (xmlRpcFunction func);

        std::map<std::string, xmlRpcFunction> vClientRpc;   // 包含了所有客服端RPC函数 
        std::map<std::string, xmlRpcFunction> vServerRpc;   // 包含了所有服务器RPC函数 
};

#endif  //_RPC_STRUCTURE_H
