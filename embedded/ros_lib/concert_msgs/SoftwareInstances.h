#ifndef _ROS_concert_msgs_SoftwareInstances_h
#define _ROS_concert_msgs_SoftwareInstances_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/SoftwareInstance.h"

namespace concert_msgs
{

  class SoftwareInstances : public ros::Msg
  {
    public:
      uint8_t instances_length;
      concert_msgs::SoftwareInstance st_instances;
      concert_msgs::SoftwareInstance * instances;

    SoftwareInstances():
      instances_length(0), instances(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = instances_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < instances_length; i++){
      offset += this->instances[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t instances_lengthT = *(inbuffer + offset++);
      if(instances_lengthT > instances_length)
        this->instances = (concert_msgs::SoftwareInstance*)realloc(this->instances, instances_lengthT * sizeof(concert_msgs::SoftwareInstance));
      offset += 3;
      instances_length = instances_lengthT;
      for( uint8_t i = 0; i < instances_length; i++){
      offset += this->st_instances.deserialize(inbuffer + offset);
        memcpy( &(this->instances[i]), &(this->st_instances), sizeof(concert_msgs::SoftwareInstance));
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/SoftwareInstances"; };
    const char * getMD5(){ return "3db13b2ea7c2b945782f742cf7b4ac03"; };

  };

}
#endif