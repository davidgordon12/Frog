#include <cstdio>
#include <http/http.h>
#include <tcp/tcp.h>

using namespace TCP;

int main() {
	TCP::Server tcp_server;

	int sockfd = tcp_server.open();
	sockfd = tcp_server.bind2(sockfd);
	sockfd = tcp_server.listen2(sockfd);

	while(1) {
		int client_sockfd = tcp_server.accept2(sockfd);
		tcp_server.serve(client_sockfd);
		tcp_server.close_con(client_sockfd);
	}
	
	tcp_server.close_con(sockfd);

	return 0;
}
