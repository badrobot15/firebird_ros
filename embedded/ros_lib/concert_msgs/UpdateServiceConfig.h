#ifndef _ROS_SERVICE_UpdateServiceConfig_h
#define _ROS_SERVICE_UpdateServiceConfig_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/ServiceProfile.h"

namespace concert_msgs
{

static const char UPDATESERVICECONFIG[] = "concert_msgs/UpdateServiceConfig";

  class UpdateServiceConfigRequest : public ros::Msg
  {
    public:
      concert_msgs::ServiceProfile service_profile;

    UpdateServiceConfigRequest():
      service_profile()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->service_profile.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->service_profile.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return UPDATESERVICECONFIG; };
    const char * getMD5(){ return "d91b5c9853bc0d14302939f48cf1cf3e"; };

  };

  class UpdateServiceConfigResponse : public ros::Msg
  {
    public:
      bool success;
      const char* error_message;

    UpdateServiceConfigResponse():
      success(0),
      error_message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_error_message = strlen(this->error_message);
      memcpy(outbuffer + offset, &length_error_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_error_message;
      memcpy(&length_error_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
     return offset;
    }

    const char * getType(){ return UPDATESERVICECONFIG; };
    const char * getMD5(){ return "6fe914479ce03184a758c3f6990c928f"; };

  };

  class UpdateServiceConfig {
    public:
    typedef UpdateServiceConfigRequest Request;
    typedef UpdateServiceConfigResponse Response;
  };

}
#endif
