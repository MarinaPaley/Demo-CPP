#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

double ConvertGramsToKgs(const double mass);
double GetKineticEnergy(const double mass, const double velocity);

int main()
{
    double massInGrams, velocity;
    std::cout << "Enter mass in grams and velocity in m per sec\n";
    std::cin >> massInGrams >> velocity;

    std::cout << "Kinetic energy is " << 
        GetKineticEnergy(ConvertGramsToKgs(massInGrams), velocity);
    return 0;
}

double ConvertGramsToKgs(const double mass)
{
    const auto kiloFactor = 1000;
    return mass * kiloFactor;
}

double GetKineticEnergy(const double mass, const double velocity)
{
    return mass * pow(velocity, 2) / 2;
}
