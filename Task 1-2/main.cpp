#include <iostream>

using namespace std;

/**
 * \brief Вычисляет ширину прямоугольника
 * \param length Длина стороны прямоугольника.
 * \param factor Коэффициент пропорциональности между длиной
 * и шириной прямоугольника в %
 * \return Ширина прямоугольника
 */
double Width(const double length, const double factor);

/**
 * \brief Вычисляет площадь прямоугольника.
 * \param length Длина стороны прямоугольника.
 * \param width Ширина стороны прямоугольника.
 * \return Площадь прямоугольника.
 */
double Square(const double length, const double width);

/**
 * \brief Вычисляет периметр прямоугольника.
 * \param length Длина стороны прямоугольника.
 * \param width Ширина стороны прямоугольника.
 * \return Периметр прямоугольника.
 */
double Perimeter(const double length, const double width);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    cout << "Введите длину стороны прямоугольника\n";
    double a;
    cin >> a;

    cout << "Введите коэффициент пропорциональности n (%), "
         << "позволяющий вычислить длину второй стороны\n";
    double  n;
    cin >> n;

    const auto width = Width(a, n);

    const auto square = Square(a, width);
    cout << "Площадь квадрата равна " << square << "\n";

    const auto perimeter = Perimeter(a, width);
    cout << "Периметр прямоугольника " << perimeter << endl;
}

double Width(const double length, const double factor)
{
    const auto centFactor = 100;
    return length * factor / centFactor;
}

double Square(const double length, const double width)
{
    return length * width;
}

double Perimeter(const double length, const double width)
{
    return 2 * (length + width);
}
