#ifndef _ROS_concert_msgs_ConductorGraph_h
#define _ROS_concert_msgs_ConductorGraph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/ConcertClient.h"

namespace concert_msgs
{

  class ConductorGraph : public ros::Msg
  {
    public:
      uint8_t pending_length;
      concert_msgs::ConcertClient st_pending;
      concert_msgs::ConcertClient * pending;
      uint8_t bad_length;
      concert_msgs::ConcertClient st_bad;
      concert_msgs::ConcertClient * bad;
      uint8_t blocking_length;
      concert_msgs::ConcertClient st_blocking;
      concert_msgs::ConcertClient * blocking;
      uint8_t busy_length;
      concert_msgs::ConcertClient st_busy;
      concert_msgs::ConcertClient * busy;
      uint8_t uninvited_length;
      concert_msgs::ConcertClient st_uninvited;
      concert_msgs::ConcertClient * uninvited;
      uint8_t joining_length;
      concert_msgs::ConcertClient st_joining;
      concert_msgs::ConcertClient * joining;
      uint8_t available_length;
      concert_msgs::ConcertClient st_available;
      concert_msgs::ConcertClient * available;
      uint8_t missing_length;
      concert_msgs::ConcertClient st_missing;
      concert_msgs::ConcertClient * missing;
      uint8_t gone_length;
      concert_msgs::ConcertClient st_gone;
      concert_msgs::ConcertClient * gone;

    ConductorGraph():
      pending_length(0), pending(NULL),
      bad_length(0), bad(NULL),
      blocking_length(0), blocking(NULL),
      busy_length(0), busy(NULL),
      uninvited_length(0), uninvited(NULL),
      joining_length(0), joining(NULL),
      available_length(0), available(NULL),
      missing_length(0), missing(NULL),
      gone_length(0), gone(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = pending_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pending_length; i++){
      offset += this->pending[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = bad_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bad_length; i++){
      offset += this->bad[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = blocking_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < blocking_length; i++){
      offset += this->blocking[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = busy_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < busy_length; i++){
      offset += this->busy[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = uninvited_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < uninvited_length; i++){
      offset += this->uninvited[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = joining_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joining_length; i++){
      offset += this->joining[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = available_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < available_length; i++){
      offset += this->available[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = missing_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < missing_length; i++){
      offset += this->missing[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = gone_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < gone_length; i++){
      offset += this->gone[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t pending_lengthT = *(inbuffer + offset++);
      if(pending_lengthT > pending_length)
        this->pending = (concert_msgs::ConcertClient*)realloc(this->pending, pending_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      pending_length = pending_lengthT;
      for( uint8_t i = 0; i < pending_length; i++){
      offset += this->st_pending.deserialize(inbuffer + offset);
        memcpy( &(this->pending[i]), &(this->st_pending), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t bad_lengthT = *(inbuffer + offset++);
      if(bad_lengthT > bad_length)
        this->bad = (concert_msgs::ConcertClient*)realloc(this->bad, bad_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      bad_length = bad_lengthT;
      for( uint8_t i = 0; i < bad_length; i++){
      offset += this->st_bad.deserialize(inbuffer + offset);
        memcpy( &(this->bad[i]), &(this->st_bad), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t blocking_lengthT = *(inbuffer + offset++);
      if(blocking_lengthT > blocking_length)
        this->blocking = (concert_msgs::ConcertClient*)realloc(this->blocking, blocking_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      blocking_length = blocking_lengthT;
      for( uint8_t i = 0; i < blocking_length; i++){
      offset += this->st_blocking.deserialize(inbuffer + offset);
        memcpy( &(this->blocking[i]), &(this->st_blocking), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t busy_lengthT = *(inbuffer + offset++);
      if(busy_lengthT > busy_length)
        this->busy = (concert_msgs::ConcertClient*)realloc(this->busy, busy_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      busy_length = busy_lengthT;
      for( uint8_t i = 0; i < busy_length; i++){
      offset += this->st_busy.deserialize(inbuffer + offset);
        memcpy( &(this->busy[i]), &(this->st_busy), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t uninvited_lengthT = *(inbuffer + offset++);
      if(uninvited_lengthT > uninvited_length)
        this->uninvited = (concert_msgs::ConcertClient*)realloc(this->uninvited, uninvited_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      uninvited_length = uninvited_lengthT;
      for( uint8_t i = 0; i < uninvited_length; i++){
      offset += this->st_uninvited.deserialize(inbuffer + offset);
        memcpy( &(this->uninvited[i]), &(this->st_uninvited), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t joining_lengthT = *(inbuffer + offset++);
      if(joining_lengthT > joining_length)
        this->joining = (concert_msgs::ConcertClient*)realloc(this->joining, joining_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      joining_length = joining_lengthT;
      for( uint8_t i = 0; i < joining_length; i++){
      offset += this->st_joining.deserialize(inbuffer + offset);
        memcpy( &(this->joining[i]), &(this->st_joining), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t available_lengthT = *(inbuffer + offset++);
      if(available_lengthT > available_length)
        this->available = (concert_msgs::ConcertClient*)realloc(this->available, available_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      available_length = available_lengthT;
      for( uint8_t i = 0; i < available_length; i++){
      offset += this->st_available.deserialize(inbuffer + offset);
        memcpy( &(this->available[i]), &(this->st_available), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t missing_lengthT = *(inbuffer + offset++);
      if(missing_lengthT > missing_length)
        this->missing = (concert_msgs::ConcertClient*)realloc(this->missing, missing_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      missing_length = missing_lengthT;
      for( uint8_t i = 0; i < missing_length; i++){
      offset += this->st_missing.deserialize(inbuffer + offset);
        memcpy( &(this->missing[i]), &(this->st_missing), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t gone_lengthT = *(inbuffer + offset++);
      if(gone_lengthT > gone_length)
        this->gone = (concert_msgs::ConcertClient*)realloc(this->gone, gone_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      gone_length = gone_lengthT;
      for( uint8_t i = 0; i < gone_length; i++){
      offset += this->st_gone.deserialize(inbuffer + offset);
        memcpy( &(this->gone[i]), &(this->st_gone), sizeof(concert_msgs::ConcertClient));
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/ConductorGraph"; };
    const char * getMD5(){ return "3985298cb56505a707665446d34bba5e"; };

  };

}
#endif