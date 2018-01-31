#ifndef _ROS_scheduler_msgs_CurrentStatus_h
#define _ROS_scheduler_msgs_CurrentStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"

namespace scheduler_msgs
{

  class CurrentStatus : public ros::Msg
  {
    public:
      const char* uri;
      uint8_t status;
      uuid_msgs::UniqueID owner;
      int16_t priority;
      uint8_t rapps_length;
      char* st_rapps;
      char* * rapps;
      enum { AVAILABLE =  0    };
      enum { ALLOCATED =  1    };
      enum { MISSING =  2    };
      enum { GONE =  3    };

    CurrentStatus():
      uri(""),
      status(0),
      owner(),
      priority(0),
      rapps_length(0), rapps(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_uri = strlen(this->uri);
      memcpy(outbuffer + offset, &length_uri, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uri, length_uri);
      offset += length_uri;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      offset += this->owner.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_priority.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->priority);
      *(outbuffer + offset++) = rapps_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rapps_length; i++){
      uint32_t length_rappsi = strlen(this->rapps[i]);
      memcpy(outbuffer + offset, &length_rappsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rapps[i], length_rappsi);
      offset += length_rappsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_uri;
      memcpy(&length_uri, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uri-1]=0;
      this->uri = (char *)(inbuffer + offset-1);
      offset += length_uri;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      offset += this->owner.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
      uint8_t rapps_lengthT = *(inbuffer + offset++);
      if(rapps_lengthT > rapps_length)
        this->rapps = (char**)realloc(this->rapps, rapps_lengthT * sizeof(char*));
      offset += 3;
      rapps_length = rapps_lengthT;
      for( uint8_t i = 0; i < rapps_length; i++){
      uint32_t length_st_rapps;
      memcpy(&length_st_rapps, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_rapps; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_rapps-1]=0;
      this->st_rapps = (char *)(inbuffer + offset-1);
      offset += length_st_rapps;
        memcpy( &(this->rapps[i]), &(this->st_rapps), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/CurrentStatus"; };
    const char * getMD5(){ return "6aad8a50fb8e5cf19eb4622c1c4b6467"; };

  };

}
#endif