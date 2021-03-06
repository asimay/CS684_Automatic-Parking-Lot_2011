#include "firebird_winavr.h"
#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
void white_I_LEFT_WHITELINE_VALUE(integer);
void white_I_RIGHT_WHITELINE_VALUE(integer);
void white_I_MIDDLE_WHITELINE_VALUE(integer);
void white_I_FRONT_IR_VALUE(integer);
int white(void);
int white_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int LEFT_WHITELINE_VALUE : 1;
  unsigned int RIGHT_WHITELINE_VALUE : 1;
  unsigned int MIDDLE_WHITELINE_VALUE : 1;
  unsigned int FRONT_IR_VALUE : 1;
  unsigned int MOVE_FWD : 1;
  unsigned int MOTOR_LEFT_SPEED : 1;
  unsigned int MOTOR_RIGHT_SPEED : 1;
  unsigned int TURN_LEFT : 1;
  unsigned int TURN_RIGHT : 1;
  unsigned int LEFT_BACK : 1;
  unsigned int RIGHT_BACK : 1;
  unsigned int PARK : 1;
  unsigned int BUZZER_ON : 1;
  unsigned int BUZZER_OFF : 1;
  unsigned int T : 1;
  unsigned int T_1 : 1;
  unsigned int T_2 : 1;
} _s = {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
#define tick tick_timer()
static integer LEFT_WHITELINE_VALUE_v;
static integer RIGHT_WHITELINE_VALUE_v;
static integer MIDDLE_WHITELINE_VALUE_v;
static integer FRONT_IR_VALUE_v;
static integer MOTOR_LEFT_SPEED_v;
static integer MOTOR_RIGHT_SPEED_v;
static integer x;
static integer forward_sensor_value;
static integer left_value;
static integer right_value;
static integer forward_sensor_value_1;
static integer middle_value;
static unsigned char _state_18;
static unsigned char _state_14;
static unsigned char _state_6;
static unsigned char _state_10;
static unsigned char _state_1 = 3;
static int _term_75;
void white_I_LEFT_WHITELINE_VALUE(integer _v) {
  _s.LEFT_WHITELINE_VALUE = 1;
  LEFT_WHITELINE_VALUE_v = _v;
}
void white_I_RIGHT_WHITELINE_VALUE(integer _v) {
  _s.RIGHT_WHITELINE_VALUE = 1;
  RIGHT_WHITELINE_VALUE_v = _v;
}
void white_I_MIDDLE_WHITELINE_VALUE(integer _v) {
  _s.MIDDLE_WHITELINE_VALUE = 1;
  MIDDLE_WHITELINE_VALUE_v = _v;
}
void white_I_FRONT_IR_VALUE(integer _v) {
  _s.FRONT_IR_VALUE = 1;
  FRONT_IR_VALUE_v = _v;
}

int white(void)
{
	_term_75=-1;
  switch (_state_1) {
  case 0:
    goto N24;
  case 1:
    if (_s.FRONT_IR_VALUE) {
      /* Vacuous terminate */;
      forward_sensor_value = FRONT_IR_VALUE_v;
      if ((forward_sensor_value > 250)) {
        _s.PARK = 1;
      } else {
        _s.LEFT_BACK = 1;
        x = 1;
      }
    N24:
      _state_1 = 0;
    } else {
      _state_1 = 1;
      goto N26;
    }
    break;
  case 2:
    _state_1 = 2;
    if (_state_18) {
      if (_s.MIDDLE_WHITELINE_VALUE) {
        goto N64;
      } else {
        _state_18 = 1;
        _term_75 &= -(1 << 1);
      }
    } else {
    N64:
      _state_18 = 0;
      /* Vacuous terminate */;
    }
    if (_state_14) {
      if (_s.FRONT_IR_VALUE) {
        goto N67;
      } else {
        _state_14 = 1;
        _term_75 &= -(1 << 1);
      }
    } else {
    N67:
      _state_14 = 0;
      /* Vacuous terminate */;
    }
    if (_state_10) {
      if (_s.RIGHT_WHITELINE_VALUE) {
        goto N70;
      } else {
        _state_10 = 1;
        _term_75 &= -(1 << 1);
      }
    } else {
    N70:
      _state_10 = 0;
      /* Vacuous terminate */;
    }
    if (_state_6) {
      if (_s.LEFT_WHITELINE_VALUE) {
        goto N73;
      } else {
        _state_6 = 1;
        _term_75 &= -(1 << 1);
      }
    } else {
    N73:
      _state_6 = 0;
      /* Vacuous terminate */;
    }
    switch (~_term_75) {
    case 0:
      left_value = LEFT_WHITELINE_VALUE_v;
      right_value = RIGHT_WHITELINE_VALUE_v;
      middle_value = MIDDLE_WHITELINE_VALUE_v;
      forward_sensor_value_1 = FRONT_IR_VALUE_v;
      if ((left_value > 40)) {
        _s.MOVE_FWD = 1;
        (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
        (MOTOR_RIGHT_SPEED_v = 70), (_s.MOTOR_RIGHT_SPEED = 1);
        goto N50;
      } else {
        if ((right_value > 40)) {
          _s.MOVE_FWD = 1;
          (MOTOR_LEFT_SPEED_v = 70), (_s.MOTOR_LEFT_SPEED = 1);
          (MOTOR_RIGHT_SPEED_v = 150), (_s.MOTOR_RIGHT_SPEED = 1);
          goto N50;
        } else {
          if ((((right_value < 40) && (left_value < 40)) && (middle_value < 40))) {
            _s.MOVE_FWD = 1;
            (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
            (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
            _s.TURN_LEFT = 1;
            _state_1 = 1;
          } else {
          N50:
            _state_1 = 2;
            /* Vacuous terminate */;
            /* Vacuous terminate */;
            /* Vacuous terminate */;
            /* Vacuous terminate */;
            _state_18 = 1;
            _state_14 = 1;
            _state_10 = 1;
            _state_6 = 1;
            if (((forward_sensor_value_1 > 250) && (forward_sensor_value_1 < 300))) {
              _s.MOVE_FWD = 1;
              (MOTOR_LEFT_SPEED_v = 100), (_s.MOTOR_LEFT_SPEED = 1);
              (MOTOR_RIGHT_SPEED_v = 100), (_s.MOTOR_RIGHT_SPEED = 1);
              _s.BUZZER_ON = 1;
            }
            if (((forward_sensor_value_1 > 200) && (forward_sensor_value_1 < 250))) {
              _s.MOVE_FWD = 1;
              (MOTOR_LEFT_SPEED_v = 50), (_s.MOTOR_LEFT_SPEED = 1);
              (MOTOR_RIGHT_SPEED_v = 50), (_s.MOTOR_RIGHT_SPEED = 1);
              _s.BUZZER_ON = 1;
            }
            if (((forward_sensor_value_1 > 150) && (forward_sensor_value_1 < 200))) {
              _s.MOVE_FWD = 1;
              (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
              (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
              _s.BUZZER_ON = 1;
            }
          }
        }
      }
      break;
    case 1:
      break;
    case 3:
      break;
    default: break;
    }
    goto N26;
  case 3:
    _s.BUZZER_OFF = 0;;
    _s.BUZZER_ON = 0;;
    _s.PARK = 0;;
    _s.RIGHT_BACK = 0;;
    _s.LEFT_BACK = 0;;
    _s.TURN_RIGHT = 0;;
    _s.TURN_LEFT = 0;;
    _s.MOTOR_RIGHT_SPEED = 0;;
    _s.MOTOR_LEFT_SPEED = 0;;
    _s.MOVE_FWD = 0;;
    x = 0;
    _state_1 = 2;
    _state_18 = 1;
    /* Vacuous terminate */;
    _state_14 = 1;
    /* Vacuous terminate */;
    _state_10 = 1;
    /* Vacuous terminate */;
    _state_6 = 1;
    /* Vacuous terminate */;
  N26:
    /* Vacuous terminate */;
    break;
  default: break;
  }
  if (_s.MOVE_FWD) { white_O_MOVE_FWD(); _s.MOVE_FWD = 0; }
  if (_s.MOTOR_LEFT_SPEED) { white_O_MOTOR_LEFT_SPEED(MOTOR_LEFT_SPEED_v); _s.MOTOR_LEFT_SPEED = 0; }
  if (_s.MOTOR_RIGHT_SPEED) { white_O_MOTOR_RIGHT_SPEED(MOTOR_RIGHT_SPEED_v); _s.MOTOR_RIGHT_SPEED = 0; }
  if (_s.TURN_LEFT) { white_O_TURN_LEFT(); _s.TURN_LEFT = 0; }
  if (_s.TURN_RIGHT) { white_O_TURN_RIGHT(); _s.TURN_RIGHT = 0; }
  if (_s.LEFT_BACK) { white_O_LEFT_BACK(); _s.LEFT_BACK = 0; }
  if (_s.RIGHT_BACK) { white_O_RIGHT_BACK(); _s.RIGHT_BACK = 0; }
  if (_s.PARK) { white_O_PARK(); _s.PARK = 0; }
  if (_s.BUZZER_ON) { white_O_BUZZER_ON(); _s.BUZZER_ON = 0; }
  if (_s.BUZZER_OFF) { white_O_BUZZER_OFF(); _s.BUZZER_OFF = 0; }
  _s.LEFT_WHITELINE_VALUE = 0;
  _s.RIGHT_WHITELINE_VALUE = 0;
  _s.MIDDLE_WHITELINE_VALUE = 0;
  _s.FRONT_IR_VALUE = 0;
  return (_state_1 != 0);
}

int white_reset(void)
{
  _s.LEFT_WHITELINE_VALUE = 0;
  _s.RIGHT_WHITELINE_VALUE = 0;
  _s.MIDDLE_WHITELINE_VALUE = 0;
  _s.FRONT_IR_VALUE = 0;
  return 0;
}
/****************************** Fire Bird Specific part ***************************/
static int  IR_THRESHHOLD[3] = {50, 50, 50};
 white_O_PARK(void)
{
	PARK();
}
 white_O_TURN_RIGHT(void)
{
	TURN_RIGHT();
}
white_O_MOTOR_LEFT_SPEED(int val)
{
	MOTOR_LEFT_SPEED(val);
}
white_O_BUZZER_ON(void)
{
	BUZZER_ON();
}
white_O_MOTOR_RIGHT_SPEED(int val)
{
	MOTOR_RIGHT_SPEED(val);
}
 white_O_RIGHT_BACK(void)
{
	RIGHT_BACK();
}
 white_O_LEFT_BACK(void)
{
	LEFT_BACK();
}
white_O_BUZZER_OFF(void)
{
	BUZZER_OFF();
}
 white_O_TURN_LEFT(void)
{
	TURN_LEFT();
}
white_O_MOVE_FWD(void)
{
	MOVE_FWD();
}

/****************************** Main function ***************************/
void main()
{
 init_devices();
 white_reset();
 white();
 while(1)
 {
    white_I_LEFT_WHITELINE_VALUE(LIGHT_LEFT);
    white_I_RIGHT_WHITELINE_VALUE(LIGHT_RIGHT);
    white_I_FRONT_IR_VALUE(FRONT_IR);
    white_I_MIDDLE_WHITELINE_VALUE(LIGHT_MIDDLE);
    white();
 }
}