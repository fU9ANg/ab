
#ifndef _GEN_TALENTNODE_H
#define _GEN_TALENTNODE_H

#include <iostream>
#include <string>
#include <vector>

#include "common.h"
#include "ChenyuanTypes.pb.h"
#include "TalentPropBase.h"

using namespace std;

typedef std::vector<TalentPropBase> TALENTPROP_VECTOR;

class TalentNodeBase
{
public:
    // TalentProps
    const TALENTPROP_VECTOR& getTalentProps() const {
        return (m_TalentProps);
    }
    TALENTPROP_VECTOR& getTalentProps() {
        return (m_TalentProps);
    }
    TalentPropBase& getTalentProps(int site) {
        return (m_TalentProps[site]);
    }
    const TalentPropBase& getTalentProps(int site) const {
        return (m_TalentProps[site]);
    }
    bool setTalentProps(TALENTPROP_VECTOR& value) {
        m_TalentProps = value;
        return (true);
    }

private:
    ChenyuanTypes::TalentNodeSerializeDB selfSerializeDB;
    TALENTPROP_VECTOR   m_TalentProps;

public:
    void dumpObject (void)
    {
        std::cout << "------ TalentNode ------" << std::endl;
        TALENTPROP_VECTOR::iterator it;
        for (it = m_TalentProps.begin(); it != m_TalentProps.end(); ++it) {
            (*it).dumpObject();
        }
    }

    std::string SerializeObjectToStringForDB (std::string& mainstr)
    {
        std::string substr;
        size_t nlistsize;

        // 4. for user define list type
        nlistsize = m_TalentProps.size ();
        PushSizeToString (mainstr, nlistsize);
        for (size_t i=0; i<nlistsize; i++) {
            m_TalentProps[i].SerializeObjectToStringForDB(mainstr);
        }

        return (mainstr);
    }

    bool ParseObjectFromStringForDB (std::string& mainstr)
    {
        std::string substr;
        unsigned short nsize;

        if (mainstr.empty())
            return (false);

        // 4. for user define list type
        m_TalentProps.clear();
        PopSizeFromString (mainstr, nsize);
        for (size_t i=0; i<nsize; ++i) {
            TalentPropBase tmpobj;
            tmpobj.ParseObjectFromStringForDB (mainstr);
            m_TalentProps.push_back (tmpobj);
        }

        return (true);
    }
};

#endif  //_GEN_TALENTNODE_H
