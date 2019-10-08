#ifndef VREP_ROS_INTERFACE_H_INCLUDED
#define VREP_ROS_INTERFACE_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#include <boost/lexical_cast.hpp>
#include <boost/any.hpp>

#include "config.h"

//#include <image_transport/image_transport.h>

#define PLUGIN_NAME "RosInterface"
#define PLUGIN_VERSION 5

struct ScriptCallback
{
    int scriptId;
    std::string name;
};

struct Proxy
{
    bool destroyAfterSimulationStop;
};

#include <ros_msg_builtin_io.h>

struct SubscriberProxy : Proxy
{
    int handle;
    std::string topicName;
    std::string topicType;
    ScriptCallback topicCallback;
    boost::any subscription;
    //image_transport::Subscriber imageTransportSubscriber;
    WriteOptions wr_opt;
};

struct PublisherProxy : Proxy
{
    int handle;
    std::string topicName;
    std::string topicType;
    boost::any publisher;
    //image_transport::Publisher imageTransportPublisher;
    ReadOptions rd_opt;
};

struct ServiceClientProxy : Proxy
{
    int handle;
    std::string serviceName;
    std::string serviceType;
    boost::any client;
    ReadOptions rd_opt;
    WriteOptions wr_opt;
};

struct ServiceServerProxy : Proxy
{
    int handle;
    std::string serviceName;
    std::string serviceType;
    ScriptCallback serviceCallback;
    boost::any service;
    ReadOptions rd_opt;
    WriteOptions wr_opt;
};

#include <stubs.h>
#include <callbacks.h>

#endif // VREP_ROS_INTERFACE_H_INCLUDED
