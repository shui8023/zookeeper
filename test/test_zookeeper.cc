/*
 * test_zookeeper.cc -- 
 *
 * Authors:
 *     shuidu(dubingyangxiyou@gmail.com), 04/19/2016 11:26:16 PM
 *
 */

#include "zookeeper.h"

#include <vector>
#include <iostream>
#include <string>

void function(zhandle_t *zh, int type, int state, const char *path, void *watherCtx) {
    std::cout << "asd"<< path <<std::endl;
}
int main(int argc, char *argv[])
{
    zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);
    zhandle_t  *zk;
    std::string  host = "119.29.159.86:2181,119.29.111.219:2181,119.29.57.93:2181";

    zk = zookeeper_init(host.c_str(), function, 115, NULL, NULL,0);
    if (zk == NULL) {
        std::cout << "connect error" << std::endl;
    }

    std::string path = "/shui/shuiasdsd";
    int ret;
    //  int ret = zoo_wexists(zk, "/shui", function, NULL, NULL);
    //  if (ret != ZOK) {
    //    std::cout << "exists" << std::endl;
    //    return 1;
    //  }
    String_vector stringvector;
    ret = zoo_wget_children(zk, "/shui", function, NULL, &stringvector);
    if (ret != ZOK) {
        std::cout << "exists" << std::endl;
        return 1;
    }
    ret = zoo_create(zk, path.c_str(), "test", 4, &ZOO_OPEN_ACL_UNSAFE, ZOO_SEQUENCE, NULL, 0);
    if (ret != ZOK) {
        std::cout << "err" << std::endl;
    }
    ret = zoo_wget_children(zk, "/shui", function, NULL, &stringvector);
    if (ret != ZOK) {
        std::cout << "exists" << std::endl;
        return 1;
    }
    while (1);
    return 0;
}
