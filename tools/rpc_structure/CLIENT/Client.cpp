
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "MsgReceiver.h"
#include "ODSocket.h"

#include "../protocol.h"    // for test..   
#include "../client/LocalRpcHandlers.h" // for test..
using namespace LocalRpcHandlers;
using namespace std;

#define GLOBAL_FUNC_INVALIED_FD \
        (MsgReceiver::g_socket.getSocketFd())
#define GLOBAL_FUNC_INVALIED \
        (MsgReceiver::g_socket)

#define MAX_BUFFER_SIZE 1024

bool restartNetwork ()
{
        MsgReceiver::close ();

        if (MsgReceiver::start (false)) {
                printf ("[DEBUG]: connect success!\n");
                return (true);
        } else {
                printf ("[DEBUG]: can't connect!\n");
                return (false);
        }
}

int main ()
{
        restartNetwork ();
        // TODO:
        char buff[MAX_BUFFER_SIZE];
        (void) memset (buff, 0x00, sizeof (MAX_BUFFER_SIZE));
        int len = read (GLOBAL_FUNC_INVALIED_FD, buff, MAX_BUFFER_SIZE);
        buff[len] = 0x00;
#ifdef __TEST__
        printf ("recv data is: '%s'\n", buff);
#else
        MSG_HEAD* phead = (MSG_HEAD*) buff;
        printf ("datalen = %d, cLen = %d, cFuncId = %d\n", len, phead->cLen, phead->cFuncId);
        char* p = (char*) buff + MSG_HEAD_LEN;
        size_t assign_size = phead->cLen - MSG_HEAD_LEN;
        std::string tmpstr;
        tmpstr.assign ((char*)buff + MSG_HEAD_LEN, phead->cLen - MSG_HEAD_LEN);
        UpdateOneBagItem_HANDLER (tmpstr);
#endif
        ////////
        GLOBAL_FUNC_INVALIED.Close ();

        return (0);
}
