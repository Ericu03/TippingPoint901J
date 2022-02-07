#include "main.h"
#include "config.hpp"
#include "auton_functions.h"


void blueleft(){
/**
base_PID(53,90);
pros::delay(200);
pneumatic1.set_value(true);
pros::delay(300);
base_PID(-35,90);
pros::delay(50);
pneumatic1.set_value(false);
turn_PID(-10);
pros::delay(100);
front_left_wheel.move_velocity(-100);//move and hit the wall to reset robot
back_left_wheel.move_velocity(-100);
back_right_wheel.move_velocity(100);
front_right_wheel.move_velocity(100);
pros::delay(850);
base_PID(3,90);
pros::delay(100);
turn_PID(-92);
pros::delay(200);
pneumaticbacklift(false);
pros::delay(1600);
front_left_wheel.move_velocity(-100);//move and hit the wall to reset robot
back_left_wheel.move_velocity(-100);
back_right_wheel.move_velocity(100);
front_right_wheel.move_velocity(100);
pros::delay(800);
pneumaticbacklift(true);
pros::delay(1100);
front_left_wheel.move_velocity(100);//move and hit the wall to reset robot
back_left_wheel.move_velocity(100);
back_right_wheel.move_velocity(-100);
front_right_wheel.move_velocity(-100);
pros::delay(950);
front_left_wheel.move_velocity(0);//move and hit the wall to reset robot
back_left_wheel.move_velocity(0);
back_right_wheel.move_velocity(0);
front_right_wheel.move_velocity(0);
**/


base_PID(-20,100);
pros::delay(50);
pneumaticbacklift(true);
pros::delay(150);
ring.move_velocity(150);
base_PID(20,100);
pros::delay(100);
ring.move_velocity(0);



}


void blueright(){//-turn is left
/**	pros::delay(100);
	turn_PID(-8);//turn left a bit
	pros::delay(100);
	base_PID(10,90);//move forward 10 inches
	pros::delay(100);
	turn_PID(8);//turn right to align with goal
	pros::delay(100);
	base_PID(10,90);//move forward toward goal
	pros::delay(150);
	base_PID(52,90);
	pros::delay(300);
	pneumatic1.set_value(true);//grab goal
	pros::delay(450);
	base_PID(-30,90);//move back to halfway line
	pros::delay(100);
	pneumatic1.set_value(false);
	pros::delay(200);
	front_left_wheel.move_velocity(-100);//move and hit the wall to reset robot
	back_left_wheel.move_velocity(-100);
	back_right_wheel.move_velocity(100);
	front_right_wheel.move_velocity(100);
	pros::delay(900);
	base_PID(5,90);//move forward a bit
	pros::delay(100);
	turn_PID(-148);//turn left to face goal with back
	pros::delay(100);
	pneumaticbacklift(true);
	pros::delay(800);
	base_PID(-19,90);//move forward toward goal
	pros::delay(250);
	//grab the goal
  pneumaticbacklift(true);
	pros::delay(900);
	base_PID(17,90);//move back behind goal line
	pros::delay(100);
**/

	base_PID(-20,90);
	pros::delay(50);
	pneumaticbacklift(true);
	ring.move_velocity(100);
	pros::delay(150);
	base_PID(15,90);
	ring.move_velocity(0);
	pros::delay(50);
	turn_PID(95);
	pros::delay(50);
	base_PID(30,90);
	pros::delay(100);
	pneumatic1.set_value(true);
	pros::delay(150);
	base_PID(-30,90);


}

void redleft(){
	base_PID(53,90);
	pros::delay(200);
	pneumatic1.set_value(true);
	pros::delay(300);
	base_PID(-35,90);
	pros::delay(50);
	pneumatic1.set_value(false);
	turn_PID(-10);
	pros::delay(100);
	front_left_wheel.move_velocity(-100);//move and hit the wall to reset robot
	back_left_wheel.move_velocity(-100);
	back_right_wheel.move_velocity(100);
	front_right_wheel.move_velocity(100);
	pros::delay(850);
	base_PID(3,90);
	pros::delay(100);
	turn_PID(-92);
	pros::delay(200);
	pneumaticbacklift(false);
	pros::delay(1600);
	front_left_wheel.move_velocity(-100);//move and hit the wall to reset robot
	back_left_wheel.move_velocity(-100);
	back_right_wheel.move_velocity(100);
	front_right_wheel.move_velocity(100);
	pros::delay(800);
	pneumaticbacklift(true);
	pros::delay(1100);
	front_left_wheel.move_velocity(100);//move and hit the wall to reset robot
	back_left_wheel.move_velocity(100);
	back_right_wheel.move_velocity(-100);
	front_right_wheel.move_velocity(-100);
	pros::delay(950);
	front_left_wheel.move_velocity(0);//move and hit the wall to reset robot
	back_left_wheel.move_velocity(0);
	back_right_wheel.move_velocity(0);
	front_right_wheel.move_velocity(0);

}

