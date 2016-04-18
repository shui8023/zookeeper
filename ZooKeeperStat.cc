/*
 * ZooKeeperStat.cc -- 
 *
 * Authors:
 *     shuidu(dubingyangxiyou@gmail.com), 04/15/16 10:14:06
 *
 */

#include "ZooKeeperStat.h"

namespace ZooKeeper {

ZooKeeperStat::ZooKeeperStat(const Stat &stat): _stat(stat) {

}

ZooKeeperStat::~ZooKeeperStat() {

}

int32_t ZooKeeperStat::GetAversion() const {
    return _stat.aversion;
}

int64_t ZooKeeperStat::GetCtime() const {
    return _stat.ctime;
}

int32_t ZooKeeperStat::GetCversion() const {
    return _stat.cversion;
}

int64_t ZooKeeperStat::GetCzxid() const {
    return _stat.czxid;
}

int32_t ZooKeeperStat::GetDataLength() const {
    return _stat.dataLength;
}

int64_t ZooKeeperStat::GetEphemeralOwner() const {
    return _stat.ephemeralOwner;
}

int64_t ZooKeeperStat::GetMzxid() const {
    return _stat.mzxid;
}

int32_t ZooKeeperStat::GetNumChildren() const {
    return _stat.numChildren;
}

int64_t ZooKeeperStat::GetPzxid() const {
    return _stat.pzxid;
}

int32_t ZooKeeperStat::GetVersion() const {
    return _stat.version;
}
Stat ZooKeeperStat::GetStat() const {
    return _stat;
}

}
