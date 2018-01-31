#ifndef _ROS_concert_service_msgs_KillTurtlePairRequest_h
#define _ROS_concert_service_msgs_KillTurtlePairRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "concert_service_msgs/KillTurtleRequest.h"

namespace concert_service_msgs
{

  class KillTurtlePairRequest : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      concert_service_msgs::KillTurtleRequest request;

    KillTurtlePairRequest():
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

    const char * getType(){ return "concert_service_msgs/KillTurtlePairRequest"; };
    const char * getMD5(){ return "0f974aecea7bf5add789608093b710e2"; };

  };

}
#endif