/*
 * ZooKeeperManager.cc -- 
 *
 * Version:
 * 
 * Authors:
 *     shuidu(shuidu@tencent.com), 04/15/16 19:45
 *
 */

#include "ZooKeeperManager.h"
#include "ZooKeeperEvent.h"

namespace ZooKeeper {

ZooKeeperManager::ZooKeeperManager(const std::string &host, int connectionTimeout)
            :_host(host), _timeOut(connectionTimeout), _isInit(false), _handle(NULL) {
       

}

ZooKeeperManager::ZooKeeperManager()
            :_host(""), _timeOut(0), _isInit(false), _handle(NULL) {
}

ZooKeeperManager::~ZooKeeperManager() {
    if (_isInit) {
        if (_handle != NULL) {
            int result = zookeeper_close(_handle);           
            if (result != ZOK) {
                throw ZooKeeperException(result);
            }
        }
    }
}

int ZooKeeperManager::Initialize(const std::string &host, int connectionTimeout) {
    if (!_isInit) {
        _host = host;
        _timeOut = connectionTimeout;

        _handle = zookeeper_init(host.c_str(), ZooKeeperEvent::EventHandler, 
                            connectionTimeout, NULL, this, 0);
        if (_handle == NULL) {
            return -1;
        }
        _isInit = true;
    }

    return 0;
}

int ZooKeeperManager::RegisterEventHandler(ZooKeeperEventHandler *eventhandler) {
    
}

const std::string& ZookeeperManager::GetHost() const {
    return _host;
}

int ZooKeeperManager::GetConnectionTimeout() const {
    return _timeOut;
}

void ZooKeeperManager::FireEvent(zhandle_t *zhandle, int state);

int ZooKeeperManager::CreateNode(const std::string &path, const std::string &data, int flag) {
    int result;
    result = zoo_create(_handle, path.c_str(), data.c_str(), data.size(), &ZOO_OPEN_ACL_UNSAFE, flag);

    return result;
}

int ZooKeeperManager::CreateSequenNode(const std::string &path, const std::string &data, const std::string &nodeName) {
    int result;
    char sequencedPath[MAX_PATH_BUFFER];

    result = zoo_create(_handle, path.c_str(), data.c_str(), &ZOO_OPEN_ACL_UNSAFE, flag, sequencedPath);
    
    if (result == ZOK) {
        nodeName = std::string(sequencedPath, strlen(sequencedPath));
    }

    return result;
}

int ZooKeeperManager::GetNode(const std::string &path, std::string &data) {
    char buffer[MAX_DATA_BUFFER];
    int length = MAX_DATA_BUFFER;
    int result;

    result = zoo_wget(_handle, path.c_str(), NULL, NULL, buffer, &length, &_stat.GetStat());
    if (result == ZOK) {
        data = std::string(buffer, strlen(buffer));
    }

    return result;
}

int ZooKeeperManager::GetNode(const std::string &path, std::string &data, ZooKeeperEventHandler *eventhandler) {
    InSert(path, eventhandler);

    char buffer[MAX_DATA_BUFFER];
    int length = MAX_DATA_BUFFER;
    int result;

    result = zoo_wget(_handle, path.c_str(), eventhandler,  this, buffer, &length, &_stat.GetStat());
    if (result == ZOK) {
        data = std::string(buffer, strlen(buffer));
    }

    return result;
}

int ZooKeeperManager::GetNodeChildren(const std::string &path, std::vector<std::string> childrenName) {
    String_vector stringvector;
    int result;

    result = zoo_wget_children2(_handle, path.c_str(), NULL, NULL, &stringvector, &_stat._stat);
    if (result == ZOK) {
        for (uint32_t i = 0; i != stringvector.count; i++) {
            childrenName.push_back(stringvector.data[i]);
        }
    }

    return result;
}

int ZooKeeperManager::GetNodeChildren(const std::string &path, std::vector<std::string> childrenName,
                    ZooKeeperEventHandler *eventhandler) {
    String_vector stringvector;
    int result;

    result = zoo_wget_children2(_handle, path.c_str(), eventhandler, this, &stringvector, &_stat._stat);
    if (result == ZOK) {
        for (uint32_t i = 0; i != stringvector.count; i++) {
            childrenName.push_back(stringvector.data[i]);
        }
    }

    return result;
}
int ZooKeeperManager::SetNode(const std::string &path, const std::string &data) {
    int result;

    result = zoo_set2(_handle, path.c_str(), data.c_str(), data.size(), -1, &_stat._stat);

    return result;
}

int ZooKeeperManager::DeleteNode(const std::string &path) {
   int result;
   
   result = zoo_delete(_handle, path.c_str(), -1);

   return result;
}

int ZooKeeperManager::AddEventHandler(const std::string &path, ZooKeeperEventHandler *eventhandler) {
    Insert(path, eventhandler);
    int result;

    result = zoo_wexists(_handle, path.c_str(), ZooKeeperEvent::EventHandler, this, &_stat._stat);

    return result;
}

bool ZooKeeperManager::RemoveEventHandler(const std::string &path) {
    bool result;

    result = Rrase(path);

    return result;
}

bool ZooKeeperManager::Insert(const std:string &path, ZooKeeperEventHandler * eventHandler) {
    auto result = _eventHandlermap.insert(std::make_pair(path, eventHandler));
//    std::pair<iterator, bool>
    return result.second;
}
bool ZooKeeperManager::Erase(const std::string &path) {
    bool result = false;
    
    auto it = _eventHandlermap.find(path);
    if (it != _eventHandlermap.end()) {
        _eventHandlermap.erase(it);
        result = true;
    }

    return result;
}

} // namespace
