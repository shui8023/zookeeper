/*
 * ZooKeeperException.cc -- 
 *
 * Authors:
 *     shuidu(dubingyangxiyou@gmail.com), 04/15/16 11:01:53
 *
 */

#include "ZooKeeperException.h"

#include <cerrno>
#include <cstring>
#include <sstream>

#ifdef __cplusplus
extern "C" {
#endif 
#ifdef __cplusplus
}
#endif 

std::string itos(int errno) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

namespace ZooKeeper {
    
ZooKeeperException::ZooKeeperException(int error) {
    char *description = std::strerror(error); 
    
    if (errno == ZSYSTEMERROR) {
        std::string result = "Error " + itos(error) + "Description " + description + "Errno " + itos(errno);
        _what.assign(result);
    } else {
        std::string result = "Error " + itos(error) + "Description " + description;
        _what.assign(result);
        
    }
}

ZooKeeperException::ZooKeeperException(int error, const std::string &description) {
    std::string result = "Error " + itos(error) + "Description " + description;
    _what.assign(result);
}

ZooKeeperException::~ZooKeeperException() {
    
}

const char *ZooKeeperException::What() const {
    return _what.c_str();
}

} // namespace 
