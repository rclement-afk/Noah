#include <math.h>
#include <kipr/wombat.h>
#include <UI.h>
#include <consts.h>

//file written by Carleigh Wilcox
//follow all directions listed in comments.
//copy+paste this line of code to main.c:
/*
	while(startup){button_press(); msleep(50);}
*/
//comment the line out if you do not want to use the ui
//add your program functions after the line
//change the below variables to match your robot. if N/A, leave it as 9
int cML = 0; //left motor
int cMR = 1; //right motor
int cM = 9; //any extra motor
int cET = 9; //ET
int cET2 = 9; //2nd ET
int clIR = 1; //left IR
int crIR = 0; //right IR
int clight = 6; //light sensor
int extra1 = 9; //any extra analog 
int extra2 = 9; //any extra analog
int cS0 = 0; //0th servo
int cS1 = 1; //1st servo
int cS2 = 2; //2nd servo
int cS3 = 3; //3rd servo

//no touchy beyond this line \/
/////////////////



// NO TOUCHY \/

int serv_var = 9;
int gyro_ang = 9;
int theta_val = 0;
int connect = 0;
int c_speed = 100;
double c_time = 1000;
int device = 0;

int choice = 1; 
int startup = 1;
int mainm = 0;
int start = 0;
int diag = 0;
int motorm = 0;
int servom = 0;
int serv = 0;
int gyrom = 0;
int thetam = 0;
int test_period = 0;
int thetam2 = 0;
int sensors = 0;
int create = 0;
int c_sensors = 0;
int c_drive = 0;
int c_deg;

void stop_all(){

}

void button_press(){    
    while(choice > 0){boot();}
    while(mainm > 0){f_startup();}
    while(diag > 0){f_diag();}
    while(start > 0){f_start();}
    while(motorm > 0){f_motors();}
    while(servom > 0){f_servos();}
    while(serv > 0){servos();}
    while(sensors > 0){f_sensors();}

}
void boot(){
    choice++;
    if(choice == 2){
        extra_buttons_show();
        printf("A Button: Boot\n\nWarning: Before pressing the stop button or backing out of the program, make sure you END PROGRAM\n");
    }
    if(a_button()){
        while(a_button()){msleep(50);}
        choice = 0;
        mainm = 1;
        printf("\n\n\nBooting..\n\n\n");
    }
}
void f_startup(){
    mainm++;
    if(mainm == 2){
    	printf("\nA Button: Start Robot\nB Button: Diagnostics\nZ Button: End Program\n");
    }
	if(a_button()){
        while(a_button()){msleep(50);}
        mainm = 0;
        start = 1;       
    } 
    if(b_button()){
        while(b_button()){msleep(50);}
        mainm = 0;
        diag = 1;
    } 
    if(z_button()){
    	while(z_button()){msleep(50);}
        printf("\nProgram Ended");
        choice = 0;
        start = 0;
        diag = 0;
        mainm = 0;
        motorm = 0;
        servom = 0;
        serv = 0;
        gyrom = 0;
        test_period = 0;
    	startup = 0;
    }
}

void f_start(){
    start++;
    if(start == 2){
    	printf("\nA Button: Light\nB Button: Start Now\nC Button: Countdown\nZ Button: Cancel\n");
    }
	if(a_button()){
        while(a_button()){msleep(50);}
        int val;
        if(clight == 9){
        	printf("\nPlease change the value of your light sensor variable.\n");
            start = 0;
            mainm = 1;
        }
        val = analog(clight);
        while(val > 500 && clight != 9){    
            val = analog(clight); 
        	printf("\nCalibrating: %d",val);
            msleep(500);
            console_clear();
            if(val < 500){//function
                printf("\n\n\nStarting!\n\n\n");
            	startup = 0;
            }
            //function
   		 } 
    }
    if(b_button()){
        while(b_button()){msleep(50);}
		printf("\n\n\nStarting!\n\n\n");
        start = 0;
        startup = 0;
        //function
    } 
    if(c_button()){
        while(c_button()){msleep(50);}
        start = 0;
        startup = 0;
        int i = 1;
        printf("\n\n\n");
    	while(i < 4){
            printf("%d, ",i);
        	msleep(1000);
            i++;    
        }
        printf("\n\n\nStarting!\n\n\n");
        //function
    }
    if(z_button()){
    	while(z_button()){msleep(50);}
       	printf("\nCanceled\n");
    	start = 0;
        mainm = 1;
    }
}

