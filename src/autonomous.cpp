#include "configure/config.h"
#include "odom.h"
#include "graphics/lvgl_functions.h"
//does this work

std::shared_ptr<OdomChassisController> chassis =
  ChassisControllerBuilder()
    .withMotors(1, -2) // left motor is 1, right motor is 2 (reversed)
    // green gearset, 4 inch wheel diameter, 11.5 inch wheelbase
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    // left encoder in ADI ports A & B, right encoder in ADI ports C & D (reversed)
    .withSensors(ADIEncoder{'A', 'B'}, ADIEncoder{'C', 'D', true})
    // specify the tracking wheels diameter (2.75 in), track (7 in), and TPR (360)
    .withOdometry({{2.75_in, 7_in}, quadEncoderTPR}, StateMode::FRAME_TRANSFORMATION)
    .buildOdometry();

// set the state to zero
chassis->setState({0_in, 0_in, 0_deg});
// turn 45 degrees and drive approximately 1.4 ft
chassis->driveToPoint({1_ft, 1_ft});
// turn approximately 45 degrees to end up at 90 degrees
chassis->turnToAngle(90_deg);
// turn approximately -90 degrees to face {5_ft, 0_ft} which is to the north of the robot
chassis->turnToPoint({5_ft, 0_ft});
