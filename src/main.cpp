#include <cstdio>
#include <http/http.h>
#include <tcp/tcp.h>

using namespace HTTP;
using namespace TCP;

int main() {
	TCP::Server tcp_server;
	HTTP::Server http_server;

	tcp_server.open();
	tcp_server.serve();
	tcp_server.close_con();


	return 0;
}
