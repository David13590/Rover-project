#ifndef GESTURE_
#define GESTURE_

class gesture{
    private:
        #define buttonPin 17

    public:
        void gestureSetup();
        bool readGesture();
};
#endif