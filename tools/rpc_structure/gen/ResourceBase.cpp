

#include "ResourceBase.h"

ResourceBase::ResourceBase ()
{
        selfSerializeDB.Clear ();
        selfSerializeNet.Clear ();

        m_Id = 0;
        m_Name.clear();
}

int ResourceBase::getId (void)
{
        return (m_Id);
}

string ResourceBase::getName (void)
{
        return (m_Name);
}
void ResourceBase::setId (int i)
{
        m_Id = i;
}
void ResourceBase::setName (string n)
{
        m_Name = n;
}

void ResourceBase::dumpObject (void)
{
        std::cout << "------ Resource ------" << std::endl;
        std::cout << "m_Id: " << m_Id << std::endl;
        std::cout << "m_Name: " << m_Name << std::endl;
}
std::string ResourceBase::SerializeObjectToStringForDB (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeDB.set_id (getId());

        selfSerializeDB.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool ResourceBase::ParseObjectFromStringForDB (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeDB.ParseFromString(substr);

        // 1. for base type
        setId (selfSerializeDB.id());

        return (true);
}

std::string ResourceBase::SerializeObjectToStringForNet (std::string& mainstr)
{
        std::string substr;

        // 1. for base type
        selfSerializeNet.set_id (getId());
        selfSerializeNet.set_name (getName());

        selfSerializeNet.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool ResourceBase::ParseObjectFromStringForNet (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString(mainstr, substr, nSize);
        selfSerializeNet.ParseFromString(substr);

        // 1. for base type
        setId (selfSerializeNet.id());
        setName (selfSerializeNet.name());

        return (true);
}
