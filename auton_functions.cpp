#include "main.h"
#include "config.hpp"
#include "auton_functions.h"

const double WHEEL_RADIUS = 1.375;
const int DEFAULTSLEWRATEINCREMENT = 10;
const float TICKS_PER_ROTATION =  360.0;
const double CIRCUMFERENCE = 2*M_PI*WHEEL_RADIUS;
const double DIAMETER = 2.75;

//pros::vision_signature_s_t BLUE_SIG = pros::Vision::signature BLUE_GOAL (1, -3197, -1623, -2410, 3277, 9039, 6158, 1.400, 0);
//pros::vision_signature_s_t RED_SIG = pros::Vision::signature RED_GOAL (2, 6799, 10551, 8675, -2663, -2153, -2408, 2.100, 0);
//pros::vision_signature_s_t YELLOW_SIG = pros::Vision::signature YELLOW_GOAL (3, -1, 2143, 1071, -6369, -5327, -5848, 1.800, 0);


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

mid_enc.reset();
//middle_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
//middle_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
double degreegoal = (targetdistance/CIRCUMFERENCE)*TICKS_PER_ROTATION;
double target = 0.0;
int maxvel = maxvelocity;
double goal = 0.0;
bool goalMet = false;
double targetVelocity = 0.0;
double currentPos;
double error;
double integral = 0.0;
double derivative = 0.0;
double previouserror = 0.0;
target = degreegoal;
double revolutions = 0;
double kP = 0.06;//0.1625 4cm error
double kI = 0.0005;//0.0005
double kD = 0.005;//0.005
  if(target < 0){
  maxvel *= -1;
  }

    while(!goalMet){

     currentPos = mid_enc.get_value();


      error = target - currentPos;

      if(std::abs(error) < 600){
        integral = integral + error;

      }


      derivative = error - previouserror;
      previouserror = error;

      targetVelocity = (kP * error) + (kI* integral) + (kD * derivative);

      /**if(std::abs(targetVelocity) > std::abs(maxvel)){ to test
        targetVelocity = maxvel;
      }**/
    //  front_left_wheel.move_velocity(targetVelocity);//*0.94
    //  back_left_wheel.move_velocity(targetVelocity);//*0.94
    //  front_right_wheel.move_velocity(-targetVelocity);
    //  back_right_wheel.move_velocity(-targetVelocity);
    // middle_left_wheel.move_velocity(-targetVelocity);
    // middle right_wheel.move_velocity(-targetVelocity);

      slewRateControl(&front_left_wheel, targetVelocity, DEFAULTSLEWRATEINCREMENT);
      slewRateControl(&back_left_wheel, targetVelocity, DEFAULTSLEWRATEINCREMENT);
      slewRateControl(&front_right_wheel, -targetVelocity, DEFAULTSLEWRATEINCREMENT);
      slewRateControl(&back_right_wheel, -targetVelocity, DEFAULTSLEWRATEINCREMENT);
      slewRateControl(&middle_left_wheel, -targetVelocity, DEFAULTSLEWRATEINCREMENT);
      slewRateControl(&middle_right_wheel, -targetVelocity, DEFAULTSLEWRATEINCREMENT);
      if(std::abs(error) < 1.5){
        goalMet = true;
      }
      pros::delay(10);
    }
    brakeMotor();

}



void turn_PID(float targetdegree){
mid_enc.reset();
left_enc.reset();


//middle_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
//middle_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
 float turn_constant_right = 4.79;//2.4 orig 2.85
 float turn_constant_left = 4.78;//2.42
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
 double kP = 0.75;
 double kI = 0.0005;
 double kD = 0.001;
 double integral = 0;
 double derivative = 0;
 double revolutions = 0;
 if(targetdegree<0){maxVelocity *= -1;}


 while(!goalMet){
    revolutions = -mid_enc.get_value();

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
     slewRateControl(&middle_left_wheel, leftTarget, DEFAULTSLEWRATEINCREMENT);
     slewRateControl(&middle_right_wheel, rightTarget, DEFAULTSLEWRATEINCREMENT);

   if (std::abs(error) < 4){
     goalMet = true;
   }

   pros::delay(10);
 }
 brakeMotor();
}

/**
void vision_tracker(int color, int direction){//blue is 1 red is 2 yellow is 3
  vision.clear_led();
  pros::vision_object_s_t testblue = vision.get_by_code(0, 1);
	pros::vision_object_s_t testred = vision.get_by_code(0, 2);
  pros::vision_object_s_t testyellow = vision.get_by_code(0,3);


  bool goalmet = false;
  int target_velocity = 70;
  int turnround = direction;


  while(!goalmet){

    front_left_wheel.move_velocity(30*turnround);
    back_left_wheel.move_velocity(30*turnround);
    front_right_wheel.move_velocity(30*turnround);
    back_right_wheel.move_velocity(30*turnround);

    testblue = vision.get_by_code(0,1);
    testred = vision.get_by_code(0,2);
    testyellow = vision.get_by_code(0,3);


    if(color == 1){
      if()
    }
    if(color == 2){

    }
    if(color == 3){

    }
    else{
    slewRateControl(&front_left_wheel,target_velocity,DEFAULTSLEWRATEINCREMENT);
    slewRateControl(&front_right_wheel,-target_velocity,DEFAULTSLEWRATEINCREMENT);
    slewRateControl(&back_left_wheel,target_velocity,DEFAULTSLEWRATEINCREMENT);
    slewRateControl(&back_right_wheel,-target_velocity,DEFAULTSLEWRATEINCREMENT);
    }





  pros::delay(5);
  }
}

void lift_PID(float targetDegree, int maxVelocity, int delay, int multi)
{
  const double degreeGoal = (targetDegree*7);
  bool goalMet = false;
  bool limitStart = false;
  int targetVelocity = 0;
  double currentPosition = 0;
  double error = 0;
  double previous_error = degreeGoal;
  double kP = 0.15;
  double kI = 0.0025;
  double kD = 0.003;
  double integral = 0;
  double derivative = 0;


  if (targetDegree < 0) {maxVelocity *= -1;}

  lift.tare_position();
  pros::delay(delay);

  while(!goalMet){
    if(multi == 1){
      intake1.move_velocity(-100);
      intake2.move_velocity(100);
    } else{
      intake1.move_velocity(0);
      intake2.move_velocity(0);
    }
    currentPosition = lift.get_position();
    error = degreeGoal - currentPosition;

    if (std::abs(error) < 100){
      integral += error;
    }
    derivative = error - previous_error;
    previous_error = error;

    targetVelocity = kP*error + kI*integral + kD*derivative;

    if (targetVelocity > maxVelocity){
      targetVelocity = maxVelocity;
    }

    slewRateControl(&lift, targetVelocity, DEFAULTSLEWRATEINCREMENT);

    if (std::abs(error) < 12){
      goalMet = true;
    }

    pros::delay(10);
  }
}
**/

void pneumaticbacklift(bool choice){
  if(choice == true){//fall
    pneumatic2.set_value(false);
    pneumatic3.set_value(false);
  }
  else if(choice == false){//pick up
    pneumatic2.set_value(true);
    pneumatic3.set_value(true);

  }
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
