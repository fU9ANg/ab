

#include "ItemBase.h"

ItemBase::ItemBase ()
{
        selfSerializeDB.Clear ();
        selfSerializeNet.Clear ();

        m_Id = 0;
        m_Price = 0.f;
}

int ItemBase::getId (void)
{
        return (m_Id);
}
float ItemBase::getPrice (void)
{
        return (m_Price);
}
void ItemBase::setId (int id)
{
        m_Id = id;
}
void ItemBase::setPrice (float price)
{
        m_Price = price;
}

void ItemBase::dumpObject (void)
{
        std::cout << "------ Item ------" << std::endl;
        std::cout << "m_Id: " << m_Id << std::endl;
        std::cout << "m_Price: " << m_Price << std::endl;
}
std::string ItemBase::SerializeObjectToStringForDB (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeDB.set_id(getId());

        selfSerializeDB.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool ItemBase::ParseObjectFromStringForDB (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeDB.ParseFromString(substr);

        // 1. for base type
        setId(selfSerializeDB.id());

        return (true);
}

std::string ItemBase::SerializeObjectToStringForNet (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeNet.set_id(getId());
        selfSerializeNet.set_price(getPrice());

        selfSerializeNet.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool ItemBase::ParseObjectFromStringForNet (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeNet.ParseFromString(substr);

        // 1. for base type
        setId(selfSerializeNet.id());
        setPrice(selfSerializeNet.price());

        return (true);
}
