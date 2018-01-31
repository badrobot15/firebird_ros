#ifndef _ROS_firebird_IR_h
#define _ROS_firebird_IR_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace firebird
{

  class IR : public ros::Msg
  {
    public:
      typedef uint16_t _ir1_type;
      _ir1_type ir1;
      typedef uint16_t _ir2_type;
      _ir2_type ir2;
      typedef uint16_t _ir3_type;
      _ir3_type ir3;
      typedef uint16_t _ir4_type;
      _ir4_type ir4;
      typedef uint16_t _ir5_type;
      _ir5_type ir5;
      typedef uint16_t _ir6_type;
      _ir6_type ir6;
      typedef uint16_t _ir7_type;
      _ir7_type ir7;
      typedef uint16_t _ir8_type;
      _ir8_type ir8;

    IR():
      ir1(0),
      ir2(0),
      ir3(0),
      ir4(0),
      ir5(0),
      ir6(0),
      ir7(0),
      ir8(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ir1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir1);
      *(outbuffer + offset + 0) = (this->ir2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir2 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir2);
      *(outbuffer + offset + 0) = (this->ir3 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir3 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir3);
      *(outbuffer + offset + 0) = (this->ir4 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir4 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir4);
      *(outbuffer + offset + 0) = (this->ir5 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir5 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir5);
      *(outbuffer + offset + 0) = (this->ir6 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir6 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir6);
      *(outbuffer + offset + 0) = (this->ir7 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir7 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir7);
      *(outbuffer + offset + 0) = (this->ir8 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ir8 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ir8);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->ir1 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir1);
      this->ir2 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir2 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir2);
      this->ir3 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir3 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir3);
      this->ir4 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir4 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir4);
      this->ir5 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir5 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir5);
      this->ir6 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir6 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir6);
      this->ir7 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir7 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir7);
      this->ir8 =  ((uint16_t) (*(inbuffer + offset)));
      this->ir8 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ir8);
     return offset;
    }

    const char * getType(){ return "firebird/IR"; };
    const char * getMD5(){ return "f152f0f07de80e13c3b902b872742f05"; };

  };

}
#endif