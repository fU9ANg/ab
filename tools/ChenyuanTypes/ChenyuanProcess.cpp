
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>

#include "pugixml.hpp"
#include "ChenyuanProcess.h"

using namespace std;

int ChenyuanProcess::LoadRpcContentFromXml (const std::string strFile)
{
        if (strFile.empty())
                return (-1);

        pugi::xml_document doc;
        if (!doc.load_file (strFile.c_str())) {
                return (-1);
        }

        pugi::xml_node xml_define = doc.child("Define");
        for (pugi::xml_node xml_type = xml_define.first_child(); xml_type;
                        xml_type = xml_type.next_sibling())
        {
                xmlChenyuanType tmptype;

                std::string xml_type_name = xml_type.attribute("name").value();
                std::string xml_type_baseobjectname = xml_type.attribute("base").value();
                std::string xml_type_serializedb = xml_type.attribute("serializeDB").value();
                std::string xml_type_serializeclient = xml_type.attribute("serializeClient").value();
                if (xml_type_name.empty()) {;}
#ifdef _DEBUG_READXML_INFO
                std::cout << "name=" << xml_type_name << ",base=" << xml_type_baseobjectname <<
                             ",serializeDB=" << xml_type_serializedb << ",serializeClient=" << 
                             xml_type_serializeclient << std::endl;
#endif
                // set value for xmlChenyuanType
                if (!xml_type_name.empty())
                        tmptype.name = xml_type_name;
                if (!xml_type_baseobjectname.empty())
                        tmptype.base = xml_type_baseobjectname;
                if (!xml_type_serializedb.empty())
                        tmptype.serializeDBAll = true;
                if (!xml_type_serializeclient.empty())
                        tmptype.serializeClientAll = true;

                for (pugi::xml_node xml_type_child = xml_type.first_child(); xml_type_child;
                                xml_type_child = xml_type_child.next_sibling())
                {
                        xmlChenyuanProp tmpprop;
                        if (strcmp (xml_type_child.name(), "Property") == 0) {
                                std::string xml_type_child_name = xml_type_child.attribute("name").value();
                                std::string xml_type_child_dataType = xml_type_child.attribute("dataType").value();
                                std::string xml_type_child_arraySize = xml_type_child.attribute("arraySize").value();
                                std::string xml_type_child_doc = xml_type_child.attribute("doc").value();
#ifdef _DEBUG_READXML_INFO
                                std::cout << "\t\t\tname=" << xml_type_child_name
                                          << "dataType=" << xml_type_child_dataType
                                          << "arraySize=" << xml_type_child_arraySize
                                          << "doc=" << xml_type_child_doc << std::endl;
#endif

                                // set value for xmlChenyuanProp
                                if (!xml_type_child_name.empty())
                                        tmpprop.name = xml_type_child_name;
                                if (!xml_type_child_dataType.empty())
                                        tmpprop.dataType = xml_type_child_dataType;
                                if (!xml_type_child_arraySize.empty())
                                        tmpprop.arraySize = xml_type_child_arraySize;
                                if (!xml_type_child_doc.empty())
                                        tmpprop.doc = xml_type_child_doc;

                                //tmptype.mProps.insert(std::make_pair<std::string, xmlChenyuanProp> (tmpprop.name, tmpprop));
                                tmptype.add (tmpprop);
                        }
                        else if (strcmp (xml_type_child.name(), "serializeDB") == 0) {
                                //serializeDB;
                                for (pugi::xml_node xml_type_child_serializedb = xml_type_child.first_child();
                                     xml_type_child_serializedb; xml_type_child_serializedb = xml_type_child_serializedb.next_sibling()) 
                                {
                                        std::string xml_type_serializedb_name = xml_type_child_serializedb.attribute("name").value();
                                        if (!xml_type_serializedb_name.empty())
                                        {
                                                std::map<std::string, xmlChenyuanProp>::iterator it;
                                                it = tmptype.mProps.find(xml_type_serializedb_name);
                                                if (it != tmptype.mProps.end()) {
                                                        it->second.serializeDB = true;
                                                }
                                        }
                                }
                        }
                        else if (strcmp (xml_type_child.name(), "serializeClient") == 0) {
                                //serializeClient;
                                for (pugi::xml_node xml_type_child_serializeclient = xml_type_child.first_child();
                                     xml_type_child_serializeclient; xml_type_child_serializeclient = xml_type_child_serializeclient.next_sibling()) 
                                {
                                        std::string xml_type_serializeclient_name = xml_type_child_serializeclient.attribute("name").value();
                                        if (!xml_type_serializeclient_name.empty())
                                        {
                                                std::map<std::string, xmlChenyuanProp>::iterator it;
                                                it = tmptype.mProps.find(xml_type_serializeclient_name);
                                                if (it != tmptype.mProps.end()) {
                                                        it->second.serializeClient = true;
                                                }
                                        }
                                }
                        }
                } // for property
                //m_chenyuanDefine.vTypes.push_back (tmptype);
                m_chenyuanDefine.add (tmptype);
        } // for type

        return (0);
}

void ChenyuanProcess::dump (void)
{
#ifdef _DUMP_OBJECT_INFO
        m_chenyuanDefine.dump ();
#endif
}
