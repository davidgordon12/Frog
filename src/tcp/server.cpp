#include <http/http.h>
#include <http/types.h>
#include <tcp/tcp.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

using namespace TCP;

bool Server::open() {
	struct sockaddr_in serv_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, STDIN_FILENO);

	if(sockfd < 0) {
		fprintf(stderr, "Unable to open the socket");
		exit(0);
	}

	bzero((char*)&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT);

	if(bind(sockfd, (const sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "Unable to bind the socket");
		exit(0);
	}

	socklen_t clilen;
	struct sockaddr_in cli_addr;

	if(listen(sockfd, MAX_REQUESTS) < 0) {
		fprintf(stderr, "Unable to listen to the socket");
		exit(0);
	}

	int len = sizeof(cli_addr);

	newsockfd = accept(sockfd, (sockaddr*)&cli_addr, (socklen_t*)&len);

	if(newsockfd < 0) {
		fprintf(stderr, "Unable to accept the socket");
		exit(0);
	}

	return true;
}

bool Server::serve() {
	bzero(buffer, MAX_BYTES);

	res = read(newsockfd, &buffer, sizeof(buffer));

	if(res < 0) {
		fprintf(stderr, "Unable to read from the socket");
		exit(0);
	}

	using namespace HTTP;

	HTTP::Server server;

	res_t response = server.handle_request((const char*)&buffer);

	bzero(buffer, sizeof(buffer));

	strcpy(buffer, response.content.c_str());

	res = write(newsockfd, buffer, response.length);

	if(res < 0) {
		fprintf(stderr, "Unable to write to the socket");
		exit(0);
	}

	return true;
}


void Server::close_con() {
	close(sockfd);
	close(newsockfd);
}
