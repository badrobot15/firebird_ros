#ifndef _ROS_concert_service_msgs_SpawnTurtlePairResponse_h
#define _ROS_concert_service_msgs_SpawnTurtlePairResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "concert_service_msgs/SpawnTurtleResponse.h"

namespace concert_service_msgs
{

  class SpawnTurtlePairResponse : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      concert_service_msgs::SpawnTurtleResponse response;

    SpawnTurtlePairResponse():
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

    const char * getType(){ return "concert_service_msgs/SpawnTurtlePairResponse"; };
    const char * getMD5(){ return "d5742d0ce5f2bef0a88989c31cd56f59"; };

  };

}
#endif