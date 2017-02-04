#ifndef CYCLE_HPP
#define CYCLE_HPP 1


#include "animation.hpp"
#include <climits>

class cycle : public animation {
private:
  animation* ani;

public:
  cycle(animation* ani){
    this->ani = ani;
  }
  /// getDuration stuffs
  double getDuration(){ return LONG_MAX; }

  void animate(long ms){
    ani->animate(ms % (int)ani->getDuration());
  }
};

#endif
