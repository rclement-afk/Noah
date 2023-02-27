#include <kipr/wombat.h>
#include <create_func.h>
#include <functions.h>
#include <consts.h>
int main(){ 
    int main_speed = 250;
    int cube_reading=0;
    //int turn_speed = 250;
    //claw open 550
    //claw closed 1550
    //wrist up 550
    //wrist down 1830
    //arm up 350
    //arm down 1875
    create_connect();
    printf("CONNECTED\n");
    set_servo_position(1,350);
    set_servo_position(2,550);
    set_servo_position(3,550);
    enable_servos();
    msleep(2000);
    printf("%d\n",get_create_lbump());
    
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
    slow_servo(2,1870,2);
    slow_servo(3,550,2);
    slow_servo(2,1650,2);
    //drop pom 4
    rotate(155);
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
    slow_servo(2,1650,2);
    //drop pom 5
///////poms sorted//////////////////////////////////////////////////////////////////////////////////////
    create_backward(30,main_speed);
    create_forward(5,main_speed);
    rotate(-90);
    create_backward(15,main_speed);
    square_up_back_create(2,main_speed);
    slow_servo(2,800,2);
    while(get_create_lbump()<1||get_create_rbump()<1){
    	msleep(15);
        create_drive_straight(main_speed);
    }
    msleep(15);
    create_stop();
    msleep(15);
    create_backward(3,main_speed);
    rotate(-90);
    cube_reading=analog(0);
    printf("nothing: %d\n",cube_reading);
    while(analog(0)<cube_reading+100){
    	create_drive_straight(-1*main_speed);
    }
    create_stop();
    slow_servo(2,450,2);
    slow_servo(0,1265,2);
    slow_servo(3,700,2);
    create_forward(15,main_speed);
    rotate(90);
    slow_servo(2,1100,2);
    slow_servo(3,1100,2);
    slow_servo(2,600,2);
    create_disconnect();
    return 0;
}