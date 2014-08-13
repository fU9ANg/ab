
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
    std::string Serialize (enum SerializeFlag) {
        std::string SerializeStr;
        bool flag;

        if (SerializeFlag = SF_CLIENT) {
            pbCreatureClient tmp_obj_creature_client_;
            tmp_obj_creature_client_ = SerializeToClient ();

            flag = tmp_obj_creature_client_.SerializeToString (&SerializeStr);
        }
        else if (SerializeFlag = SF_DB) {
            pbCreatureDB tmp_obj_creature_db_;
            tmp_obj_creature_db_ = SerializeToDB ();

            flag = tmp_obj_creature_db_.SerializeToString (&SerializeStr);
        }

        if (flag)
            return (SerializeStr);
        else
            return ("");

    }
protected:
    pbCreatureClient SerializeToClient (void)
    {
        pbCreatureClient tmp_obj_creature_client_;
        tmp_obj_creature_client_.set_posx (PosX);

        pbCreateClient* tmp_obj_base_p_ = new pbCreateClient;
        *tmp_obj_base_p_= ccCreate::SerializeToClient ();
        tmp_obj_creature_client_.set_allocated_base (tmp_obj_base_p_);

        pbBufferClient* tmp_obj_buffer_client_p_;
        BUFFERLIST::iterator it;
        for (it = Buffs.begin(); it != Buffs.end(); it++) {
            tmp_obj_buffer_client_p_ = tmp_obj_creature_client_.add_buffs ();
            *tmp_obj_buffer_client_p_= it->SerializeToClient ();
        }

        return (tmp_obj_creature_client_);
    }

    bool ParseFromClient   (string& str) {
        pbCreatureClient tmp_obj_creature_client_;
        if (tmp_obj_creature_client_.ParseFromString (str)) {

            PosX = tmp_obj_creature_client_.posx ();

            int size = tmp_obj_creature_client_.buffs_size ();
            for (int i=0; i<size; i++) {
                ccBuffer tmp_obj_buffer_;
                pbBufferClient tmp_obj_buffer_client_ = tmp_obj_creature_client_.buffs(i);
                tmp_obj_buffer_.ParseFromObject (tmp_obj_buffer_client_);

                Buffs.push_back (tmp_obj_buffer_);
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