void redright(){

	base_PID(52,100);
	pros::delay(200);
	pneumatic1.set_value(true);//grab goal
	pros::delay(450);
	base_PID(-30,90);//move back to halfway line
	pros::delay(100);
	pneumatic1.set_value(false);
	pros::delay(200);
	front_left_wheel.move_velocity(-100);//move and hit the wall to reset robot
	back_left_wheel.move_velocity(-100);
	back_right_wheel.move_velocity(100);
	front_right_wheel.move_velocity(100);
	pros::delay(900);
	base_PID(5,90);//move forward a bit
	pros::delay(100);
	turn_PID(-148);//turn left to face goal with back
	pros::delay(100);
	pneumaticbacklift(true);
	pros::delay(800);
	base_PID(-19,90);//move forward toward goal
	pros::delay(250);
  pneumaticbacklift(true);
	pros::delay(900);
	base_PID(10,90);//move back behind goal line
	pros::delay(100);


}

void autonskills(){


///back of red with the back of the robot facing the seesaw.
base_PID(-8,100);//move back
pros::delay(200);
pneumaticbacklift(true);
pros::delay(100);
base_PID(10,100);//move forward
pros::delay(300);
turn_PID(10);//turn right
pros::delay(100);
base_PID(8,50);//move forward a bit
pros::delay(300);
turn_PID(80);//turn right to face straight
pros::delay(300);
base_PID(18,90);//move forward in front of the rings
pros::delay(300);
turn_PID(45);//turn right to face the goal
pros::delay(50);
base_PID(15,90);//move forward
pros::delay(100);
pneumatic1.set_value(true);//grab goal
pros::delay(500);
base_PID(20,90);//move forward to the front of the seesaw
pros::delay(200);
turn_PID(32);//turn right
pros::delay(100);
base_PID(6,90);//move forward a bit
pros::delay(100);
lift.move_voltage(12000);//lift up the base
pros::delay(600);
turn_PID(-30);//turn left to flip the goal
pros::delay(200);
pneumatic1.set_value(false);//release the goal on top
pros::delay(300);
front_left_wheel.move_velocity(100);//reset with seesaw
back_left_wheel.move_velocity(100);
back_right_wheel.move_velocity(-100);
front_right_wheel.move_velocity(-100);
pros::delay(300);
base_PID(-10,90);//move back
pros::delay(200);
turn_PID(90);//turn left directly to the blue goal
pros::delay(200);
base_PID(25,90);//move forward
pros::delay(100);
turn_PID(5);//turn right a bit
pros::delay(50);
base_PID(8,60);//move forward
pros::delay(300);
pneumatic1.set_value(true);//grab goal
pros::delay(300);
base_PID(-25,90);//move back
pros::delay(100);
turn_PID(45);//turn right so that the back face the middle goal
pros::delay(100);
base_PID(-15,90);
pros::delay(100);
pneumaticbacklift(true);//pick up middle goal
pros::delay(400);
base_PID(-40,100);//move all the way back
pros::delay(100);
pneumaticbacklift(false);
pros::delay(100);
base_PID(13,90);//move forward
pros::delay(100);
turn_PID(-35);//turn left to face perpendicular to the seesaw
pros::delay(100);
front_left_wheel.move_velocity(-100);//move back to align with the wall
back_left_wheel.move_velocity(-100);
front_right_wheel.move_velocity(100);
back_right_wheel.move_velocity(100);
pros::delay(1000);
base_PID(45,100);//move forward all the way to the front of the seesaw
pros::delay(100);
lift.move_velocity(100);//lift goal up
pros::delay(700);
turn_PID(-90);//turn left
pros::delay(200);
base_PID(20,80);//move forward
pros::delay(200);
pneumatic1.set_value(false);

}



void autonomous(){
	base_PID(10,90);
	pros::delay(200);
	base_PID(10,50);
if(skillsbuttonstate == 2){
	if(sideautonstate == 2 && colorautonstate ==2){
		blueleft();
	}
	if(sideautonstate == 1 && colorautonstate == 2){
		blueright();
	}
	if(sideautonstate ==  2 && colorautonstate == 1){
		redleft();
	}
	if(sideautonstate == 1 && colorautonstate == 1){
		redright();
	}
}
else if(skillsbuttonstate == 1){
	autonskills();
}





}
