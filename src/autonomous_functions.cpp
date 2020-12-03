#include "autonomous.h"
#include "configure/config.h"


/*
Move all four motors on the chassis based on time (in milliseconds) and
power (in millivolts from -12000 to 12000)
*/
void time_based(float time, float power){
  frontL.move_voltage(power);
  frontR.move_voltage(power);
  backL.move_voltage(power);
  backR.move_voltage(power);
  pros::delay(time);
  frontL.move_voltage(0);
  frontR.move_voltage(0);
  backL.move_voltage(0);
  backR.move_voltage(0);
}
/*
Assumes initial velocity is 0 and end velocity is 0
start position is received from odom
end position is distance
acc is m/s^2
max_vel
*/
void generate_velocity_profile_throttle(float distance, float max_vel, float acc, int steps){
  float start_vel_to_full_speed_time = max_vel/acc;
  // x = 1/2*a*t^2
  float accel_accumulated_dist = 1/2 * acc * pow(start_vel_to_full_speed_time, 2);
  float
//  https://github.com/dov/onedmotion/blob/master/onedmotion.py
}

//
// int balanceThreshold = 5;
// void encoderPID(float target, float threshold){
//  int initial_eL =encoderL.get_value();
//  int initial_eR = encoderR.get_value();
//  int power = 0;
//  int lPower = 0;
//  int rPower = 0;
//  float error = target;
//  float integral = 0;
//  float kP = 0.5;
//  float kI = 0.01;
//  float kD = 0.0;
//  float dT = 0;
//
//  float balanceError = 0;
//  float kBP = 0.5;
//  float kBI = 0.01;
//  float kBD = 0.0;
//
// 	 while (fabs(error) > fabs(threshold)){
//
//      integral = integral + error;
//
//      if (fabs(error) > 30){
//        integral = 0;
//      }
//
//      if(target * error <= 0){
//            integral = 0;
//          }
// 		// debug_text(std::to_string(error));
// 		 error = target - encoderL.get_value() - initial_eL;
// 		 // std::cout<<error;
//      power = error*kP + integral*kI;
//      lPower = power;
//      rPower = power;
//      balanceError = (encoderL.get_value() - initial_eL) - (encoderR.get_value() - initial_eR);
//      // if balance error is positive while moving forward, left side is too much.
//      // if balance error is negative while movign forward, right side is too much.
//      // if balance error is positive while moving backwards, right side is too much.
//      // if balance error is negative while moving backwards, left side is too much
//      if(fabs(balanceError) > balanceThreshold){
//        if(target > 0){
//          lPower = power - balanceError * kBP;
//          rPower = power + balanceError * kBP;
//        }
//        else if(target < 0){
//          lPower = power + balanceError * kBP;
//          rPower = power - balanceError * kBP;
//        }
//      }
//  		 frontL.move(lPower);
//  		 frontR.move(rPower);
//  		 backL.move(lPower);
//  		 backR.move(rPower);
// 		 pros::delay(10);
//      dT = dT + 10;
// 	 }
// 		 frontL.move(0);
// 		 frontR.move(0);
// 		 backL.move(0);
// 		 backR.move(0);
//
// }
//
// void turnLeftPID(float target, float threshold){
//  //pros::ADIEncoder sensor (encoderL_port_top, encoderL_port_bottom, false);
//  int current_valueL1=encoderL.get_value();
//  //int current_valueL2=encoderR.get_value();
//  int power = 50;
//  float error = target;
// 	 while (error > threshold){
// 		 debug_text(std::to_string(error));
// 		 //frontL.move(power);
// 		 //frontR.move(power);
// 		 backL.move(-1*power);
// 		 backR.move(power);
// 		 error = target - encoderL.get_value() - current_valueL1;
// 		 //error = target - encoderR.get_value() - current_valueL2;
// 		 std::cout<<error;
// 		 pros::delay(10);
// 	 }
// 		 frontL.move(0);
// 		 frontR.move(0);
// 		 backL.move(0);
// 		 backR.move(0);
//
// }
