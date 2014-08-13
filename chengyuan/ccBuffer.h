
#ifndef __CCBUFFER_H
#define __CCBUFFER_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "pbBuffer.pb.h"

#define DATA_PERMISSION public

using namespace std;

class ccBuffer
{
public:
    typedef std::vector<int> TIMESLIST;

public:
    pbBufferClient SerializeToClient (void) {
        pbBufferClient tmp_obj_buffer_client_;
        tmp_obj_buffer_client_.set_id (Id);
        tmp_obj_buffer_client_.set_starttime (StartTime);

        TIMESLIST::iterator it;
        for (it=Times.begin(); it!=Times.end(); it++) {
            tmp_obj_buffer_client_.add_times (*it);
        }

        return (tmp_obj_buffer_client_);
    }
    bool ParseFromClient   (std::string& str) {
        pbBufferClient tmp_obj_buffer_client_;
        if (tmp_obj_buffer_client_.ParseFromString (str)) {

            Id        = tmp_obj_buffer_client_.id ();
            StartTime = tmp_obj_buffer_client_.starttime ();

            int size;
            size = tmp_obj_buffer_client_.times_size ();
            for (int i=0; i<size; i++) {
                Times.push_back (tmp_obj_buffer_client_.times (i));
            }

            return (true);
        }

        return (false);
    }

    bool ParseFromObject (pbBufferClient& tmp_obj_buffer_client_) {
            Id        = tmp_obj_buffer_client_.id ();
            StartTime = tmp_obj_buffer_client_.starttime ();

            int size;
            size = tmp_obj_buffer_client_.times_size ();
            for (int i=0; i<size; i++) {
                Times.push_back (tmp_obj_buffer_client_.times (i));
            }

            return (true);

        return (false);
    }
    std::string SerializeToDB (void) {
        pbBufferDB tmp_obj_buffer_db_;
        tmp_obj_buffer_db_.set_id (Id);
        tmp_obj_buffer_db_.set_expiretime (ExpireTime);

        TIMESLIST::iterator it;
        for (it=Times.begin(); it!=Times.end(); it++) {
            tmp_obj_buffer_db_.add_times (*it);
        }

        std::string str;
        if (tmp_obj_buffer_db_.SerializeToString (&str))
            return (str);
        else
            return ("");
    }
    bool ParseFromDB   (std::string& str) {
        pbBufferDB tmp_obj_buffer_db_;
        if (tmp_obj_buffer_db_.ParseFromString (str)) {

            Id        = tmp_obj_buffer_db_.id ();
            ExpireTime= tmp_obj_buffer_db_.expiretime ();

            int size;
            size = tmp_obj_buffer_db_.times_size ();
            for (int i=0; i<size; i++) {
                Times.push_back (tmp_obj_buffer_db_.times (i));
            }

            return (true);
        }

        return (false);
    }

DATA_PERMISSION:
    int  Id;
    long StartTime;
    long ExpireTime;
    TIMESLIST Times;
};

#endif  //__CCBUFFER_H
