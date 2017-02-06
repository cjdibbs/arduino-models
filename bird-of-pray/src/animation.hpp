#ifndef ANIMATION_HPP
#define ANIMATION_HPP 1

class animation {
public:
  virtual double getDuration() = 0;
  virtual void animate(long ms) = 0;
  virtual bool isComplete(long ms){
    return ms > this->getDuration();
  }
};

const double STEPS_VOLTS = 255.0/5.0;

#endif
