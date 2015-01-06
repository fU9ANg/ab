
#ifndef _GEN_INTINT_H
#define _GEN_INTINT_H

#include <iostream>
#include <string>
#include <vector>
#include "common.h"
#include "ChenyuanTypes.pb.h"

using namespace std;

class IntIntBase
{
public:
    IntIntBase ();

    int getInt1 (void);
    int getInt2 (void);
    void setInt1 (int i1);
    void setInt2 (int i2);

private:
    ChenyuanTypes::IntIntSerializeDB       selfSerializeDB;
    ChenyuanTypes::IntIntSerializeNet   selfSerializeNet;

    int     m_Int1;
    int     m_Int2;

public:
    void dumpObject (void);

    std::string SerializeObjectToStringForDB (std::string& mainstr);
    bool ParseObjectFromStringForDB (std::string& mainstr);
    std::string SerializeObjectToStringForNet (std::string& mainstr);
    bool ParseObjectFromStringForNet (std::string& mainstr);
};

#endif  // _GEN_INTINT_H
