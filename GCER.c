#include <kipr/wombat.h>
#include <functions.h>
#include <consts.h>
#include <UI.h>
#include <GCER.h>

int dspd = 950;
int tspd = 550;
int sqspd = 500;

int god_start(){
	//while(startup){button_press(); msleep(50);}
    slow_servo(arm,arm_min+630,1);
    slow_servo(claw,claw_max,1);
    reset_timer(1);
    return pom_sort();
}
int pom_sort(){   
    //perfect code
    //25
    in_turn(-28,tspd);
    slow_servo(arm,arm_min+270,1);
    in_drive(dspd,7);
    slow_servo(claw,claw_min,2);
    msleep(100);
    in_turn(28,tspd);
    square_up(2,sqspd);
    in_drive(-1*dspd,2.5);
    slow_servo(arm,arm_min + 800,2);
    //
    /*
    in_drive(dspd,10);
    in_turn(90,tspd);
    in_drive(-1*dspd,9);
    square_up(2,-1*sqspd);
    in_drive(dspd,10);
    slow_servo(arm,arm_min+400,2);
    in_turn(42,tspd);
    slow_servo(claw,claw_max,2);
    slow_servo(arm,arm_max-200,2);
    in_turn(47,tspd);
  
    //in_drive(dspd,1);
    square_up(2,-1*sqspd);
    in_drive(dspd,15);
    in_turn(-90,tspd);
    
    msleep(200);
    //in_drive(-1*dspd,4);
    printf("im here");
    square_up(1,sqspd);
    */
    
    in_turn(90,tspd);
    square_up(2,sqspd);
    
    slow_servo(arm,arm_min+600,2);
    msleep(100);
    
    
    in_turn(42,tspd+50);
    slow_servo(claw,claw_max,2);
    in_turn(-42,tspd+50);
     slow_servo(arm,arm_min+400,1);
    msleep(100);
    square_up(2,sqspd);
    
    in_drive(dspd,20);
    
    in_turn(25,tspd);
    in_drive(dspd,6.3);
    slow_servo(claw,claw_min,2);
    
    
    in_drive(-1*dspd,5);
    in_turn(-20,tspd);
    slow_servo(arm,arm_max-200,1);
    in_drive(-1*dspd,17);
    square_up(2,-1*sqspd);
    in_drive(-1*dspd,14);
    square_up(2,sqspd);
    //in_drive(dspd,2);
    in_turn(-90,tspd);
    in_drive(-1*dspd,4);
    slow_servo(arm,arm_min+400,1);
    
    slow_servo(claw,claw_max,2);
    //square_up(2,-1*sqspd);
    //OG
    /*
    in_turn(90,tspd);
    square_up(2,sqspd);
    slow_servo(arm,arm_min + 500,1);
    in_turn(40,tspd+50);
    slow_servo(claw,claw_max,2);
    in_turn(-40,tspd+50);
     slow_servo(arm,arm_min + 900,1);
    square_up(2,sqspd);
    
    in_drive(dspd,12);
    in_turn(-90,tspd);
    msleep(800);
    in_drive(-1*dspd,6);
    slow_servo(arm,arm_min+250,1);
    in_drive(dspd,5);
    slow_servo(claw,claw_min,2);
    square_up(2,sqspd);
    
    slow_servo(arm,arm_min + 900,1);
    in_turn(90,tspd);
    in_drive(-1*dspd,8);
    square_up(2,-1*sqspd);
    slow_servo(arm,arm_min + 500,1);
    in_turn(50,tspd+50);
    slow_servo(claw,claw_max,2);
    in_turn(-50,tspd+50);
    square_up(2,-1*sqspd);
    in_drive(dspd,19);
    
    slow_servo(arm,arm_min + 500,1);
    in_turn(15,tspd);
    in_drive(dspd,5);
    slow_servo(claw,claw_min+200,2);
    
    in_drive(-1*dspd,5);
    in_turn(-20,tspd);
    slow_servo(arm,arm_max-200,1);
    in_drive(-1*dspd,10);
    in_turn(90,tspd);
    in_turn(90,tspd);
    square_up(2,-1*sqspd);
    in_drive(dspd,6);
    square_up(1,sqspd);
    in_drive(dspd,6);
    in_turn(90,tspd);
    in_drive(-1*dspd,6);
    slow_servo(arm,arm_min+400,1);
    in_drive(dspd,8);
    
    slow_servo(claw,claw_max,2);
    //square_up(2,-1*sqspd);
    */
	return noodles();
}
int noodles(){
    console_clear();
    printf("\n%d time\n",timer(1));
    //in_drive(-400,2);
    //msleep(2000);
    return 0;
}