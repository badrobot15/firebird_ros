#ifndef _ROS_firebird_Lcd_h
#define _ROS_firebird_Lcd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace firebird
{

  class Lcd : public ros::Msg
  {
    public:
      typedef uint8_t _row_type;
      _row_type row;
      typedef uint8_t _col_type;
      _col_type col;
      typedef const char* _val_type;
      _val_type val;

    Lcd():
      row(1),
      col(1),
      val("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->row >> (8 * 0)) & 0xFF;
      offset += sizeof(this->row);
      *(outbuffer + offset + 0) = (this->col >> (8 * 0)) & 0xFF;
      offset += sizeof(this->col);
      uint32_t length_val = strlen(this->val);
      varToArr(outbuffer + offset, length_val);
      offset += 4;
      memcpy(outbuffer + offset, this->val, length_val);
      offset += length_val;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->row =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->row);
      this->col =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->col);
      uint32_t length_val;
      arrToVar(length_val, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_val; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_val-1]=0;
      this->val = (char *)(inbuffer + offset-1);
      offset += length_val;
     return offset;
    }

    const char * getType(){ return "firebird/Lcd"; };
    const char * getMD5(){ return "5bd7a07814989824c425f713eeb625da"; };

  };

}
#endif