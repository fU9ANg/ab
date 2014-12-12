
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
    PosBase ()
    {
    }

    int getX (void)
    {
        return (m_X);
    }
    int getY (void)
    {
        return (m_Y);
    }

    void setX (int x)
    {
        m_X = x;
    }
    void setY (int y)
    {
        m_Y = y;
    }
private:
    ChenyuanTypes::PosSerializeDB  selfSerializeDB;
    int     m_X;
    int     m_Y;

public:
    void dumpObject (void)
    {
        std::cout << "------ Pos ------" << std::endl;
        std::cout << "m_X: " << m_X << std::endl;
        std::cout << "m_Y: " << m_Y << std::endl;
    }
    std::string SerializeObjectToStringForDB (std::string& mainstr)
    {
        std::string substr;

        // 1. for base type
        selfSerializeDB.set_x(getX());
        selfSerializeDB.set_y(getY());

        selfSerializeDB.SerializeToString (&substr);
        PushSerializeString (mainstr, substr);

        return (mainstr);
    }

    bool ParseObjectFromStringForDB (std::string& mainstr)
    {
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
            return (false);

        PopSerializeString(mainstr, substr, nSize);
        selfSerializeDB.ParseFromString(substr);

        // 1. for base type
        setX(selfSerializeDB.x());
        setY(selfSerializeDB.y());

        return (true);
    }
};

#endif  // _GEN_POS_H
