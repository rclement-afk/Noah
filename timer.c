#include <kipr/wombat.h>
#include <timer.h>
float time_arr[6];

void reset_timer(int ind){
    time_arr[ind]=seconds();
};
void reset_sys_timer(){
    time_arr[0]=seconds();
};
float sys_timer(){
    if(time_arr[0]==0){reset_sys_timer();}
    return seconds()-time_arr[0];
};
int timer(int ind){
    return seconds()-time_arr[ind];
};