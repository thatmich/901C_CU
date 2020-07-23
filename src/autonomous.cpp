#include "configure/config.h"
#include "odom.h"
#include "graphics/lvgl_functions.h"

float acceleration_constant = 7;

double velocity_tmp = 0;
double movedDistance = 0;
void motion_prof1D(float distance, int max_speed){
  float start_y = gposition.y;
  while(frontL.get_actual_velocity() < max_speed || movedDistance <= distance/2){
    velocity_tmp+= acceleration_constant;
    frontL.move_velocity(velocity_tmp);
    backL.move_velocity(velocity_tmp);
    frontR.move_velocity(velocity_tmp);
    backR.move_velocity(velocity_tmp);

    movedDistance = gposition.y;
    pros::delay(50);
  }
  debug_text("ACCELERATION FINISHED");
  float acc_distance = movedDistance;
  while(movedDistance - acc_distance < acc_distance){
    movedDistance = gposition.y;
    pros::delay(50);
  }
  debug_text("CRUISE");
  while(movedDistance < distance && velocity_tmp >0){
    velocity_tmp-= acceleration_constant;
    frontL.move_velocity(velocity_tmp);
    backL.move_velocity(velocity_tmp);
    frontR.move_velocity(velocity_tmp);
    backR.move_velocity(velocity_tmp);

    movedDistance = gposition.y - start_y;
    pros::delay(50);
  }
  debug_text("DECELERATION FINISHED");


  velocity_tmp = 0;
  frontL.move_velocity(velocity_tmp);
  backL.move_velocity(velocity_tmp);
  frontR.move_velocity(velocity_tmp);
  backR.move_velocity(velocity_tmp);

}
