
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include "ChenyuanTypes.pb.h"
#include "common.h"

#include "Player.h"
#include "Pos.h"
#include "TalentNode.h"
#include "TalentProp.h"

using namespace std;

#define SPELL_NUMBER        5
#define TALENTNODE_NUMBER   2
#define TALENTPROP_NUMBER   1

int main ()
{
    std::string             sName = "玩家1";
    int                     iRoleId = 109;
    Pos                     oPos;
    int                     iX = 110;
    int                     iY = 120;
    std::vector<int>        vSpellList;
    std::vector<TalentNodeBase> vTalentNodes;
    std::vector<TalentPropBase> vTalentProps;
    std::string             mainstr;

    Player p;

    oPos.setX(iX);
    oPos.setY(iY);

    for (int i=1; i<=SPELL_NUMBER; i++) {
        vSpellList.push_back (i);
    }

    vTalentNodes.clear();
    for (int i=1; i<=TALENTNODE_NUMBER; i++) {
        TalentNode objNode;

        // begin
        vTalentProps.clear();
        for (int j=1; j<=TALENTPROP_NUMBER; j++) {

            TalentProp objProp;
            objProp.setPropId (j+1);
            objProp.setPropVal(j+2);
            objProp.setLocked (j+3);
            vTalentProps.push_back(objProp);
        }
        objNode.setTalentProps(vTalentProps);
        // end

        vTalentNodes.push_back (objNode);
    }

    p.setName(sName);
    p.setRoleId(iRoleId);
    p.setPos(oPos);
    p.setSpellList(vSpellList);
    p.setTalentNodes(vTalentNodes);

    ////////////////////////// dump object ///////////////////////////
    //
    p.SerializeObjectToStringForDB(mainstr);
    p.dumpObject();

    std::cout << "---------------- mainstr.size() = " << mainstr.size() << " ----------------" << std::endl;
#if 1
    // Parse to other_object from string
    Player p1;
    p1.ParseObjectFromStringForDB (mainstr);
    p1.dumpObject();
#endif

    return (0);
}
