#ifndef _ROS_concert_service_msgs_CaptureResourcePairRequest_h
#define _ROS_concert_service_msgs_CaptureResourcePairRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "concert_service_msgs/CaptureResourceRequest.h"

namespace concert_service_msgs
{

  class CaptureResourcePairRequest : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      concert_service_msgs::CaptureResourceRequest request;

    CaptureResourcePairRequest():
      id(),
      request()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      offset += this->request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->request.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "concert_service_msgs/CaptureResourcePairRequest"; };
    const char * getMD5(){ return "70e7b6a649a463eaffc6444527dec77e"; };

  };

}
#endif