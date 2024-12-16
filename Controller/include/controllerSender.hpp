#ifndef CONTROLLERSENDER_HPP_
#define CONTROLLERSENDER_HPP_
    
class controllerSender{
    private:
        //JoystickLeft
        #define JOY_LEFT_VRX_PIN 36
        #define JOY_LEFT_VRY_PIN 39
        #define JOY_LEFT_SW_PIN 33

        //JoystickRight
        #define JOY_RIGHT_VRX_PIN 35
        #define JOY_RIGHT_VRY_PIN 32
        #define JOY_RIGHT_SW_PIN 34

    public:
        const int buttonDebounceTime = 200;
        const int mapFromLow = 0;
        const int mapFromHigh = 4095;
        const int mapToLow = 0;
        const int mapToHigh = 1000;
               
};
#endif