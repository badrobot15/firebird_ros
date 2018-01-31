#ifndef _ROS_concert_service_msgs_CaptureResourceRequest_h
#define _ROS_concert_service_msgs_CaptureResourceRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_service_msgs
{

  class CaptureResourceRequest : public ros::Msg
  {
    public:
      const char* rocon_uri;
      bool release;

    CaptureResourceRequest():
      rocon_uri(""),
      release(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_rocon_uri = strlen(this->rocon_uri);
      memcpy(outbuffer + offset, &length_rocon_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rocon_uri, length_rocon_uri);
      offset += length_rocon_uri;
      union {
        bool real;
        uint8_t base;
      } u_release;
      u_release.real = this->release;
      *(outbuffer + offset + 0) = (u_release.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->release);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_rocon_uri;
      memcpy(&length_rocon_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rocon_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rocon_uri-1]=0;
      this->rocon_uri = (char *)(inbuffer + offset-1);
      offset += length_rocon_uri;
      union {
        bool real;
        uint8_t base;
      } u_release;
      u_release.base = 0;
      u_release.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->release = u_release.real;
      offset += sizeof(this->release);
     return offset;
    }

    const char * getType(){ return "concert_service_msgs/CaptureResourceRequest"; };
    const char * getMD5(){ return "9ef24df11d8c425fa509296ab551e5d4"; };

  };

}
#endif