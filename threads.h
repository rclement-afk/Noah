void starting_claw();
void thread_starting_pos();
void shift_h();
void shift_v();
//thread shift;
//void thread_shift(int dir);
//thread back;
//void thread_back();

///////////////////////////////////////////
//thread servo_cntrl;
#define max_0 2000
#define min_0 600
#define max_1 0
#define min_1 0
#define max_2 980
#define min_2 40
#define max_3 2000
#define min_3 250
int servo_positions[4];
int servo_controls[4][4];
int max,min;

void servo_control();
void smart_servo(int port, int perc, float time, int delay);
