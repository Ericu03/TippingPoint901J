#include "main.h"

extern const int FRONT_LEFT_WHEEL;
extern const int MIDDLE_LEFT_WHEEL;
extern const int BACK_LEFT_WHEEL;
extern const int FRONT_RIGHT_WHEEL;
extern const int MIDDLE_RIGHT_WHEEL;
extern const int BACK_RIGHT_WHEEL;

extern const int INTAKE_L;
extern const int INTAKE_R;
extern const int LIFT;
extern const int RING;
extern const int LEFTENCODER;
extern const int MIDENCODER;
extern const int VISION;

extern pros::Controller master;
extern pros::Motor front_left_wheel;
extern pros::Motor middle_left_wheel;
extern pros::Motor back_left_wheel;
extern pros::Motor front_right_wheel;
extern pros::Motor middle_right_wheel;
extern pros::Motor back_right_wheel;

extern pros::Motor intake_l;
extern pros::Motor intake_r;
extern pros::Motor lift;
extern pros::Motor ring;

extern pros::Vision vision;
extern pros::ADIEncoder left_enc;
extern pros::ADIEncoder mid_enc;
extern pros::ADIDigitalOut pneumatic1;
extern pros::ADIDigitalOut pneumatic2;
extern pros::ADIDigitalOut pneumatic3;
extern pros::Rotation leftencoder;
extern pros::Rotation rightencoder;
extern pros::ADIDigitalIn colorlimit_switch;
extern pros::ADIDigitalIn sidelimit_switch;
extern bool blueSide;
extern bool close;
extern bool skillsOn;
extern int colorautonstate;
extern int sideautonstate;
extern int skillsbuttonstate;
extern bool colorbutton_unpressed;
extern bool sidebutton_unpressed;
