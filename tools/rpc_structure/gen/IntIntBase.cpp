

#include "IntIntBase.h"

IntIntBase::IntIntBase ()
{
        selfSerializeDB.Clear ();
        selfSerializeNet.Clear ();

        m_Int1 = 0;
        m_Int2 = 0;
}

int  IntIntBase::getInt1 (void)
{
        return (m_Int1);
}
int  IntIntBase::getInt2 (void)
{
        return (m_Int2);
}
void IntIntBase::setInt1 (int i1)
{
        m_Int1 = i1;
}
void IntIntBase::setInt2 (int i2)
{
        m_Int2 = i2;
}

void IntIntBase::dumpObject (void)
{
        std::cout << "------ IntInt ------" << std::endl;
        std::cout << "m_Int1: " << m_Int1 << std::endl;
        std::cout << "m_Int2: " << m_Int2 << std::endl;
}
std::string IntIntBase::SerializeObjectToStringForDB (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeDB.set_int1(getInt1());
        selfSerializeDB.set_int2(getInt2());

        selfSerializeDB.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool IntIntBase::ParseObjectFromStringForDB (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeDB.ParseFromString(substr);

        // 1. for base type
        setInt1(selfSerializeDB.int1());
        setInt2(selfSerializeDB.int2());

        return (true);
}

std::string IntIntBase::SerializeObjectToStringForNet (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeNet.set_int1(getInt1());
        selfSerializeNet.set_int2(getInt2());

        selfSerializeNet.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool IntIntBase::ParseObjectFromStringForNet (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeNet.ParseFromString(substr);

        // 1. for base type
        setInt1(selfSerializeNet.int1());
        setInt2(selfSerializeNet.int2());

        return (true);
}
