
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "MsgReceiver.h"
#include "ODSocket.h"

#include "ClientRpc.h" // for test..
#include "Item.h"      // for test..

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

#if 0
            char buff[MAX_BUFFER_SIZE];
            (void) memset (buff, 0x00, sizeof (MAX_BUFFER_SIZE));
            sprintf (buff, "%s", "AA-BB-CC-DD-EE-FF");
            printf ("FD=%d\n", clientSocket.getSocketFd());
            int len = write (clientSocket.getSocketFd(), buff, strlen (buff));
            if (len <= 0)
                printf ("[ERROR]: send len <= 0\n");
            else
                printf ("[INFO]: send finished.\n");
#else
            ClientRpc cRpc;
            Item item;
            item.setId (900);
            item.setPrice (14000);
            cRpc.UpdateOneBagItem (clientSocket.getSocketFd(), 34, item);//int pos, ItemBase& item)
#endif


            ////////
            clientSocket.Close();
        }

        return (0);
}
