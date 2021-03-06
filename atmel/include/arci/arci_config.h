#ifndef _ARCI_CONFIG_H
#define _ARCI_CONFIG_H

// global settings
#define PERIOD      10      // system period
#define PERIOD_T    10      // timeout period
// #define PERIOD_W    80     // timeout period
#define MAX_TIMEOUT 40      // timeout (compared to an unsigned char!)

// servo settings
#define FREQ        50.0    // servo/motor frequency
#define STEP_LEFT   40
#define STEP_RIGHT  40
#define MIDDLE      1450

// motor settings
// @ 50Hz
//#define SLOW_SPEED    6000
//#define MAX_SPEED     20250
//#define STEP_SPEED    101

/*
    accidentally damaged ATMEGA and the TIMER used by the motor seems to only
    be capable of producing a 250Hz PWM signal now so these values work with
    that to get the right duty cycles. ¯\_(ツ)_/¯
*/
// @ 250Hz
#define MAX_SPEED   4040
#define STEP_SPEED  171
#define SLOW_SPEED  1640
#define MAX_REV     (SLOW_SPEED + (STEP_SPEED*2))

#define TASKS_NUM 5
// SM states
enum DATA_STATES { START_D, INIT_D, WAIT_D, READ_D };
enum MOTOR_STATES { START_M, INIT_M, WAIT_M, MOVE_M };
enum SERVO_STATES { START_S, INIT_S, WAIT_S, UPDATE_S };
enum TIME_STATES { START_T, INIT_T, NO_DATA_D, DATA_D, ATTN_D };
enum WIRED_STATES { START_W, INIT_W, WAIT_W, CMD_W };

// shared vars
unsigned char incoming_data;    // tmp value to read incoming data
unsigned char ready;            // connected to client flag
// unsigned char wired;            // connected to wired remote flag
unsigned char crash_alert;      // crash alert flag
unsigned char data_avail;       // data received flag

#endif  // ARCI_CONFIG_H
