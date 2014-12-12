
#ifndef _GEN_TALENTPROP_H
#define _GEN_TALENTPROP_H

#include <iostream>
#include <string>
#include <vector>

#include "common.h"
#include "ChenyuanTypes.pb.h"

using namespace std;

class TalentPropBase
{
public:
    TalentPropBase ()
    {
    }

    int getPropId(void)
    {
        return (m_PropId);
    }
    int getPropVal(void)
    {
        return (m_PropVal);
    }
    int getLocked(void)
    {
        return (m_Locked);
    }
    // sets
    void setPropId(int id)
    {
        m_PropId = id;
    }
    void setPropVal(int val)
    {
        m_PropVal = val;
    }
    void setLocked(int lock)
    {
        m_Locked = lock;
    }

private:
    ChenyuanTypes::TalentPropSerializeDB selfSerializeDB;
    int     m_PropId;
    int     m_PropVal;
    int     m_Locked;

public:
    void dumpObject (void)
    {
        std::cout << "------ TalentProp ------" << std::endl;
        std::cout << "m_PropId: " << m_PropId << std::endl;
        std::cout << "m_PropVal: " << m_PropVal << std::endl;
        std::cout << "m_Locked: " << m_Locked << std::endl;
    }

    std::string SerializeObjectToStringForDB (std::string& mainstr)
    {
        //std::string mainstr;
        std::string substr;

        // 1. for base type
        selfSerializeDB.set_propid  (getPropId());
        selfSerializeDB.set_propval (getPropVal());
        selfSerializeDB.set_locked  (getLocked());

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

        PopSerializeString (mainstr, substr, nSize);
        selfSerializeDB.ParseFromString (substr);

        // 1. for base type
        setPropId  (selfSerializeDB.propid());
        setPropVal (selfSerializeDB.propval());
        setLocked  (selfSerializeDB.locked());

        return (true);
    }
};

#endif  //_GEN_TALENTPROP_H
