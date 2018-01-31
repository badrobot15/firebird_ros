#ifndef _ROS_concert_service_msgs_CaptureResourcePair_h
#define _ROS_concert_service_msgs_CaptureResourcePair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_service_msgs/CaptureResourcePairRequest.h"
#include "concert_service_msgs/CaptureResourcePairResponse.h"

namespace concert_service_msgs
{

  class CaptureResourcePair : public ros::Msg
  {
    public:
      concert_service_msgs::CaptureResourcePairRequest pair_request;
      concert_service_msgs::CaptureResourcePairResponse pair_response;

    CaptureResourcePair():
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

    const char * getType(){ return "concert_service_msgs/CaptureResourcePair"; };
    const char * getMD5(){ return "119d2731866ad230a6fd7e87d8a22b1f"; };

  };

}
#endif