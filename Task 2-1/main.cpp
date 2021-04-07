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
double GetVolume(const double radius);


/**
 * \brief Расчет площади поверхности шара.
 * \param radius Радиус шара. 
 * \return Площадь поверхности шара.
 */
double GetSurfaceArea(const double radius);

/**
 * \brief Пользовательский выбор расчета или объема шара (0),
 * или площади поверхности шара (1)
 */
enum class ActionChoice { volume, surface };

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
        case ActionChoice::volume:
        {
            const auto volume = GetVolume(radius);
            cout << "Объем шара = " << volume;
            break;
        }
        case ActionChoice::surface:
        {
            const auto surfaceArea = GetSurfaceArea(radius);
            cout << "Поверхность шара = " << surfaceArea;
            break;
        }
    }
    cout << endl;
    return 0;
}
double GetSurfaceArea(const double radius)
{
    return 4 * M_PI * radius * radius;
}

double GetVolume(const double radius)
{
    return 4.0 / 3.0 * M_PI * pow(radius, 3);
}