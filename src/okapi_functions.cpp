#include "main.h"

#include "configure/config.h"
#include "usercontrol.h"
#include "autonomous.h"
#include "okapi_functions.h"
using namespace okapi;
std::shared_ptr<OdomChassisController> myChassis =
  ChassisControllerBuilder()
    .withMotors({19,5}, {17,15}) //
    // Green gearset, 4 in wheel diam, 11.5 in wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .withSensors(
        ADIEncoder{'A', 'B'}, // Left encoder in ADI ports A & B
        ADIEncoder{'C', 'D', true},  // Middle encoder in ADI ports C & D (reversed)
        ADIEncoder{'G', 'H', true}) // Right encoder in ADI ports A & B
    // specify the tracking wheels diameter (2.75), track (), and TPR (360)
    .withOdometry({{4_in, 7_in}, quadEncoderTPR}, StateMode::FRAME_TRANSFORMATION)
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
    // set the state to zero
  myChassis->setState({0_in, 0_in, 0_deg});

  myChassis->setMaxVelocity(150);
  // turn 45 degrees and drive approximately 1.4 ft
  myChassis->driveToPoint({3_ft, 0_ft});
  // turn approximately 45 degrees to end up at 90 degrees
  //myChassis->turnToAngle(90_deg);
  // turn approximately -90 degrees to face {5_ft, 0_ft} which is to the north of the robot
  //myChassis->turnToPoint({5_ft, 0_ft});

  // profileController->generatePath(
  // {{0_in, 0_in, 0_deg}, {20_in, 0_in, 0_deg}}, "A");
  // profileController->setTarget("A");
  // profileController->waitUntilSettled();
	// pros::delay(200);

}
