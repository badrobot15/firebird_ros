#ifndef _ROS_scheduler_msgs_Request_h
#define _ROS_scheduler_msgs_Request_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "scheduler_msgs/Resource.h"
#include "ros/time.h"
#include "ros/duration.h"

namespace scheduler_msgs
{

  class Request : public ros::Msg
  {
    public:
      uuid_msgs::UniqueID id;
      uint8_t resources_length;
      scheduler_msgs::Resource st_resources;
      scheduler_msgs::Resource * resources;
      uint8_t status;
      uint8_t reason;
      const char* problem;
      ros::Time availability;
      ros::Duration hold_time;
      int16_t priority;
      enum { NEW =  0    };
      enum { RESERVED =  1    };
      enum { WAITING =  2    };
      enum { GRANTED =  3    };
      enum { PREEMPTING =  4    };
      enum { CANCELING =  5    };
      enum { CLOSED =  6    };
      enum { NONE =  0    };
      enum { PREEMPTED =  1    };
      enum { BUSY =  2    };
      enum { UNAVAILABLE =  3    };
      enum { TIMEOUT =  4    };
      enum { INVALID =  5    };
      enum { BACKGROUND_PRIORITY =  -20000       };
      enum { LOW_PRIORITY =  -10000              };
      enum { DEFAULT_PRIORITY =  0               };
      enum { HIGH_PRIORITY =  10000              };
      enum { CRITICAL_PRIORITY =  20000          };

    Request():
      id(),
      resources_length(0), resources(NULL),
      status(0),
      reason(0),
      problem(""),
      availability(),
      hold_time(),
      priority(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->id.serialize(outbuffer + offset);
      *(outbuffer + offset++) = resources_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < resources_length; i++){
      offset += this->resources[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->reason >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reason);
      uint32_t length_problem = strlen(this->problem);
      memcpy(outbuffer + offset, &length_problem, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->problem, length_problem);
      offset += length_problem;
      *(outbuffer + offset + 0) = (this->availability.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->availability.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->availability.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->availability.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->availability.sec);
      *(outbuffer + offset + 0) = (this->availability.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->availability.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->availability.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->availability.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->availability.nsec);
      *(outbuffer + offset + 0) = (this->hold_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hold_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hold_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hold_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hold_time.sec);
      *(outbuffer + offset + 0) = (this->hold_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hold_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hold_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hold_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hold_time.nsec);
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_priority.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->id.deserialize(inbuffer + offset);
      uint8_t resources_lengthT = *(inbuffer + offset++);
      if(resources_lengthT > resources_length)
        this->resources = (scheduler_msgs::Resource*)realloc(this->resources, resources_lengthT * sizeof(scheduler_msgs::Resource));
      offset += 3;
      resources_length = resources_lengthT;
      for( uint8_t i = 0; i < resources_length; i++){
      offset += this->st_resources.deserialize(inbuffer + offset);
        memcpy( &(this->resources[i]), &(this->st_resources), sizeof(scheduler_msgs::Resource));
      }
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      this->reason =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reason);
      uint32_t length_problem;
      memcpy(&length_problem, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_problem; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_problem-1]=0;
      this->problem = (char *)(inbuffer + offset-1);
      offset += length_problem;
      this->availability.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->availability.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->availability.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->availability.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->availability.sec);
      this->availability.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->availability.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->availability.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->availability.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->availability.nsec);
      this->hold_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->hold_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hold_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hold_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hold_time.sec);
      this->hold_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->hold_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->hold_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->hold_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->hold_time.nsec);
      union {
        int16_t real;
        uint16_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_priority.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/Request"; };
    const char * getMD5(){ return "1556d9f8919617c2f52b2a4ab15f6468"; };

  };

}
#endif