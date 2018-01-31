#ifndef _ROS_firebird_Battery_h
#define _ROS_firebird_Battery_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace firebird
{

  class Battery : public ros::Msg
  {
    public:
      typedef uint16_t _bat_volt_type;
      _bat_volt_type bat_volt;

    Battery():
      bat_volt(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->bat_volt >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bat_volt >> (8 * 1)) & 0xFF;
      offset += sizeof(this->bat_volt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->bat_volt =  ((uint16_t) (*(inbuffer + offset)));
      this->bat_volt |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->bat_volt);
     return offset;
    }

    const char * getType(){ return "firebird/Battery"; };
    const char * getMD5(){ return "c6dd4d2dbec322eecca8a2d0d1fdf4d4"; };

  };

}
#endif