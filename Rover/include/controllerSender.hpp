#ifndef CONTROLLERSENDER_HPP_
#define CONTROLLERSENDER_HPP_
    
class controllerSender{
    private:
        //JoystickLeft
        #define JOY_LEFT_VRX_PIN 34
        #define JOY_LEFT_VRY_PIN 35
        #define JOY_LEFT_SW_PIN 32

        //JoystickRight
        #define JOY_RIGHT_VRX_PIN 000
        #define JOY_RIGHT_VRY_PIN 000
        #define JOY_RIGHT_SW_PIN 000

    public:
        const int buttonDebounceTime = 100;
               
};
#endif