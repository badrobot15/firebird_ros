#ifndef _ROS_concert_service_msgs_CaptureResourcePairResponse_h
#define _ROS_concert_service_msgs_CaptureResourcePairResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "concert_service_msgs/CaptureResourceResponse.h"

namespace concert_service_msgs
{

  class CaptureResourcePairResponse : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      concert_service_msgs::CaptureResourceResponse response;

    CaptureResourcePairResponse():
      id(),
      response()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      offset += this->response.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      offset += this->response.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "concert_service_msgs/CaptureResourcePairResponse"; };
    const char * getMD5(){ return "173d52f12f1f234789c59ba574370e5b"; };

  };

}
#endif