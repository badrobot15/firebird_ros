#ifndef _ROS_concert_msgs_ConcertClients_h
#define _ROS_concert_msgs_ConcertClients_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "concert_msgs/ConcertClient.h"

namespace concert_msgs
{

  class ConcertClients : public ros::Msg
  {
    public:
      uint8_t clients_length;
      concert_msgs::ConcertClient st_clients;
      concert_msgs::ConcertClient * clients;
      uint8_t missing_clients_length;
      concert_msgs::ConcertClient st_missing_clients;
      concert_msgs::ConcertClient * missing_clients;
      uint8_t uninvited_clients_length;
      concert_msgs::ConcertClient st_uninvited_clients;
      concert_msgs::ConcertClient * uninvited_clients;

    ConcertClients():
      clients_length(0), clients(NULL),
      missing_clients_length(0), missing_clients(NULL),
      uninvited_clients_length(0), uninvited_clients(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = clients_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < clients_length; i++){
      offset += this->clients[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = missing_clients_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < missing_clients_length; i++){
      offset += this->missing_clients[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = uninvited_clients_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < uninvited_clients_length; i++){
      offset += this->uninvited_clients[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t clients_lengthT = *(inbuffer + offset++);
      if(clients_lengthT > clients_length)
        this->clients = (concert_msgs::ConcertClient*)realloc(this->clients, clients_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      clients_length = clients_lengthT;
      for( uint8_t i = 0; i < clients_length; i++){
      offset += this->st_clients.deserialize(inbuffer + offset);
        memcpy( &(this->clients[i]), &(this->st_clients), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t missing_clients_lengthT = *(inbuffer + offset++);
      if(missing_clients_lengthT > missing_clients_length)
        this->missing_clients = (concert_msgs::ConcertClient*)realloc(this->missing_clients, missing_clients_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      missing_clients_length = missing_clients_lengthT;
      for( uint8_t i = 0; i < missing_clients_length; i++){
      offset += this->st_missing_clients.deserialize(inbuffer + offset);
        memcpy( &(this->missing_clients[i]), &(this->st_missing_clients), sizeof(concert_msgs::ConcertClient));
      }
      uint8_t uninvited_clients_lengthT = *(inbuffer + offset++);
      if(uninvited_clients_lengthT > uninvited_clients_length)
        this->uninvited_clients = (concert_msgs::ConcertClient*)realloc(this->uninvited_clients, uninvited_clients_lengthT * sizeof(concert_msgs::ConcertClient));
      offset += 3;
      uninvited_clients_length = uninvited_clients_lengthT;
      for( uint8_t i = 0; i < uninvited_clients_length; i++){
      offset += this->st_uninvited_clients.deserialize(inbuffer + offset);
        memcpy( &(this->uninvited_clients[i]), &(this->st_uninvited_clients), sizeof(concert_msgs::ConcertClient));
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/ConcertClients"; };
    const char * getMD5(){ return "dc25b17de2f711f3b3dcaacf8d8f58eb"; };

  };

}
#endif