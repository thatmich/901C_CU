#include "config.h"
#define QUAD_TOP_PORTL 'A'
#define QUAD_BOTTOM_PORTL 'B'
#define QUAD_TOP_PORTR 'C'
#define QUAD_BOTTOM_PORTR 'D'
#define QUAD_TOP_PORTM 'G'
#define QUAD_BOTTOM_PORTM 'H'

// declares controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
bool main_base = true;
//declare motor ports
// PROG BOT
//
//
// const int frontL_port   = 19;
// const int frontR_port   = 15;
// const int backL_port    = 5;
// const int backR_port    = 17;
// const int leftIntakePort  = 2;
// const int rightIntakePort = 1;
// const int topRollerPort = 12;
// const int botRollerPort = 14;
//
// pros::Motor frontL(frontL_port, true);
// pros::Motor frontR(frontR_port, false);
// pros::Motor backL(backL_port,false);
// pros::Motor backR(backR_port, true);
// pros::Motor leftIntake(leftIntakePort,false);
// pros::Motor rightIntake(rightIntakePort,true);
// pros::Motor topRoller(topRollerPort,false);
// pros::Motor botRoller(botRollerPort,true);

// MAIN BOT
const int frontL_port   = 19;
const int frontR_port   = 15;
const int backL_port    = 5;
const int backR_port    = 17;
const int leftIntakePort  = 2;
const int rightIntakePort = 3;
const int topRollerPort = 12;
const int botRollerPort = 14;

const int auton_limit_plus_port = 1;
const int auton_limit_minus_port = 2;


// declare motors

pros::Motor frontL(frontL_port, true);
pros::Motor frontR(frontR_port, true);
pros::Motor backL(backL_port,false);
pros::Motor backR(backR_port, true);
pros::Motor leftIntake(leftIntakePort,false);
pros::Motor rightIntake(rightIntakePort,true);
pros::Motor topRoller(topRollerPort,false);
pros::Motor botRoller(botRollerPort,true);


/*//declare encoder ports
const int encoderL_port_top = 1;
const int encoderL_port_bottom = 2;
const int encoderR_port_top = 7;
const int encoderR_port_bottom = 8;
const int encoderM_port_top = 4; // middle encoder ports
const int encoderM_port_bottom = 3;
*/
pros::ADIEncoder encoderL(QUAD_TOP_PORTL, QUAD_BOTTOM_PORTL, true);
pros::ADIEncoder encoderR(QUAD_TOP_PORTR, QUAD_BOTTOM_PORTR, true);
pros::ADIEncoder encoderM(QUAD_TOP_PORTM, QUAD_BOTTOM_PORTM, false);

// pros::ADIDigitalIn auton_limit_plus(auton_limit_plus_port);
// pros::ADIDigitalIn auton_limit_minus(auton_limit_minus_port);

pros::Imu imu_sensor(20);
