#ifndef _ROS_concert_service_msgs_SpawnTurtlePair_h
#define _ROS_concert_service_msgs_SpawnTurtlePair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_service_msgs/SpawnTurtlePairRequest.h"
#include "concert_service_msgs/SpawnTurtlePairResponse.h"

namespace concert_service_msgs
{

  class SpawnTurtlePair : public ros::Msg
  {
    public:
      concert_service_msgs::SpawnTurtlePairRequest pair_request;
      concert_service_msgs::SpawnTurtlePairResponse pair_response;

    SpawnTurtlePair():
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

    const char * getType(){ return "concert_service_msgs/SpawnTurtlePair"; };
    const char * getMD5(){ return "d40647d6460ee3e522a284534a00ec9f"; };

  };

}
#endif