#include "config.h"
#define QUAD_TOP_PORTL 'A'
#define QUAD_BOTTOM_PORTL 'B'
#define QUAD_TOP_PORTR 'C'
#define QUAD_BOTTOM_PORTR 'D'
#define QUAD_TOP_PORTM 'E'
#define QUAD_BOTTOM_PORTM 'F'


// declares controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//declare motor ports


const int frontL_port   = 10;
const int frontR_port   = 15;
const int backL_port    = 5;
const int backR_port    = 17;
const int leftIntakePort  = 9;
const int rightIntakePort = 20;


// declare motors

pros::Motor frontL(frontL_port, true);
pros::Motor frontR(frontR_port, false);
pros::Motor backL(backL_port,false);
pros::Motor backR(backR_port, true);
pros::Motor leftIntake(leftIntakePort,false);
pros::Motor rightIntake(rightIntakePort,true);

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
