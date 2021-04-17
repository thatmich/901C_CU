#include "main.h"

#include "configure/config.h"
#include "usercontrol.h"
#include "autonomous.h"
#include "okapi_functions.h"
using namespace okapi;
std::shared_ptr<OdomChassisController> myChassis =
  ChassisControllerBuilder()
    .withMotors({19,5}, {17,15}) //
    // .withGains(
    //     {0.001, 0, 0.0001}, // distance controller gains
    //     {0.001, 0, 0.0001}, // turn controller gains
    //     {0.001, 0, 0.0001}  // angle controller gains (helps drive straight)
    // )
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 15_in}, imev5GreenTPR})
    .withSensors(
        ADIEncoder{'A', 'B', false}, // Left encoder in ADI ports A & B
        ADIEncoder{'C', 'D', true},  // Middle encoder in ADI ports C & D (reversed)
        ADIEncoder{'G', 'H', false}) // Right encoder in ADI ports G & H
    // specify the side tracking wheels diameter (2.75) side track distance (9.5),
    // middle wheel distance (2) and diameter (2.75), and TPR (360)
    .withOdometry({{2.75_in, 9.5_in}, quadEncoderTPR}, StateMode::FRAME_TRANSFORMATION)
    .buildOdometry();

std::shared_ptr<AsyncMotionProfileController> profileController =
  AsyncMotionProfileControllerBuilder()
    .withLimits({
      1.0, // Maximum linear velocity of the Chassis in m/s
      2.0, // Maximum linear acceleration of the Chassis in m/s/s
      10.0 // Maximum linear jerk of the Chassis in m/s/s/s
    })
    .withOutput(myChassis)
    .buildMotionProfileController();

void testing(){
  myChassis->setState({0_in, 0_ft, 0_deg});
  myChassis->setMaxVelocity(120);
    myChassis->turnToAngle(-120_deg);
    myChassis->waitUntilSettled();


}

void run_intake(float speed){
  leftIntake.move_velocity(speed);
  rightIntake.move_velocity(speed);
}

void run_base(float speed){
  frontL.move_velocity(speed);
  frontR.move_velocity(speed);
  backL.move_velocity(speed);
  backR.move_velocity(speed);
}

void prog_skills_left(){
  myChassis->setState({0_in, 0_ft, 0_deg}); // initial state
  myChassis->setMaxVelocity(100);// max velocity

  run_intake(200); // run intakes


  myChassis->driveToPoint({1.8_ft, 0_ft});  // drive forward for ball
  myChassis->waitUntilSettled();
  pros::delay(500);

  myChassis->turnAngle(-133_deg); // turn towards goal
  myChassis->waitUntilSettled();
  myChassis->moveDistance(2_ft);
  run_base(100);
  pros::delay(200);
  run_base(0);

  botRoller.move_velocity(100);
  topRoller.move_velocity(-500);
  pros::delay(1000);

  run_intake(0);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  run_intake(-100);

  // end of first goal

  // begin second goal
  myChassis->moveDistance(-4.3_ft);
  myChassis->waitUntilSettled();
  botRoller.move_velocity(-100);
  topRoller.move_velocity(200);
  pros::delay(1200);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  pros::delay(300);


  run_intake(200);
  myChassis->turnAngle(-140_deg);
  myChassis->waitUntilSettled();
  myChassis->moveDistance(1.5_ft);
  myChassis->waitUntilSettled();

  myChassis->turnAngle(90_deg);
  myChassis->waitUntilSettled();
  run_intake(0);

  myChassis->moveDistance(2.5_ft);
  myChassis->waitUntilSettled();
  run_base(100);
  pros::delay(400);
  run_base(0);

  botRoller.move_velocity(100);
  topRoller.move_velocity(-500);
  pros::delay(1000);

  run_intake(0);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  run_intake(-100);

  // end of first goal


  // begin third goal
  myChassis->moveDistance(-1.5_ft);
  myChassis->waitUntilSettled();
  run_intake(0);

  myChassis->turnAngle(-70_deg);
  myChassis->waitUntilSettled();
  run_intake(200);

  myChassis->moveDistance(2.5_ft);
  myChassis->waitUntilSettled();











}

