
#ifndef __CCBUFFER_H
#define __CCBUFFER_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class ccBuffer
{
public:
    typedef std::vector<int> TIMESLIST;
private:
    int Id;
    long StartTime;
    long ExpireTime;
    TIMESLIST Times;
};

#endif  //__CCBUFFER_H
