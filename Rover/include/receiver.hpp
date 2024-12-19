#ifndef RECEIVER_HPP_
#define RECEIVER_HPP_

typedef struct channel_data{
    int channel1;
    int channel2;
    bool channel3;
    int channel4;
    int channel5;
    bool channel6;
    bool channel7;
    bool channel8;
} channel_data;

typedef struct saved_channel_data{
    int channel1;
    int channel2;
    bool channel3;
    int channel4;
    int channel5;
    bool channel6;
    bool channel7;
    bool channel8;
} saved_channel_data;

void receiver_setup();
saved_channel_data& get_saved_channel_data();

#endif