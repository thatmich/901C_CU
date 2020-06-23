#include "main.h"
#include "configure/config.h"
#include <cmath>

/* Defines */
// The diameter of the tracking wheels in inches
#define WHEEL_DIAMETER_IN_LR 4
#define WHEEL_DIAMETER_IN_S 4

// The distance between the tracking wheels and the centre of the robot in inches
#define L_DISTANCE_IN 5.236 //6.8198
#define R_DISTANCE_IN 5.236 //6.8198
#define S_DISTANCE_IN 6.7

// The number of tick per rotation of the tracking wheel (for quad encoders)
#define TICKS_PER_ROTATION 360.0

// Used internally by trackPosition
#define SPIN_TO_IN_LR (WHEEL_DIAMETER_IN_LR * M_PI / TICKS_PER_ROTATION)
#define SPIN_TO_IN_S (WHEEL_DIAMETER_IN_S * M_PI / TICKS_PER_ROTATION)


typedef struct pos{
  float a;
  float y;
  float x;
  int leftLst;
  int rightLst;
  int backLst;
} sPos; // position of the robot

extern sPos gposition;

void resetPosition(sPos& position);
void resetPositionFull(sPos& position, float y, float x, float a);
void track_task(void* param);
