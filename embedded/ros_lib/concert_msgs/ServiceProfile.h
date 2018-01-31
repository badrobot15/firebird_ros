#ifndef _ROS_concert_msgs_ServiceProfile_h
#define _ROS_concert_msgs_ServiceProfile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/Icon.h"
#include "rocon_std_msgs/KeyValue.h"
#include "uuid_msgs/UniqueID.h"

namespace concert_msgs
{

  class ServiceProfile : public ros::Msg
  {
    public:
      const char* resource_name;
      const char* name;
      const char* description;
      const char* author;
      uint16_t priority;
      rocon_std_msgs::Icon icon;
      const char* launcher_type;
      const char* launcher;
      const char* interactions;
      const char* parameters;
      uint8_t parameters_detail_length;
      rocon_std_msgs::KeyValue st_parameters_detail;
      rocon_std_msgs::KeyValue * parameters_detail;
      uuid_msgs::UniqueID uuid;
      int16_t status;
      bool enabled;
      enum { TYPE_ROSLAUNCH =  roslaunch };
      enum { TYPE_CUSTOM =  custom };
      enum { TYPE_SHADOW =  shadow };

    ServiceProfile():
      resource_name(""),
      name(""),
      description(""),
      author(""),
      priority(0),
      icon(),
      launcher_type(""),
      launcher(""),
      interactions(""),
      parameters(""),
      parameters_detail_length(0), parameters_detail(NULL),
      uuid(),
      status(0),
      enabled(0)
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
      *(outbuffer + offset + 0) = (this->priority >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->priority >> (8 * 1)) & 0xFF;
      offset += sizeof(this->priority);
      offset += this->icon.serialize(outbuffer + offset);
      uint32_t length_launcher_type = strlen(this->launcher_type);
      memcpy(outbuffer + offset, &length_launcher_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->launcher_type, length_launcher_type);
      offset += length_launcher_type;
      uint32_t length_launcher = strlen(this->launcher);
      memcpy(outbuffer + offset, &length_launcher, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->launcher, length_launcher);
      offset += length_launcher;
      uint32_t length_interactions = strlen(this->interactions);
      memcpy(outbuffer + offset, &length_interactions, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->interactions, length_interactions);
      offset += length_interactions;
      uint32_t length_parameters = strlen(this->parameters);
      memcpy(outbuffer + offset, &length_parameters, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parameters, length_parameters);
      offset += length_parameters;
      *(outbuffer + offset++) = parameters_detail_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < parameters_detail_length; i++){
      offset += this->parameters_detail[i].serialize(outbuffer + offset);
      }
      offset += this->uuid.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.real = this->enabled;
      *(outbuffer + offset + 0) = (u_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled);
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
      this->priority =  ((uint16_t) (*(inbuffer + offset)));
      this->priority |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->priority);
      offset += this->icon.deserialize(inbuffer + offset);
      uint32_t length_launcher_type;
      memcpy(&length_launcher_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_launcher_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_launcher_type-1]=0;
      this->launcher_type = (char *)(inbuffer + offset-1);
      offset += length_launcher_type;
      uint32_t length_launcher;
      memcpy(&length_launcher, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_launcher; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_launcher-1]=0;
      this->launcher = (char *)(inbuffer + offset-1);
      offset += length_launcher;
      uint32_t length_interactions;
      memcpy(&length_interactions, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_interactions; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_interactions-1]=0;
      this->interactions = (char *)(inbuffer + offset-1);
      offset += length_interactions;
      uint32_t length_parameters;
      memcpy(&length_parameters, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameters; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameters-1]=0;
      this->parameters = (char *)(inbuffer + offset-1);
      offset += length_parameters;
      uint8_t parameters_detail_lengthT = *(inbuffer + offset++);
      if(parameters_detail_lengthT > parameters_detail_length)
        this->parameters_detail = (rocon_std_msgs::KeyValue*)realloc(this->parameters_detail, parameters_detail_lengthT * sizeof(rocon_std_msgs::KeyValue));
      offset += 3;
      parameters_detail_length = parameters_detail_lengthT;
      for( uint8_t i = 0; i < parameters_detail_length; i++){
      offset += this->st_parameters_detail.deserialize(inbuffer + offset);
        memcpy( &(this->parameters_detail[i]), &(this->st_parameters_detail), sizeof(rocon_std_msgs::KeyValue));
      }
      offset += this->uuid.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->status = u_status.real;
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.base = 0;
      u_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled = u_enabled.real;
      offset += sizeof(this->enabled);
     return offset;
    }

    const char * getType(){ return "concert_msgs/ServiceProfile"; };
    const char * getMD5(){ return "dcb6ede1f2f06a387af71a83b4776139"; };

  };

}
#endif