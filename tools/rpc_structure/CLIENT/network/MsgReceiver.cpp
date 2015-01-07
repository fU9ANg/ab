
#include "MsgReceiver.h"
#include "ODSocket.h"
#include <errno.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

ODSocket MsgReceiver::g_socket;

bool MsgReceiver::start (bool isServer) {
	bool rlt = false;

	if (-1==g_socket.Init()) {
		(void) printf ("[ERROR] init : socket\n");
		return false;
	}

	if (!g_socket.Create (AF_INET, SOCK_STREAM, 0)) {
		(void) printf ("[ERROR] Create : socket\n");
		return false;
	}

    if (isServer) {
        unsigned short serv_port = 13333;

        struct sockaddr_in serv_addr;
	    serv_addr.sin_family = AF_INET;
	    serv_addr.sin_addr.s_addr = inet_addr("192.168.0.13");
	    serv_addr.sin_port = htons(serv_port);

        MsgReceiver::g_socket.Bind (serv_addr, serv_port);
        MsgReceiver::g_socket.Listen ();
        rlt = true;
    }
    else {
        rlt = MsgReceiver::connect ();
        if (!rlt) {
            close();
        }
    }
	return (rlt);
}

bool MsgReceiver::close ()
{
#if 0
	if (g_socket) {
		(void) printf ("g_socket close!");
		g_socket.Close ();
		return (true);
	}
	else return (false);
#else
	//(void) printf ("g_socket close!");
	g_socket.Close ();
#endif
    return (true);
}

bool MsgReceiver::connect () {
	std::string serv_addr = "192.168.0.13";
	unsigned short serv_port = 13333;

	if (!MsgReceiver::g_socket.Connect ((const char*) serv_addr.c_str(), serv_port)) {
		(void) printf ("[ERROR]: can't connect to '%s', port(%d)\n", (const char*) serv_addr.c_str(), serv_port);
		return false;
	} else {
		(void) printf ("[INFO]: connected");
		return true;
	}
}

MsgReceiver::MsgReceiver () {}

MsgReceiver::~MsgReceiver () {}

ssize_t MsgReceiver::send_n(int fd,
        void* buf,
        ssize_t left,
        struct timeval* timeout){
    if (NULL == buf){
        return -1;
    }

    ssize_t recved = 0;
    fd_set st;
    while(0 != left) {
        FD_ZERO(&st);
        FD_SET(fd, &st);
        int i = select(fd + 1, NULL, &st, NULL, timeout);
        if (0 >= i) {
            break;
        } else {
            ssize_t len = send(fd, (void*)((char*)buf + recved), left, 0);
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            recved += len;
        }
    }
    return 0;
}

ssize_t MsgReceiver::recv_n(int fd,
        void* buf,
        ssize_t left,
        struct timeval* timeout){
    if (NULL == buf){
        return -1;
    }
    ssize_t recved = 0;
    fd_set st;
    while(0 != left){
        FD_ZERO(&st);
        FD_SET(fd, &st);
        int i = select(fd + 1, &st, NULL, NULL, timeout);
        if (0 >= i) {
            break;
        } else {
            ssize_t len = recv(fd, (void*)((char*)buf + recved), left, 0);
            if(0 == len){
                break;
            }
            if(-1 == len){
                return -1;
            }
            left -= len;
            recved += len;
        }
    }
    return recved;
}

int MsgReceiver::recv_v(int fd, void* buf, ssize_t left)
{
	//MutexLockGuard g (m_lock);
	if (NULL == buf) {
		return -1;
	}

	int recved = 0;
	int len = 0;
	while (left > 0) {
		len = recv(fd, (char*)buf+recved, left, 0);
		if (len <= 0) {
			if (EAGAIN == errno || EINTR == errno) {
				if (len < 0) len = 0;
				continue;
			} else {
				(void) printf("[NETDEBUG] recv_v : while break before : errno = %d", errno); break;
			}
		}

		left -= len;
		recved += len;
	}

	return recved;
}

int MsgReceiver::send_v(int fd, void* buf, ssize_t left) {
	//MutexLockGuard g (m_lock);
	if (NULL == buf) {
		return -1;
	}

	char* ptr = (char*)buf;
	int sended = 0;
	int len = 0;
	while (left > 0) {
		len = send(fd, ptr, left, 0);
		if (len <= 0) {
			if (EAGAIN == errno || EINTR == errno) {
				if (len < 0)
					len = 0;
				continue;
			} else {
				break;
			}
		}

		left -= len;
		ptr += len;
		sended += len;
	}

	return sended;
}
