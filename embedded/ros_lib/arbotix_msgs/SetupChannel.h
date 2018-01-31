#ifndef _ROS_SERVICE_SetupChannel_h
#define _ROS_SERVICE_SetupChannel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arbotix_msgs
{

static const char SETUPCHANNEL[] = "arbotix_msgs/SetupChannel";

  class SetupChannelRequest : public ros::Msg
  {
    public:
      const char* topic_name;
      uint8_t pin;
      uint8_t value;
      uint8_t rate;

    SetupChannelRequest():
      topic_name(""),
      pin(0),
      value(0),
      rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic_name = strlen(this->topic_name);
      memcpy(outbuffer + offset, &length_topic_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      *(outbuffer + offset + 0) = (this->pin >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pin);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      *(outbuffer + offset + 0) = (this->rate >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic_name;
      memcpy(&length_topic_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
      this->pin =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pin);
      this->value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->value);
      this->rate =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->rate);
     return offset;
    }

    const char * getType(){ return SETUPCHANNEL; };
    const char * getMD5(){ return "c65e58d8b3b4d406126f6dc829a6011f"; };

  };

  class SetupChannelResponse : public ros::Msg
  {
    public:

    SetupChannelResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETUPCHANNEL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetupChannel {
    public:
    typedef SetupChannelRequest Request;
    typedef SetupChannelResponse Response;
  };

}
#endif
