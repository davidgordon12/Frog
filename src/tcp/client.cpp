#include <tcp/tcp.h>
#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()


using namespace TCP;

void Client::m_send() {
	for(;;) {
		bzero(buffer, sizeof(buffer));
		fprintf(stdout, "Enter message to send to the server: ");
		int n = 0;
		while((buffer[n++] = getchar()) != '\n');
		write(sockfd, buffer, sizeof(buffer));
		bzero(buffer, sizeof(buffer));
		read(sockfd, buffer, sizeof(buffer));
		fprintf(stdout, "Server: %s", buffer);
	}
};

bool Client::send() {
	socklen_t clilen;
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, STDIN_FILENO);

	if(sockfd < 0) {
		fprintf(stderr, "Unable to open the socket");
		return false;
	}

	bzero((char*)&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(PORT);

	if(connect(sockfd, (const sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "Unable to connect to the socket");
		return false;
	}

	m_send();

	close(sockfd);

	return true;
}


int main() {
	Client client;
	if(client.send()) {
		fprintf(stdout, "Client online... Sending data to port 8080");
	}
	return 0;
}
