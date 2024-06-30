#include <string>
#include <memory>
#include <http/http.h>

using namespace HTTP;

res_t Server::handle_request(req_t req) {
    res_t res;
    res.status = "200 OK";
    res.date = "2024-06-30 02:51:00";
    res.server = "Frog";
    res.etag = "A21398EFCAB3621FEGA6";
    res.ranges = "bytes";
    res.length = 0;
    res.type = "text/html";
    res.content = "hi";

    return res;
}

std::string Server::handle_get(std::unique_ptr<std::string> path) {
    return "hi";
}

void Server::open_connection() {
    /*
    Do my TCP connection stuff here
    */
}