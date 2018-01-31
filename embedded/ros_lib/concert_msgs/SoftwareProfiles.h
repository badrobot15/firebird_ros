#ifndef _ROS_concert_msgs_SoftwareProfiles_h
#define _ROS_concert_msgs_SoftwareProfiles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/SoftwareProfile.h"

namespace concert_msgs
{

  class SoftwareProfiles : public ros::Msg
  {
    public:
      uint8_t profiles_length;
      concert_msgs::SoftwareProfile st_profiles;
      concert_msgs::SoftwareProfile * profiles;

    SoftwareProfiles():
      profiles_length(0), profiles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = profiles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < profiles_length; i++){
      offset += this->profiles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t profiles_lengthT = *(inbuffer + offset++);
      if(profiles_lengthT > profiles_length)
        this->profiles = (concert_msgs::SoftwareProfile*)realloc(this->profiles, profiles_lengthT * sizeof(concert_msgs::SoftwareProfile));
      offset += 3;
      profiles_length = profiles_lengthT;
      for( uint8_t i = 0; i < profiles_length; i++){
      offset += this->st_profiles.deserialize(inbuffer + offset);
        memcpy( &(this->profiles[i]), &(this->st_profiles), sizeof(concert_msgs::SoftwareProfile));
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/SoftwareProfiles"; };
    const char * getMD5(){ return "b1749b57e354bf30f98c3179a4fff5d7"; };

  };

}
#endif