
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

#include "ChenyuanProcess.h"

#define XML_FILENAME    "./ChenyuanTypes.xml"

using namespace std;

int main ()
{
        xmlChenyuanDefine tmpdefine;

        const std::string strFile = XML_FILENAME;
        ChenyuanProcess process;
        process.LoadRpcContentFromXml (strFile);
        process.dump ();

        return (0);
}
