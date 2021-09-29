#include "main.h"
#include "config.hpp"
#include "auton_functions.h"


void blueleft(){
base_PID(60,100);//10 inches


}


void blueright(){
turn_PID(90);
}

void redleft(){

}

void redright(){

}





void autonomous(){
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

//auton skills
base_PID(1,20);
pros::delay(20);
turn_PID(90);
pros::delay(20);
base_PID(5,30);
pros::delay(100);
pneumatic1.set_value(true);
pros::delay(300);
base_PID(-5,40);
pros::delay(20);
turn_PID(-90);
pros::delay(20);
base_PID(-4,50);
pros::delay(20);
base_PID(90,90);
pros::delay(50);
base_PID(-5,60);
pros::delay(20);
turn_PID(45);
pros::delay(50);
lift.move_velocity(12000);
lift2.move_velocity(12000);
pros::delay(300);
lift.move_voltage(0);
lift2.move_voltage(0);
pros::delay(30);
base_PID(10,60);
pros::delay(40);
pneumatic1.set_value(false);
pros::delay(100);
base_PID(-10,50);
pros::delay(30);





}
