#ifndef _TCP_H
#define _TCP_H

#include <sys/socket.h>

namespace TCP {

#define PORT 30000
#define MAX_REQUESTS 25
#define MAX_BYTES 1000000 * 2.2

class Server {
public:
	bool open();
	bool serve();
	void close_con();
private:
	int res = 0;
	int sockfd = 0;
	int newsockfd = 0;
	char buffer[MAX_BYTES];
};

class Client {
public:
	bool send();
private:
	int res = 0;
	int sockfd = 0;
	int connfd = 0;
	char buffer[MAX_BYTES];
private:
	void m_send();
};

}

#endif // !_TCP_H
