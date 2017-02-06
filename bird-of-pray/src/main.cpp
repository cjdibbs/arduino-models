#include "fade.hpp"
#include "sequence.hpp"
#include "fixed.hpp"
#include "cycle.hpp"
#include "offset.hpp"

long time = 0;
const byte deltaTime = 10;

animation** animations = new animation*[6];

const byte torpedoPin = 2;

animation* torpedo = new sequence(
  new animation*[3] {
    new fade(0, 2.2, 2000, 10),
    new fixed(2.2, 50, 10),
    new fixed(0, 2000, 10)
  },
  3
);

double engine_max = 2.1;
double engine_high = .8;
double engine_low = .2;

animation* buildEngineLite(int offset, int pin){
  return new sequence(
    new animation*[4] {
      new fade(0, engine_max, 200, pin),
      new fixed(engine_max, offset, pin),
      new fade(engine_max, engine_low, 200, pin),
      new cycle(
        new sequence(
          new animation*[2] {
            new fade(engine_low, engine_high, 100, pin),
            new fade(engine_high, engine_low, 100, pin)
          },
          2
        )
      )
    },
    4
  );
}

void fire(){
  if(animations[0] == NULL || animations[0]->isComplete(time)){
    animations[0] = new offset(time, torpedo);
    //TODO trigger sound too....
  }
}

void setup() {
  Serial.begin(9600);

  animations[0] = NULL; // torpedos
  animations[1] = buildEngineLite(0, 3);
  animations[2] = buildEngineLite(500, 5);
  animations[3] = buildEngineLite(250, 6);
  animations[4] = buildEngineLite(125, 9);
  animations[5] = NULL; // disrupters?

  pinMode(torpedoPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(torpedoPin), &fire, RISING);

}

void loop() {

  for(int ii = 0; ii < 6; ii++)
    if(animations[ii] != 0)
      animations[ii]->animate(time);

  time += deltaTime;
  delay(deltaTime);

}
