/*
 * ZooKeeperSessionEventHandler.h -- 
 *
 * Authors:
 *     shuidu(|EMAIL)|, 04/15/16 16:12:12
 *
 */

#ifndef ZOOKEEPEREVENTHANDLER_H_
#define ZOOKEEPEREVENTHANDLER_H_

namespace ZooKeeper {

class ZooKeeperEventHandler {
public:
    virtual void OnConnecting(const std::string &host) { }
    virtual void OnConnected(const std::string &host) { }
    virtual void OnNodeCreated(const std::string &path) { }
    virtual void OnNodeChanged(const std::string &path) { }
    virtual void OnNodeChildrenChanged(const std::string &path) { }
    virtual void OnNodeDeleted(const std::string &path) { }
};
} // namespace 

#endif // ZOOKEEPEREVENTHANDLER_H_
