
#ifndef __CCCREATURE_H
#define __CCCREATURE_H

#include "ccBuffer.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "pbCreate.pb.h"
#include "pbCreature.pb.h"
#include "pbSpell.pb.h"
#include "pbBuffer.pb.h"

#define DATA_PERMISSION public

using namespace std;

class ccCreature : public ccCreate
{
public:
    typedef vector<ccBuffer> BUFFERLIST;

public:
    std::string SerializeToClient (void)
    {
        pbCreateClient tmp_obj_create_client_;

        tmp_obj_create_client_.set_hp (Hp);
        tmp_obj_create_client_.set_mp (Mp);

        PROPLIST::iterator itp;
        for (itp=Props.begin(); itp!=Props.end(); itp++) {
            tmp_obj_create_client_.add_props (*itp);
        }

        SPELLLIST::iterator its;
        pbSpellClient* tmp_obj_spell_client_;
        for (its=Spells.begin(); its!=Spells.end(); its++) {
            tmp_obj_spell_client_ = tmp_obj_create_client_.add_spells ();
            tmp_obj_spell_client_->set_id (its->Id);
            tmp_obj_spell_client_->set_name (its->Name);
            tmp_obj_spell_client_->set_casttime (its->CastTime);
            tmp_obj_spell_client_->set_cdtime (its->CDTime);
            tmp_obj_spell_client_->set_costmp (its->CostMp);
            tmp_obj_spell_client_->set_usetime (its->UseTime);
        }

        std::string obj_str;
        if (tmp_obj_create_client_.SerializeToString (&obj_str))
            return (obj_str);
        else
            return ("");
    }

    bool ParseFromClient   (string& str) {
        pbCreateClient tmp_obj_create_client_;
        if (tmp_obj_create_client_.ParseFromString (str)) {

            Hp = tmp_obj_create_client_.hp ();
            Mp = tmp_obj_create_client_.mp ();

            int size;
            size = tmp_obj_create_client_.props_size ();
            for (int i=0; i<size; i++) {
                Props.push_back (tmp_obj_create_client_.props (i));
            }
            size = tmp_obj_create_client_.spells_size ();
            for (int i=0; i<size; i++) {
                ccSpell tmp_obj_spell_;
                tmp_obj_spell_.Id       = tmp_obj_create_client_.spells (i).id ();
                tmp_obj_spell_.Name     = tmp_obj_create_client_.spells (i).name ();
                tmp_obj_spell_.CastTime = tmp_obj_create_client_.spells (i).casttime ();
                tmp_obj_spell_.CDTime   = tmp_obj_create_client_.spells (i).cdtime ();
                tmp_obj_spell_.CostMp   = tmp_obj_create_client_.spells (i).costmp ();
                tmp_obj_spell_.UseTime  = tmp_obj_create_client_.spells (i).usetime ();

                Spells.push_back (tmp_obj_spell_);
            }

            return (true);
        }

        return (false);
    }

    std::string SerializeToDB (void)
    {
        pbCreateDB tmp_obj_create_db_;

        tmp_obj_create_db_.set_hp (Hp);
        tmp_obj_create_db_.set_level (Level);

        PROPLIST::iterator itp;
        for (itp=Props.begin(); itp!=Props.end(); itp++) {
            tmp_obj_create_db_.add_props (*itp);
        }

        std::string obj_str;
        if (tmp_obj_create_db_.SerializeToString (&obj_str))
            return (obj_str);
        else
            return ("");
    }
    bool ParseFromDB   (std::string str)
    {
        pbCreateDB tmp_obj_create_db_;
        if (tmp_obj_create_db_.ParseFromString (str)) {

            Hp    = tmp_obj_create_db_.hp ();
            Level = tmp_obj_create_db_.level ();

            int size;
            size = tmp_obj_create_db_.props_size ();
            for (int i=0; i<size; i++) {
                Props.push_back (tmp_obj_create_db_.props (i));
            }

            return (true);
        }
        return (false);
    }
DATA_PERMISSION:
    int PosX;
    int PosY;
    BUFFERLIST Buffs;
};

#endif  //__CCCREATURE_H
