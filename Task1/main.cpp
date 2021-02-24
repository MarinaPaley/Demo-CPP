// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

int Square (int length);
double Square(const double length, const double factor);
double Divide(double devident, double devider);
bool isEven(int value);
double Perimeter(const double length, const double factor);
double Volume(const double radius);
double Squre_Sphera(const double radius);
double f1(const double x, const double a);
double f2(const double x, const double a);
double y(const double x);


enum Action { volume, surface};

int main()
{
    const auto leftBound = 2.0;
    const auto rightBound = 3.0;
    const auto step = 0.1;

    auto x = leftBound;
    while ( (x < rightBound) || (abs(x - rightBound) < step))
    {
        cout << "x = " << setprecision(2) << x << " y =  " << setprecision(5) << y(x) << endl;
        x += step;
    }

    /*const auto a = 2.5;
    double x;
    cout << "Введите переменную x = ";
    cin >> x;
    if (x > a)
    {
        cout << "y = " << f1(x, a);
    }
    else
    {
        cout << "y = " << f2(x, a);
    }
    */

    /*double radius;
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

    /*
    switch (action)
    {
        case volume:
            cout << "Объем шара = " << Volume(radius);
            break;
        case surface:
            cout << "Поверхность шара = " << Squre_Sphera(radius);
            break;
    }
    */

    /*double a;
    double n;
    cout << "Введите длину прямоугольника и коэффициент ";
    cin >> a >> n;
    cout << "S = " << Square(a, n) << " P = " << Perimeter(a, n);*/

    /*const double x = 1.426;
    const double y = -1.22;
    const double z = 3.5;

    const auto a = (2 * cos(x - M_PI / 6.0)) / (0.5 + sin(y) * sin(y));
    const auto b = 1 + (z * z / (3 + z * z / 5.0));

    cout << setprecision(10) << a << ' ' << b << endl;

    const auto epsilonDouble = numeric_limits<double>::epsilon();
    const auto epsilonFloat = numeric_limits<float>::epsilon();
    cout << "double = " << epsilonDouble << endl;
    cout << "float = " << epsilonFloat;*/



    /*cout << "Введите ширину квадрата!" << endl;
    int width;
    cin >> width;    
    cout << "Площадь квадрата равна "<< Square(width);*/

    /*cout << "Введите две числовые переменные через пробел" << endl;
    int devident, devider;
    cin >> devident >> devider;
    cout << Divide(devident, devider);*/

    /*cout << "Введите целое число" << endl;
    int value;
    cin >> value;
    cout << "Число четное? " << boolalpha << isEven(value);


    cout << "Число четное? " << boolalpha <<
        (value % 2 == 0 ? true : false);
    // condition ? operation_if_true : operation_if_false // operator ?:*/


    return 0;
}

double y (const double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

double f1(const double x, const double a)
{
    return x * pow(x - a, 1.0 / 3.0);
}

double f2(const double x, const double a)
{
    return x * sin(a * x);
}

double Squre_Sphera(const double radius)
{
    return 4 * M_PI * radius * radius;
}

double Volume (const double radius)
{
    return 4.0 / 3.0 * M_PI * pow(radius, 3);
}

double Square (const double length, const double factor)
{
    return length * length * factor;
}

double Perimeter(const double length, const double factor)
{
    return 2 * (1 + factor) * length;
}

int Square(const int length)
{
    const auto square = length * length;
    return square;
}

double Divide(const double devident, const double devider)
{
    return devident / devider;
}

bool isEven(const int value)
{
    /*int a = value % 2;
    if (a == 0)
        return  true;
    return false;*/

    return value % 2 == 0;
}
