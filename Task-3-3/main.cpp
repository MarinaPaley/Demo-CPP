#include <iomanip>
#include <iostream>

using namespace std;

/**
 * \brief Расчет функции 3 в степени x.
 * \param x Показатель степени.
 * \return Значение 3 в степени x.
 */
double Get3PowerX(const double x);

/**
 * \brief Вычисление рекуррентного члена ряда.
 * \param x Параметр функции, аппроксимируемой рядом.
 * \param index Индекс члена ряда.
 * \return Значение рекуррентного члена.
 */
double GetRecurrent(const double x, const unsigned int index);

/**
 * \brief Вычисление суммы ряда от x, до того момента пока |x_i - x_{x-1}| >= epsilon
 * \param x Показатель степени.
 * \param epsilon Погрешность вычислений.
 * \return Значение 3 в степени x.
 */
double GetSumOfSeries(const double x, const double epsilon);

/**
 * \brief Форматный вывод в поток вывода out (по умолчанию std::cout).
 * \param argument Аргумент табулируемой функции.
 * \param function Значение табулируемой функции.
 * \param series Аппроксимация табулируемой функции.
 * \param out Поток вывода, в который будет осуществлен форматный вывод.
 */
void FormatOutput(const double argument, const double function, const double series, ostream& out = cout);

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
        const auto function = Get3PowerX(x);
        const auto series = GetSumOfSeries(x, epsilon);

        FormatOutput(x, function, series);

        x += step;
    }

    return 0;
}

double Get3PowerX(const double x)
{
    return pow(3, x);
}

double GetRecurrent(const double x, const unsigned int index)
{
    return log(3) * x / (index + 1);
}

double GetSumOfSeries(const double x, const double epsilon)
{
    auto previous = 0.0;
    auto current = 1.0;
    auto sum = current;
    unsigned int index = 0;

    do
    {
        previous = current;
        current = previous * GetRecurrent(x, index);
        sum += current;
        index++;
    } while (abs(previous - current) >= epsilon);

    return sum;
}

void FormatOutput(const double argument, const double function, const double series, ostream& out)
{
    out << setw(10) << argument << " | "
        << setw(15) << function << " | "
        << setw(15) << series << "\n";
}
