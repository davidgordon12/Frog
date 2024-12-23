#ifndef _TCP_H
#define _TCP_H

#include <sys/socket.h>

namespace TCP {

#define PORT 30000
#define MAX_REQUESTS 25
#define MAX_BYTES 1000000

class Server {
public:
	int open();
	int bind2(int sockfd);
	int accept2(int sockdf);
	int listen2(int sockfd);
	void serve(int sockfd);
	void close_con(int sockfd);
private:
	int res = 0;
	int sockfd = 0;
	char buffer[MAX_BYTES];
};
}

#endif // !_TCP_H
