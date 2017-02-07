#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP 1

#include "animation.hpp"

class sequence : public animation {
private:
  animation** animations;
  int count;

public:
  sequence(animation** animations, int count){
    this->animations = animations;
    this->count = count;
  }
  /// getDuration stuffs
  double getDuration(){
    double ret = 0;
    for(int ii = 0; ii < count; ii++)
      ret += animations[ii]->getDuration();
    return ret;
  }

  void animate(long ms){
    int ii = 0;


    while(ii < (count-1) && ms > animations[ii]->getDuration()) {
      ms -= animations[ii++]->getDuration();
    }

    animations[ii]->animate(ms);
  }
};

#endif
