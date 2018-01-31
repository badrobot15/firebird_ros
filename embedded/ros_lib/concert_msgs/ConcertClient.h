#ifndef _ROS_concert_msgs_ConcertClient_h
#define _ROS_concert_msgs_ConcertClient_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_std_msgs/PlatformInfo.h"
#include "gateway_msgs/ConnectionStatistics.h"
#include "rocon_app_manager_msgs/Rapp.h"

namespace concert_msgs
{

  class ConcertClient : public ros::Msg
  {
    public:
      const char* name;
      const char* gateway_name;
      rocon_std_msgs::PlatformInfo platform_info;
      bool is_local_client;
      const char* state;
      const char* ip;
      gateway_msgs::ConnectionStatistics conn_stats;
      uint8_t rapps_length;
      rocon_app_manager_msgs::Rapp st_rapps;
      rocon_app_manager_msgs::Rapp * rapps;

    ConcertClient():
      name(""),
      gateway_name(""),
      platform_info(),
      is_local_client(0),
      state(""),
      ip(""),
      conn_stats(),
      rapps_length(0), rapps(NULL)
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
      uint32_t length_gateway_name = strlen(this->gateway_name);
      memcpy(outbuffer + offset, &length_gateway_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->gateway_name, length_gateway_name);
      offset += length_gateway_name;
      offset += this->platform_info.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_local_client;
      u_is_local_client.real = this->is_local_client;
      *(outbuffer + offset + 0) = (u_is_local_client.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_local_client);
      uint32_t length_state = strlen(this->state);
      memcpy(outbuffer + offset, &length_state, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      uint32_t length_ip = strlen(this->ip);
      memcpy(outbuffer + offset, &length_ip, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ip, length_ip);
      offset += length_ip;
      offset += this->conn_stats.serialize(outbuffer + offset);
      *(outbuffer + offset++) = rapps_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rapps_length; i++){
      offset += this->rapps[i].serialize(outbuffer + offset);
      }
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
      uint32_t length_gateway_name;
      memcpy(&length_gateway_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gateway_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gateway_name-1]=0;
      this->gateway_name = (char *)(inbuffer + offset-1);
      offset += length_gateway_name;
      offset += this->platform_info.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_local_client;
      u_is_local_client.base = 0;
      u_is_local_client.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_local_client = u_is_local_client.real;
      offset += sizeof(this->is_local_client);
      uint32_t length_state;
      memcpy(&length_state, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      uint32_t length_ip;
      memcpy(&length_ip, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ip; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ip-1]=0;
      this->ip = (char *)(inbuffer + offset-1);
      offset += length_ip;
      offset += this->conn_stats.deserialize(inbuffer + offset);
      uint8_t rapps_lengthT = *(inbuffer + offset++);
      if(rapps_lengthT > rapps_length)
        this->rapps = (rocon_app_manager_msgs::Rapp*)realloc(this->rapps, rapps_lengthT * sizeof(rocon_app_manager_msgs::Rapp));
      offset += 3;
      rapps_length = rapps_lengthT;
      for( uint8_t i = 0; i < rapps_length; i++){
      offset += this->st_rapps.deserialize(inbuffer + offset);
        memcpy( &(this->rapps[i]), &(this->st_rapps), sizeof(rocon_app_manager_msgs::Rapp));
      }
     return offset;
    }

    const char * getType(){ return "concert_msgs/ConcertClient"; };
    const char * getMD5(){ return "7b021e6713839995a4c68ebde750ba79"; };

  };

}
#endif