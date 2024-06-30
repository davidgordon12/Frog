#ifndef _HTTP_H
#define _HTTP_H

#include <http/types.h>

namespace HTTP {

class Server {
public:
    res_t handle_request(req_t req);
private:
    void open_connection();
    std::string handle_get(std::unique_ptr<std::string> path);
    res_t build_response(std::string path, std::string content);
};
}

#endif // !_HTTP_H
