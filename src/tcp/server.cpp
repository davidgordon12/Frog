#include <tcp/tcp.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace TCP;

bool Server::open() {
	struct sockaddr_in serv_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, STDIN_FILENO);

	if(sockfd < 0) {
		fprintf(stderr, "Unable to open the socket");
		return false;
	}

	bzero((char*)&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT);

	if(bind(sockfd, (const sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "Unable to bind the socket");
		return false;
	}

	socklen_t clilen;
	struct sockaddr_in cli_addr;

	if(listen(sockfd, MAX_REQUESTS) < 0) {
		fprintf(stderr, "Unable to listen to the socket");
		return false;
	}

	int len = sizeof(cli_addr);

	newsockfd = accept(sockfd, (sockaddr*)&cli_addr, (socklen_t*)&len);

	if(newsockfd < 0) {
		fprintf(stderr, "Unable to accept the socket");
		return false;
	}

	return true;
}

bool Server::serve() {
	bzero(buffer, MAX_BYTES);

	res = read(newsockfd, &buffer, sizeof(buffer));

	if(res < 0) {
		fprintf(stderr, "Unable to read from the socket");
		return false;
	}

	res = write(newsockfd, buffer, sizeof(buffer));

	if(res < 0) {
		fprintf(stderr, "Unable to write to the socket");
		return false;
	}

	return true;
}


void Server::close_con() {
	close(sockfd);
	close(newsockfd);
}
