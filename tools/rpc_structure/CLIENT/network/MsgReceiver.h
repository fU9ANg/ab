#ifndef __MSGRECEIVER_H__
#define __MSGRECEIVER_H__

#include "ODSocket.h"

class MsgReceiver {
public :
	static ODSocket g_socket;

public :
	MsgReceiver ();
	virtual ~MsgReceiver ();
	static bool start (bool);
	static bool close ();

	static int recv_v(int, void*, ssize_t);
	static int send_v(int, void*, ssize_t);
	static ssize_t recv_n(int, void*, ssize_t, struct timeval* timeout);
	static ssize_t send_n(int, void*, ssize_t, struct timeval* timeout);

private :
	static bool connect ();
};

#endif /* __MSGRECEIVER_H__ */
