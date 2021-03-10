#include <iostream>

using namespace std;

/**
 * \brief Рассчитывает сумму ряда через рекуррентное соотношение
 * до тех пор, пока текущий член ряда не превосходит epsilon
 * \param epsilon точность расчета суммы ряда
 * \return 
 */
double Sum(const double epsilon);
/**
 * \brief Рассчитывает сумму ряда через рекуррентное соотношение
 * из n членов
 * \param size количество членов ряда
 * \return 
 */
double Sum(const size_t size);

/**
 * \brief Функция расчета рекуррентного соотношения
 * \param index номер члена ряда
 * \return
 */
double Recurrence(const size_t index);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    cout << "Введите количество членов ряда = ";
    size_t count;
    cin >> count;

    cout << "\nВведите точность расчета суммы ряда ";
    double epsilon;
    cin >> epsilon;

    const auto sumNumber = Sum(count);
    cout << "\nСумма "<< count << " членов ряда = " << sumNumber;

    const auto sumEpsilon = Sum(epsilon);
    cout << "\nСумма членов ряда = " << sumEpsilon << " с точностью " << epsilon;

    return 0;
}

double Recurrence(const size_t index)
{
    return 1.0 / ((index + 2) * (index + 3));
}

double Sum(const size_t size)
{   
    auto previous = 1.0 / (2 * 2 * 3);
    auto sum = previous;
    for (size_t k = 1; k < size; k++)
    {
        const auto current = Recurrence(k) * previous;
        sum += current;
        previous = current;
    }

    return sum;
}

double Sum(const double epsilon)
{
    auto previous = 1.0 / (2 * 2 * 3);
    auto sum = previous;
    auto k = 1;
    while (abs(previous) > epsilon)
    {
        const auto current = Recurrence(k) * previous;
        sum += current;
        previous = current;
        k++;
    }

    return sum;
}


