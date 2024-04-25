#include <iostream>
#include <string>

class Drone {
private:
    std::string manufacturer;
    std::string model;
    double max_speed; // in meters per second

public:
    // Constructor
    Drone(std::string man, std::string mod, double max_spd)
        : manufacturer(man), model(mod), max_speed(max_spd) {}

    // Method to fly the drone
    void fly() {
        std::cout << "The drone is flying." << std::endl;
    }

    // Method to get drone details
    void getDetails() {
        std::cout << "Manufacturer: " << manufacturer << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Max Speed: " << max_speed << " m/s" << std::endl;
    }
};

int main() {
    // Creating an instance of Drone
    Drone drone("DJI", "Mavic Air", 20.0);

    // Flying the drone
    drone.fly();

    // Getting drone details
    drone.getDetails();

    return 0;
}
