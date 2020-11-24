#include "main.h"

// forces a declaration without a definition
extern const int frontL_port;
extern const int frontR_port;
extern const int backL_port;
extern const int backR_port;


extern pros::Controller controller;
extern pros::Motor frontL;
extern pros::Motor frontR;
extern pros::Motor backL;
extern pros::Motor backR;
extern pros::Motor leftIntake;
extern pros::Motor rightIntake;
extern pros::Motor topRoller;
extern pros::Motor botRoller;

extern pros::ADIEncoder encoderL;
extern pros::ADIEncoder encoderR;
extern pros::ADIEncoder encoderM;

extern pros::Imu imu_sensor;
