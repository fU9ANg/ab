
#include "ODSocket.h"
#include <stdio.h>
#include <string>
#include <errno.h>
#include <iostream>

using namespace std;

#ifdef WIN32
	#pragma comment(lib, "wsock32")
#endif

ODSocket::ODSocket(SOCKET sock) : m_sock(sock) {}

ODSocket::~ODSocket() {}

int ODSocket::Init() {
#ifdef WIN32
	WSADATA wsaData;
	WORD version = MAKEWORD(2, 0);
	int ret = WSAStartup(version, &wsaData);
	if (ret) {
		return -1;
	}
#endif

	return 0;
}

int ODSocket::Clean() {
#ifdef WIN32
	return (WSACleanup());
#endif
	return 0;
}

ODSocket& ODSocket::operator = (SOCKET s) {
	m_sock = s;
	return (*this);
}

ODSocket::operator SOCKET () {
	return m_sock;
}

bool ODSocket::Create(int af, int type, int protocol) {
	m_sock = socket(af, type, protocol);
	if ( m_sock == INVALID_SOCKET ) {
		(void) printf ("[ERROR] Create : type = %d, errno = %d", type, errno);
		return false;
	}
	//fcntl (m_sock, F_SETFL, O_NONBLOCK);
    printf ("m_sock = %d\n", m_sock);
	return true;
}

bool ODSocket::Connect(const char* ip, unsigned short port) {
#define CONNECT_TIMEOUT 5

	int error;
	struct sockaddr_in svraddr;
	svraddr.sin_family = AF_INET;
	svraddr.sin_addr.s_addr = inet_addr(ip);
	svraddr.sin_port = htons(port);
#if 1
    if (connect (m_sock, (struct sockaddr*) &svraddr, sizeof (svraddr)) == -1) {
		if (errno == EINPROGRESS){// it is in the connect process
			struct timeval tv;
			fd_set writefds;
			tv.tv_sec = CONNECT_TIMEOUT;
			tv.tv_usec = 0;
			FD_ZERO(&writefds);
			FD_SET(m_sock, &writefds);
			if(select(m_sock+1,NULL,&writefds,NULL,&tv)>0){
					socklen_t len=sizeof(socklen_t);
				    // 主要针对防火墙
					getsockopt(m_sock, SOL_SOCKET, SO_ERROR, &error, &len);
					if(error==0) {
						(void) printf ("[SOCKDEBUG]: 1, connect success.\n");
					}
					else {
						(void) printf("[SOCKDEBUG] ERROR1: if (ret == SOCKET_ERROR) port = %d", port);
						return (false);
					}
			}
			else {
				//timeout or error happed
				(void) printf("[SOCKDEBUG] ERROR2: if (ret == SOCKET_ERROR) port = %d", port);
				return (false);
			}
		}
		else {
			(void) printf("[SOCKDEBUG] ERROR3: if (ret == SOCKET_ERROR) port = %d", port);
			(void) printf ("errno =%d", errno);
			return (false);
		}
	}
	else {
		(void) printf ("[SOCKDEBUG]: 2, connect success.\n");
		return (true);
	}
#else
	int ret = connect(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
	if (ret == SOCKET_ERROR) {
		(void) printf("[ERROR] Connect : if (ret == SOCKET_ERROR) port = %d", port);
		m_sock = -1;
		return false;
	}
#endif
	return (true);
}

bool ODSocket::Bind(const struct sockaddr_in& svraddr, unsigned short port) {
	int opt =  1;
	if ( setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt)) < 0 ) 
		return false;

	int ret = bind(m_sock, (struct sockaddr*)&svraddr, sizeof(svraddr));
	if ( ret == SOCKET_ERROR ) {
		(void) printf("[ERROR] Bind : error = %d", GetError());
		return false;
	}
	return true;
}

bool ODSocket::Listen(int backlog) {
	int ret = listen(m_sock, backlog);
	if ( ret == SOCKET_ERROR ) {
		(void) printf("[ERROR] Listen : error = %d", GetError());
		return false;
	}
	return true;
}

