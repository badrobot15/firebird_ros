#ifndef _ROS_firebird_Sensor_h
#define _ROS_firebird_Sensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "firebird/WLS.h"
#include "firebird/Sharp.h"
#include "firebird/IR.h"
#include "firebird/Battery.h"
#include "firebird/Aux.h"

namespace firebird
{

  class Sensor : public ros::Msg
  {
    public:
      typedef firebird::WLS _wls_type;
      _wls_type wls;
      typedef firebird::Sharp _sharp_type;
      _sharp_type sharp;
      typedef firebird::IR _ir_type;
      _ir_type ir;
      typedef firebird::Battery _battery_type;
      _battery_type battery;
      typedef firebird::Aux _aux_type;
      _aux_type aux;

    Sensor():
      wls(),
      sharp(),
      ir(),
      battery(),
      aux()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->wls.serialize(outbuffer + offset);
      offset += this->sharp.serialize(outbuffer + offset);
      offset += this->ir.serialize(outbuffer + offset);
      offset += this->battery.serialize(outbuffer + offset);
      offset += this->aux.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->wls.deserialize(inbuffer + offset);
      offset += this->sharp.deserialize(inbuffer + offset);
      offset += this->ir.deserialize(inbuffer + offset);
      offset += this->battery.deserialize(inbuffer + offset);
      offset += this->aux.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "firebird/Sensor"; };
    const char * getMD5(){ return "77112cf9e65ba23f3d6b07852b35a9ae"; };

  };

}
#endif