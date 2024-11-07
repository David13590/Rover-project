#ifndef SENSOR_HPP_
#define SENSOR_HPP_

class sensorClass{
    public:
        struct sensorReturnOutput{
            int sensorDistanceLeft;
            int sensorDistanceRight;
        };
        void sensorSetup();
        sensorReturnOutput* sensorRead();

    private:
        #define XshutSensor1 33
        #define XshutSensor2 15
        sensorReturnOutput mySensorOutput;
};
#endif