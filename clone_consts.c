#include <kipr/wombat.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/functions.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/consts.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/timer.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/threads.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/run_functs.h>
#include </home/root/Documents/KISS/Default User/Wombat/include/clone_consts.h>
//int is_prime = 1;
void prime_or_clone(){
  if(is_prime == 1){
     return;
  }
  int *target_theta_45_c = &target_theta_45;
  int *target_theta_90_c = &target_theta_90;
  int *target_theta_180_c = &target_theta_180;
  int *target_theta_m45_c = &target_theta_m45;
  int *target_theta_m90_c = &target_theta_m90;
  int *target_theta_m180_c= &target_theta_m180;
    
  //clone: change your var values here
  *target_theta_45_c = 275970; 
  *target_theta_90_c = 541500; //563800
  *target_theta_180_c = 275970;
  *target_theta_m45_c = 275970;
  *target_theta_m90_c = 562150;
  *target_theta_m180_c = 1135100;
}