#include "config.h"

// declares controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//declare motor ports

<<<<<<< HEAD
const int frontL_port   = 5;
const int frontR_port   = 6;
const int backL_port    = 16;
const int backR_port    = 15;
=======
const int frontL_port   = 17;
const int frontR_port   = 15;
const int backL_port    = 6;
const int backR_port    = 5;
>>>>>>> 67d9581ca0af28f69478f976666f16a7d2ecb2f1

// declare motors

pros::Motor frontL(frontL_port, true);
pros::Motor frontR(frontR_port, false);
pros::Motor backL(backL_port,false);
pros::Motor backR(backR_port, true);

//declare encoder ports
const int encoderL_port_top = 1;
const int encoderL_port_bottom = 2;
const int encoderR_port_top = 7;
const int encoderR_port_bottom = 8;
const int encoderM_port_top = 4; // middle encoder ports
const int encoderM_port_bottom = 3;

pros::ADIEncoder encoderL(encoderL_port_top, encoderL_port_bottom, true);
pros::ADIEncoder encoderR(encoderR_port_top, encoderR_port_bottom, true);
pros::ADIEncoder encoderM(encoderM_port_top, encoderM_port_bottom, false);
