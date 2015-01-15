
#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

//extern std::string SerializeObjectToString (void);

//extern void ParseObjectFromString (std::string& str);

#if 0
extern bool PushSizeToString (std::string& mainstr, unsigned short nsize);
extern bool PopSizeFromString (std::string& mainstr, unsigned short &nsize);
extern bool PushSerializeString (std::string& mainstr, std::string& str);
extern bool PopSerializeString (std::string& mainstr, std::string& str, unsigned short& size);
#else
extern bool AppendSizeToString      (std::string& mainstr, unsigned short nsize);
extern bool ExtractSizeFromString   (std::string& mainstr, unsigned short &nsize);
extern bool AppendObjectToString    (std::string& mainstr, std::string& str);
extern bool ExtractObjectFromString (std::string& mainstr, std::string& str, unsigned short& size);
extern void CALL_CLIENT_RPC (int fd, int funcid, std::string mainstr);
#endif

#endif  //_COMMON_H
