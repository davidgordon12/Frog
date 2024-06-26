#include <cstdio>
#include <tcp/tcp.h>

using namespace TCP;

int main() {
	Server server;
	Client client;

	if(server.open()) {
		fprintf(stdout, "Server open... Listening on port 8080");
	}
	if(client.send()) {
		fprintf(stdout, "Client sending request to port 8080");
	}

	return 0;
}
