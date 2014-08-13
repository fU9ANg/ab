
#ifndef __CCCREATURE_H
#define __CCCREATURE_H

#include "ccBuffer.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class ccCreature : public ccCreate
{
public:
    typedef vector<ccBuffer> BUFFERLIST;

public:
    void SerializeToClient (void);
    void SerializeFromDB   (void);

private:
    int PosX;
    int PosY;
    BUFFERLIST Buffs;
};

#endif  //__CCCREATURE_H
