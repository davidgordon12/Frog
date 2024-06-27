#include <cstdio>
#include <tcp/tcp.h>

using namespace TCP;

int main() {
	Server server;

	bool is_open = server.open();

	while(is_open) {
		server.serve();
	}

	server.close_con();

	return 0;
}
