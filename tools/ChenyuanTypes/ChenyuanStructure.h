
#ifndef _CHENYUANSTRUCTURE_H
#define _CHENYUANSTRUCTURE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#include <vector>
#include <map>


using namespace std;

class xmlChenyuanProp
{
public:
        xmlChenyuanProp (void);
        void dump (void);

public:
        std::string name;
        std::string dataType;
        std::string arraySize;
        std::string doc;
        bool        serializeClient;
        bool        serializeDB;
};

class xmlChenyuanType
{
public:
        xmlChenyuanType (void);
        void add (xmlChenyuanProp prop);
        void dump (void);
public:
        std::string base;
        std::string name;
        std::map<std::string, xmlChenyuanProp> mProps;
        bool hasUserDataType;
        bool serializeClientAll;
        bool serializeDBAll;
        // std::vector<std::string> vSerializeDB;
        // std::vector<std::string> vSerializeClient;
};

class xmlChenyuanDefine
{
public:
        xmlChenyuanDefine ();
        void add (xmlChenyuanType type);
        void dump (void);

private:
        //std::vector<xmlChenyuanType> vTypes;
        std::map<std::string, xmlChenyuanType> vTypes;
};

#endif  //_CHENYUANSTRUCTURE_H
