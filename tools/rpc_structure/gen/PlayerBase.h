
#ifndef _GEN_PLAYERBASE_H
#define _GEN_PLAYERBASE_H

#include <iostream>
#include <string>
#include <vector>

#include "common.h"
#include "PosBase.h"
#include "TalentNodeBase.h"

using namespace std;

typedef std::vector<int> INT_VECTOR;
typedef std::vector<TalentNodeBase> TALENTNODE_VECTOR;

class PlayerBase
{
public:
    PlayerBase ()
    {
        m_RoleId    = 0;
    }

    // Name
    const std::string& getName() const {
        return (m_Name);
    }
    bool setName (const std::string& value) {
        m_Name = value;
        return (true);
    }
    // RoleId
    int getRoleId() const {
        return (m_RoleId);
    }
    bool setRoleId (const int& value) {
        m_RoleId = value;
        return (true);
    }
    // Pos
    const PosBase& getPos() const {
        return (m_Pos);
    }
    PosBase& getPos() {
        return (m_Pos);
    }
    bool setPos(const PosBase& value) {
        m_Pos = value;
        return (true);
    }
    // SpellList
    const INT_VECTOR& getSpellList(void) const {
        return (m_SpellList);
    }
    INT_VECTOR& getSpellList() {
        return (m_SpellList);
    }
    int getSpellList(int site) const {
        return (m_SpellList[site]);
    }
    bool setSpellList(const INT_VECTOR& value) {
        m_SpellList = value;
        return (true);
    }
    // TalentNodes
    const TALENTNODE_VECTOR& getTalentNodes() const {
        return (m_TalentNodes);
    }
    TALENTNODE_VECTOR& getTalentNodes() {
        return (m_TalentNodes);
    }
    TalentNodeBase& getTalentNodes(int site) {
        return (m_TalentNodes[site]);
    }
    const TalentNodeBase& getTalentNodes(int site) const {
        return (m_TalentNodes[site]);
    }
    bool setTalentNodes(TALENTNODE_VECTOR& value) {
        m_TalentNodes = value;
        return (true);
    }

private:
    ChenyuanTypes::PlayerSerializeDB   selfSerializeDB;

    std::string             m_Name; //名称
    int                     m_RoleId; //场景Id
    class PosBase           m_Pos;
    INT_VECTOR              m_SpellList; //技能列表
    TALENTNODE_VECTOR       m_TalentNodes; //批量洗天赋属性列表

public:
    void dumpObject (void)
    {
        std::cout << "名称: " << m_Name << std::endl;
        std::cout << "场景Id: " << m_RoleId << std::endl;
        m_Pos.dumpObject();

        std::cout << "技能列表: " << std::endl;
        INT_VECTOR::iterator it;
        for (it = m_SpellList.begin(); it != m_SpellList.end(); ++it) {
            std::cout << "\t" << (*it) << std::endl;
        }
        TALENTNODE_VECTOR::iterator ite;
        for (ite = m_TalentNodes.begin(); ite != m_TalentNodes.end(); ++ite) {
            (*ite).dumpObject();
        }
    }

    bool SerializeObjectToStringForDB (std::string& mainstr)
    {
        std::string substr;
        size_t nlistsize;
        bool rlt = false;

        // 1. for base type
        selfSerializeDB.set_name (getName());
        selfSerializeDB.set_roleid (getRoleId());

        // 2. for base list type
        INT_VECTOR::iterator it;
        for (it = m_SpellList.begin(); it != m_SpellList.end(); ++it) {
            selfSerializeDB.add_spelllist ((*it));
        }

        ///// first serialize base type
        rlt = selfSerializeDB.SerializeToString (&substr);

        rlt = PushSerializeString (mainstr, substr);

        // 3. for user define type
        m_Pos.SerializeObjectToStringForDB (mainstr);

        // 4. for user define list type
        nlistsize = m_TalentNodes.size ();
        PushSizeToString (mainstr, nlistsize);
        for (size_t i=0; i<nlistsize; i++) {
            m_TalentNodes[i].SerializeObjectToStringForDB (mainstr);
        }

        return (mainstr);
    }

    bool ParseObjectFromStringForDB (std::string& mainstr)
    {
        std::string substr;
        unsigned short nsize;

        if (mainstr.empty())
            return (false);

        PopSerializeString (mainstr, substr, nsize);
        selfSerializeDB.ParseFromString (substr);

        // 1. for base type
        setName (selfSerializeDB.name());
        setRoleId (selfSerializeDB.roleid());

        // 2. for base list type
        m_SpellList.clear();
        for (int i=0; i<selfSerializeDB.spelllist().size(); i++) {
            m_SpellList.push_back (selfSerializeDB.spelllist(i));
        }
        // 3. for user define type
        m_Pos.ParseObjectFromStringForDB (mainstr);

        // 4. for user define list type
        m_TalentNodes.clear();
        PopSizeFromString (mainstr, nsize);
        for (size_t i=0; i<nsize; ++i) {
            TalentNodeBase tmpobj;
            tmpobj.ParseObjectFromStringForDB (mainstr);
            m_TalentNodes.push_back (tmpobj);
        }
        return (true);
    }
};

#endif // _GEN_PLAYERBASE_H
