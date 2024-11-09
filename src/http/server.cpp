#include <string>
#include <http/http.h>

using namespace HTTP;

res_t Server::handle_request(const char* request) {
    std::string content = handle_get("index.html");
    res_t res = build_response(content);
    return res;
}

res_t Server::build_response(std::string content) {
    res_t res;
    res.status = "200 OK";
    res.date = "2024-06-30 02:51:00";
    res.server = "Frog";
    res.etag = "A21398EFCAB3621FEGA6";
    res.ranges = "bytes";
    res.length = content.length();
    res.type = "text/html";
    res.content = content;
    return res;
}

std::string Server::handle_get(std::string path) {
    /* TODO: Read the file from the path and return it in the content body */
    return "hi";
}

std::string Server::response_to_string(res_t res) {
    return res.content;
}
