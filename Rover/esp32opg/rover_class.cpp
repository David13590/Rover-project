#include <iostream>

class Rover {
    private:
        int hbro_array_højre[2] = {14, 16};
        int hbro_array_venstre[2] = {12, 13};
        int sensor[2] = {21, 22};
    public:
        void forward(int);
};

void Rover::forward(int speed) {
    std::cout << hbro_array_højre[0] << std::endl;
}

int main() {
    Rover rover;
    rover.forward(200);
}