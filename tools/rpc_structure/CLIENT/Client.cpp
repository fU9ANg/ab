
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "MsgReceiver.h"
#include "ODSocket.h"

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
        printf ("recv data is: '%s'\n", buff);
        ////////
        GLOBAL_FUNC_INVALIED.Close ();

        return (0);
}
