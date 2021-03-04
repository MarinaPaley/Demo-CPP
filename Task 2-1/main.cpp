// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

double Volume(const double radius);
double Squre_Sphera(const double radius);

enum Action { volume, surface };

int main()
{
    double radius;
    cout << "Введите радиус шара = ";
    cin >> radius;
    cout << endl;

    int input;
    cout << "Введите действие над шаром (объем = 0, площадь поверхности = 1) ";
    cin >> input;

    const auto action = static_cast<Action>(input);

    /*if (action == volume)
    {
        cout << "Объем шара = " << Volume(radius);
    }
    else
    {
        cout << "Поверхность шара = " << Squre_Sphera(radius);
    }*/
    switch (action)
    {
        case volume:
            cout << "Объем шара = " << Volume(radius);
            break;
        case surface:
            cout << "Поверхность шара = " << Squre_Sphera(radius);
            break;
    }
    return 0;
}
double Squre_Sphera(const double radius)
{
    return 4 * M_PI * radius * radius;
}

double Volume(const double radius)
{
    return 4.0 / 3.0 * M_PI * pow(radius, 3);
}