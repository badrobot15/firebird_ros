#ifndef _ROS_SERVICE_RenameRobotStateInWarehouse_h
#define _ROS_SERVICE_RenameRobotStateInWarehouse_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

static const char RENAMEROBOTSTATEINWAREHOUSE[] = "moveit_msgs/RenameRobotStateInWarehouse";

  class RenameRobotStateInWarehouseRequest : public ros::Msg
  {
    public:
      const char* old_name;
      const char* new_name;
      const char* robot;

    RenameRobotStateInWarehouseRequest():
      old_name(""),
      new_name(""),
      robot("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_old_name = strlen(this->old_name);
      memcpy(outbuffer + offset, &length_old_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->old_name, length_old_name);
      offset += length_old_name;
      uint32_t length_new_name = strlen(this->new_name);
      memcpy(outbuffer + offset, &length_new_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->new_name, length_new_name);
      offset += length_new_name;
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
      uint32_t length_old_name;
      memcpy(&length_old_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_old_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_old_name-1]=0;
      this->old_name = (char *)(inbuffer + offset-1);
      offset += length_old_name;
      uint32_t length_new_name;
      memcpy(&length_new_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_new_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_new_name-1]=0;
      this->new_name = (char *)(inbuffer + offset-1);
      offset += length_new_name;
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

    const char * getType(){ return RENAMEROBOTSTATEINWAREHOUSE; };
    const char * getMD5(){ return "073dc05c3fd313b947cea483c25c46b0"; };

  };

  class RenameRobotStateInWarehouseResponse : public ros::Msg
  {
    public:

    RenameRobotStateInWarehouseResponse()
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

    const char * getType(){ return RENAMEROBOTSTATEINWAREHOUSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RenameRobotStateInWarehouse {
    public:
    typedef RenameRobotStateInWarehouseRequest Request;
    typedef RenameRobotStateInWarehouseResponse Response;
  };

}
#endif
