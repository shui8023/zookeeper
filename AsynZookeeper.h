/*
 * AsynZookeeper.h -- 
 *
 * Authors:
 *     shuidu(|EMAIL)|, 04/14/16 20:14:30
 *
 */

#ifndef ASYNZOOKEEPER_H_
#define ASYNZOOKEEPER_H_

#include "zookeeper.h"
#include "zookeeper_log.h"
#include "proto.h"
#include "recordio.h"
#include "zookeeper_version.h"
#include "zookeeper.jute.h"
#include "ZooKeeperManager.h"

#include <string>
#include <vector>
#include <map>

namespace ZooKeeper {
class AsynZookeeper {
public:
    AsynZookeeper(const std::string &host, int recv_timeout);

    AsynZookeeper();

    bool Init(const std::string &host, int recv_time);

    bool Init();
    /* *
     * return the socket address for current connection such as 27.0.0.1:2188
     * */
    const std::string& GetConnectHost();
    /* *
     * Create a node in ZooKeeper 
     * \param path the name of node path
     * \param data the data to be stored in the node
     * \param zook_name the name of node
     * \param flag Create flags
     * */
    int Create(const std::string &path, const std::string &data,  int flag);

    int Create(const std::string &path, const std::string &data, std::string &name);
    /* *
     * Delete a Node in ZooKeeper
     * \param path the name of node path
     * \param version the expected version of the node, the function will fail if the 
     *  actual version of the node does not match the expected version
     * */
    
    int Get(const std::string &path, std::string &data);

    int Get(const std::string &path, std::string &data, ZooKeeperEventHandler *eventhandler);

    int GetChildren(const std::string &path, std::map<std::string> &data);

    int GetChildren(const std::string &path, std::map<std::string> &data, ZooKeeperEventHandler *eventhandler);

    int Set(const std::string &path, const std::string &data);

    int Delete(const std::string &path);

    int AddEvent(const std::string &path, ZookeeperEventHandler *eventhandler);

    int AddEvent(ZooKeeperEventHandler *eventhandler);

    bool RemoveEvent(const std::string &path);

    ~AsynZookeeper();

private:
    ZooKeeperManager _zk;
};

} // namespace

#endif //ASYNZOOKEEPER_H_
