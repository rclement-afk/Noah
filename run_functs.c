#include <kipr/wombat.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/functions.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/consts.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/timer.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/threads.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/run_functs.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/clone_consts.h>
int base = 800;
int dbase = 66;
//
int ver = 0;
int hor = 1;
//
int mystery = 1;
int Mmystery = 0;
//
int white = 1;
int black = 2;


void touchdown();

/*int god_start(){
  prime_or_clone();
  calibrate_gyro();
  thread_starting_pos();
  wait_light();
  shut_down_in(119);
  reset_timer(3);
  msleep(5000);
  
return grab_rings();
}
void column_run(){
   Drive(-1000,-1*dbase);
   square_up(black,-1*base);
   thread_shift(hor);
   Drive(1600,base);
   msleep(600);
   while(1){
   	if(buffer(4)<=1230){ //1215
          move(200,200);
    }else{
        move(0,0);
    	break;
    }
   }
   thread_destroy(shift);
   slow_servo(arm,arm_min+100,1);
   msleep(1200);
   if(timer(3) > 105){
    printf("done");
   	return;
   }
   thread_back();
   square_up(black,-1*base);
   thread_destroy(back);
}
void ring_loop(int lower){
   double drive_time = 0.4;
   int drive_ticks = 0;
   if(lower < 400){drive_time+=0.9;}else{drive_ticks-=500;}
   slow_servo(arm,arm_min-lower,1); //-200
   Drive(1550,dbase);
   turn_with_gyro(base,mystery,0); 
   Drive(800,dbase);
   PID_gyro_drive(600,drive_time);
   slow_servo(claw,claw_min+200,1);
   slow_servo(arm,arm_max,1);
   msleep(100);
   Drive(-1650,-1*dbase);
   turn_with_gyro(base,Mmystery,0); 
   turn_with_gyro(base,-90,0);
   Drive(-1600+drive_ticks,-1*dbase);
   square_up(black,-400);
   Drive(2350,dbase);
   turn_with_gyro(base,90,0);
   column_run();

int grab_rings(){
   //red orange yellow
   PID_gyro_drive(-200,1.8);
   slow_servo(arm, 1440,1); //1450
   PID_gyro_drive(500,1); 
   slow_servo(claw,claw_min+100,1);
   PID_gyro_drive(-1*base,1);
   square_up(2,-1*base);
   Drive(-2370,-1*dbase); //9.5625 inches 2670 2370
   move(0,0);
   msleep(300);
   slow_servo(arm,arm_max,1);
   Drive(500,dbase);
   msleep(500);
   turn_with_gyro(base,90,1);
   Drive(3000,dbase);
   square_up(black,base);
   Drive(-1500,-1*dbase);
   move(0,0);
   turn_with_gyro(base,180,0);
   column_run();
   
   ring_loop(400); //400
   ring_loop(265); //250
   
   //Drive(1500,base);
   
   thread_shift(ver);
   slow_servo(arm,arm_min-400,1); 
   msleep(800);
   thread_destroy(shift);
   Drive(1500,dbase);
   turn_with_gyro(base,mystery,0); 
   Drive(1800,dbase);
   slow_servo(claw,claw_min,1);
   msleep(200);
   turn_with_gyro(base,mystery,0);
   square_up(black,base);
   return ring_stand_return();
   
//   return 0;


int ring_stand_return(){
    int ET=5;
    if(analog(ET)>2000){
    	turn_with_gyro(base,90,0);
        turn_with_gyro(base,-90,0);
        printf("rightleft");
    }
    if(analog(ET)<770){
        turn_with_gyro(base,-90,0);
        turn_with_gyro(base,90,0);
        printf("leftright");
    }
    square_up(black,base); 
    if(analog(ET)<2000&&analog(ET)>1600){
    	turn_with_gyro(base,-22,0);
        Drive(1500,base);
        printf("\n22");
    }
    if(analog(ET)<1600&&analog(ET)>1100){
    	turn_with_gyro(base,-30,0);
        Drive(1500,base);
        printf("\n30");
    }
    if(analog(ET)<1100&&analog(ET)>900){
    	turn_with_gyro(base,-40,0);
        Drive(1500,base);
        printf("\n40");
    }
    thread_destroy(servo_cntrl);
    return 0;
}

red: 3 
orange: 3 5/8
yellow: 3 7/8
green: 4 1/8
blue: 4 4/8
*/