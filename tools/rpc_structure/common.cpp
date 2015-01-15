
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "common.h"

#include "protocol.h" /// for test...
#include "unistd.h"   /// for test...

using namespace std;

extern void CALL_CLIENT_RPC (int fd, int funcid, std::string mainstr)
{
    #define MAX_BUFFER_SIZE 1024
#if 0
    char buff[MAX_BUFFER_SIZE];
    (void) memset (buff, 0x00, MAX_BUFFER_SIZE);
    sprintf (buff, "%s", "AA-BB-CC-DD-EE-FF");
    printf ("FD=%d\n", clientSocket.getSocketFd());
    int len = write (clientSocket.getSocketFd(), buff, strlen (buff));
#else
    char buff[MAX_BUFFER_SIZE];
    (void) memset (buff, 0x00, MAX_BUFFER_SIZE);
    MSG_HEAD* phead = (MSG_HEAD *) buff;
    phead->cFuncId = funcid;
    (void) memcpy ((char*) buff + MSG_HEAD_LEN, mainstr.c_str(), mainstr.size());
    phead->cLen = MSG_HEAD_LEN + mainstr.size();

    printf ("cLen=%d, cFuncId=%d, mainstr.size=%ld\n", phead->cLen, phead->cFuncId, mainstr.size());
    int len = write (fd, buff, phead->cLen);
#endif
    if (len <= 0)
            printf ("[ERROR]: send len <= 0\n");
    else
            printf ("[INFO]: send finished.\n");
}

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
