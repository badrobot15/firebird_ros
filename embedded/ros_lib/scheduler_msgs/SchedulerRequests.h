#ifndef _ROS_scheduler_msgs_SchedulerRequests_h
#define _ROS_scheduler_msgs_SchedulerRequests_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "uuid_msgs/UniqueID.h"
#include "scheduler_msgs/Request.h"

namespace scheduler_msgs
{

  class SchedulerRequests : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uuid_msgs::UniqueID requester;
      uint8_t requests_length;
      scheduler_msgs::Request st_requests;
      scheduler_msgs::Request * requests;

    SchedulerRequests():
      header(),
      requester(),
      requests_length(0), requests(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->requester.serialize(outbuffer + offset);
      *(outbuffer + offset++) = requests_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < requests_length; i++){
      offset += this->requests[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->requester.deserialize(inbuffer + offset);
      uint8_t requests_lengthT = *(inbuffer + offset++);
      if(requests_lengthT > requests_length)
        this->requests = (scheduler_msgs::Request*)realloc(this->requests, requests_lengthT * sizeof(scheduler_msgs::Request));
      offset += 3;
      requests_length = requests_lengthT;
      for( uint8_t i = 0; i < requests_length; i++){
      offset += this->st_requests.deserialize(inbuffer + offset);
        memcpy( &(this->requests[i]), &(this->st_requests), sizeof(scheduler_msgs::Request));
      }
     return offset;
    }

    const char * getType(){ return "scheduler_msgs/SchedulerRequests"; };
    const char * getMD5(){ return "d0adc2f83296939c4b208a3e0619e86f"; };

  };

}
#endif