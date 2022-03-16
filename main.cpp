#include "main.h"
#include "config.hpp"
#include "auton_functions.h"
#include "okapi/api.hpp"

double  E= 2.71828182845904523536;
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
//void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {


	while(true){
std::cout <<"left:" << left_enc.get_value();
//std::cout <<"right:" << front_left_wheel.get_position();
		double power = 200*master.get_analog(ANALOG_LEFT_Y)/127;
	double turn = 200*master.get_analog(ANALOG_RIGHT_X)/127;
	int l = (int)(pow(((power + turn)/200.0),2.0)*200.0);
	int r = (int) (pow(((power - turn)/200.0),2.0)*200.0);
	//printf("LEFt Angle: %ld \n", leftencoder.get_angle());


/**	double exponent = okapi::ipow(E, 0.1*master.get_analog(ANALOG_LEFT_Y));
	double exponent2 = okapi::ipow(E, 0.1*master.get_analog(ANALOG_RIGHT_X));
	double power = (200 / (exponent + 1)) - 18.182;
	double turn = (200 / (exponent2 + 1)) -18.182;
	int l = (int)(pow(((power + turn)/200.0),2.0)*170.0);
	int r = (int) (pow(((power - turn)/200.0),2.0)*170.0);**/
	if(power+turn < 0){
		l *= -1;
	}
	if(power-turn >0){
		r *=-1;
	}
	int frontleftvel = front_left_wheel.get_actual_velocity()*0.97;
	int middleleftvel = middle_left_wheel.get_actual_velocity()*0.97;
	int backleftvel = back_left_wheel.get_actual_velocity()*0.97;
	int frontrightvel = front_right_wheel.get_actual_velocity();
	int middlerightvel = middle_right_wheel.get_actual_velocity();
	int backrightvel = back_right_wheel.get_actual_velocity();

	front_left_wheel.move_velocity(l);
	middle_left_wheel.move_velocity(l);
	back_left_wheel.move_velocity(l);
	front_right_wheel.move_velocity(r);
	middle_right_wheel.move_velocity(r);
	back_right_wheel.move_velocity(r);
/**
	if(front_left_wheel.get_position() < front_right_wheel.get_position()){
		int difference = std::abs((back_right_wheel.get_target_velocity() - backrightvel)) / ((backrightvel+back_right_wheel.get_target_velocity())/2);
		front_left_wheel.move_velocity(l);
		middle_left_wheel.move_velocity(l);
		back_left_wheel.move_velocity(l);
		front_right_wheel.move_velocity(r*difference);
		middle_right_wheel.move_velocity(r);
		back_right_wheel.move_velocity(r*difference);
	}
**/
	if(master.get_analog(ANALOG_LEFT_Y) ==0){
		pros::delay(25);
		front_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		pros::delay(14);
		front_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	}






//back lift
	if(master.get_digital(DIGITAL_UP) != 0){
		pneumatic2.set_value(false);
		pneumatic3.set_value(false);

	}


	else if(master.get_digital(DIGITAL_DOWN) !=0){
		pneumatic2.set_value(true);
		pneumatic3.set_value(true);



	}
	else if((master.get_digital(DIGITAL_UP) != 0) & (master.get_digital(DIGITAL_Y) != 0)){
		pneumatic2.set_value(false);
		pneumatic2.set_value(false);
		ring.move_voltage(12000);
	}

	if(master.get_digital(DIGITAL_Y) != 0){
		ring.move_voltage(12000);

	}
	else if(master.get_digital(DIGITAL_A)!= 0){
		ring.move_voltage(0);
		ring.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	}


	//front lift
	if(master.get_digital(DIGITAL_L1) != 0){

		lift.move_voltage(12000);

	}
	else if(master.get_digital(DIGITAL_L2) != 0){

		lift.move_voltage(-12000);
	}
	else{
		lift.move_voltage(0);
		lift.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	}



	//pneumatic pistons claw
	if(master.get_digital(DIGITAL_R1) != 0){
		pneumatic1.set_value(false);

	}
	else if(master.get_digital(DIGITAL_R2) != 0){
		pneumatic1.set_value(true);

	}


	//brake function

	if(master.get_digital(DIGITAL_X) != 0){
		front_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		front_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		middle_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		middle_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
		front_left_wheel.move_velocity(0);
		front_right_wheel.move_velocity(0);
		back_left_wheel.move_velocity(0);
		back_right_wheel.move_velocity(0);
		middle_left_wheel.move_velocity(0);
		middle_right_wheel.move_velocity(0);


	}
	else{
		front_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		front_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		middle_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		back_left_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		back_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
		middle_right_wheel.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

	}
	pros::delay(5);
	}
}

