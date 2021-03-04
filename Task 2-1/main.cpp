// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <iomanip>
#include <cmath>


using namespace std;

/**
 * \brief Расчет объема шара.
 * \param radius Радиус шара. 
 * \return Объем шара.
 */
double Volume(const double radius);


/**
 * \brief Расчет площади поверхности шара.
 * \param radius Радиус шара. 
 * \return Площадь поверхности шара.
 */
double SurfaceArea(const double radius);

/**
 * \brief Пользовательский выбор расчета или объема шара (0),
 * или площади поверхности шара (1)
 */
enum ActionChoice { volume, surface };

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    cout << "Введите радиус шара = ";
    double radius;
    cin >> radius;

    cout << "Введите действие над шаром (объем = 0, площадь поверхности = 1) ";
    int input;
    cin >> input;

    const auto choice = static_cast<ActionChoice>(input);

    switch (choice)
    {
        case volume:
        {
            const auto volume = Volume(radius);
            cout << "Объем шара = " << volume;
            break;
        }
        case surface:
        {
            const auto surfaceArea = SurfaceArea(radius);
            cout << "Поверхность шара = " << surfaceArea;
            break;
        }
    }
    return 0;
}
double SurfaceArea(const double radius)
{
    return 4 * M_PI * radius * radius;
}

double Volume(const double radius)
{
    return 4.0 / 3.0 * M_PI * pow(radius, 3);
}