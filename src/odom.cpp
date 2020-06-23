#include "odom.h"

sPos gposition;
void trackPosition(int left, int right, int back, sPos& position){
  float L = (left - position.leftLst) * SPIN_TO_IN_LR; // Amount left side moved
  float R = (right - position.rightLst) * SPIN_TO_IN_LR; // Amount left side moved
  float S = (back - position.backLst) * SPIN_TO_IN_S; // amount back side moved

  // update last values

  position.leftLst = left;
  position.rightLst = right;
  position.backLst = back;

  float h; // The hypotenuse of the triangle formed by the middle of the robot on the starting position and ending position and the middle of the circle it travels around
	float i; // Half of the angle that I've traveled
	float h2; // The same as h but using the back instead of the side wheels
	float a = (L - R) / (L_DISTANCE_IN + R_DISTANCE_IN); // The angle that I've traveled

  if(a) // if angle is not zero
  {
    float r = R/a; // radius of arc (from center to right side of the robot)
    i = a/2.0;
    float sinI = sin(i);
    h = ((r + R_DISTANCE_IN) * sinI) * 2.0;

		float r2 = S / a; // The radius of the circle the robot travel's around with the back of the robot
		h2 = ((r2 + S_DISTANCE_IN) * sinI) * 2.0;
	}
	else // if there is no arc (unlikely scenario)
	{
		h = R;
		i = 0;

		h2 = S;
	}

  float p = i + position.a; // The global ending angle of the robot
	float cosP = cos(p);
	float sinP = sin(p);

	// Update the global position
	position.y += h * cosP;
	position.x += h * sinP;

	position.y += h2 * -sinP; // -sin(x) = sin(-x)
	position.x += h2 * cosP; // cos(x) = cos(-x)

	position.a += a;
}

void resetPosition(sPos& position){
  position.leftLst = position.rightLst = position.backLst = 0;
	position.y = position.x = position.a = 0;
}

void resetPositionFull(sPos& position, float y, float x, float a)
{
	resetPosition(position);

	encoderL.reset();
  encoderR.reset();
  encoderM.reset();

	position.y = y;
	position.x = x;
	position.a = a;
}

void track_task(void* param){
  while(true){
    trackPosition(encoderL.get_value(), encoderR.get_value(), encoderM.get_value(), gposition);
    // std::cout<<"ARC:"<<gposition.a<<std::endl;
    // std::cout<<"X:"<<gposition.x<<std::endl;
    // std::cout<<"Y:"<<gposition.y<<std::endl;
    std::cout<<gposition.x<<", "<<gposition.y<<std::endl;
    pros::delay(20);
  }
}
