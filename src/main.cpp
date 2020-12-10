#include "main.h"

#include "configure/config.h"
#include "usercontrol.h"
#include "autonomous.h"
#include "odom.h"
#include "graphics/lvgl_functions.h"
#include "okapi_functions.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	setup();
	 // imu_sensor.reset();
    //while(imu_sensor.is_calibrating()){
      //pros::delay(10);
    //}
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
	//encoderPID(800, 20);
	//turnLeftPID(200,50);
testing();

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




void opcontrol() {
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
		pros::delay(20);
	}
}
