#ifndef _ROS_firebird_Sharp_h
#define _ROS_firebird_Sharp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace firebird
{

  class Sharp : public ros::Msg
  {
    public:
      typedef uint16_t _sharp1_type;
      _sharp1_type sharp1;
      typedef uint16_t _sharp2_type;
      _sharp2_type sharp2;
      typedef uint16_t _sharp3_type;
      _sharp3_type sharp3;
      typedef uint16_t _sharp4_type;
      _sharp4_type sharp4;
      typedef uint16_t _sharp5_type;
      _sharp5_type sharp5;

    Sharp():
      sharp1(0),
      sharp2(0),
      sharp3(0),
      sharp4(0),
      sharp5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sharp1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sharp1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sharp1);
      *(outbuffer + offset + 0) = (this->sharp2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sharp2 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sharp2);
      *(outbuffer + offset + 0) = (this->sharp3 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sharp3 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sharp3);
      *(outbuffer + offset + 0) = (this->sharp4 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sharp4 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sharp4);
      *(outbuffer + offset + 0) = (this->sharp5 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sharp5 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sharp5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->sharp1 =  ((uint16_t) (*(inbuffer + offset)));
      this->sharp1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sharp1);
      this->sharp2 =  ((uint16_t) (*(inbuffer + offset)));
      this->sharp2 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sharp2);
      this->sharp3 =  ((uint16_t) (*(inbuffer + offset)));
      this->sharp3 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sharp3);
      this->sharp4 =  ((uint16_t) (*(inbuffer + offset)));
      this->sharp4 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sharp4);
      this->sharp5 =  ((uint16_t) (*(inbuffer + offset)));
      this->sharp5 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sharp5);
     return offset;
    }

    const char * getType(){ return "firebird/Sharp"; };
    const char * getMD5(){ return "9b55274f07e0034a2b2f4d4b4436aac6"; };

  };

}
#endif