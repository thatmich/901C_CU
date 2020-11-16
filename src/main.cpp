#include "main.h"

#include "configure/config.h"
#include "usercontrol.h"
#include "autonomous.h"
#include "odom.h"
#include "graphics/lvgl_functions.h"

void encoderPID(float target, float threshold){
	//pros::ADIEncoder sensor (encoderL_port_top, encoderL_port_bottom, false);
	int current_valueL1=encoderL.get_value();
	int power = 100;
	float error = target;
	/*while(value>current_valueL1){
			current_valueL1 = encoderL.get_value();
			char c = current_valueL1;
		//	debug_text(c);
			frontL.move(power);
 	 		//frontR.move(power);
 	 		//backL.move(power);
 	 		//backR.move(power);
			pros::delay(10);
		}*/
		while (error > threshold){
			debug_text(std::to_string(error));
			frontL.move(power);
			frontR.move(power);
			backL.move(power);
			backR.move(power);
			error = target - encoderL.get_value() - current_valueL1;
			std::cout<<error;
			pros::delay(10);
		}
			frontL.move(0);
			frontR.move(0);
			backL.move(0);
			backR.move(0);

}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	 setup();
	// imu_sensor.reset();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	encoderPID(800, 20);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

 void time_based(float time, float power){
   frontL.move(power);
	 frontR.move(power);
	 backL.move(power);
	 backR.move(power);
   pros::delay(time);
   frontL.move(0);
	 frontR.move(0);
	 backL.move(0);
	 backR.move(0);
 }



void opcontrol() {
	std::cout << "OP CONTROL IS RUNNING FFS";
	std::string debugstring;
	debugstring = std::to_string(7000);
	debug_text(debugstring);
	while(true){
		updateControllerValues();
		tank_exponential();

		if(controller.get_digital(DIGITAL_R1)==1){
			leftIntake.move(200);
			rightIntake.move(200);
		}
		else if (controller.get_digital(DIGITAL_R2)==1){
			leftIntake.move(-200);
			rightIntake.move(-200);
		}
		else{
			leftIntake.move(0);
			rightIntake.move(0);
		}

		if(controller.get_digital(DIGITAL_L1)==1){
			topRoller.move(600);

		}
		else if (controller.get_digital(DIGITAL_L2)==1){
			topRoller.move(-600);
		}
		else{
			topRoller.move(0);
		}
		if(controller.get_digital(DIGITAL_UP)==1){
			botRoller.move(600);

		}
		else if (controller.get_digital(DIGITAL_DOWN)==1){
			botRoller.move(-600);
		}
		else{
			botRoller.move(0);
		}
	//	encoder_value(200);
		pros::delay(100);
	}
}
