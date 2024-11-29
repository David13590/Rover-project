#ifndef JOYSTICK_HPP_
#define JOYSTICK_HPP_
    
class joystick{
    private:
        const int neutralMin = 1700;
        const int neutralMax = 2000;

    public:
        struct joystickValue{
            int X;
            int Y;
        };
        void setup();
        joystickValue* get_value(int joyXPin, int joyYPin);
        
};

#endif