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

    const auto massInKgs = ConvertGramsToKgs(massInGrams);
    const auto energy = GetKineticEnergy(massInKgs, velocity);

    std::cout << "Kinetic energy is " << energy;
    return 0;
}


/**
 * \brief Метод перевода массы в граммах в массу в килограммах
 * \param mass Масса в г
 * \return Масса в кг
 */
double ConvertGramsToKgs(const double mass)
{
    const auto kiloFactor = 1000;
    return mass * kiloFactor;
}

/**
 *   \brief Метод расчёта кинетической энергии в СИ.
 *
 *   \param mass Масса в килограммах (кг).
 *   \param velocity Скорость в метрах в секунду (м/с).
 *   \return Значение кинетической энергии в Джоулях (Дж).
 */
double GetKineticEnergy(const double mass, const double velocity)
{
    return mass * pow(velocity, 2) / 2;
}
