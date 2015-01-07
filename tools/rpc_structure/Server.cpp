
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
        //MsgReceiver::close ();

        if (MsgReceiver::start (true)) {
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

        while (1) {
            printf ("... WHILE-1: wait client connection ...\n");
            ODSocket clientSocket;
            char clientIpaddr[MAX_BUFFER_SIZE];
            GLOBAL_FUNC_INVALIED.Accept (clientSocket, clientIpaddr);
            printf ("CLIENT IP ADDRESS IS: %s\n", clientIpaddr);

            // TODO:

            char buff[MAX_BUFFER_SIZE];
            (void) memset (buff, 0x00, sizeof (MAX_BUFFER_SIZE));
            sprintf (buff, "%s", "AA-BB-CC-DD-EE-FF");
            printf ("FD=%d\n", GLOBAL_FUNC_INVALIED_FD);
            int len = write (GLOBAL_FUNC_INVALIED_FD, buff, strlen (buff));
            if (len <= 0)
                printf ("[ERROR]: send len <= 0\n");
            else
                printf ("[INFO]: send finished.\n");


            ////////
            clientSocket.Close();
        }

        return (0);
}
