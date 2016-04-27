#compiler the zookeeper api


TARGET=test_zookeeper.cc

OBJECTS=$(shell find ../ -name "*.cc")


FLAG=-I /usr/local/include/zookeeper -l zookeeper_mt -std=c++11

GCC=g++

INCLUDE= -I ../

all:
	$(GCC) $(OBJECTS) $(TARGET) $(FLAG) $(INCLUDE)
