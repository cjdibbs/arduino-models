#include "fade.hpp"
#include "sequence.hpp"
#include "fixed.hpp"
#include "cycle.hpp"

long time = 0;

animation** animations = new animation*[6];

animation* torpedo = new sequence(
  new animation*[3] {
    new fade(0, 2.2, 2000, 10),
    new fixed(2.2, 50, 10),
    new fixed(0, 2000, 10)
  },
  3
);

double engine_max = 2.1;
double engine_high = .7;
double engine_low = .3;

animation* buildEngineLite(int offset, int pin){
  return new sequence(
    new animation*[4] {
      new fade(0, engine_max, 500, pin),
      new fixed(engine_max, offset, pin),
      new fade(engine_max, engine_low, 500, pin),
      new cycle(
        new sequence(
          new animation*[2] {
            new fade(engine_low, engine_high, 500, pin),
            new fade(engine_high, engine_low, 500, pin)
          },
          2
        )
      )
    },
    4
  );
}

void setup() {
  Serial.begin(9600);

  animations[0] = new cycle(torpedo);
  animations[1] = buildEngineLite(0, 3);
  animations[2] = buildEngineLite(500, 5);
  animations[3] = buildEngineLite(250, 6);
  animations[4] = buildEngineLite(125, 9);


}

void loop() {

  for(int ii = 0; ii < 6; ii++)
    if(animations[ii] != 0)
      animations[ii]->animate(time);

  time += 10;
  delay(10);

}
