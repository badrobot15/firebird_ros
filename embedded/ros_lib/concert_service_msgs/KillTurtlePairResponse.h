#ifndef _ROS_concert_service_msgs_KillTurtlePairResponse_h
#define _ROS_concert_service_msgs_KillTurtlePairResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "concert_service_msgs/KillTurtleResponse.h"

namespace concert_service_msgs
{

  class KillTurtlePairResponse : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      concert_service_msgs::KillTurtleResponse response;

    KillTurtlePairResponse():
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

    const char * getType(){ return "concert_service_msgs/KillTurtlePairResponse"; };
    const char * getMD5(){ return "2d12e3db65db9ae3b7de64597c1f0f15"; };

  };

}
#endif