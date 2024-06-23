#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_REQUESTS 25
#define MAX_BYTES 4096

namespace TCP {
class Listener {
private:
	int res;
	int sockfd;
	int newsockfd;
	int port = 8080;
	char buffer[4096];
	socklen_t clilen;
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;

public:
	bool open() {
		sockfd = socket(AF_INET, SOCK_STREAM, STDIN_FILENO);

		if(sockfd < 0) {
			fprintf(stderr, "Unable to open the socket");
			return false;
		}

		bzero((char*)&serv_addr, sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_addr.s_addr = INADDR_ANY;
		serv_addr.sin_port = htons(port);

		if(bind(sockfd, &serv_addr, sizeof(serv_addr)) < 0) {
			fprintf(stderr, "Unable to bind the socket");
			return false;
		}

		listen(sockfd, MAX_REQUESTS);
		newsockfd = accept(sockfd, &cli_addr, (socklen_t*)sizeof(cli_addr));

		close(sockfd);

		if(newsockfd < 0) {
			fprintf(stderr, "Unable to accept the socket");
			return false;
		}

		bzero(buffer, MAX_BYTES);
		
		res = read(newsockfd, &buffer, MAX_BYTES-1);

		if(res < 0) {
			fprintf(stderr, "Unable to read from the socket");
			return false;
		}

		res = write(newsockfd, buffer, MAX_BYTES);

		if(res < 0) {
			fprintf(stderr, "Unable to write to the socket");
			return false;
		}

		close(newsockfd);

		return true;
	}
};
}
