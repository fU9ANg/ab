
#ifndef _CHENYUANPROCESS_H
#define _CHENYUANPROCESS_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>
#include "ChenyuanStructure.h"

using namespace std;

class ChenyuanProcess
{
public:
        int LoadRpcContentFromXml (const std::string strFile);
        void dump (void);

private:
        xmlChenyuanDefine m_chenyuanDefine;
};

#endif // _CHENYUANPROCESS_H
