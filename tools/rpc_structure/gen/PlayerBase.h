
#ifndef _GEN_PLAYERBASE_H
#define _GEN_PLAYERBASE_H

#include <iostream>
#include <string>
#include <vector>

#include "common.h"
#include "PosBase.h"
#include "TalentNodeBase.h"

using namespace std;

class PlayerBase
{
public:
    PlayerBase ();

    // Name
    const std::string& getName() const;
    bool setName (const std::string& value);
    // RoleId
    int getRoleId() const;
    bool setRoleId (const int& value);
    // Pos
    const PosBase& getPos() const;
    PosBase& getPos();
    bool setPos(const PosBase& value);
    // SpellList
    const std::vector<int>& getSpellList(void) const;
    std::vector<int>& getSpellList();
    int getSpellList(int site) const;
    bool setSpellList(const std::vector<int>& value);
    // TalentNodes
    const std::vector<TalentNodeBase>& getTalentNodes() const;
    std::vector<TalentNodeBase>& getTalentNodes();
    TalentNodeBase& getTalentNodes(int site);
    const TalentNodeBase& getTalentNodes(int site) const;
    bool setTalentNodes(std::vector<TalentNodeBase>& value);

private:
    ChenyuanTypes::PlayerSerializeDB selfSerializeDB;
    ChenyuanTypes::PlayerSerializeNet selfSerializeNet;

    std::string m_Name; //名称
    int m_RoleId; //场景Id
    class PosBase m_Pos;
    std::vector<int> m_SpellList; //技能列表
    std::vector<TalentNodeBase> m_TalentNodes; //批量洗天赋属性列表

public:
    void dumpObject (void);
    bool SerializeObjectToStringForDB (std::string& mainstr);
    bool ParseObjectFromStringForDB (std::string& mainstr);
    bool SerializeObjectToStringForNet (std::string& mainstr);
    bool ParseObjectFromStringForNet (std::string& mainstr);
};

#endif // _GEN_PLAYERBASE_H
