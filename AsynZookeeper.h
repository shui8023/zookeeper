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

#include <string>
#include <vector>

namespace ZooKeeper {
class AsynZookeeper {
public:
    AsynZookeeper(std::string &host, int recv_timeout, int flag);

    AsynZookeeper();

    bool Init(std::string &host, int recv_time, int flag);
    /* *
     * return the socket address for current connection such as 27.0.0.1:2188
     * */
    std::string GetConnectHost();
    /* *
     * Create a node in ZooKeeper 
     * \param path the name of node path
     * \param data the data to be stored in the node
     * \param zook_name the name of node
     * \param flag Create flags
     * */
    int Create(std::string &path, std::string &data, std::string &zook_name, int flag);
    /* *
     * Delete a Node in ZooKeeper
     * \param path the name of node path
     * \param version the expected version of the node, the function will fail if the 
     *  actual version of the node does not match the expected version
     * */
    int Delete(std::string &path, int version);
    
    int Exists(std::string &path, int watch);

    int Get(std::string &path, std::string data, int version);

    int GetChildren(std:string &path, std::vector<std::string> &zk_names);

    ~AsynZookeeper();
private:
    /* *
     * get the state of the zookeeper connection
     * */
    int GetZooState();

private:
    zhandle_t * _zkhandle;
    const clientid_t *_clientid;
    std::string _host;
    int _timeout;
};

};

#endif //ASYNZOOKEEPER_H_
