

#include "PosBase.h"

PosBase::PosBase ()
{
        selfSerializeDB.Clear ();
        selfSerializeNet.Clear ();

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

std::string PosBase::SerializeObjectToStringForNet (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeNet.set_x(getX());
        selfSerializeNet.set_y(getY());

        selfSerializeNet.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool PosBase::ParseObjectFromStringForNet (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeNet.ParseFromString(substr);

        // 1. for base type
        setX(selfSerializeNet.x());
        setY(selfSerializeNet.y());

        return (true);
}