void f_diag(){
    diag++;
    if(diag == 2){
    	printf("\nA Button: Motors\nB Button: Servos\nC Button: Wallaby Gyroscope\nX Button: Sensors\nY Button: Create\nZ Button: Cancel\n");
    }
	if(a_button()){
        while(a_button()){msleep(50);}
    	diag = 0;
        motorm = 1;
    }
    if(b_button()){
        while(b_button()){msleep(50);}
    	diag = 0;
        servom = 1;
    }
    if(c_button()){
    }
    if(x_button()){
    	while(x_button()){msleep(50);}
    	diag = 0;
        sensors = 1;
    }
    if(y_button()){
    }
     if(z_button()){
    	while(z_button()){msleep(50);}
       	printf("\nCanceled\n");
    	diag = 0;
        mainm = 1;
    }
}
void f_motors(){
    motorm++;
    if(motorm == 2){
    	printf("\nA Button: Left Motor\nB Button: Right Motor\nC Button: Misc Motor\nX Button: Drive\nZ Button: Cancel\n");
    }
	if(a_button()){
        while(a_button()){msleep(50);}
        if(cML != 9){
        	motors(cML, 1); 
        	motors(cML, -1);
        }else{
            printf("\nYour motor is not valid.\n");
        }
    }
    if(b_button()){
        while(b_button()){msleep(50);}
        if(cMR != 9){
        	motors(cMR, 1); 
        	motors(cMR, -1);
        }else{
            printf("\nYour motor is not valid.\n");
        }
    }
    if(c_button()){
        while(c_button()){msleep(50);}
        if(cM != 9){
        	motors(cM, 1); 
        	motors(cM, -1);
        }else{
            printf("\nYour motor is not valid.\n");
        }
    }
    if(x_button()){
        while(x_button()){msleep(50);}
        if(cML != 9 && cMR != 9){
        	device = 0;
            motorm = 0;
            c_drive = 1;
        }else{
            printf("\nYour motors are not valid.\n");
        }
        
    }
    if(z_button()){
    	while(z_button()){msleep(50);}
       	printf("\nCanceled\n");
    	motorm = 0;
        diag = 1;
    }
}
void motors(int motor, int dir){
    if(motor != 9){
		printf("\n\n\nMotor Test In Progress: \n");
    	msleep(600);
    	cmpc(motor);
    	if(dir < 0){
    		while(gmpc(motor) > dir*600){
          		mav(motor,dir*200);
     		}
   		 }
    	if(dir > 0){
    		while(gmpc(motor) < dir*600){
          		mav(motor,dir*200);
     		}
   		 }
   		 printf("Motor: %d ticks",gmpc(motor));
    	 mav(motor,0);
    }
}
void f_servos(){
    servom++;
    if(servom == 2){
    	printf("\nA Button: 0th Servo\nB Button: 1st Servo\nC Button: 2nd Servo\nX Button: 3rd Servo\nZ Button: Cancel\n");
    }
	if(a_button()){
        while(a_button()){msleep(50);}
        servom = 0;
        serv = 1;
        serv_var = 0;
    }
    if(b_button()){
        while(b_button()){msleep(50);}
        servom = 0;
        serv = 1;
        serv_var = 1;
    }
    if(c_button()){
        while(c_button()){msleep(50);}
        servom = 0;
        serv = 1;
        serv_var = 2;
    }
    if(x_button()){
        while(x_button()){msleep(50);}
        servom = 0;
        serv = 1;
        serv_var = 3;
    }
    if(z_button()){
    	while(z_button()){msleep(50);}
    	servom = 0;
        serv_var = 9;
        diag = 1;
    }
}
void servos(){
    serv++;
    if(serv == 2){
    	printf("\nA Button: Up 10\nB Button: Down 10\nC Button: Up 100\nX Button: Down 100\nZ Button: Cancel\n");
    }
    if(a_button()){
        while(a_button()){msleep(50);}
    	servo_move(serv_var,10);
        msleep(50);
    }
    if(b_button()){
        while(b_button()){msleep(50);}
    	servo_move(serv_var,-10);
        msleep(50);
    }
    if(c_button()){
        while(c_button()){msleep(50);}
    	servo_move(serv_var,100);
        msleep(50);
    }
    if(x_button()){
        while(x_button()){msleep(50);}
    	servo_move(serv_var,-100);
        msleep(50);
    }
	if(z_button()){
    	while(z_button()){msleep(50);}
       	printf("\nCanceled\n");
        serv = 0;
        servom = 1;
    }
}
void servo_move(int servo, int pos){
    servo = serv_var;
	enable_servos();
    msleep(100);
    if(get_servo_position(servo)+pos > 2047){set_servo_position(servo,2047); return;}
    if(get_servo_position(servo)+pos < 0){set_servo_position(servo,0); return;}
    set_servo_position(servo,get_servo_position(servo) + pos);
    msleep(100);
    disable_servos();
    printf("Position: %d\n",get_servo_position(servo));
}

void f_sensors(){
		printf("\nTesting Sensors:\n");
             int sensorsA[] = {cET,cET2,clIR,crIR,clight,extra1,extra2};
             int i = 0;
             while(i<7){
                if(sensorsA[i] != 9){
                     printf("Sensor %d: ",sensorsA[i]);
                     printf("%d\n",analog(sensorsA[i]));
               	}
                 	i++;
              }
            printf("\nZ Button: Cancel\n");
    		int j = 0;
    		while(j < 250){
            	msleep(1);
                j++;
                if(z_button()){
             		while(z_button()){msleep(50);}
            	 	printf("Sensor Test Concluded!\n");
             		sensors = 0;
            		diag = 1;       
         		}
            }
        	console_clear();
         if(z_button()){
             while(z_button()){msleep(50);}
             printf("Sensor Test Concluded!\n");
             sensors = 0;
            diag = 1;
                    
         }
}

void drive(){
    //msleep(500);
    if(device){
    	create_drive_direct(c_speed, c_speed);
   	 	msleep(c_time);
    	create_drive_direct(0,0);
    }
	if(!device){
        cmpc(cML);
        cmpc(cMR);
    	mav(cML,c_speed);
        mav(cMR,c_speed);
        msleep(c_time);
        mav(cML,0);
        mav(cMR,0);
        printf("\nLeft Motor: %d ticks\n",gmpc(cML));
        printf("\nRight Motor: %d ticks\n",gmpc(cMR));
        ao();
    }
    printf("\nA Button: Go\nB Button: Up Speed\nC Button: Down Speed\nX Button: Up Time\nY Button: Down Time\nZ Button: Cancel\n");
}
void change_deg(){

}