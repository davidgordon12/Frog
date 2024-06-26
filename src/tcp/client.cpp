#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

#define MAX_BYTES 4096
#define MAX 25

namespace TCP {
class Client {
private:
	int res;
	int sockfd;
	int connfd;
	int port = 8080;
	char buffer[MAX_BYTES];
	socklen_t clilen;
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;

	void write() {
		bzero(buffer, sizeof(buffer));
		printf("Enter message to send to the server: ");
		res = 0;
		while(char c = getchar() != '\n') {
			buffer[res] = c;
		}
	};
public:
	bool send() {
		sockfd = socket(AF_INET, SOCK_STREAM, STDIN_FILENO);

		if(sockfd < 0) {
			fprintf(stderr, "Unable to open the socket");
			return false;
		}

		bzero((char*)&serv_addr, sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(port);

		if(connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0) {
			fprintf(stderr, "Unable to connect to the socket");
			return false;
		}



		close(sockfd);

		return true;
	}
};
}
