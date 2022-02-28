/*
  DigiKeyPlus.h - Shortcut commands built on top of DigiKeyboard.h
  Created by BrightShard, 2022
*/

#ifndef DigiKeyPlus_h
#define DigiKeyPlus_h

#include "Arduino.h"



// Actual class ----------------------------------------------------------------
class DigiKeyPlus
{
  public:
    DigiKeyPlus();
    void Init(int slowFactor, int buttonPin, void (*script)());
    void Update();
    void Append(const char* text);
    void Append(char text);
    void Type(const char* text);
    void Type(char text);
    void Type(byte key, byte modifier);
    void Type(byte key);
    void Wait(int time);
    void VolumeUp();
    void VolumeDown();
    void MacSpotlight(String query);
    void MacTerminal();
    void WinRun(String command);
  private:
    void (*_script)();
    bool _canRun;
    int _slowFactor;
    int _buttonPin;
};



// Keycodes --------------------------------------------------------------------
#define CONTROL_LEFT    (1<<0)
#define SHIFT_LEFT      (1<<1)
#define ALT_LEFT        (1<<2)
#define GUI_LEFT        (1<<3)
#define WIN_LEFT        (1<<3)
#define CMD_LEFT        (1<<3)
#define CONTROL_RIGHT   (1<<4)
#define SHIFT_RIGHT     (1<<5)
#define ALT_RIGHT       (1<<6)
#define GUI_RIGHT       (1<<7)
#define WIN_RIGHT       (1<<7)
#define CMD_RIGHT       (1<<7)

#define KEY_A       4
#define KEY_B       5
#define KEY_C       6
#define KEY_D       7
#define KEY_E       8
#define KEY_F       9
#define KEY_G       10
#define KEY_H       11
#define KEY_I       12
#define KEY_J       13
#define KEY_K       14
#define KEY_L       15
#define KEY_M       16
#define KEY_N       17
#define KEY_O       18
#define KEY_P       19
#define KEY_Q       20
#define KEY_R       21
#define KEY_S       22
#define KEY_T       23
#define KEY_U       24
#define KEY_V       25
#define KEY_W       26
#define KEY_X       27
#define KEY_Y       28
#define KEY_Z       29
#define KEY_0       39
#define KEY_1       30
#define KEY_2       31
#define KEY_3       32
#define KEY_4       33
#define KEY_5       34
#define KEY_6       35
#define KEY_7       36
#define KEY_8       37
#define KEY_9       38

#define KEY_ENTER   40
#define KEY_SPACE   44
#define VOLUME_UP   128
#define VOLUME_DOWN 129
#define CAPS_LOCK   130
#define ARROW_LEFT  80
#define ARROW_RIGHT 79
#define ARROW_UP    82
#define ARROW_DOWN  81

#define FUNCTION1      58
#define FUNCTION2      59
#define FUNCTION3      60
#define FUNCTION4      61
#define FUNCTION5      62
#define FUNCTION6      63
#define FUNCTION7      64
#define FUNCTION8      65
#define FUNCTION9      66
#define FUNCTION10     67
#define FUNCTION11     68
#define FUNCTION12     69

#endif
