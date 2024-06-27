#include <cstdio>
#include <tcp/tcp.h>

using namespace TCP;

int main() {
	Server server;

	if(server.open()) {
		fprintf(stdout, "Server open... Listening on port 8080");
	}

	return 0;
}
