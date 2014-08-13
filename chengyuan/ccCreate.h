
#ifndef __CCCREATE_H
#define __CCCREATE_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#include "ccSpell.h"

using namespace std;

class ccCreate
{
public:
    typedef vector<int> PROPLIST;
    typedef vector<ccSpell> SPELLLIST;

public:
    void SerializeToClient (void);
    void SerializeFromDB   (void);

private:
    int Level;
    int Hp;
    int Mp;
    PROPLIST  Props;
    SPELLLIST Spells;
};

#endif  //__CCCREATE_H
