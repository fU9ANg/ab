
//
// This file is automatically generated by Tools.
// Do not modify this file -- YOUR CHANGES WILL BE ERASED!
//

#ifndef __SHEET_H__
#define __SHEET_H__

#include "SheetBase.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//////////////////////////////////////////////
class SheetTestData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//编号
	string Name;	//名称
	SheetTestData ();
};

class SheetTest : public SheetBase
{
private:
	SheetTestData *data;
public:
	vector<SheetTestData*> getAll ();
	SheetTestData* getRow (int n);
	bool forEach (SheetTestData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetTest* shTest;

//////////////////////////////////////////////
class SheetTest2Data : public SheetBaseData
{
public:
	int ID2;	//ID
	int Type2;	//编号
	string Name2;	//名称
	SheetTest2Data ();
};

struct _SheetIndexTypeTest2ID2Name2 {
	int ID2;
	string Name2;
	_SheetIndexTypeTest2ID2Name2();
	_SheetIndexTypeTest2ID2Name2(int _ID2,string _Name2) {
		ID2 = _ID2;
		Name2 = _Name2;
	}
	bool operator<(const _SheetIndexTypeTest2ID2Name2& s) const {
		if (this->ID2<s.ID2) return (true);
		if (this->ID2>s.ID2) return (false);
		if (this->Name2<s.Name2) return (true);
		if (this->Name2>s.Name2) return (false);
		return (false);
	}
};
struct _SheetIndexTypeTest2ID2Type2 {
	int ID2;
	int Type2;
	_SheetIndexTypeTest2ID2Type2();
	_SheetIndexTypeTest2ID2Type2(int _ID2,int _Type2) {
		ID2 = _ID2;
		Type2 = _Type2;
	}
	bool operator<(const _SheetIndexTypeTest2ID2Type2& s) const {
		if (this->ID2<s.ID2) return (true);
		if (this->ID2>s.ID2) return (false);
		if (this->Type2<s.Type2) return (true);
		if (this->Type2>s.Type2) return (false);
		return (false);
	}
};
class SheetTest2 : public SheetBase
{
private:
	SheetTest2Data *data;
	std::map<_SheetIndexTypeTest2ID2Type2, int> index_ID2_Type2;
	std::map<_SheetIndexTypeTest2ID2Name2, int> index_ID2_Name2;
public:
	vector<SheetTest2Data*> getAll ();
	SheetTest2Data* getRow (int n);
	SheetTest2Data* findByID2Name2 (int _ID2,string _Name2);
	SheetTest2Data* tryFindByID2Name2 (int _ID2,string _Name2);
	SheetTest2Data* findByID2Type2 (int _ID2,int _Type2);
	SheetTest2Data* tryFindByID2Type2 (int _ID2,int _Type2);
	bool forEach (SheetTest2Data& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetTest2* shTest2;

//////////////////////////////////////////////
class SheetPlayerData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int Quality;	//品质
	int Level;	//等级
	SheetPlayerData ();
};

struct _SheetIndexTypePlayerNameLevel {
	string Name;
	int Level;
	_SheetIndexTypePlayerNameLevel();
	_SheetIndexTypePlayerNameLevel(string _Name,int _Level) {
		Name = _Name;
		Level = _Level;
	}
	bool operator<(const _SheetIndexTypePlayerNameLevel& s) const {
		if (this->Name<s.Name) return (true);
		if (this->Name>s.Name) return (false);
		if (this->Level<s.Level) return (true);
		if (this->Level>s.Level) return (false);
		return (false);
	}
};
struct _SheetIndexTypePlayerIDName {
	int ID;
	string Name;
	_SheetIndexTypePlayerIDName();
	_SheetIndexTypePlayerIDName(int _ID,string _Name) {
		ID = _ID;
		Name = _Name;
	}
	bool operator<(const _SheetIndexTypePlayerIDName& s) const {
		if (this->ID<s.ID) return (true);
		if (this->ID>s.ID) return (false);
		if (this->Name<s.Name) return (true);
		if (this->Name>s.Name) return (false);
		return (false);
	}
};
class SheetPlayer : public SheetBase
{
private:
	SheetPlayerData *data;
	std::map<_SheetIndexTypePlayerIDName, int> index_ID_Name;
	std::multimap<_SheetIndexTypePlayerNameLevel, int> index_Name_Level;
	std::map<int, int> index_ID;
public:
	vector<SheetPlayerData*> getAll ();
	SheetPlayerData* getRow (int n);
	std::vector<SheetPlayerData*> findByNameLevel (string _Name,int _Level);
	SheetPlayerData* findByIDName (int _ID,string _Name);
	SheetPlayerData* tryFindByIDName (int _ID,string _Name);
	bool forEach (SheetPlayerData& item);
	virtual int init ();
	virtual int initLink ();
	SheetPlayerData* findByID (int _ID);
	SheetPlayerData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetPlayer* shPlayer;

//////////////////////////////////////////////
class SheetMonsterData : public SheetBaseData
{
public:
	int ID;	//ID
	int MonsterID;	//怪物表ID
	string MonsterName;	//怪物表名称
	int MonsterQuality;	//怪物表品质
	int MonsterLevel;	//怪物表等级
	SheetMonsterData ();
};

struct _SheetIndexTypeMonsterMonsterQualityMonsterLevel {
	int MonsterQuality;
	int MonsterLevel;
	_SheetIndexTypeMonsterMonsterQualityMonsterLevel();
	_SheetIndexTypeMonsterMonsterQualityMonsterLevel(int _MonsterQuality,int _MonsterLevel) {
		MonsterQuality = _MonsterQuality;
		MonsterLevel = _MonsterLevel;
	}
	bool operator<(const _SheetIndexTypeMonsterMonsterQualityMonsterLevel& s) const {
		if (this->MonsterQuality<s.MonsterQuality) return (true);
		if (this->MonsterQuality>s.MonsterQuality) return (false);
		if (this->MonsterLevel<s.MonsterLevel) return (true);
		if (this->MonsterLevel>s.MonsterLevel) return (false);
		return (false);
	}
};
class SheetMonster : public SheetBase
{
private:
	SheetMonsterData *data;
	std::multimap<_SheetIndexTypeMonsterMonsterQualityMonsterLevel, int> index_MonsterQuality_MonsterLevel;
	std::map<int, int> index_ID;
public:
	vector<SheetMonsterData*> getAll ();
	SheetMonsterData* getRow (int n);
	std::vector<SheetMonsterData*> findByMonsterQualityMonsterLevel (int _MonsterQuality,int _MonsterLevel);
	bool forEach (SheetMonsterData& item);
	virtual int init ();
	virtual int initLink ();
	SheetMonsterData* findByID (int _ID);
	SheetMonsterData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetMonster* shMonster;

//////////////////////////////////////////////
class SheetNPCData : public SheetBaseData
{
public:
	int ID;	//ID
	int NPCID;	//NPC表ID
	string NPCName;	//NPC名称
	int NPCQuality;	//NPC品质
	int NPCPosX;	//NPC位置x
	int NPCPosY;	//NPC位置y
	int NPCPosZ;	//NPC位置z
	int NPCLevel;	//NPC等级
	SheetNPCData ();
};

struct _SheetIndexTypeNPCNPCPosXNPCPosY {
	int NPCPosX;
	int NPCPosY;
	_SheetIndexTypeNPCNPCPosXNPCPosY();
	_SheetIndexTypeNPCNPCPosXNPCPosY(int _NPCPosX,int _NPCPosY) {
		NPCPosX = _NPCPosX;
		NPCPosY = _NPCPosY;
	}
	bool operator<(const _SheetIndexTypeNPCNPCPosXNPCPosY& s) const {
		if (this->NPCPosX<s.NPCPosX) return (true);
		if (this->NPCPosX>s.NPCPosX) return (false);
		if (this->NPCPosY<s.NPCPosY) return (true);
		if (this->NPCPosY>s.NPCPosY) return (false);
		return (false);
	}
};
class SheetNPC : public SheetBase
{
private:
	SheetNPCData *data;
	std::multimap<_SheetIndexTypeNPCNPCPosXNPCPosY, int> index_NPCPosX_NPCPosY;
	std::map<int, int> index_ID;
public:
	vector<SheetNPCData*> getAll ();
	SheetNPCData* getRow (int n);
	std::vector<SheetNPCData*> findByNPCPosXNPCPosY (int _NPCPosX,int _NPCPosY);
	bool forEach (SheetNPCData& item);
	virtual int init ();
	virtual int initLink ();
	SheetNPCData* findByID (int _ID);
	SheetNPCData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetNPC* shNPC;
#endif // __SHEET_H__
