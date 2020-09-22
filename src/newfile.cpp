#include "auton_functions.h"
#include "../configure/config.h"
#include <fstream>

// CONSTANTS

void max_acceleration(){
  std::cout << "Velocity, Time(ms) \n";
  frontL.move_velocity(-200);
  frontR.move_velocity(-200);
  backL.move_velocity(-200);
  backR.move_velocity(-200);
  int time = 0;
  double vel = 0;
  while(frontL.get_actual_velocity()<-198){
    vel = frontL.get_actual_velocity();
    std::cout  << vel << ',' << time << std::endl;
    pros::delay(1);
    time++;
  }
  while(time<4000){
    std::cout  << vel << ',' << time << std::endl;
    pros::delay(1);
    time++;
  }
  frontL.move_velocity(0);
  frontR.move_velocity(0);
  backL.move_velocity(0);
  backR.move_velocity(0);
}

/*void tilterPID(float target, float threshold){
  tray.set_brake_mode(MOTOR_BRAKE_BRAKE);
  float kP = 0.5;
  float kI = 0.01;
  float kD = 0;
  int integral = 0;
  float power = 0;
  int tilter_value = tray.get_position();
  float error = target;
  int dT = 0;
  printf("Time, Error\n");
  while(fabs(error) > fabs(threshold)){

    integral = integral + error;
    if(fabs(error) > 30){
      integral = 0;
    }
    if(target * error <= 0){
      integral = 0;
    }

    power = error * kP + integral * kI;
    tray.move_velocity(power);
    error = target - tray.get_position() - tilter_value;
    // printf("Tilter = %lf\n", tray.get_position());
    // printf("Velocity = %lf\n", tray.get_actual_velocity());
    //
    printf("%d, ", dT);
    printf("%lf\n", error);
    pros::delay(10);
    dT = dT + 10;
  }

  tray.move_voltage(0);

}*/

// PID for the base
void basePID(float target, float threshold)
{
  float kP = 0.5; // test
  float kI = 0; // test
  float kD = 0;
  //int integral = 0;
  float power = 0;
  int base_value = frontL.get_position();
  float error = target;
  int dT = 0;
  printf("Time, Error\n");
  while(fabs(error) > fabs(threshold))
  {
    // integral = integral + error;
    // if(fabs(error) > 30)
    // {
    //   integral = 0;
    // }
    //
    // if(target * error <= 0)
    // {
    //   integral = 0;
    // }

    power = error * kP; //+ integral * kI;
    frontL.move_voltage(power * 6);
    frontR.move_voltage(power * 6);
    backL.move_voltage(power * 6);
    backR.move_voltage(power * 6);
    error = target - frontL.get_position() - base_value;
    printf("Base = %lf\n", frontL.get_position());
    printf("Voltage = %i\n", frontL.get_voltage());
    pros::delay(10);
    dT = dT + 10;
  }

  frontL.move_voltage(0);
  frontR.move_voltage(0);
  backL.move_voltage(0);
  backR.move_voltage(0);


}
