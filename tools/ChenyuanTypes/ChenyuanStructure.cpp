
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

#include "ChenyuanStructure.h"

using namespace std;

xmlChenyuanProp::xmlChenyuanProp (void) {
        name = "NULL";
        dataType = "NULL";
        arraySize = "NULL";
        doc = "NULL";
        serializeClient = false;
        serializeDB = false;
}
void xmlChenyuanProp::dump (void)
{
        std::cout << "\t\t<Property";
        if (name != "NULL")
                std::cout << " name=\"" << name << "\"";
        if (dataType != "NULL")
                std::cout << " dataType=\"" << dataType << "\"";
        if (arraySize != "NULL")
                std::cout << " arraySize=\"" << arraySize << "\"";
        if (doc != "NULL")
                std::cout << " doc=\"" << doc << "\"";
        std::cout << "/>" << std::endl;
}




xmlChenyuanType::xmlChenyuanType (void) {
        base = "NULL";
        name = "NULL";
        mProps.clear();
        hasUserDataType = false;
        serializeClientAll = false;
        serializeDBAll = false;
}
void xmlChenyuanType::add (xmlChenyuanProp prop)
{
        mProps.insert (std::make_pair<std::string, xmlChenyuanProp> (prop.name, prop));
}
void xmlChenyuanType::dump (void)
{
        bool bFristFlag;

        std::cout << "\t<Type";
        if (name != "NULL")
                std::cout << " name=\"" << name << "\"";
        if (base != "NULL")
                std::cout << " base=\"" << base << "\"";
        if (serializeDBAll)
                std::cout << " serializeDB=\"all\"";
        if (serializeClientAll)
                std::cout << " serializeClient=\"all\"";

        if (mProps.size() == 0)
                std::cout << "/>" << std::endl;
        else
                std::cout << ">" << std::endl;

        std::map<std::string, xmlChenyuanProp>::iterator it;
        // for Properties
        for (it = mProps.begin(); it != mProps.end(); ++it) {
                it->second.dump();
        }

        // for SerializeClient Properties
        bFristFlag = true;
        for (it = mProps.begin(); it != mProps.end(); ++it) {
                if (it->second.serializeClient) {
                        if (bFristFlag) {
                                bFristFlag = false;
                                std::cout << "\t\t<serializeClient>" << std::endl;
                        }
                        std::cout << "\t\t\t<Property name=\"" << it->second.name << "\"/>" << std::endl;
                }
        }
        if (bFristFlag == false)
                std::cout << "\t\t</serializeClient>" << std::endl;

        // for SerializeDB Properties
        bFristFlag = true;
        for (it = mProps.begin(); it != mProps.end(); ++it) {
                if (it->second.serializeDB) {
                        if (bFristFlag) {
                                bFristFlag = false;
                                std::cout << "\t\t<serializeDB>" << std::endl;
                        }
                        std::cout << "\t\t\t<Property name=\"" << it->second.name << "\"/>" << std::endl;
                }
        }
        if (bFristFlag == false)
                std::cout << "\t\t</serializeDB>" << std::endl;

        if (mProps.size() > 0)
                std::cout << "\t</Type>" << std::endl;
}


xmlChenyuanDefine::xmlChenyuanDefine ()
{
        vTypes.clear();
}
void xmlChenyuanDefine::add (xmlChenyuanType type)
{
        //vTypes.push_back (type);
        vTypes.insert (std::make_pair<std::string, xmlChenyuanType> (type.name, type));
}
void xmlChenyuanDefine::dump (void)
{
        std::cout << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
        std::cout << "<Define>" << std::endl;
        std::map<std::string, xmlChenyuanType>::iterator it;
        for (it = vTypes.begin(); it != vTypes.end(); ++it)
                it->second.dump ();
        std::cout << "</Define>" << std::endl;
}
