#include "main.h"
#include "config.hpp"

void slewRateControl(pros::Motor *motor, int targetVelocity, int increment);
void base_PID(double targetdistance, int maxvelocity);
void turn_PID(float targetdegree);
void move_straight_rel_test(double xCoord, int maxVel, int multi);
void brakeMotor();
void unbrakeMotor();
void lift_PID(float targetDegree, int maxVelocity, int delay, int multi);
void vision_tracker(int color, int direction);//1 or -1
void pneumaticbacklift(bool choice);

