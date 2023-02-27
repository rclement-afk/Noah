#include <kipr/wombat.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/functions.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/consts.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/timer.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/threads.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/run_functs.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/clone_consts.h>
//slow_servo(int part, int des, int speed) {
int main()
{
//float intial=seconds();
//printf("%f",intial);
//slow_servo(arm,900,1);
    slow_servo(claw,claw_grab-50,1);
 slow_servo(claw,claw_empty,1);  
 //   slow_servo(claw,claw_grab-50,1);
  
  run_2();
   // float final=seconds();
    
    //	int calibrate();
 	//claw_open();
//   pre_run();
  
   //square_up(2,400);
   //  run();

   // move(-200,-200);
   // msleep(2000);
  //  square_up(1,450);
 // slow_servo(claw,claw_empty,2);
 // move(0,0);
 //   slow_servo(claw,claw_grab+750,1);
   //slow_servo(claw,claw_empty-780,1);
     // slow_servo(claw,claw_grab+750,1);
      //slow_servo(claw,claw_empty-780,1);
    return 0;
	 
}
