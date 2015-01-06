
#ifndef _GEN_ITEM_H
#define _GEN_ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include "common.h"
#include "ChenyuanTypes.pb.h"

using namespace std;

class ItemBase
{
public:
    ItemBase ();

    int getId (void);
    float getPrice (void);
    void setId (int id);
    void setPrice (float price);

private:
    ChenyuanTypes::ItemSerializeDB       selfSerializeDB;
    ChenyuanTypes::ItemSerializeNet   selfSerializeNet;

    int     m_Id;
    int     m_Price;

public:
    void dumpObject (void);

    std::string SerializeObjectToStringForDB (std::string& mainstr);
    bool ParseObjectFromStringForDB (std::string& mainstr);
    std::string SerializeObjectToStringForNet (std::string& mainstr);
    bool ParseObjectFromStringForNet (std::string& mainstr);
};

#endif  // _GEN_ITEM_H
