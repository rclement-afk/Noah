#include <kipr/wombat.h>
#include <functions.h>
#include <consts.h>

int buffer(int sensor){
  int value = 0;
  int total = 0;
  int i = 0;
  while (i<5){
    i++;
    value = analog(sensor);
    msleep(3);
    total+=value;
  };
  total=total/5;
  return total;
};

void slow_servo(int part, int des, int speed) {
  int cur = get_servo_position(part);
  if(des < 50){des=50;};if(des > 2000){des=2000;};
  if (cur < des) {
    enable_servo(part);
    while (!(cur >= des)) {
    	cur+=speed;
        set_servo_position(part, cur);
        msleep(1);
    };
    disable_servo(part);
  };
  if (cur > des){
    enable_servo(part);
    while (!(cur <= des)) {
    	cur-=speed;
        set_servo_position(part, cur);
        msleep(1);
    };
    disable_servo(part);
  };
};
