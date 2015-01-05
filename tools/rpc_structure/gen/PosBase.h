
#ifndef _GEN_POS_H
#define _GEN_POS_H

#include <iostream>
#include <string>
#include <vector>
#include "common.h"
#include "ChenyuanTypes.pb.h"

using namespace std;

class PosBase
{
public:
    PosBase ();

    int getX (void);
    int getY (void);
    void setX (int x);
    void setY (int y);

private:
    ChenyuanTypes::PosSerializeDB       selfSerializeDB;
    ChenyuanTypes::PosSerializeClient   selfSerializeClient;

    int     m_X;
    int     m_Y;

public:
    void dumpObject (void);

    std::string SerializeObjectToStringForDB (std::string& mainstr);
    bool ParseObjectFromStringForDB (std::string& mainstr);
    std::string SerializeObjectToStringForClient (std::string& mainstr);
    bool ParseObjectFromStringForClient (std::string& mainstr);
};

#endif  // _GEN_POS_H
