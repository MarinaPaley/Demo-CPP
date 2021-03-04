// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

double y(const double x);

int main()
{
    const auto leftBound = 2.0;
    const auto rightBound = 3.0;
    const auto step = 0.1;

    auto x = leftBound;
    while ((x < rightBound) || (abs(x - rightBound) < step))
    {
        cout << "x = " << setprecision(2) << x << " y =  " << setprecision(5) << y(x) << endl;
        x += step;
    }
    return 0;
}

double y(const double x)
{
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}