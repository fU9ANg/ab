
#ifndef _ODSOCKET_H_
#define _ODSOCKET_H_

#ifdef WIN32
#	include <winsock2.h>
#	include <Windows.h>
	typedef int				socklen_t;
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
    #include <sys/select.h>
	#include <arpa/inet.h>
	typedef int				SOCKET;

	//#pragma region define win32 const variable in linux
	#define INVALID_SOCKET	-1
	#define SOCKET_ERROR	-1
	//#pragma endregion
#endif


class ODSocket {

public:
	ODSocket(SOCKET sock = INVALID_SOCKET);
	~ODSocket();

	// Create socket object for snd/recv data
	bool Create(int af, int type, int protocol = 0);

	// Connect socket
	bool Connect(const char* ip, unsigned short port);
	//#region server
	// Bind socket
	bool Bind(const struct sockaddr_in&, unsigned short port);

	// Listen socket
	bool Listen(int backlog = 5); 

	// Accept socket
	bool Accept(ODSocket& s, char* fromip = NULL);
	//#endregion
	
#if 1
	// Send socket
	int Send(void* buf, int len, int flags = 0);
#else
	void Send(void* buf, int len, int flags = 0);
#endif

#if 1
	// Recv socket
	int Recv(void* buf, int len, int flags = 0);
#else
	void Recv(void* buf, int len, int flags = 0);
#endif
	// Close socket
	int Close();

	// Get errno
	int GetError();
	
	//#pragma region just for win32
	// Init winsock DLL 
	static int Init();	
	// Clean winsock DLL
	static int Clean();
	//#pragma endregion

	// Domain parse
	static bool DnsParse(const char* domain, char* ip);

	ODSocket& operator = (SOCKET s);

	operator SOCKET ();

	SOCKET getSocketFd (void);

protected:
	SOCKET m_sock;

};

#endif
