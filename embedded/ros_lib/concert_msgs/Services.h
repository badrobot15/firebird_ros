#ifndef _ROS_concert_msgs_Services_h
#define _ROS_concert_msgs_Services_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/ServiceProfile.h"

namespace concert_msgs
{

  class Services : public ros::Msg
  {
    public:
      uint8_t services_length;
      concert_msgs::ServiceProfile st_services;
      concert_msgs::ServiceProfile * services;

    Services():
      services_length(0), services(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = services_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < services_length; i++){
      offset += this->services[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t services_lengthT = *(inbuffer + offset++);
      if(services_lengthT > services_length)
        this->services = (concert_msgs::ServiceProfile*)realloc(this->services, services_lengthT * sizeof(concert_msgs::ServiceProfile));
      offset += 3;
      services_length = services_lengthT;
      for( uint8_t i = 0; i < services_length; i++){
      offset += this->st_services.deserialize(inbuffer + offset);
        memcpy( &(this->services[i]), &(this->st_services), sizeof(concert_msgs::ServiceProfile));
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/Services"; };
    const char * getMD5(){ return "385406088e57b4886d05051733612cb1"; };

  };

}
#endif