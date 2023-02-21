int cML; //left motor
int cMR; //right motor
int cM; //any extra motor
int cET; //ET
int cET2; //2nd ET
int clIR; //left IR
int crIR; //right IR
int clight; //light sensor
int extra1; //any extra analog 
int extra2; //any extra analog
int cS0; //0th servo
int cS1; //1st servo
int cS2; //2nd servo
int cS3; //3rd servo
int c45;
int cm45;
int c90;
int cm90;
int c180;
int cm180;

int choice;
int startup;
int test_period;
void button_press();
void boot();
void f_startup();
void f_start();
void f_diag();
void f_gyro();
void f_motors();
void motors(int motor, int dir);
void motors2(int dir);
void f_servos();
void servos();
void servo_move();
void gyro_test();
void f_theta();
void theta2();
void change_theta(int val);
void f_sensors();
void fc_sensors();
void f_create();
void fc_drive();
void drive();
void rundown();
void change_deg();
//void ET_run(int ET_des);