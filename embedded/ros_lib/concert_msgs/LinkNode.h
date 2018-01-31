#ifndef _ROS_concert_msgs_LinkNode_h
#define _ROS_concert_msgs_LinkNode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/KeyValue.h"

namespace concert_msgs
{

  class LinkNode : public ros::Msg
  {
    public:
      const char* id;
      const char* resource;
      int8_t min;
      int8_t max;
      bool force_name_matching;
      rocon_std_msgs::KeyValue parameters;
      enum { UNLIMITED_RESOURCE = -1 };

    LinkNode():
      id(""),
      resource(""),
      min(0),
      max(0),
      force_name_matching(0),
      parameters()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_resource = strlen(this->resource);
      memcpy(outbuffer + offset, &length_resource, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->resource, length_resource);
      offset += length_resource;
      union {
        int8_t real;
        uint8_t base;
      } u_min;
      u_min.real = this->min;
      *(outbuffer + offset + 0) = (u_min.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->min);
      union {
        int8_t real;
        uint8_t base;
      } u_max;
      u_max.real = this->max;
      *(outbuffer + offset + 0) = (u_max.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->max);
      union {
        bool real;
        uint8_t base;
      } u_force_name_matching;
      u_force_name_matching.real = this->force_name_matching;
      *(outbuffer + offset + 0) = (u_force_name_matching.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->force_name_matching);
      offset += this->parameters.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_resource;
      memcpy(&length_resource, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_resource; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_resource-1]=0;
      this->resource = (char *)(inbuffer + offset-1);
      offset += length_resource;
      union {
        int8_t real;
        uint8_t base;
      } u_min;
      u_min.base = 0;
      u_min.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->min = u_min.real;
      offset += sizeof(this->min);
      union {
        int8_t real;
        uint8_t base;
      } u_max;
      u_max.base = 0;
      u_max.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->max = u_max.real;
      offset += sizeof(this->max);
      union {
        bool real;
        uint8_t base;
      } u_force_name_matching;
      u_force_name_matching.base = 0;
      u_force_name_matching.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->force_name_matching = u_force_name_matching.real;
      offset += sizeof(this->force_name_matching);
      offset += this->parameters.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "concert_msgs/LinkNode"; };
    const char * getMD5(){ return "66d27e37c29408b86c119285c34c50cd"; };

  };

}
#endif