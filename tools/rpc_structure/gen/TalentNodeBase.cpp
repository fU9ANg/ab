
#include "TalentNodeBase.h"

TalentNodeBase::TalentNodeBase ()
{
        selfSerializeDB.Clear();
        selfSerializeNet.Clear();
        m_TalentProps.clear();
}

const std::vector<TalentPropBase>& TalentNodeBase::getTalentProps() const
{
        return (m_TalentProps);
}
std::vector<TalentPropBase>& TalentNodeBase::getTalentProps()
{
        return (m_TalentProps);
}
TalentPropBase& TalentNodeBase::getTalentProps(int site)
{
        return (m_TalentProps[site]);
}
const TalentPropBase& TalentNodeBase::getTalentProps(int site) const
{
        return (m_TalentProps[site]);
}
bool TalentNodeBase::setTalentProps(std::vector<TalentPropBase>& value)
{
        m_TalentProps = value;
        return (true);
}

void TalentNodeBase::dumpObject (void)
{
        std::cout << "------ TalentNode ------" << std::endl;
        std::vector<TalentPropBase>::iterator it;
        for (it = m_TalentProps.begin(); it != m_TalentProps.end(); ++it) {
                (*it).dumpObject();
        }
}

std::string TalentNodeBase::SerializeObjectToStringForDB (std::string& mainstr)
{
        std::string substr;
        size_t nlistsize;

        // 4. for user define list type
        nlistsize = m_TalentProps.size ();
        AppendSizeToString (mainstr, nlistsize);
        for (size_t i=0; i<nlistsize; i++) {
                m_TalentProps[i].SerializeObjectToStringForDB(mainstr);
        }

        return (mainstr);
}

bool TalentNodeBase::ParseObjectFromStringForDB (std::string& mainstr)
{
        std::string substr;
        unsigned short nsize;

        if (mainstr.empty())
                return (false);

        // 4. for user define list type
        m_TalentProps.clear();
        ExtractSizeFromString (mainstr, nsize);
        for (size_t i=0; i<nsize; ++i) {
                TalentPropBase tmpobj;
                tmpobj.ParseObjectFromStringForDB (mainstr);
                m_TalentProps.push_back (tmpobj);
        }

        return (true);
}

std::string TalentNodeBase::SerializeObjectToStringForNet (std::string& mainstr)
{
        std::string substr;
        size_t nlistsize;

        // 4. for user define list type
        nlistsize = m_TalentProps.size ();
        AppendSizeToString (mainstr, nlistsize);
        for (size_t i=0; i<nlistsize; i++) {
                m_TalentProps[i].SerializeObjectToStringForNet(mainstr);
        }

        return (mainstr);
}

bool TalentNodeBase::ParseObjectFromStringForNet (std::string& mainstr)
{
        std::string substr;
        unsigned short nsize;

        if (mainstr.empty())
                return (false);

        // 4. for user define list type
        m_TalentProps.clear();
        ExtractSizeFromString (mainstr, nsize);
        for (size_t i=0; i<nsize; ++i) {
                TalentPropBase tmpobj;
                tmpobj.ParseObjectFromStringForNet (mainstr);
                m_TalentProps.push_back (tmpobj);
        }

        return (true);
}
