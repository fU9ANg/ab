
#include "PlayerBase.h"

PlayerBase::PlayerBase ()
{
    selfSerializeDB.Clear ();
    selfSerializeNet.Clear ();

    m_Name.clear ();
    m_RoleId = 0;
    m_SpellList.clear ();
    m_TalentNodes.clear ();
}

// Name
const std::string& PlayerBase::getName () const
{
        return (m_Name);
}
bool PlayerBase::setName (const std::string& value)
{
        m_Name = value;
        return (true);
}

// RoleId
int PlayerBase::getRoleId() const
{
        return (m_RoleId);
}
bool PlayerBase::setRoleId (const int& value)
{
        m_RoleId = value;
        return (true);
}
// Pos
const PosBase& PlayerBase::getPos() const
{
        return (m_Pos);
}
PosBase& PlayerBase::getPos()
{
        return (m_Pos);
}
bool PlayerBase::setPos(const PosBase& value)
{
        m_Pos = value;
        return (true);
}
// SpellList
const std::vector<int>& PlayerBase::getSpellList(void) const
{
        return (m_SpellList);
}
std::vector<int>& PlayerBase::getSpellList()
{
        return (m_SpellList);
}
int PlayerBase::getSpellList(int site) const
{
        return (m_SpellList[site]);
}
bool PlayerBase::setSpellList(const std::vector<int>& value)
{
        m_SpellList = value;
        return (true);
}
// TalentNodes
const std::vector<TalentNodeBase>& PlayerBase::getTalentNodes() const
{
        return (m_TalentNodes);
}
std::vector<TalentNodeBase>& PlayerBase::getTalentNodes()
{
        return (m_TalentNodes);
}
TalentNodeBase& PlayerBase::getTalentNodes(int site)
{
        return (m_TalentNodes[site]);
}
const TalentNodeBase& PlayerBase::getTalentNodes(int site) const
{
        return (m_TalentNodes[site]);
}
bool PlayerBase::setTalentNodes(std::vector<TalentNodeBase>& value)
{
        m_TalentNodes = value;
        return (true);
}

void PlayerBase::dumpObject (void)
{
        std::cout << "名称: " << m_Name << std::endl;
        std::cout << "场景Id: " << m_RoleId << std::endl;
        m_Pos.dumpObject();

        std::cout << "技能列表: " << std::endl;
        std::vector<int>::iterator it;
        for (it = m_SpellList.begin(); it != m_SpellList.end(); ++it) {
                std::cout << "\t" << (*it) << std::endl;
        }
        std::vector<TalentNodeBase>::iterator ite;
        for (ite = m_TalentNodes.begin(); ite != m_TalentNodes.end(); ++ite) {
                (*ite).dumpObject();
        }
}

bool PlayerBase::SerializeObjectToStringForDB (std::string& mainstr)
{
        std::string substr;
        size_t nlistsize;
        bool rlt = false;

        // 1. for base type
        selfSerializeDB.set_name (getName());
        selfSerializeDB.set_roleid (getRoleId());

        // 2. for base list type
        std::vector<int>::iterator it;
        for (it = m_SpellList.begin(); it != m_SpellList.end(); ++it) {
                selfSerializeDB.add_spelllist ((*it));
        }

        ///// first serialize base type
        rlt = selfSerializeDB.SerializeToString (&substr);

        rlt = AppendObjectToString (mainstr, substr);

        // 3. for user define type
        m_Pos.SerializeObjectToStringForDB (mainstr);

        // 4. for user define list type
        nlistsize = m_TalentNodes.size ();
        AppendSizeToString (mainstr, nlistsize);
        for (size_t i=0; i<nlistsize; i++) {
                m_TalentNodes[i].SerializeObjectToStringForDB (mainstr);
        }

        return (rlt);
}

bool PlayerBase::ParseObjectFromStringForDB (std::string& mainstr)
{
        std::string substr;
        unsigned short nsize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString (mainstr, substr, nsize);
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
        ExtractSizeFromString (mainstr, nsize);
        for (size_t i=0; i<nsize; ++i) {
                TalentNodeBase tmpobj;
                tmpobj.ParseObjectFromStringForDB (mainstr);
                m_TalentNodes.push_back (tmpobj);
        }
        return (true);
}

bool PlayerBase::SerializeObjectToStringForNet (std::string& mainstr)
{
        std::string substr;
        size_t nlistsize;
        bool rlt = false;

        // 1. for base type
        selfSerializeNet.set_name (getName());
        selfSerializeNet.set_roleid (getRoleId());

        // 2. for base list type
        std::vector<int>::iterator it;
        for (it = m_SpellList.begin(); it != m_SpellList.end(); ++it) {
                selfSerializeNet.add_spelllist ((*it));
        }

        ///// first serialize base type
        rlt = selfSerializeNet.SerializeToString (&substr);

        rlt = AppendObjectToString (mainstr, substr);

        // 3. for user define type
        m_Pos.SerializeObjectToStringForNet (mainstr);

        // 4. for user define list type
        nlistsize = m_TalentNodes.size ();
        AppendSizeToString (mainstr, nlistsize);
        for (size_t i=0; i<nlistsize; i++) {
                m_TalentNodes[i].SerializeObjectToStringForNet (mainstr);
        }

        return (rlt);
}

bool PlayerBase::ParseObjectFromStringForNet (std::string& mainstr)
{
        std::string substr;
        unsigned short nsize;

        if (mainstr.empty())
                return (false);

        ExtractObjectFromString (mainstr, substr, nsize);
        selfSerializeNet.ParseFromString (substr);

        // 1. for base type
        setName (selfSerializeNet.name());
        setRoleId (selfSerializeNet.roleid());

        // 2. for base list type
        m_SpellList.clear();
        for (int i=0; i<selfSerializeNet.spelllist().size(); i++) {
                m_SpellList.push_back (selfSerializeNet.spelllist(i));
        }
        // 3. for user define type
        m_Pos.ParseObjectFromStringForNet (mainstr);

        // 4. for user define list type
        m_TalentNodes.clear();
        ExtractSizeFromString (mainstr, nsize);
        for (size_t i=0; i<nsize; ++i) {
                TalentNodeBase tmpobj;
                tmpobj.ParseObjectFromStringForNet (mainstr);
                m_TalentNodes.push_back (tmpobj);
        }
        return (true);
}
