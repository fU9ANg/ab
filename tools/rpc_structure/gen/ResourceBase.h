
#ifndef _GEN_RESOURCE_H
#define _GEN_RESOURCE_H

#include <iostream>
#include <string>
#include <vector>
#include "common.h"
#include "ChenyuanTypes.pb.h"

using namespace std;

class ResourceBase
{
public:
    ResourceBase ();

    int getId (void);
    string getName (void);
    void setId (int i);
    void setName (string n);

private:
    ChenyuanTypes::ResourceSerializeDB       selfSerializeDB;
    ChenyuanTypes::ResourceSerializeNet   selfSerializeNet;

    int     m_Id;
    string  m_Name;

public:
    void dumpObject (void);

    std::string SerializeObjectToStringForDB (std::string& mainstr);
    bool ParseObjectFromStringForDB (std::string& mainstr);
    std::string SerializeObjectToStringForNet (std::string& mainstr);
    bool ParseObjectFromStringForNet (std::string& mainstr);
};

#endif  // _GEN_RESOURCE_H