void prog_skills_right(){
  myChassis->setState({0_in, 0_ft, 0_deg}); // initial state
  myChassis->setMaxVelocity(80);// max velocity

  run_intake(200); // run intakes


  myChassis->driveToPoint({2_ft, 0_ft});  // drive forward for ball
  myChassis->waitUntilSettled();
  pros::delay(500);

  myChassis->turnAngle(133_deg); // turn towards goal
  myChassis->waitUntilSettled();
  myChassis->moveDistance(2_ft);
  run_base(100);
  pros::delay(400);
  run_base(0);

  botRoller.move_velocity(100);
  topRoller.move_velocity(-500);
  pros::delay(1000);

  run_intake(0);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  run_intake(-100);

  // end of first goal

  // begin second goal
  myChassis->moveDistance(-4.3_ft);
  myChassis->waitUntilSettled();
  botRoller.move_velocity(-100);
  topRoller.move_velocity(200);
  pros::delay(1200);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  pros::delay(300);


  run_intake(200);
  myChassis->turnAngle(135_deg);
  myChassis->waitUntilSettled();
  myChassis->moveDistance(1.65_ft);
  myChassis->waitUntilSettled();
  pros::delay(200);
  myChassis->moveDistance(-0.25_ft);
  myChassis->waitUntilSettled();

  myChassis->turnAngle(-90_deg);
  myChassis->waitUntilSettled();
  run_intake(0);

  myChassis->moveDistance(2.5_ft);
  myChassis->waitUntilSettled();
  run_base(100);
  pros::delay(400);
  run_base(0);

  botRoller.move_velocity(100);
  topRoller.move_velocity(-500);
  pros::delay(1000);

  run_intake(0);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  run_intake(-100);

  // end of first goal


  // begin third goal
  myChassis->moveDistance(-1.5_ft);
  myChassis->waitUntilSettled();
  run_intake(0);

  myChassis->turnAngle(70_deg);
  myChassis->waitUntilSettled();
  run_intake(200);

  myChassis->moveDistance(2.5_ft);
  myChassis->waitUntilSettled();

  myChassis->turnAngle(20_deg);
  myChassis->waitUntilSettled();

  myChassis->moveDistance(2_ft);
  myChassis->waitUntilSettled();

  myChassis->turnAngle(-45_deg);
  myChassis->waitUntilSettled();

  run_base(100);
  pros::delay(400);
  run_base(0);

  botRoller.move_velocity(100);
  topRoller.move_velocity(-500);
  pros::delay(1000);

  run_intake(0);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  run_intake(-100);

  // end of first goal

  // begin second goal
  myChassis->moveDistance(-4.3_ft);
  myChassis->waitUntilSettled();












}

void prog_skills_right2(){
  myChassis->setState({0_in, 0_ft, 0_deg}); // initial state
  myChassis->setMaxVelocity(80);// max velocity

  run_intake(200); // run intakes


  myChassis->driveToPoint({2_ft, 0_ft});  // drive forward for ball
  myChassis->waitUntilSettled();
  pros::delay(500);

  myChassis->turnAngle(133_deg); // turn towards goal
  myChassis->waitUntilSettled();
  myChassis->moveDistance(2_ft);
  run_base(100);
  pros::delay(400);
  run_base(0);

  botRoller.move_velocity(100);
  topRoller.move_velocity(-500);
  pros::delay(1000);

  run_intake(0);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  run_intake(-100);

  // end of first goal

  // begin second goal
  myChassis->moveDistance(-3_ft);
  myChassis->waitUntilSettled();
  botRoller.move_velocity(-100);
  topRoller.move_velocity(200);
  pros::delay(1200);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  pros::delay(300);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);

  run_intake(200);
  myChassis->turnAngle(-45_deg);
  myChassis->waitUntilSettled();
  myChassis->moveDistance(2.5_ft);
  myChassis->waitUntilSettled();
  pros::delay(200);
  run_base(100);
  pros::delay(300);
  run_base(0);
  myChassis->moveDistance(-1_ft);
  myChassis->waitUntilSettled();

  myChassis->turnAngle(-180_deg);
  myChassis->waitUntilSettled();
  run_intake(0);

  run_base(-100);
  pros::delay(3500);

  myChassis->moveDistance(5_ft);
  myChassis->waitUntilSettled();

  myChassis->turnAngle(-90_deg);
  myChassis->waitUntilSettled();
  myChassis->moveDistance(2_ft);
  myChassis->waitUntilSettled();


  run_base(100);
  pros::delay(1000);
  run_base(0);

  botRoller.move_velocity(100);
  topRoller.move_velocity(-500);
  pros::delay(1000);

  run_intake(0);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  run_intake(-100);

  // end of second goal

  // begin third goal
  myChassis->moveDistance(-3_ft);
  myChassis->waitUntilSettled();
  botRoller.move_velocity(-100);
  topRoller.move_velocity(200);
  pros::delay(1200);
  botRoller.move_velocity(0);
  topRoller.move_velocity(0);
  pros::delay(300);
}
