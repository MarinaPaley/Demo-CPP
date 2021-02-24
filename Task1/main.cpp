#include <iostream>

using namespace std;

int Square (int length);
double Divide(double devident, double devider);
bool isEven(int value);

int main()
{
    /*cout << "Введите ширину квадрата!" << endl;
    int width;
    cin >> width;    
    cout << "Площадь квадрата равна "<< Square(width);*/

    /*cout << "Введите две числовые переменные через пробел" << endl;
    int devident, devider;
    cin >> devident >> devider;
    cout << Divide(devident, devider);*/

    cout << "Введите целое число" << endl;
    int value;
    cin >> value;
    cout << "Число четное? " << boolalpha << isEven(value);


    cout << "Число четное? " << boolalpha <<
        (value % 2 == 0 ? true : false);
    // condition ? operation_if_true : operation_if_false // operator ?:

    return 0;
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
