#include <kipr/wombat.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/functions.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/consts.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/timer.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/threads.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/run_functs.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/clone_consts.h>
thread servo_cntrl;
void starting_claw(){
    slow_servo(claw,claw_max,1);
    msleep(1000);
}
void thread_starting_pos(){
    servo_cntrl = thread_create(servo_control);
    thread_start(servo_cntrl);
	///////////////////////////////////////
    thread starting_pos;
    starting_pos = thread_create(starting_claw);
    thread_start(starting_pos);
    slow_servo(shifter,shifter_ver, 1);
    msleep(1000);
    slow_servo(arm,arm_max,1);
    thread_destroy(starting_pos);
}
///////////////////////////////////////////
void shift_h(){
	slow_servo(shifter,shifter_hor,1);
}
void shift_v(){
	slow_servo(shifter,shifter_ver,1);
}
//thread shift;
//void thread_shift(int dir){
   // if(dir == 1){shift = thread_create(shift_h);}
   // if(dir == 0){shift = thread_create(shift_v);}
   // thread_start(shift);
//}
///////////////////////////////////////////
//thread back;
//void thread_back(){
//   back = thread_create(starting_claw);
 //  thread_start(back);
 ///  msleep(800);
 //  Drive(-800,-66);
 //  thread_shift(ver);
  // msleep(800);
 //  Drive(-800,-66);
 //  thread_destroy(shift);
//
///////////////////////////////////////////

void smart_servo(int port, int perc, float time, int delay){
    servo_controls[port][0]=get_servo_position(port);
    //msleep(50);
    //printf("%d\n",(int)servo_controls[port]);
    servo_controls[port][1]=perc;
    servo_controls[port][2]=time*100;
    servo_controls[port][3]=seconds()+delay;
}
//---------------------------------------//
int servo_controls[4][4]={{0,20,1,0},{0,50,1,0},{0,100,1,0},{0,100,1,0}};
void servo_control(){
    // 					|start pos|,|end pos|,|time|, |start time|
    float psi;
    enable_servos();
    msleep(100);
    while(1){
        if(seconds()-servo_controls[0][3]<=servo_controls[0][2]/100.0 && seconds()>servo_controls[0][3]){
            psi=servo_controls[0][0]+(((max_0-min_0)*(servo_controls[0][1]/100.0)+min_0)-servo_controls[0][0])*(seconds()-servo_controls[0][3])/(servo_controls[0][2]/100.0);
            set_servo_position(0,(int)psi);
            //printf("%f	",psi);
        }
        if(seconds()-servo_controls[1][3]<=servo_controls[1][2]/100.0 && seconds()>servo_controls[1][3]){
            psi=servo_controls[1][0]+(((max_1-min_1)*(servo_controls[1][1]/100.0)+min_1)-servo_controls[1][0])*(seconds()-servo_controls[1][3])/(servo_controls[1][2]/100.0);
            set_servo_position(1,(int)psi);
            //printf("%f	",psi);
        }
        if(seconds()-servo_controls[2][3]<=servo_controls[2][2]/100.0 && seconds()>servo_controls[2][3]){
            psi=servo_controls[2][0]+(((max_2-min_2)*(servo_controls[2][1]/100.0)+min_2)-servo_controls[2][0])*(seconds()-servo_controls[2][3])/(servo_controls[2][2]/100.0);
            set_servo_position(2,(int)psi);
            //printf("%f	",psi);
        }
        if(seconds()-servo_controls[3][3]<=servo_controls[3][2]/100.0 && seconds()>servo_controls[3][3]){
            psi=servo_controls[3][0]+(((max_3-min_3)*(servo_controls[3][1]/100.0)+min_3)-servo_controls[3][0])*(seconds()-servo_controls[3][3])/(servo_controls[3][2]/100.0);
            set_servo_position(3,(int)psi);
            //printf("%f	",psi);
        }

        msleep(30);
    }
}
//////////////////////////////////////////////////////////////////////////////////