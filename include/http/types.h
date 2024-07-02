#ifndef _TYPES_H
#define _TYPES_H

#include <string>

typedef struct req_t {
    std::string method;
    std::string path;
    float version;
    std::string host;
    std::string language;
} req_t;

typedef struct res_t {
    std::string status;
    std::string date;
    std::string server;
    std::string etag;
    std::string ranges;
    int length;
    std::string type;
    std::string content;
} res_t;

#endif 
