#ifndef _HTTP_H
#define _HTTP_H

#include <http/types.h>
#include <iostream>

namespace HTTP {

class Server {
public:
    static void log(std::string message) {
        std::cout << "[LOG] - " + message << std::endl;
    }
    res_t handle_request(const char* request);
private:
    std::string response_to_string(res_t res);
    void open_connection();
    std::string handle_get(std::string path);
    res_t build_response(std::string content);
};
}

#endif // !_HTTP_H
