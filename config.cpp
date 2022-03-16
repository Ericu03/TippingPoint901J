#include "config.hpp"

//setting ports
const int FRONT_LEFT_WHEEL = 1;
const int BACK_LEFT_WHEEL = 2;
const int MIDDLE_LEFT_WHEEL = 3;
const int FRONT_RIGHT_WHEEL = 4;
const int MIDDLE_RIGHT_WHEEL = 18;
const int BACK_RIGHT_WHEEL = 7;

const int INTAKE_L = 7;
const int INTAKE_R = 8;
const int LIFT = 9;//front lift
const int RING = 10;//ring

const int VISION = 17;
const char LENC_TOP = 'G';
const char LENC_BOT = 'H';
const char MID_TOP = 'E';
const char MID_BOT = 'F';
const char PNEUMATIC1 = 'D';
const char PNEUMATIC2 = 'B';
const char PNEUMATIC3 = 'C';


//initializing
pros::Motor front_left_wheel(FRONT_LEFT_WHEEL,pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor middle_left_wheel(MIDDLE_LEFT_WHEEL, pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor back_left_wheel(BACK_LEFT_WHEEL, pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor front_right_wheel(FRONT_RIGHT_WHEEL,pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor middle_right_wheel(MIDDLE_RIGHT_WHEEL,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor back_right_wheel(BACK_RIGHT_WHEEL, pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor intake_l(INTAKE_L,pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor intake_r(INTAKE_R,pros::E_MOTOR_GEARSET_18,false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift(LIFT, pros::E_MOTOR_GEARSET_18,true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor ring(RING, pros::E_MOTOR_GEARSET_06,false, pros::E_MOTOR_ENCODER_DEGREES);
pros::ADIEncoder left_enc (LENC_TOP, LENC_BOT, false);
pros::ADIEncoder mid_enc (MID_TOP, MID_BOT, false);
pros::ADIDigitalOut pneumatic1 (PNEUMATIC1);
pros::ADIDigitalOut pneumatic2 (PNEUMATIC2);
pros::ADIDigitalOut pneumatic3 (PNEUMATIC3);
pros::Vision vision (VISION);
pros::Controller master(CONTROLLER_MASTER);



//gui
bool blueSide = false;
bool close = false;
bool skillsOn = false;
int colorautonstate = 0;
int sideautonstate = 0;
bool colorbutton_unpressed = false;
bool sidebutton_unpressed = false;
int skillsbuttonstate = 0;
