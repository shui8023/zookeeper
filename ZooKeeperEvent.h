/*
 * ZooKeeperEvent.h -- 
 *
 * Authors:
 *     shuidu(|EMAIL)|, 04/15/16 15:31:25
 *
 */

#ifndef ZOOKEEPEREVENT_H_
#define ZOOKEEPEREVENT_H_

#include "zookeeper.h"
#include "zookeeper_log.h"
#include "proto.h"
#include "recordio.h"
#include "zookeeper_version.h"
#include "zookeeper.jute.h"

namespace ZooKeeper{

class ZooKeeperEvent {
public:
    static void EventHandler(zhandle_t *zhandle, int type, int state, const char *path, void *userData);
};
} // ZooKeeper
#endif 
