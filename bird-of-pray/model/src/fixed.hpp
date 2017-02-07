#ifndef FIXED_HPP
#define FIXED_HPP

#include "animation.hpp"
#include <Arduino.h>

class fixed : public animation {
private:
  int value;
  int pin;
  long duration;

public:
  fixed(double volts, long duration, int pin){
    this->value = (int) volts * STEPS_VOLTS;
    this->duration = duration;
    this->pin = pin;
  }

  double getDuration() { return duration; }
  void animate(long ms) { analogWrite(pin, value); }
};

#endif
