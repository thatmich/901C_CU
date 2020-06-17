#include "config.h"

// declares controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//declare motor ports

const int frontL_port   = 16;
const int frontR_port   = 15;
const int backL_port    = 6;
const int backR_port    = 5;

// declare motors

pros::Motor frontL(frontL_port, true);
pros::Motor frontR(frontR_port, false);
pros::Motor backL(backL_port,false);
pros::Motor backR(backR_port, true);

//declare encoder ports
const int encoderL_port_top = 2;
const int encoderL_port_bottom = 1;
const int encoderR_port_top = 7;
const int encoderR_port_bottom = 8;
const int encoderM_port_top = 4; // middle encoder ports
const int encoderM_port_bottom = 3;

pros::ADIEncoder encoderL(encoderL_port_top, encoderL_port_bottom, true);
pros::ADIEncoder encoderR(encoderR_port_top, encoderR_port_bottom, true);
pros::ADIEncoder encoderM(encoderM_port_top, encoderM_port_bottom, false);
