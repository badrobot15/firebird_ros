#ifndef _ROS_concert_service_msgs_KillTurtleResponse_h
#define _ROS_concert_service_msgs_KillTurtleResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_service_msgs
{

  class KillTurtleResponse : public ros::Msg
  {
    public:

    KillTurtleResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "concert_service_msgs/KillTurtleResponse"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif