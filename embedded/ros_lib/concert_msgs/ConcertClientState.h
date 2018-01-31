#ifndef _ROS_concert_msgs_ConcertClientState_h
#define _ROS_concert_msgs_ConcertClientState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_msgs
{

  class ConcertClientState : public ros::Msg
  {
    public:
      enum { PENDING =  pending };
      enum { BAD =  bad };
      enum { BLOCKING =  blocking };
      enum { BUSY =  busy };
      enum { UNINVITED =  uninvited };
      enum { JOINING =  joining };
      enum { AVAILABLE =  available };
      enum { MISSING =  missing };
      enum { GONE =  gone };

    ConcertClientState()
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

    const char * getType(){ return "concert_msgs/ConcertClientState"; };
    const char * getMD5(){ return "216b7a80921438395a695bb265efcaf1"; };

  };

}
#endif