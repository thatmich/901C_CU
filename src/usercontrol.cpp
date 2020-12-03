#include "configure/config.h"


// Variable Definitions

// joystick deadzone PERCENTAGE (not 127)
const int joydead = 3;
// joystick exponent value
const float joyExp = 2.5;
// joystick multiplier for throttle to convert from analog to motor rpm
const float joyMultiplier = 0.159;
// joystick multiplier for turn to convert from analog to motor rpm
const float turnMultiplier = 0.6;

// left joystick value
int left_joystick = 0;
// right joystick value
int right_joystick = 0;
// robot base forward motion. from -12000 to 12000
float throttle;
// robot base turn motion values. motor values vary based on L/R
float turn;
// left motor voltage
float left;
// right motor voltage
float right;
// temp values to adjust for left side of base
float tempL;
// temp values to adjust for right side of base
float tempR;


/**
* Gets controller values, runs every time loop is repeated during opcontrol
*/
void updateControllerValues(){
		left_joystick = controller.get_analog(ANALOG_LEFT_Y);
		right_joystick = controller.get_analog(ANALOG_RIGHT_X);
}
/**
* Tank drive, exponential.
* Exponential motor values based on controller values.
*/
void tank_exponential(){
  // revamped driver control, power of 2. see
	// https://www.desmos.com/calculator/vxnfti5dbk for drive graph

		// throttle is left y, turn is right x

		// change left and right joystick values into PERCENTAGE
		tempL = 100*(left_joystick/127.0);
		tempR = 100*(right_joystick/127.0);

		// if left joystick is active and positive
		if(tempL > joydead){
			// throttle is set
			throttle = joyMultiplier * pow(tempL, joyExp);
		}

		// if left joystick is active and negative
		else if(tempL < -joydead){
			// convert tempL to positive (temporarily) for exponent
			// exponents might change, and an exponent of 2 produces different
			// pos or neg results compared to an exponent of 3
			tempL = -tempL;
			// throttle is set
			throttle = joyMultiplier * pow(tempL, joyExp);
			// throttle is converted back to negative
			throttle = -throttle;
		}

		// if left joystick is not active
		else{
			throttle = 0;
		}

		// if right joystick is active and positive
		if(tempR >= joydead){
			turn = joyMultiplier * pow(tempR, joyExp);
		}
		// if right joystick is active and negative
		else if(tempR < -joydead){
			tempR = -tempR;
			turn = joyMultiplier * pow(tempR, joyExp);
			turn = -turn*turnMultiplier;
		}
		// if right joystick is not active
		else{
			turn = 0;
		}

		// combine throttle and turn
		left = throttle + turn;
		right = throttle - turn;


		// assign left and right values to the motors

		frontL.move_voltage(left);
		frontR.move_voltage(right);
		backL.move_voltage(left);
		backR.move_voltage(right);
		std::cout<<"Left mV:"<<left<<", Left Joystick"<<left_joystick <<std::endl;
		std::cout<<"Right mV:"<<right<<", Right Joystick"<<right_joystick <<std::endl;
}
