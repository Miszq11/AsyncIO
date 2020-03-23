#include "../include/car.h"
//#include <iostream>

using namespace std;
void Car::setup()
{
    engineStarted = false;
}
/*konstruktor klasy Car*/
Car::Car()
{
    enginePower = 60;
    engineDisplacement = 1200;
}
Car::Car(Car& copy)
{
    enginePower = copy.enginePower;
    engineDisplacement = copy.engineDisplacement;
}
Car::Car(unsigned int power, unsigned int displacement)
{
    engineDisplacement = displacement;
    enginePower = power;
}
void Car::brake()
{
    if(!engineStarted)
        cout << "Car is braking." << endl;
    else
        cout << "Car not starte d.\n";
    
    
}

void Car::startEngine()
{
    cout << "Engine has been started." << endl;
}
void Car::showParameters()
{
    cout << "Engine power is: " << enginePower << 
            " egnine displacement is: " << engineDisplacement <<'\n';
}

void Car::drive()
{
    cout << "Car is moving." << endl;
}