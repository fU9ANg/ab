

#include "PosBase.h"

PosBase::PosBase ()
{
        selfSerializeDB.Clear ();
        selfSerializeClient.Clear ();

        m_X = 0;
        m_Y = 0;
}

int PosBase::getX (void)
{
        return (m_X);
}
int PosBase::getY (void)
{
        return (m_Y);
}

void PosBase::setX (int x)
{
        m_X = x;
}
void PosBase::setY (int y)
{
        m_Y = y;
}

void PosBase::dumpObject (void)
{
        std::cout << "------ Pos ------" << std::endl;
        std::cout << "m_X: " << m_X << std::endl;
        std::cout << "m_Y: " << m_Y << std::endl;
}
std::string PosBase::SerializeObjectToStringForDB (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeDB.set_x(getX());
        selfSerializeDB.set_y(getY());

        selfSerializeDB.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool PosBase::ParseObjectFromStringForDB (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeDB.ParseFromString(substr);

        // 1. for base type
        setX(selfSerializeDB.x());
        setY(selfSerializeDB.y());

        return (true);
}

std::string PosBase::SerializeObjectToStringForClient (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeClient.set_x(getX());
        selfSerializeClient.set_y(getY());

        selfSerializeClient.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool PosBase::ParseObjectFromStringForClient (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeClient.ParseFromString(substr);

        // 1. for base type
        setX(selfSerializeClient.x());
        setY(selfSerializeClient.y());

        return (true);
}