bool ODSocket::Accept(ODSocket& s, char* fromip) {
	struct sockaddr_in cliaddr;
	socklen_t addrlen = sizeof(cliaddr);
	SOCKET sock = accept(m_sock, (struct sockaddr*)&cliaddr, &addrlen);
	if ( sock == SOCKET_ERROR ) {
		(void) printf("[ERROR] Accept : error = %d", GetError());
		return false;
	}

	s = sock;
	if ( fromip != NULL )
		sprintf(fromip, "%s", inet_ntoa(cliaddr.sin_addr));

	return true;
}

#if 1
int ODSocket::Send (void* buf, int len, int flags)
{
	int bytes_left = len;
	int written_bytes;
	char* ptr = (char*) buf;

	int send_len = 0;
	while (bytes_left > 0)
	{
		written_bytes = send (m_sock, ptr, bytes_left, flags);
		if (written_bytes <= 0)
		{
			if (errno == EINTR) {
				if (written_bytes < 0)
					written_bytes = 0;
				continue;
			}
			else if (errno == EAGAIN) {
				if (written_bytes < 0)
					written_bytes = 0;
				continue;
			}
			else {
				break;
			}
		}
		bytes_left -= written_bytes;
		ptr += written_bytes;
		send_len += written_bytes;
	}

	return send_len;
}
#else
int ODSocket::Send(void* buf, int len, int flags) {
	int bytes;
	int count = 0;

	while ( count < len ) {
		bytes = send(m_sock, (char*)buf + count, len - count, flags);
		if ( bytes == -1 || bytes == 0 )
			return -1;
		count += bytes;
	} 

	return count;
}
#endif

//int ODSocket::Recv(void* buf, int len, int flags)
//{
//	return (recv(m_sock, buf, len, flags));
//}
#if 0
int ODSocket::Recv(void* buf, int len, int flags)
{
	int bytes;
	int count = 0;
	while(count < len){
		bytes = recv(m_sock,(char*)buf + count, len - count, flags);
		if(bytes == -1 || bytes == 0)
			return -1;
		count+=bytes;
	}
	return count;
	//	return recv(m_sock,(char*)buf, len, flags);

}

#else

int ODSocket::Recv (void* buf, int len, int flags) {
#if 1
	int bytes_left = len;
	char* ptr = (char*) buf;

	int recv_len = 0;
	int read_bytes = 0;
	while (bytes_left > 0) {
		read_bytes = recv (m_sock, ptr, bytes_left, flags);
		if (read_bytes <= 0) {
			if (EINTR == errno || EAGAIN == errno) {
				if (read_bytes < 0)
					read_bytes = 0;
				continue;
			} else {
				break;
			}
		}
		bytes_left -= read_bytes;
		ptr += read_bytes;
		recv_len += read_bytes;
	}

	return recv_len;
#else
	int read_bytes = 0;
	char* ptr = (char*) buf;
	read_bytes = recv (m_sock, ptr, len, flags);

	CCLOG ("errno_number:%d", errno);

	return (read_bytes);
#endif
}
#endif
int ODSocket::Close() {
#ifdef WIN32
	return (closesocket(m_sock));
#else
	return (close(m_sock));
#endif
}

int ODSocket::GetError() {
#ifdef WIN32
	return (WSAGetLastError());
#else
	return (errno);
#endif
}

bool ODSocket::DnsParse(const char* domain, char* ip) {
	struct hostent* p;
	if ( (p = gethostbyname(domain)) == NULL )
		return false;

	sprintf(ip, "%u.%u.%u.%u",
			(unsigned char)p->h_addr_list[0][0], 
			(unsigned char)p->h_addr_list[0][1], 
			(unsigned char)p->h_addr_list[0][2], 
			(unsigned char)p->h_addr_list[0][3]);

	return true;
}

SOCKET ODSocket::getSocketFd (void) {
	return (m_sock);
}
