#include <iomanip>
#include <iostream>

using namespace std;

/**
 * \brief Расчет функции 3 в степени x.
 * \param x степень.
 * \return Значение 3 в степени x.
 */
double Get3PowerX(const double x);

double Recurrent(const unsigned int index, const double x);

double GetSumRow(const double x, const double epsilon);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto leftBound = 0.1;
    const auto rightBound = 1.0;
    const auto epsilon = 0.0001;
    const auto step = 0.01;

    auto x = leftBound;
    while (x <= rightBound + epsilon)
    {
        const auto func = Get3PowerX(x);
        const auto row = GetSumRow(x, epsilon);
        cout << setw(10) << x << " | " << setw(15) << func << " | " << setw(15) << row << "\n";
        x += step;
    }

    return 0;
}

double Get3PowerX(const double x)
{
    return pow(3, x);
}

double Recurrent(const unsigned int index, const double x)
{
    return log(3) * x / index;
}

double GetSumRow(const double x, const double epsilon)
{
    auto previous = 0.0;
    auto current = 1.0;
    auto sum = current;
    unsigned int index = 1;
    do
    {
        previous = current;
        current = previous * Recurrent(index, x);
        sum += current;
        index++;
    } while (std::abs(previous - current) <= epsilon);

    return sum;
}
