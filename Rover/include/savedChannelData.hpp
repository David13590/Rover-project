#pragma once
typedef struct saved_channel_data{
    int joy1x;
    int joy1y;
    bool joy1Button;
    int joy2x;
    int joy2y;
    bool joy2Button;
    bool pcbLeftButton;
    bool pcbRightButton;
} saved_channel_data;

saved_channel_data& get_saved_channel_data();