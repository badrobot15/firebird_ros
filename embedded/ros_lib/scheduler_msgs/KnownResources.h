#ifndef _ROS_scheduler_msgs_KnownResources_h
#define _ROS_scheduler_msgs_KnownResources_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "scheduler_msgs/CurrentStatus.h"

namespace scheduler_msgs
{

  class KnownResources : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t resources_length;
      scheduler_msgs::CurrentStatus st_resources;
      scheduler_msgs::CurrentStatus * resources;

    KnownResources():
      header(),
      resources_length(0), resources(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = resources_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < resources_length; i++){
      offset += this->resources[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t resources_lengthT = *(inbuffer + offset++);
      if(resources_lengthT > resources_length)
        this->resources = (scheduler_msgs::CurrentStatus*)realloc(this->resources, resources_lengthT * sizeof(scheduler_msgs::CurrentStatus));
      offset += 3;
      resources_length = resources_lengthT;
      for( uint8_t i = 0; i < resources_length; i++){
      offset += this->st_resources.deserialize(inbuffer + offset);
        memcpy( &(this->resources[i]), &(this->st_resources), sizeof(scheduler_msgs::CurrentStatus));
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/KnownResources"; };
    const char * getMD5(){ return "d3e12e9eddf5fe98089b8d550ce49151"; };

  };

}
#endif