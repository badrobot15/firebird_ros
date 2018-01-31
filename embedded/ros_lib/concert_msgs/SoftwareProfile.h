#ifndef _ROS_concert_msgs_SoftwareProfile_h
#define _ROS_concert_msgs_SoftwareProfile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/KeyValue.h"

namespace concert_msgs
{

  class SoftwareProfile : public ros::Msg
  {
    public:
      const char* resource_name;
      const char* name;
      const char* description;
      const char* author;
      const char* launch;
      int16_t max_count;
      uint8_t parameters_length;
      rocon_std_msgs::KeyValue st_parameters;
      rocon_std_msgs::KeyValue * parameters;

    SoftwareProfile():
      resource_name(""),
      name(""),
      description(""),
      author(""),
      launch(""),
      max_count(0),
      parameters_length(0), parameters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_resource_name = strlen(this->resource_name);
      memcpy(outbuffer + offset, &length_resource_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->resource_name, length_resource_name);
      offset += length_resource_name;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_description = strlen(this->description);
      memcpy(outbuffer + offset, &length_description, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      uint32_t length_author = strlen(this->author);
      memcpy(outbuffer + offset, &length_author, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->author, length_author);
      offset += length_author;
      uint32_t length_launch = strlen(this->launch);
      memcpy(outbuffer + offset, &length_launch, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->launch, length_launch);
      offset += length_launch;
      union {
        int16_t real;
        uint16_t base;
      } u_max_count;
      u_max_count.real = this->max_count;
      *(outbuffer + offset + 0) = (u_max_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_count.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->max_count);
      *(outbuffer + offset++) = parameters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_resource_name;
      memcpy(&length_resource_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_resource_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_resource_name-1]=0;
      this->resource_name = (char *)(inbuffer + offset-1);
      offset += length_resource_name;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_description;
      memcpy(&length_description, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t length_author;
      memcpy(&length_author, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_author; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_author-1]=0;
      this->author = (char *)(inbuffer + offset-1);
      offset += length_author;
      uint32_t length_launch;
      memcpy(&length_launch, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_launch; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_launch-1]=0;
      this->launch = (char *)(inbuffer + offset-1);
      offset += length_launch;
      union {
        int16_t real;
        uint16_t base;
      } u_max_count;
      u_max_count.base = 0;
      u_max_count.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_count.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_count = u_max_count.real;
      offset += sizeof(this->max_count);
      uint8_t parameters_lengthT = *(inbuffer + offset++);
      if(parameters_lengthT > parameters_length)
        this->parameters = (rocon_std_msgs::KeyValue*)realloc(this->parameters, parameters_lengthT * sizeof(rocon_std_msgs::KeyValue));
      offset += 3;
      parameters_length = parameters_lengthT;
      for( uint8_t i = 0; i < parameters_length; i++){
      offset += this->st_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(rocon_std_msgs::KeyValue));
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/SoftwareProfile"; };
    const char * getMD5(){ return "ae0fcd28b11be06d5ad15aafa639856a"; };

  };

}
#endif