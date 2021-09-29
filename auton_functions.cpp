#include "main.h"
#include "config.hpp"
#include "auton_functions.h"

const double WHEEL_RADIUS = 1.375;
const int DEFAULTSLEWRATEINCREMENT = 10;
const float TICKS_PER_ROTATION =  360.0;
const double CIRCUMFERENCE = 2*M_PI*WHEEL_RADIUS;
const double DIAMETER = 2.75;

// Increase/Decrease motor speed towards target speed by increments and move, if targetVelocity is 0 move at same speed
void slewRateControl(pros::Motor *motor, int targetVelocity, int increment){
  int currentVelocity = motor->get_target_velocity();
  if (targetVelocity != 0){
    if (currentVelocity != targetVelocity){
      if (targetVelocity > currentVelocity){
        currentVelocity += increment;
      }
      else if (targetVelocity < currentVelocity){
        currentVelocity -= increment;
      }
      if (std::abs(currentVelocity) > std::abs(targetVelocity)){
        currentVelocity = targetVelocity;
      }
    }
  } else {
    currentVelocity = targetVelocity;
  }
  motor->move_velocity(currentVelocity);
}

void base_PID(double targetdistance, int maxvelocity){//target distance in inches
left_enc.reset();//reset encoder values
right_enc.reset();

middle_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
middle_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
double degreegoal = (targetdistance /(1.375*2*M_PI))*TICKS_PER_ROTATION;
double target = 0.0;
int vel = maxvelocity;
double goal = 0.0;
bool goalMet = false;
int targetVelocity = 0;
double currentPos;
double error;
double integral = 0.0;
double derivative = 0.0;
double previouserror = 0.0;
target = degreegoal;
 double revolutions = 0;
double kP = 0.15;//0.1625 4cm error
double kI = 0.0004;//0.0005
double kD = 0.005;//0.005


  if(target < 0){
  vel *= -1;
  }

    while(!goalMet){

     currentPos = right_enc.get_value();


      error = degreegoal - currentPos;

      if(std::abs(error) < 600){
        integral = integral + error;

      }


      derivative = error - previouserror;
      previouserror = error;

      targetVelocity = kP * error + kI* integral + kD * derivative;
      if(std::abs(targetVelocity) > std::abs(vel)){
        targetVelocity = vel;
      }
      front_left_wheel.move_velocity(targetVelocity);
      back_left_wheel.move_velocity(targetVelocity);
      front_right_wheel.move_velocity(-targetVelocity);
      back_right_wheel.move_velocity(-targetVelocity);
  //  slewRateControl(&front_left_wheel, targetVelocity, DEFAULTSLEWRATEINCREMENT);
  //  slewRateControl(&back_left_wheel, targetVelocity, DEFAULTSLEWRATEINCREMENT);

  //  slewRateControl(&front_right_wheel, -targetVelocity, DEFAULTSLEWRATEINCREMENT);
  //  slewRateControl(&back_right_wheel, -targetVelocity, DEFAULTSLEWRATEINCREMENT);

      if(std::abs(error) < 1.5){
        goalMet = true;
      }
      pros::delay(10);
    }
    brakeMotor();

}



void turn_PID(float targetdegree){
right_enc.reset();
left_enc.reset();


middle_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
middle_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
 float turn_constant_right = 2.95;//2.4 orig 2.85
 float turn_constant_left = 2.42;//2.42
 int maxVelocity = 70;
 double degreeGoal;
 if (targetdegree > 0){
   degreeGoal = targetdegree*turn_constant_right;
 }
 else {
   degreeGoal = targetdegree*turn_constant_left;
 }
 bool goalMet = false;
 int targetVelocity = 0;
 int leftTarget = 0;
 int rightTarget = 0;
 double currentPosition = 0;
 double error = 0;
 double previous_error = degreeGoal;
 double kP = 0.80;
 double kI = 0.0005;
 double kD = 0.001;
 double integral = 0;
 double derivative = 0;
 double revolutions = 0;
 if(targetdegree<0){maxVelocity *= -1;}


 while(!goalMet){
    revolutions = -right_enc.get_value();

    //revolutions = rightenc.get_value();
    currentPosition = revolutions;


   error = degreeGoal - currentPosition;
   if (std::abs(error) < 300){
     integral += error;
   }

   derivative = error - previous_error;
   previous_error = error;

   targetVelocity = kP*error + kI*integral + kD*derivative;

   if (std::abs(targetVelocity) > std::abs(maxVelocity)){
     targetVelocity = maxVelocity;
   }


     leftTarget = targetVelocity;
     rightTarget = targetVelocity;

     slewRateControl(&front_left_wheel, leftTarget, DEFAULTSLEWRATEINCREMENT);
     slewRateControl(&back_left_wheel, leftTarget, DEFAULTSLEWRATEINCREMENT);
     slewRateControl(&front_right_wheel, rightTarget, DEFAULTSLEWRATEINCREMENT);
     slewRateControl(&back_right_wheel, rightTarget, DEFAULTSLEWRATEINCREMENT);


   if (std::abs(error) < 3.5){
     goalMet = true;
   }

   pros::delay(10);
 }
 brakeMotor();
}



void brakeMotor(){
  front_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  front_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  front_left_wheel.move_velocity(0);
  front_right_wheel.move_velocity(0);
  back_left_wheel.move_velocity(0);
  back_right_wheel.move_velocity(0);
}
void unbrakeMotor(){
  front_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  front_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}
