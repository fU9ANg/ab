
#ifndef _GEN_TALENTNODE_H
#define _GEN_TALENTNODE_H

#include <iostream>
#include <string>
#include <vector>

#include "common.h"
#include "ChenyuanTypes.pb.h"
#include "TalentPropBase.h"

using namespace std;

class TalentNodeBase
{
public:
    TalentNodeBase();
    // TalentProps
    const std::vector<TalentPropBase>& getTalentProps() const;
    std::vector<TalentPropBase>& getTalentProps();
    TalentPropBase& getTalentProps(int site);
    const TalentPropBase& getTalentProps(int site) const;
    bool setTalentProps(std::vector<TalentPropBase>& value);

private:
    ChenyuanTypes::TalentNodeSerializeDB selfSerializeDB;
    ChenyuanTypes::TalentNodeSerializeClient selfSerializeClient;
    std::vector<TalentPropBase>   m_TalentProps;

public:
    void dumpObject (void);

    std::string SerializeObjectToStringForDB (std::string& mainstr);
    bool ParseObjectFromStringForDB (std::string& mainstr);
    std::string SerializeObjectToStringForClient (std::string& mainstr);
    bool ParseObjectFromStringForClient (std::string& mainstr);
};

#endif  //_GEN_TALENTNODE_H
