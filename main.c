#include <kipr/wombat.h>
#include <create_func.h>
#include <functions.h>
#include <consts.h>
int main(){ 
    int main_speed = 250;
    int cube_reading=0;
    create_connect();
    printf("CONNECTED\n");
    set_servo_position(0,350);
    set_servo_position(2,550);
    set_servo_position(3,550);
    enable_servos();    
    slow_servo(0,1800,2);
    square_up_front_create(3,main_speed);
    create_backward(3,main_speed);
    msleep(50);
    rotate(-90);
    create_backward(12,main_speed);
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
    slow_servo(2,1500,2);
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
    rotate(-33);
    msleep(50);
    create_forward(15,main_speed);
    msleep(60);
    slow_servo(2,1870,2);
    slow_servo(3,1600,2);
    slow_servo(2,1450,2);
    //grab pom 4
    create_backward(15,main_speed);
    rotate(20);
    square_up_back_create(1,-1*main_speed);
    create_backward(5,main_speed);
    square_up_back_create(1,main_speed);
    rotate(185);
    create_backward(30,main_speed);
    square_up_back_create(1,main_speed);
    create_backward(5,main_speed);
    slow_servo(3,550,2);
    //drop pom 4
    rotate(150);
    create_forward(20,main_speed);
    slow_servo(2,1870,2);
    msleep(50);
    slow_servo(3,1500,2);
    slow_servo(2,1650,2);
    //grab pom 5
    create_backward(20,main_speed);
    rotate(30);
    create_backward(40,main_speed);
    square_up_back_create(2,main_speed);
    slow_servo(2,1870,2);
    slow_servo(3,550,2);
    slow_servo(2,1500,2);
    //drop pom 5
///////poms sorted//////////////////////////////////////////////////////////////////////////////////////
    rotate(-90);
    create_backward(10,main_speed);
    square_up_back_create(2,main_speed);
    create_forward(8,main_speed);
    rotate(90);
    msleep(3000);
    slow_servo(0,1855,2);
    slow_servo(2,1750,2);
    slow_servo(3,621,2);
    while((get_create_lfcliff_amt()>cliff)&&(buffer(1)<2920)){
    	create_drive_straight(main_speed);
        msleep(15);
    }
    create_stop();
    slow_servo(3,1100,2);
    slow_servo(2,900,2);
    create_backward(20,main_speed);
    rotate(90);
    create_backward(15,main_speed);
    square_up_front_create(3,main_speed);
    create_forward(15,main_speed);
    rotate(90);
    slow_servo(2,1750,2);
    while((get_create_lcliff_amt()>cliff)){
    	create_drive_straight(main_speed);
        msleep(15);
    }
    create_stop();
    create_backward(3,main_speed);
    slow_servo(3,621,2);
    slow_servo(2,1615,2);
    slow_servo(3,1100,2);
    slow_servo(2,1460,2);
    rotate(-5);
    while(analog(1)<1700){
    rotate(1);
    }
    slow_servo(2,1615,2);
    create_forward(5,main_speed);
    slow_servo(3,621,2);
    create_backward(20,main_speed);/*
///////////////////////////////////////////////////////////////////////////////////////////////////////
    rotate(80);
    slow_servo(2,1100,2);
    create_backward(10,main_speed);
    square_up_back_create(2,main_speed);
    create_forward(15,main_speed);
    rotate(90);
    square_up_front_create(2,main_speed);
    rotate(180);
    cube_reading=buffer(0);
    printf("nothing: %d\n",cube_reading);
    while(buffer(0)>cube_reading-65){
    	create_drive_straight(0.5*main_speed);
        msleep(15);
        int i=0;
        if(i%5==0){
        	printf("reading:%d\n",buffer(0));
        }
        i++;
    }
    create_stop();
    slow_servo(2,450,2);
    slow_servo(0,1265,2);
    slow_servo(3,700,2);
    create_backward(10,main_speed);
    rotate(90);
    slow_servo(2,1100,2);
    msleep(500);
    create_forward(10,main_speed);
    slow_servo(3,1100,2);
    slow_servo(2,600,2);
    create_backward(10,main_speed);*/
    create_disconnect();
    return 0;
}