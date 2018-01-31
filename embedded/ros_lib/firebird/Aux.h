#ifndef _ROS_firebird_Aux_h
#define _ROS_firebird_Aux_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace firebird
{

  class Aux : public ros::Msg
  {
    public:
      typedef uint16_t _aux1_type;
      _aux1_type aux1;
      typedef uint16_t _aux2_type;
      _aux2_type aux2;

    Aux():
      aux1(0),
      aux2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->aux1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->aux1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->aux1);
      *(outbuffer + offset + 0) = (this->aux2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->aux2 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->aux2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->aux1 =  ((uint16_t) (*(inbuffer + offset)));
      this->aux1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->aux1);
      this->aux2 =  ((uint16_t) (*(inbuffer + offset)));
      this->aux2 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->aux2);
     return offset;
    }

    const char * getType(){ return "firebird/Aux"; };
    const char * getMD5(){ return "4f9ac417de999ed2d446d23039e12ccd"; };

  };

}
#endif