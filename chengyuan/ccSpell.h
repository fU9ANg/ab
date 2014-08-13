
#ifndef __CCCSPELL_H
#define __CCCSPELL_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "pbSpell.pb.h"

#define DATA_PERMISSION public

using namespace std;

class ccSpell
{
public:
    std::string SerializeToClient (void)
    {
        pbSpellClient tmp_obj_spell_client_;

        tmp_obj_spell_client_.set_id (Id);
        tmp_obj_spell_client_.set_name (Name);
        tmp_obj_spell_client_.set_casttime (CastTime);
        tmp_obj_spell_client_.set_cdtime (CDTime);
        tmp_obj_spell_client_.set_costmp (CostMp);
        tmp_obj_spell_client_.set_usetime (UseTime);

        std::string obj_str;
        if (tmp_obj_spell_client_.SerializeToString (&obj_str))
            return (obj_str);
        else
            return ("");
    }
    bool ParseFromClient   (string& str) {
        pbSpellClient tmp_obj_spell_client_;
        if (tmp_obj_spell_client_.ParseFromString (str)) {

            Id       = tmp_obj_spell_client_.id ();
            Name     = tmp_obj_spell_client_.name ();
            CastTime = tmp_obj_spell_client_.casttime ();
            CDTime   = tmp_obj_spell_client_.cdtime ();
            CostMp   = tmp_obj_spell_client_.costmp ();
            UseTime  = tmp_obj_spell_client_.usetime ();

            return (true);
        }

        return (false);
    }
    std::string SerializeToDB (void)
    {
        pbSpellDB tmp_obj_spell_db_;

        tmp_obj_spell_db_.set_id (Id);
        tmp_obj_spell_db_.set_name (Name);
        tmp_obj_spell_db_.set_casttime (CastTime);
        tmp_obj_spell_db_.set_cdtime (CDTime);
        tmp_obj_spell_db_.set_costmp (CostMp);
        tmp_obj_spell_db_.set_lastcasttime (LastCastTime);

        std::string obj_str;
        if (tmp_obj_spell_db_.SerializeToString (&obj_str))
            return (obj_str);
        else
            return ("");
    }
    bool ParseFromDB   (std::string str)
    {
        pbSpellDB tmp_obj_spell_db_;
        if (tmp_obj_spell_db_.ParseFromString (str)) {

            Id           = tmp_obj_spell_db_.id ();
            Name         = tmp_obj_spell_db_.name ();
            CastTime     = tmp_obj_spell_db_.casttime ();
            CDTime       = tmp_obj_spell_db_.cdtime ();
            CostMp       = tmp_obj_spell_db_.costmp ();
            LastCastTime = tmp_obj_spell_db_.lastcasttime ();

            return (true);
        }

        return (false);
    }

DATA_PERMISSION:
    int Id;
    string Name;
    int CastTime;
    int CDTime;
    int CostMp;
    int UseTime;
    long LastCastTime;
};

#endif  //__CCSPELL_H
