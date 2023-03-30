#include <kipr/wombat.h>
#include <create_func.h>
#include <functions.h>
#include <consts.h>
int main(){ 
    int main_speed = 250;
    //int cube_reading=0;
    create_connect();
    printf("CONNECTED\n");
    printf("%d\n",get_create_battery_charge());
    set_servo_position(0,350);
    set_servo_position(2,550);
    set_servo_position(3,550);
    enable_servos();    
    slow_servo(0,1800,2);
    square_up_front_create(3,main_speed);
    //create_backward(3,main_speed);
    msleep(50);
    rotate(-90);
    create_backward(15,main_speed);
    slow_servo(2,1870,2);
    msleep(50);
    slow_servo(3,1600,2);
    slow_servo(2,1600,2);
    //grab palm 1
    create_forward(10,main_speed);
    msleep(50);
    rotate(90);
    create_backward(15,main_speed);
    square_up_back_create(1,main_speed);
    slow_servo(2,1870,2);
    slow_servo(3,550,2);
    slow_servo(2,700,2);
    //drop pom 1
    create_forward(5,main_speed);
    msleep(50);
	rotate(-90);
    create_backward(11,main_speed);
    slow_servo(2,1870,2);
    msleep(50);
    slow_servo(3,1600,2);
    slow_servo(2,1650,2);
    //grab pom 2
    create_forward(5,main_speed);
    msleep(50);
    rotate(-90);
    square_up_front_create(3,-1*main_speed);
    slow_servo(2,1870,2);
    slow_servo(3,550,2);
    slow_servo(2,1650,2);
    //drop pom 2
    square_up_back_create(1,main_speed);
    rotate(110);
    slow_servo(2,1870,2);
    
    //grab pom 3
    rotate(65);
    slow_servo(2,1650,2);
    square_up_front_create(1,-1*main_speed);
    square_up_back_create(1,main_speed);
    slow_servo(2,1870,2);
    slow_servo(3,550,2);
    slow_servo(2,1650,2);
    //drop pom 3
    rotate(-27);
    msleep(50);
    create_forward(15,main_speed);
    msleep(60);
    slow_servo(2,1870,2);
    slow_servo(3,1600,2);
    slow_servo(2,1450,2);
    //grab pom 4
    rotate(-70);
    create_backward(10,main_speed);
    rotate(-90);
    square_up_back_create(1,main_speed);
    //create_backward(5,main_speed);
    //square_up_back_create(1,main_speed);
    //rotate(185);
    //create_backward(35,main_speed);
    //square_up_back_create(1,main_speed);
    //create_backward(5,main_speed);
    slow_servo(3,550,2);
    //drop pom 4
    rotate(163);
    create_forward(29,main_speed);
    slow_servo(2,1870,2);
    msleep(50);
    slow_servo(3,1500,2);
    slow_servo(2,1050,2);
    //grab pom 5
    create_backward(20,main_speed);
    rotate(25);
    create_backward(45,main_speed);
    square_up_back_create(2,main_speed);
    slow_servo(2,1870,2);
    slow_servo(3,550,2);
    slow_servo(2,1500,2);
    //drop pom 5
///////poms sorted//////////////////////////////////////////////////////////////////////////////////////
    rotate(-90);
    create_backward(15,main_speed);
    square_up_back_create(2,main_speed);
    create_forward(8,main_speed);
    rotate(93);
    //msleep(3000);
    slow_servo(0,1855,2);
    slow_servo(2,1750,2);
    slow_servo(3,621,2);
    while((get_create_lfcliff_amt()>cliff)&&(buffer(1)<2920)){
    	create_drive_straight(main_speed);
        msleep(15);
    }
	create_forward(5,main_speed);
    slow_servo(3,1100,2);
    slow_servo(2,900,2);
    create_backward(20,main_speed);
    rotate(90);
    create_backward(20,main_speed);
    square_up_front_create(3,main_speed);
    create_forward(15,main_speed);
    rotate(89);
    slow_servo(2,1750,2);
    while((get_create_lcliff_amt()>cliff)){
    	create_drive_straight(main_speed);
        msleep(15);
    }
    create_stop();
    create_backward(4,main_speed);
    slow_servo(3,621,2);
    slow_servo(2,1615,2);
    slow_servo(3,1100,2);
    slow_servo(2,1600,2);
    rotate(-10);
    while(analog(1)<1700){
    	create_spin_CW(50);
        msleep(15);
    }
    create_spin_CCW(50);
        msleep(20);
    create_forward(6,main_speed);
    slow_servo(3,621,2);
    create_backward(20,main_speed);
///////////////////////////////////////////////////////////////////////////////////////////////////////
    //square_up_back_create(2,-1*main_speed);
    rotate(80);
    slow_servo(0,1300,2);
    slow_servo(2,400,2);
    create_backward(10,main_speed);
    square_up_back_create(2,main_speed);
    create_backward(10,main_speed);
    rotate(-90);
    square_up_back_create(1,main_speed);
    msleep(50);
    //create_forward(5,main_speed);
    rotate(-280);
    square_up_back_create(1,main_speed);
    create_forward(40,main_speed);
    slow_servo(3,1150,2);
    slow_servo(2,300,2);
    square_up_back_create(2,-1*main_speed);
    rotate(125);
    slow_servo(2,1600,2);
    slow_servo(3,500,2);
    slow_servo(2,1000,2);
    rotate(45);
    create_backward(15,main_speed);
    square_up_back_create(2,main_speed);
    create_forward(35,main_speed);
    rotate(-90);
    //create_forward(30,main_speed);
    //create_backward(30,main_speed);
    rotate(-90);
    square_up_back_create(2,main_speed);
    create_disconnect();
    return 0;
}