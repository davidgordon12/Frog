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

int Server::open() {
	sockfd = socket(AF_INET, SOCK_STREAM, STDIN_FILENO);

	if(sockfd < 0) {
		fprintf(stderr, "Unable to open the socket");
		exit(0);
	}

	HTTP::Server::log("Created socket with file descriptor " + std::to_string(sockfd));
	
	return sockfd;
}

int Server::bind2(int sockfd) {
	struct sockaddr_in serv_addr;

	bzero((char*)&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT);

	if(bind(sockfd, (const sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "Unable to bind the socket");
		exit(0);
	}

	HTTP::Server::log("Bound to socket with file descriptor " + std::to_string(sockfd));

	return sockfd;
}

int Server::listen2(int sockfd) {
	if(listen(sockfd, MAX_REQUESTS) < 0) {
		fprintf(stderr, "Unable to listen to the socket");
		exit(0);
	}

	HTTP::Server::log("Listening on port  " + std::to_string(PORT));

	return sockfd;
}

int Server::accept2(int sockfd) {
	socklen_t clilen;
	struct sockaddr_in cli_addr;

	int len = sizeof(cli_addr);

	int client_sockfd = accept(sockfd, (sockaddr*)&cli_addr, (socklen_t*)&len);

	if(client_sockfd < 0) {
		fprintf(stderr, "Unable to accept the socket");
		exit(0);
	}

	HTTP::Server::log("Accepted client socket with file descriptor " + std::to_string(client_sockfd));

	return client_sockfd;
}

void Server::serve(int sockfd) {
	bzero(buffer, MAX_BYTES);

	res = read(sockfd, &buffer, sizeof(buffer));

	if(res < 0) {
		fprintf(stderr, "Unable to read from the socket");
		exit(0);
	}

	bzero(buffer, sizeof(buffer));

	std::string msg = "hi socket # " + std::to_string(sockfd) + "\0"; 
	strcpy(buffer, msg.c_str());

	res = write(sockfd, buffer, strlen(buffer));

	if(res < 0) {
		fprintf(stderr, "Unable to write to the socket");
		exit(0);
	}
}


void Server::close_con(int sockfd) {
	close(sockfd);
}
