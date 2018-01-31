#ifndef _ROS_concert_service_msgs_KillTurtlePair_h
#define _ROS_concert_service_msgs_KillTurtlePair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_service_msgs/KillTurtlePairRequest.h"
#include "concert_service_msgs/KillTurtlePairResponse.h"

namespace concert_service_msgs
{

  class KillTurtlePair : public ros::Msg
  {
    public:
      concert_service_msgs::KillTurtlePairRequest pair_request;
      concert_service_msgs::KillTurtlePairResponse pair_response;

    KillTurtlePair():
      pair_request(),
      pair_response()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pair_request.serialize(outbuffer + offset);
      offset += this->pair_response.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pair_request.deserialize(inbuffer + offset);
      offset += this->pair_response.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "concert_service_msgs/KillTurtlePair"; };
    const char * getMD5(){ return "d7f05d5e41a7cb8b3cbf2ace791fdbe4"; };

  };

}
#endif