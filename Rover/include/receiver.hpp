#ifndef RECEIVER_HPP_
#define RECEIVER_HPP_

void receiver_setup();

typedef struct channel_data{
    int channel1;
    int channel2;
    bool channel3;
    int channel4;
    int channel5;
    bool channel6;
} channel_data;

typedef struct saved_channel_data{
    int saved_channel1;
    int saved_channel2;
    bool saved_channel3;
    int saved_channel4;
    int saved_channel5;
    bool saved_channel6;
} saved_channel_data;

#endif