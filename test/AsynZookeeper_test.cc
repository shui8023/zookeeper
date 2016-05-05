/*
 * AsynZookeeper.cc -- 
 *
 * Authors:
 *     shuidu(dubingyangxiyou@gmail.com), 2016年05月05日 12时49分35秒
 *
 */

#include "AsynZookeeper.h"

#include <string>
#include <iostream>

using namespace ZooKeeper;
using namespace std;

class Deal : public ZooKeeperEventHandler {
    public:
        void OnNodeChanged(const std::string &path) {
            cout << "changed" << path << endl;
        }

        void OnNodeCreated(const std::string &path) {
            cout << "created"  << path << endl;  
        }

        void OnNodeDeleted(const std::string &path) {
            cout << "delete" << path << endl;
        }
        void OnNodeChildrenChanged(const std::string &path) {
            cout << "Children" << path << endl;
        }
};

int main(int argc, char *argv[])
{
    zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);
    string host = "119.29.57.93:2181,119.29.111.219:2181,199.29.159.86:2181";
    AsynZookeeper zk;
    bool result;
    result = zk.Init(host, 10000000);
    
    Deal deal;
    ZooKeeperEventHandler *de = &deal;
    cout << result << endl;
    de->OnNodeDeleted("asd");
    int ret;
    ret = zk.Create("/shui/shui", "dasd", 0);
    cout << ret << endl;
    string name;
    ret = zk.Create("/shui/shui/asd", "asd", name);
    cout << ret << endl;

    string data;
    ret = zk.Get("/shui/shui", data);
    cout << ret << data << endl;

    ret = zk.Get("/shui/shui", data, de);
    cout << ret << endl;
    while (1);
    return 0;
}
