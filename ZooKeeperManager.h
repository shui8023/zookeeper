/*
 * ZooKeeperNodeManager.h -- 
 *
 * Authors:
 *     shuidu(|EMAIL)|, 04/15/16 16:28:59
 *
 */

#ifndef ZOOKEEPERMANAGER_H_
#define ZOOKEEPERMANAGER_H_

#include "ZooKeeperEventHandler.h"
#include "ZooKeeperStat.h"
#include "ZooKeeperException.h"

#include <map>

namespace ZooKeeper{

class ZooKeeperEventHandler;

class ZooKeeperManager { 
public:
    ZooKeeperManager(const std::string &host, int connectionTimeout);

    ZooKeeperManager();   

    ~ZooKeeperManager();
    
    int Initialize(const std::string &host, int connectionTimeout);
    
    const std::string& GetHost() const;
    
    int GetConnectionTimeout() const;
    
    void FireEvent(zhandle_t *zhandle, int state, int type, const char *path);
    
    int CreateNode(const std::string &path, const std::string &data, int flag);

    int CreateSequenNode(const std::string &path, const std::string &data, const std::string &nodeName);
    
    int GetNode(const std::string &path, std::string &data);
    
    int GetNode(const std::string &path, std::string &data, ZooKeeperEventHandler *eventhandler);
    
    int GetNodeChildren(const std::string &path, std::vector<std::string> childrenName);

    int GetNodeChildren(const std::string &path, std::vector<std::string> childrenName,
                        ZooKeeperEventHandler *eventhandler);
    int SetNode(const std::string &path, const std::string &data);
    
    int DeleteNode(const std::string &path);

    int AddEventHandler(const std::string &path, ZooKeeperEventHandler *eventhandler);

    int AddEventHandler(ZookeeperEventHandler *eventhandler);
    
    bool RemoveEventHandler(const std::string &path);

private:
    bool Insert(const std:string &path, ZooKeeperEventHandler * eventHandler);
    bool Erase(const std::string &path);

private:
    static const int MAX_PATH_BUFFER = 1024;
    static const int MAX_DATA_BUFFER = 1024 * 1024;
    std::string _host;
    zhandler_t  *_handle;
    bool _isInit;
    int _timeOut;
    typedef std:map<std::string, ZooKeeperEventHandler *> EvnetHandlerMap;
    EventHandlerMap _eventHandlermap;
    ZooKeeperStat _stat;
};

} // namespace

#endif // ZOOKEEPERMANGER_H_
