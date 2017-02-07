#ifndef FADE_HPP
#define FADE_HPP

#include <Arduino.h>
#include "Animation.hpp"

class fade : public animation {
private:
  double min_value;
  double max_value;
  double duration;
  int pin;

public:
  fade(double minVolts, double maxVolts, double duration, int pin){
    this->min_value = minVolts * STEPS_VOLTS;
    this->max_value = maxVolts * STEPS_VOLTS;
    this->duration = duration;
    this->pin = pin;
  }

  double getDuration(){
    return duration;
  }

  void animate(long ms){
      int value = min_value;

      if(ms > 0 && ms < duration)
        value = (int)( (max_value-min_value)*ms/duration + min_value);
      else if(ms >= duration)
        value = max_value;

      analogWrite(pin, value);
  }
};

#endif
