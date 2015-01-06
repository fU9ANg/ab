
#include "TalentPropBase.h"

TalentPropBase::TalentPropBase ()
{
        selfSerializeDB.Clear ();
        selfSerializeNet.Clear ();
        m_PropId = 0;
        m_PropVal= 0;
        m_Locked = 0;
}

int TalentPropBase::getPropId(void)
{
        return (m_PropId);
}
int TalentPropBase::getPropVal(void)
{
        return (m_PropVal);
}
int TalentPropBase::getLocked(void)
{
        return (m_Locked);
}
// sets
void TalentPropBase::setPropId(int id)
{
        m_PropId = id;
}
void TalentPropBase::setPropVal(int val)
{
        m_PropVal = val;
}
void TalentPropBase::setLocked(int lock)
{
        m_Locked = lock;
}

void TalentPropBase::dumpObject (void)
{
        std::cout << "------ TalentProp ------" << std::endl;
        std::cout << "m_PropId: " << m_PropId << std::endl;
        std::cout << "m_PropVal: " << m_PropVal << std::endl;
        std::cout << "m_Locked: " << m_Locked << std::endl;
}

std::string TalentPropBase::SerializeObjectToStringForDB (std::string& mainstr)
{
        //std::string mainstr;
        std::string substr;

        // 1. for base type
        selfSerializeDB.set_propid  (getPropId());
        selfSerializeDB.set_propval (getPropVal());
        selfSerializeDB.set_locked  (getLocked());

        selfSerializeDB.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool TalentPropBase::ParseObjectFromStringForDB (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString (mainstr, substr, nSize);
        selfSerializeDB.ParseFromString (substr);

        // 1. for base type
        setPropId  (selfSerializeDB.propid());
        setPropVal (selfSerializeDB.propval());
        setLocked  (selfSerializeDB.locked());

        return (true);
}

std::string TalentPropBase::SerializeObjectToStringForNet (std::string& mainstr)
{
        //std::string mainstr;
        std::string substr;

        // 1. for base type
        selfSerializeNet.set_propid  (getPropId());
        selfSerializeNet.set_propval (getPropVal());
        selfSerializeNet.set_locked  (getLocked());

        selfSerializeNet.SerializeToString (&substr);
        AppendObjectToString (mainstr, substr);

        return (mainstr);
}

bool TalentPropBase::ParseObjectFromStringForNet (std::string& mainstr)
{
        std::string substr;
        unsigned short nSize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString (mainstr, substr, nSize);
        selfSerializeNet.ParseFromString (substr);

        // 1. for base type
        setPropId  (selfSerializeNet.propid());
        setPropVal (selfSerializeNet.propval());
        setLocked  (selfSerializeNet.locked());

        return (true);
}
