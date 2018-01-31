#ifndef _ROS_SERVICE_ListRobotStatesInWarehouse_h
#define _ROS_SERVICE_ListRobotStatesInWarehouse_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

static const char LISTROBOTSTATESINWAREHOUSE[] = "moveit_msgs/ListRobotStatesInWarehouse";

  class ListRobotStatesInWarehouseRequest : public ros::Msg
  {
    public:
      const char* regex;
      const char* robot;

    ListRobotStatesInWarehouseRequest():
      regex(""),
      robot("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_regex = strlen(this->regex);
      memcpy(outbuffer + offset, &length_regex, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->regex, length_regex);
      offset += length_regex;
      uint32_t length_robot = strlen(this->robot);
      memcpy(outbuffer + offset, &length_robot, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->robot, length_robot);
      offset += length_robot;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_regex;
      memcpy(&length_regex, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_regex; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_regex-1]=0;
      this->regex = (char *)(inbuffer + offset-1);
      offset += length_regex;
      uint32_t length_robot;
      memcpy(&length_robot, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot-1]=0;
      this->robot = (char *)(inbuffer + offset-1);
      offset += length_robot;
     return offset;
    }

    const char * getType(){ return LISTROBOTSTATESINWAREHOUSE; };
    const char * getMD5(){ return "6f0970a3ca837e2fc3ed63e314b44b42"; };

  };

  class ListRobotStatesInWarehouseResponse : public ros::Msg
  {
    public:
      uint8_t states_length;
      char* st_states;
      char* * states;

    ListRobotStatesInWarehouseResponse():
      states_length(0), states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < states_length; i++){
      uint32_t length_statesi = strlen(this->states[i]);
      memcpy(outbuffer + offset, &length_statesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->states[i], length_statesi);
      offset += length_statesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t states_lengthT = *(inbuffer + offset++);
      if(states_lengthT > states_length)
        this->states = (char**)realloc(this->states, states_lengthT * sizeof(char*));
      offset += 3;
      states_length = states_lengthT;
      for( uint8_t i = 0; i < states_length; i++){
      uint32_t length_st_states;
      memcpy(&length_st_states, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_states; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_states-1]=0;
      this->st_states = (char *)(inbuffer + offset-1);
      offset += length_st_states;
        memcpy( &(this->states[i]), &(this->st_states), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return LISTROBOTSTATESINWAREHOUSE; };
    const char * getMD5(){ return "a8656b247c0429bb79afe0ddb88eb2f5"; };

  };

  class ListRobotStatesInWarehouse {
    public:
    typedef ListRobotStatesInWarehouseRequest Request;
    typedef ListRobotStatesInWarehouseResponse Response;
  };

}
#endif
