#ifndef _ROS_concert_msgs_SoftwareInstance_h
#define _ROS_concert_msgs_SoftwareInstance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/KeyValue.h"

namespace concert_msgs
{

  class SoftwareInstance : public ros::Msg
  {
    public:
      const char* resource_name;
      const char* name;
      int16_t max_count;
      const char* namespace;
      uint8_t users_length;
      char* st_users;
      char* * users;
      uint8_t parameters_length;
      rocon_std_msgs::KeyValue st_parameters;
      rocon_std_msgs::KeyValue * parameters;

    SoftwareInstance():
      resource_name(""),
      name(""),
      max_count(0),
      namespace(""),
      users_length(0), users(NULL),
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
      union {
        int16_t real;
        uint16_t base;
      } u_max_count;
      u_max_count.real = this->max_count;
      *(outbuffer + offset + 0) = (u_max_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_count.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->max_count);
      uint32_t length_namespace = strlen(this->namespace);
      memcpy(outbuffer + offset, &length_namespace, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->namespace, length_namespace);
      offset += length_namespace;
      *(outbuffer + offset++) = users_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < users_length; i++){
      uint32_t length_usersi = strlen(this->users[i]);
      memcpy(outbuffer + offset, &length_usersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->users[i], length_usersi);
      offset += length_usersi;
      }
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
      union {
        int16_t real;
        uint16_t base;
      } u_max_count;
      u_max_count.base = 0;
      u_max_count.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_count.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_count = u_max_count.real;
      offset += sizeof(this->max_count);
      uint32_t length_namespace;
      memcpy(&length_namespace, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_namespace; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_namespace-1]=0;
      this->namespace = (char *)(inbuffer + offset-1);
      offset += length_namespace;
      uint8_t users_lengthT = *(inbuffer + offset++);
      if(users_lengthT > users_length)
        this->users = (char**)realloc(this->users, users_lengthT * sizeof(char*));
      offset += 3;
      users_length = users_lengthT;
      for( uint8_t i = 0; i < users_length; i++){
      uint32_t length_st_users;
      memcpy(&length_st_users, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_users; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_users-1]=0;
      this->st_users = (char *)(inbuffer + offset-1);
      offset += length_st_users;
        memcpy( &(this->users[i]), &(this->st_users), sizeof(char*));
      }
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

    const char * getType(){ return "concert_msgs/SoftwareInstance"; };
    const char * getMD5(){ return "d51f42200dcf594007d5fbba6c47cfe9"; };

  };

}
#endif