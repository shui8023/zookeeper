/*
 * AsynZookeeper.cc -- 
 *
 * Authors:
 *     shuidu(dubingyangxiyou@gmail.com), 04/19/2016 04:38:04 AM
 *
 */

#include "AsynZookeeper.h"

namespace ZooKeeper {

AsynZookeeper::AsynZookeeper(const std::string &host, int recv_timeout) {
    _zk = ZooKeeperManager(host, recv_timeout);
}

AsynZookeeper::AsynZookeeper() {

}

bool AsynZookeeper::Init(const std::string &host, int recv_time) {
    return _zk.Initialize(host, recv_time);
}

bool AsynZookeeper::Init() {
    return true;   
}
/* *
 * return the socket address for current connection such as 27.0.0.1:2188
 * */
const std::string& AsynZookeeper::GetConnectHost() {
    return _zk.GetHost();
}
/* *
 * Create a node in ZooKeeper 
 * \param path the name of node path
 * \param data the data to be stored in the node
 * \param zook_name the name of node
 * \param flag Create flags
 * */
int AsynZookeeper::Create(const std::string &path, const std::string &data,  int flag) {
    return _zk.CreateNode(path, data, flag);
}

int AsynZookeeper::Create(const std::string &path, const std::string &data, std::string &name) {
    return _zk.CreateSequenNode(path, data, name);
}

/* *
 * Delete a Node in ZooKeeper
 * \param path the name of node path
 * \param version the expected version of the node, the function will fail if the 
 *  actual version of the node does not match the expected version
 * */

int Get(const std::string &path, std::string &data) {
    
}

int Get(const std::string &path, std::string &data, ZooKeeperEventHandler *eventhandler);

int GetChildren(const std::string &path, std::map<std::string> &data);

int GetChildren(const std::string &path, std::map<std::string> &data, ZooKeeperEventHandler *eventhandler);

int Set(const std::string &path, const std::string &data);

int Delete(const std::string &path);

int AddEvent(const std::string &path, ZookeeperEventHandler *eventhandler);

int AddEvent(ZooKeeperEventHandler *eventhandler);

bool RemoveEvent(const std::string &path);

~AsynZookeeper();

} // namespace
