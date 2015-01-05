
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "common.h"

using namespace std;

bool AppendSizeToString (std::string& mainstr, unsigned short nsize)
{
    if (nsize <= 0)
        return (false);

    static char tmpsize[4];
    size_t size_size = sizeof (unsigned short);
    
    *(unsigned short*) tmpsize = nsize;
    mainstr.append (tmpsize, size_size);

    return (true);
}

bool ExtractSizeFromString (std::string& mainstr, unsigned short &nsize)
{
    if (mainstr.empty ())
        return (false);

    size_t pos = sizeof (unsigned short);
    nsize = *(unsigned short*) mainstr.c_str ();

    mainstr = mainstr.substr (pos);

    return (true);
}

bool AppendObjectToString (std::string& mainstr, std::string& str)
{
    if (str.empty ())
        return (false);

    static char tmpsize[4];
    size_t size_size = sizeof (unsigned short);
    
    *(unsigned short*) tmpsize = str.size ();
    mainstr.append (tmpsize, size_size);
    mainstr.append (str);

    return (true);
}

bool ExtractObjectFromString (std::string& mainstr, std::string& str, unsigned short& size)
{
    if (mainstr.empty ())
        return (false);

    size_t pos = sizeof (unsigned short);
    size = *(unsigned short*) mainstr.c_str ();
    str = mainstr.substr (pos, size);
    mainstr = mainstr.substr (pos+size);

    return (true);
}
