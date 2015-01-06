
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
    TalentPropBase ();
    int getPropId (void);
    int getPropVal (void);
    int getLocked (void);
    // sets
    void setPropId (int id);
    void setPropVal (int val);
    void setLocked (int lock);

private:
    ChenyuanTypes::TalentPropSerializeDB selfSerializeDB;
    ChenyuanTypes::TalentPropSerializeNet selfSerializeNet;
    int     m_PropId;
    int     m_PropVal;
    int     m_Locked;

public:
    void dumpObject (void);

    std::string SerializeObjectToStringForDB (std::string& mainstr);
    bool ParseObjectFromStringForDB (std::string& mainstr);
    std::string SerializeObjectToStringForNet (std::string& mainstr);
    bool ParseObjectFromStringForNet (std::string& mainstr);
};

#endif //_GEN_TALENTPROP_H
