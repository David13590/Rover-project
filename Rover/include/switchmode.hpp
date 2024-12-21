#ifndef SWITCHMODE_HPP_
#define SWITCHMODE_HPP_

void switchmodeSetup();
void switchmode_getMode();

enum switchMode{
    manual = 0,
    arm,
    autonomous
};
#endif