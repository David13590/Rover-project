#ifndef GESTURE_
#define GESTURE_

class gesture{
    private:
        #define buttonPin 1

    public:
        void gestureSetup();
        bool readGesture();
};
#endif