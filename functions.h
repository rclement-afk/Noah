//main functs
void stop_it();
void line_follow(int side, int speed);
void slow_servo(int part, int des, int speed);
int buffer(int sensor);
void move(int l_speed, int r_speed);
void a_cel();
void de_cel();
void square_up(int ending, int speed);
int Rspd;
int Lspd;
void in_turn(int deg,int spd);
float itt(int tpr, float inches);
void ratio(int spd);
void in_drive(int spd, float des);