
#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

extern std::string SerializeObjectToString (void);

extern void ParseObjectFromString (std::string& str);

extern bool PushSizeToString (std::string& mainstr, unsigned short nsize);
extern bool PopSizeFromString (std::string& mainstr, unsigned short &nsize);
extern bool PushSerializeString (std::string& mainstr, std::string& str);
extern bool PopSerializeString (std::string& mainstr, std::string& str, unsigned short& size);

#endif  //_COMMON_H
