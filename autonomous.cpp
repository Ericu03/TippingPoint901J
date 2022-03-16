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

pneumatic1.set_value(false);
base_PID(18,200);
pros::delay(50);
base_PID(-14,50);
pros::delay(100);
turn_PID(-90);
pros::delay(150);
base_PID(-5,80);
pros::delay(150);
pneumaticbacklift(true);
pros::delay(150);
/**
base_PID(3,60);
pros::delay(100);
turn_PID(90);
pros::delay(100);
lift.move_velocity(200);
pros::delay(300);
base_PID(8,60);
ring.move_voltage(12000);

**/


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

	pneumaticbacklift(false);
	pros::delay(500);
	base_PID(-24,140);
	pros::delay(100);
	pneumaticbacklift(true);
	pros::delay(150);
	ring.move_voltage(12000);
	turn_PID(45);
	pros::delay(200);
	ring.move_voltage(0);
	base_PID(94,150);
	pros::delay(50);
	turn_PID(-95);
	pros::delay(150);
	lift.move_velocity(160);
	pros::delay(410);
	lift.move_velocity(0);
	//base_PID(14,150);
	front_left_wheel.move_velocity(100);
	back_left_wheel.move_velocity(100);
	middle_left_wheel.move_velocity(100);
	middle_right_wheel.move_velocity(-100);
	front_right_wheel.move_velocity(-100);
	back_right_wheel.move_velocity(-100);
	pros::delay(700);
	front_left_wheel.move_velocity(0);
	back_left_wheel.move_velocity(0);
	front_right_wheel.move_velocity(0);
	back_right_wheel.move_velocity(0);
	middle_left_wheel.move_velocity(0);
	middle_right_wheel.move_velocity(0);
	pros::delay(150);
	pneumatic1.set_value(true);




}

void redleft(){
/**	base_PID(53,90);
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
}

void redright(){
pneumatic1.set_value(true);
pneumaticbacklift(false);
base_PID(41,250);

pneumatic1.set_value(false);
base_PID(-22,200);
pros::delay(100);
turn_PID(-128);
pros::delay(100);
base_PID(-22,140);
pros::delay(100);
pneumaticbacklift(true);
pros::delay(250);
base_PID(15,140);
ring.move_voltage(12000);
pros::delay(1000);
ring.move_voltage(0);

}

void autonskills(){

	/**
	turn_PID(-57);
	lift.move_velocity(200);
	pros::delay(700);
	base_PID(30,150);
	pneumatic1.set_value(false);**/
}



void autonomous(){


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
