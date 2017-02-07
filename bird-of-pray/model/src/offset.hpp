#ifndef OFFSET_HPP
#define OFFSET_HPP 1

#include "animation.hpp"

class offset : public animation {
private:
  double by;
  animation* sub;
public:
  offset(double by, animation* sub){
    this->by = by;
    this->sub = sub;
  }

  double getDuration(){
    return sub->getDuration() + by;
  }

  void animate(long ms){
    ms -= by;
    if(ms > 0)
      sub->animate(ms);
  }
};

#endif
