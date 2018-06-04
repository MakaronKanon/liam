/*
 Liam - DIY Robot Lawn Mower

 Debug Mode Library

 ======================
  Licensed under GPLv3
 ======================
*/

#include <Arduino.h>
#include "Wheelmotor.h"
#include "CutterMotor.h"
#include "BWFSensor.h"
#include "MotionSensor.h"
#include "Definition.h"
#include "Controller.h"

#ifndef _SETUPDEBUG_H_
#define _SETUPDEBUG_H_

class SETUPDEBUG {
  public:
    SETUPDEBUG(CONTROLLER* mower, WHEELMOTOR* left, WHEELMOTOR* right, CUTTERMOTOR* cut, BWFSENSOR* bwf, MOTIONSENSOR* comp, BATTERY* batt);
    int tryEnterSetupDebugMode(int currentState);
    void updateBWF();
  private:
    CONTROLLER* mower;
    WHEELMOTOR* leftMotor;
    WHEELMOTOR* rightMotor;
    CUTTERMOTOR* cutter;
    BWFSENSOR* sensor;
    MOTIONSENSOR* compass;
    BATTERY* battery;
    void printHelp();
    void toggleWheelLeft();
    void togglewheelRight();
    void toggleCutterMotor();
    void getBwfSignals();
    void getMotionValues();
    void toggleLed();

    int pitch;
    boolean led_is_on;

    boolean cutter_motor_is_on;
    boolean left_wheel_motor_is_on;
    boolean right_wheel_motor_is_on;
    boolean cutter_is_attached;
    int cutterspeed;

    int16_t mx, gx, ax;
    int16_t my, gy, ay;
    int16_t mz, gz, az;
    int x, y, z;

    int current_heading, target_heading, tilt_angle;
};

#endif /* _SETUPDEBUG_H_ */
