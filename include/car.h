#ifndef CAR_H
#define CAR_H
#include <iostream>
class Car
{
private:
    unsigned int enginePower;
    unsigned int engineDisplacement;
    bool engineStarted;

    void setup();

public:
    Car();
    Car(Car&);
    Car(unsigned int, unsigned int);
    void brake();
    void startEngine();
    void drive();
    void showParameters();
};

#endif