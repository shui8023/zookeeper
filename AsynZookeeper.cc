/*
 * AsynZookeeper.cc -- 
 *
 * Authors:
 *     shuidu(dubingyangxiyou@gmail.com), 04/19/2016 04:38:04 AM
 *
 */

#include "AsynZookeeper.h"

namespace ZooKeeper {

AsynZookeeper::AsynZookeeper() {

}

bool AsynZookeeper::Init(const std::string &host, int recv_time) {
    return _zk.Initialize(host, recv_time);
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

int AsynZookeeper::Get(const std::string &path, std::string &data) {
    return _zk.GetNode(path, data)   
}

int AsynZookeeper::Get(const std::string &path, std::string &data, ZooKeeperEventHandler *eventhandler) {
    return _zk.GetNode(path, data, eventhandler);
}

int AsynZookeeper::GetChildren(const std::string &path, std::map<std::string> &data) {
    return _zk.GetNodeChildren(path, data);
}

int AsynZookeeper::GetChildren(const std::string &path, std::map<std::string> &data, ZooKeeperEventHandler *eventhandler) {
    return _zk.GetNodeChildren(path, data, eventhandler);
}

int AsynZookeeper::Set(const std::string &path, const std::string &data) {
    return _zk.SetNode(path, data);
}

int AsynZookeeper::Delete(const std::string &path) {
    return _zk.DeleteNode(path);
}

int AsynZookeeper::AddEvent(const std::string &path, ZookeeperEventHandler *eventhandler) {
    return _zk.AddEventHandler(path, eventhandler);
}

int AsynZookeeper::AddEvent(ZooKeeperEventHandler *eventhandler) {
    return _zk.AddEventHandler("", eventhandler);
}

bool AsynZookeeper::RemoveEvent(const std::string &path) {
    return _zk.RemoveEventHandler(path);
}

AsynZookeeper::~AsynZookeeper() {

}

} // namespace
