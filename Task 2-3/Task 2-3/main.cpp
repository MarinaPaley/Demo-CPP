#include <iostream>

using namespace std;

/**
 * \brief
 * Функция определения является ли среднее арифметическое трех чисел целым числом?
 * \param a целое число
 * \param b целое число
 * \param c целое число
 * \return true при условии, что среднее арифметическое является целым числом
 */
bool IsAverageInt(const int a, const int b, const int c);

/**
 * \brief Точка входа в программу
 * \return код ошибки. 0 - успех
 */
int main()
{  
    cout << "Input 3 integer numbers \n";
    int a, b, c;
    cin >> a >> b >> c;

    const auto result = IsAverageInt(a, b, c)
        ? "Average is integer"
        : "Average is real";

    cout << result;

    return 0;
}

bool IsAverageInt(const int a, const int b, const int c)
{
    return (a + b + c) % 3 == 0;
}
