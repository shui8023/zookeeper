/*
 * ZooKeeperStat.h -- 
 *
 * Authors:
 *     shuidu(|EMAIL)|, 04/15/16 09:55:12
 *
 */

#ifndef ZOOKEEPERSTAT_H_
#define ZOOKEEPERSTAT_H_

#include "zookeeper.h"
#include "zookeeper_log.h"
#include "proto.h"
#include "recordio.h"
#include "zookeeper_version.h"
#include "zookeeper.jute.h"

/* C++11 */
#include <cstdint> 

namespace ZooKeeper {
class ZooKeeperStat {
public:
    ZooKeeperStat(const Stat &stat);
    ZooKeeperStat();
    ZooKeeperStat& operator=(const Stat &stat);
    ~ZooKeeperStat();
    int32_t GetAversion() const;
    int64_t GetCtime() const;
    int32_t GetCversion() const;
    int64_t GetCzxid() const;
    int32_t GetDataLength() const;
    int64_t GetEphemeralOwner() const;
    int64_t GetMtime() const;
    int64_t GetMzxid() const;
    int32_t GetNumChildren() const;
    int64_t GetPzxid() const;
    int32_t GetVersion() const;
    Stat GetStat() const;
private:
    Stat _stat;
};

} //namespace

#endif 

