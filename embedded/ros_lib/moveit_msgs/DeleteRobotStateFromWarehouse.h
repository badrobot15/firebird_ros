#ifndef _ROS_SERVICE_DeleteRobotStateFromWarehouse_h
#define _ROS_SERVICE_DeleteRobotStateFromWarehouse_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace moveit_msgs
{

static const char DELETEROBOTSTATEFROMWAREHOUSE[] = "moveit_msgs/DeleteRobotStateFromWarehouse";

  class DeleteRobotStateFromWarehouseRequest : public ros::Msg
  {
    public:
      const char* name;
      const char* robot;

    DeleteRobotStateFromWarehouseRequest():
      name(""),
      robot("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
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
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
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

    const char * getType(){ return DELETEROBOTSTATEFROMWAREHOUSE; };
    const char * getMD5(){ return "dab44354403f811c40b84964e068219c"; };

  };

  class DeleteRobotStateFromWarehouseResponse : public ros::Msg
  {
    public:

    DeleteRobotStateFromWarehouseResponse()
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

    const char * getType(){ return DELETEROBOTSTATEFROMWAREHOUSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DeleteRobotStateFromWarehouse {
    public:
    typedef DeleteRobotStateFromWarehouseRequest Request;
    typedef DeleteRobotStateFromWarehouseResponse Response;
  };

}
#endif
