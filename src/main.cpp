#include "main.h"

#include "configure/config.h"
#include "usercontrol.h"
#include "autonomous.h"
#include "odom.h"
#include "graphics/lvgl_functions.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	setup();
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
void autonomous() {}

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

void encoder_value(int value){
	//pros::ADIEncoder sensor (encoderL_port_top, encoderL_port_bottom, false);
	int current_valueL1 = encoderL.get_value();

	int power = 100;
	while (current_valueL1<value) {
			current_valueL1 = encoderL.get_value();
			char c = current_valueL1;
			debug_text(c);
			frontL.move(power);
 	 		//frontR.move(power);
 	 		//backL.move(power);
 	 		//backR.move(power);
			//pros::delay(100);
		}
		frontL.move(0);
		frontR.move(0);
		backL.move(0);
		backR.move(0);

	}


$h


void opcontrol() {
<<<<<<< HEAD
	bool autonTest = true;
	resetPositionFull(gposition, 0, 0, 0);
	std::string param1("track");
	pros::Task track_task_frame(track_task, &param1);
	

	//
	// while(!autonTest){
	// 	updateControllerValues();
	// 	tank_exponential();
	// 	pros::delay(100);
	// }
=======
	/*bool autonTest = true;
	resetPositionFull(gposition, 0, 0, 0);
	std::string param1("track");
	pros::Task track_task_frame(track_task, &param1);
	//motion_prof1D(100, 20);
	//pros::delay(10000);
	debug_text("I AM FINISHED!!");
	//time_based(10000,100);
	//encoder_value(100);
*/
	while(true){
		updateControllerValues();
		tank_exponential();
		if(controller.get_digital(DIGITAL_R1)==1){
			leftIntake.move(100);
			rightIntake.move(100);
		}
		else if (controller.get_digital(DIGITAL_R2)==1){
			leftIntake.move(-100);
			rightIntake.move(-100);
		}
		else{
			leftIntake.move(0);
			rightIntake.move(0);
		}
		encoder_value(200);
		pros::delay(100);
	}
>>>>>>> 7687c916707f2429d4056b71ee5a815b6348ea35
}
