//main functs


int  calibrate();
	void pre_run();
 void run_2();

int itt(float inches);
void wait_light();
void line_follow(int side, int speed);
void slow_servo(int part, int des, int speed);
int buffer(int sensor);
void move(int l_speed, int r_speed);
void a_cel();
void de_cel();
void Drive(int desired,int speed);
void square_up(int ending, int speed);
double calibrate_gyro();
void drive_with_gyro(int speed, double time);
void turn_with_gyro(int speed, int deg, int frz);
void PID_gyro_drive(int speed,double time);
void drive_with_ticks(int tic);
void grab_poms();
void turn_with_tic();
void right_turn();
void left_turn();
void grab_poms_left();
void b_drive();
void run();