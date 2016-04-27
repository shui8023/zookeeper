/*
 * ZooKeeperEvent.cc -- 
 *
 * Authors:
 *     shuidu(dubingyangxiyou@gmail.com), 04/19/2016 07:15:01 PM
 *
 */

#include "ZooKeeperEvent.h"
#include "ZooKeeperManager.h"

namespace ZooKeeper {

void ZooKeeperEvent::EventHandler(zhandle_t *zhandle, int type, int state, const char *path, void *userData) {
    if (userData != NULL) {
        ZooKeeperManager *zk = reinterpret_cast<ZooKeeperManager *>(userData);
        zk->FireEvent(zhandle, state, type, path);
    }   
}

} //namespace 
