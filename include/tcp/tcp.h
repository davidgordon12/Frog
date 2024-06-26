#ifndef _TCP_H
#define _TCP_H

namespace TCP {

#define MAX_REQUESTS 25
#define MAX_BYTES 4096

class Server {
public:
	bool open();
private:
	int res = 0;
	int sockfd = 0;
	int newsockfd = 0;
	int port = 8080;
	char buffer[MAX_BYTES];
};

class Client {
public:
	bool send();
private:
	int res = 0;
	int sockfd = 0;
	int connfd = 0;
	int port = 8080;
	char buffer[MAX_BYTES];
private:
	void write();
};

}

#endif // !_TCP_H
