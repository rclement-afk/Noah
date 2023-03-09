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
};/*
void find_cube(){
    //far to close, when hit far again, go back
    int old = buffer(fET);
    int new = buffer(fET) + 10;
    int corner;
    reset_timer(5);
    int i = 0;
    //new val - old val : if old val > new val (3 times consequtively?), reached end of corner
    //old = first val
    //new = val after first
	while(timer(5) < 4){
    	while(new > old && timer(5) < 4){
            old = buffer(fET);
            printf("%d old et\n",old);
        	move(300,-300);
            msleep(100);
            stop_it();
            new = buffer(fET);
            printf("%d new et\n",new);
            
            if(new < old){
                printf("found corner");
            	corner = old;
                i = 0;
                while(i<3){
                	move(300,-300);
                    msleep(100);
                    stop_it();
                    if(buffer(fET) < corner){i++;}else{printf(" %d brokkn ",i); break;}
                }
            	if(i==2){stop_it(); printf("omg a corner"); reset_timer(5); break;}
            }
        }
        while(i ==2 && timer(5)<1.5){
            //printf("hellooo");
        	move(-50,50);
            msleep(100);
            stop_it();
            if(buffer(ET) >= corner){stop_it(); return;}
        }
        
        //}//
    }
}*/