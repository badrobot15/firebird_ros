#ifndef _ROS_firebird_WLS_h
#define _ROS_firebird_WLS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace firebird
{

  class WLS : public ros::Msg
  {
    public:
      typedef uint16_t _wls1_type;
      _wls1_type wls1;
      typedef uint16_t _wls2_type;
      _wls2_type wls2;
      typedef uint16_t _wls3_type;
      _wls3_type wls3;

    WLS():
      wls1(0),
      wls2(0),
      wls3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->wls1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wls1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wls1);
      *(outbuffer + offset + 0) = (this->wls2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wls2 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wls2);
      *(outbuffer + offset + 0) = (this->wls3 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wls3 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wls3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->wls1 =  ((uint16_t) (*(inbuffer + offset)));
      this->wls1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->wls1);
      this->wls2 =  ((uint16_t) (*(inbuffer + offset)));
      this->wls2 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->wls2);
      this->wls3 =  ((uint16_t) (*(inbuffer + offset)));
      this->wls3 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->wls3);
     return offset;
    }

    const char * getType(){ return "firebird/WLS"; };
    const char * getMD5(){ return "183222e4ddf0c8e85a20fc76ccf581b9"; };

  };

}
#endif