
#include <kipr/wombat.h>
#include <math.h>
#include <create_func.h>

void create_forward(int dist, int speed){
    dist*=10; //Converts centimeters into millimeters
    set_create_distance(0); //Clears create position counter
    create_drive_straight(speed); //Initializes movement
    while(get_create_distance()<dist) //Waits until distance traveled reaches distance
    {
        msleep(1);
    }
    create_stop(); //Stops movement
    msleep(15);
}

void create_backward(int dist, int speed){
    dist*=10; //Converts centimeters into millimeters
    set_create_distance(0); //Clears create position counter
    create_drive_straight(-speed); //Initializes movement
    while(get_create_distance()>-dist) //Waits until distance traveled reaches distance
    {
        msleep(1);
    }
    create_stop(); //Stops movement
    msleep(15);
}

void create_rotate(int degrees, int speed, int direction){
    msleep(15);
    create_stop();
    msleep(15);
    switch(direction){
        case 2:
            set_create_total_angle(0);
            
            while(get_create_total_angle()<degrees)
            {
                create_drive_direct(-speed, speed);
            }
            create_stop();
            break;
        case 1:
            set_create_total_angle(0);
            create_drive_direct(speed, -speed);
            while(get_create_total_angle()>-degrees)
            {
                msleep(1);
            }
            create_stop();
            break;
    }
}

int white = 1;
int black = 2;
int physical = 3;
int black_speed;
void square_up_front_create(int ending,int speed){
    if(speed > 0 && speed < 600){
        black_speed = 0.5*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2|| ending==3){
        while(1){
            if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                create_drive_direct(speed,speed);
            }
            if(get_create_rfcliff_amt()<cliff){
                create_drive_direct(speed,stop);
            }
            if(get_create_lfcliff_amt()<cliff){
                create_drive_direct(stop,speed);
            }
            if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff) {
                create_drive_direct(stop,stop);
                break;
            }
        }
    }
    switch(ending){
        case 1:
            {
                while(1){
                    if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff){
                        create_drive_direct(black_speed,black_speed);
                    }
                    if(get_create_lfcliff_amt()>cliff){
                        create_drive_direct(stop,black_speed);
                    }
                    if(get_create_rfcliff_amt()>cliff){
                        create_drive_direct(black_speed,stop);
                    }
                    if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
        case 2:
            {
                while(1){
                    if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff){
                        create_drive_direct(-1*black_speed,-1*black_speed);
                    }
                    if(get_create_lfcliff_amt()>cliff){
                        create_drive_direct(stop,-1*black_speed);
                    }
                    if(get_create_rfcliff_amt()>cliff){
                        create_drive_direct(-1*black_speed,stop);
                    }
                    if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
        case 3:
            {
                
            }
    }
}
void square_up_back_create(int ending,int speed){
    if(speed > 0 && speed < 600){
        black_speed = 0.5*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2){
        while(1){
            if(get_create_lcliff_amt()>cliff && get_create_rcliff_amt()>cliff){
                create_drive_direct(speed,speed);
            }
            if(get_create_rcliff_amt()<cliff){
                create_drive_direct(speed,stop);
            }
            if(get_create_lcliff_amt()<cliff){
                create_drive_direct(stop,speed);
            }
            if(get_create_lcliff_amt()<cliff && get_create_rcliff_amt()<cliff) {
                create_drive_direct(stop,stop);
                break;
            }
        }
    }
    switch(ending){
        case 1:
            {
                while(1){
                    if(get_create_lcliff_amt()<cliff && get_create_rcliff_amt()<cliff){
                        create_drive_direct(black_speed,black_speed);
                    }
                    if(get_create_lcliff_amt()>cliff){
                        create_drive_direct(stop,black_speed);
                    }
                    if(get_create_rcliff_amt()>cliff){
                        create_drive_direct(black_speed,stop);
                    }
                    if(get_create_lcliff_amt()>cliff && get_create_rcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
        case 2:
            {
                while(1){
                    if(get_create_lcliff_amt()<cliff && get_create_rcliff_amt()<cliff){
                        create_drive_direct(-1*black_speed,-1*black_speed);
                    }
                    if(get_create_lcliff_amt()>cliff){
                        create_drive_direct(stop,-1*black_speed);
                    }
                    if(get_create_rcliff_amt()>cliff){
                        create_drive_direct(-1*black_speed,stop);
                    }
                    if(get_create_lcliff_amt()>cliff && get_create_rcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }

            }
            case 3:
            {
                
            }
    }
}
void linefollow_create(int speed){
    while(1){
        if(get_create_rcliff_amt()<cliff){
            create_drive_direct((3*speed)/4,speed);
        }
        if(get_create_rcliff_amt()>cliff){
            create_drive_direct(speed,(3*speed)/4);
        }
    }
}
void move(int l_speed,int r_speed){
    create_drive_direct	(l_speed,r_speed);		
}

void rotate(int deg){
    int fast=250;
    int speed,prev=0,theta=0;
    float modif;
    modif=1.09;
    deg=-1*deg*modif;
    set_create_total_angle(0);
    while(theta>deg+1 || theta<deg-1){
        theta=get_create_total_angle();

        //total_angle sometimes glitches out and this saves it
        if(theta>prev+10 || theta<prev-10){set_create_total_angle(prev);printf("\n=_=\n");theta=get_create_total_angle();}

        prev=theta;
        speed=(10*(deg-theta))^4;
        if(speed> 	fast){speed=   fast;}
        if(speed<-1*fast){speed=-1*fast;}
        create_drive_direct(speed*-1,speed*1);
        msleep(15);
        //printf("%d ",theta);
    }
    printf("rotate:%f\n",(get_create_total_angle()/modif*-1));
    create_drive_direct(0,0);
}
