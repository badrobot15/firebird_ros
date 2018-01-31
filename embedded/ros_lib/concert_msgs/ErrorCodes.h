#ifndef _ROS_concert_msgs_ErrorCodes_h
#define _ROS_concert_msgs_ErrorCodes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_msgs
{

  class ErrorCodes : public ros::Msg
  {
    public:
      enum { SUCCESS =  0 };
      enum { SERVICE_UNEXPECTED_ERROR =  31 };
      enum { SERVICE_INSUFFICIENT_CLIENTS =  32 };
      enum { SERVICE_NOT_READY =  33 };

    ErrorCodes()
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

    const char * getType(){ return "concert_msgs/ErrorCodes"; };
    const char * getMD5(){ return "850c35c6305cee69bf981dadb8ebd51c"; };

  };

}
#endif