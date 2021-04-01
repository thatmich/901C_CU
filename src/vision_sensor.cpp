// #define OPTICAL_PORT1
// #include "main.h"
// #define REDBALL1
// #define BLUEBALL1
// #include "configure/config.h"
//
// void retrieveSignatureRed() {
//   pros::Vision vision_sensor (VISION_PORT);
//   while (true) {
//     vision_object_s_t rtn = vision_sensor.get_by_sig(0, REDBALL1);
//     // Gets the largest object of the EXAMPLE_SIG signature
//     std::cout << "sig: " << rtn.signature;
//     // Prints "sig: 1"
//     pros::delay(2);
//   }
// }
//
// void retrieveSignatureBlue() {
//   pros::Vision vision_sensor (VISION_PORT);
//   while (true) {
//     vision_object_s_t rtn = vision_sensor.get_by_sig(0, BLUEBALL1);
//     // Gets the largest object of the EXAMPLE_SIG signature
//     std::cout << "sig: " << rtn.signature;
//     // Prints "sig: 1"
//     pros::delay(2);
//   }
// }
//
// void printHue() {
//   pros::Optical optical_sensor(9);
//   while (true) {
//     printf("Hue value: %lf \n", optical_sensor.get_hue());
//     pros::delay(20);
//   }
// }
