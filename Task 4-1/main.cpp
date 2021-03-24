#include <iostream>
#include <string>
#include <random>

using namespace std;

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(size_t size, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param array массив.
 * \param size размер массива.
 * \param message претворяющая печать надпись.
 */
void ArrayPrint(const int* array, size_t size, const string& message = "");

/**
 * \brief Ввод целого числа.
 * \param message претворяющая печать надпись.
 * \return целое число, введенное пользователем.
 */
int IntInput(const string& message);

/**
 * \brief Метод, изменяющий неправильный диапазон.
 * \param min минимальное значение.
 * Будет изменено, если ошибочно было больше максимального.
 * Результатом станет -10.
 * \param max максимальное значение.
 * Будет изменено, если ошибочно было меньше минимального.
 * Результатом станет 10.
 */
void ChangeWrongRange(int& min, int& max);

/**
 * \brief Нахождение суммы нечетных значений элементов массива.
 * \param array массив.
 * \param size размер массива.
 * \return сумма нечетных значений элементов массива.
 * Если массива не существует, то сумма = 42.
 */
int SumOddValues(const int* array, size_t size);

/**
 * \brief Определяет, нечетное ли число?
 * \param element число.
 * \return если нечетное, то true. Если четное - false
 */
bool IsOdd(int element);

/**
 * \brief Вывод на консоль всех индексов, начиная с заданного.
 * \param size размер массива.
 * \param number заданный индекс.
 */
void PrintIndexesAboveConst(size_t size, size_t number);

/**
 * \brief Создание нового массива, путем копирования исходного массива
 * и замены второго элемента на максимальный отрицательный элемент (если такой имеется)
 * \param array исходный массив.
 * \param size размер массива.
 * \return новый измененный массив.
 */
int* SecondElementChanged(const int* array, const size_t size);

/**
 * \brief Метод, который возвращает индекс первого отрицательного элемента массива. 
 * \param array массив
 * \param size размер массива
 * \return индекс первого отрицательного элемента массива.
 * Если отрицательный элемент не найден, то индекс равен размеру массива.
 */
size_t FirstNegativeElement(const int* array, size_t size);

/**
 * \brief Метод, возвращает индекс максимального отрицательного элемента.
 * \param array массив.
 * \param size размер массива.
 * \return возвращает индекс максимального отрицательного элемента.
 * Если отрицательный элемент не найден, то индекс равен размеру массива.
 */
size_t MaxNegativeElement(const int* array, size_t size);

/**
 * \brief Копирование исходного массива.
 * \param array исходный массив.
 * \param size размер массива.
 * \return новый массив со скопированными элементами.
 */
int* ArrayCopy(const int* array, size_t size);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \param message надпись для пользователя.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size, const string& message = "");


/**
 * \brief Метод преобразования строки в целое число
 * \param value неинициализированная переменная
 * \return true, если введено целое число. Инициализируем переменную правильным вводом.
 *false, если строка не может быть преобразована в целое число. Нет инициализации переменной.
 */
bool TryParse(size_t& value);

/**
 * \brief 
 */
enum class ArrayInputWay
{
    random,
    keyboard
};

/**
 * \brief Точка входа в программу
 * \return 0, в случае успеха
 */
int main()
{
    std::cout << "Input array size = ";
    size_t size;
   // cin >> size;
    if (!TryParse(size))
    {
        std::cout << "Error!";
        return 3;
    }

    if (size == 0)
    {
        std::cout << "You entered wrong size!\n";
        return 1;
    }
    
    std::cout << "Which way of array filling are you prefer?\n"
         << static_cast<int>(ArrayInputWay::random) << " - random,\n"
         << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n"
         << "Your choice is ";
    int choice;
    std::cin >> choice;

    try
    {
        const auto chosen = static_cast<ArrayInputWay>(choice);
        int* myArray = nullptr;

        switch (chosen)
        {
            case ArrayInputWay::random:
            {
                auto minValue = IntInput("Input min value of array = ");
                auto maxValue = IntInput("Input max value of array = ");
                if (maxValue <= minValue)
                {
                    ChangeWrongRange(minValue, maxValue);
                }
                myArray = FillRandomArray(size, minValue, maxValue);
                break;
            }
            case ArrayInputWay::keyboard:
            {
                myArray = FillUserArray(size, "Input elements of the array");
                break;
            }
            default :
                cout << "You entered wrong choice!\n";
                return 1;
        }

        ArrayPrint(myArray, size, "\nThe array is:\n");

        const auto sum = SumOddValues(myArray, size);
        cout << "Sum of elements odd value = " << sum << "\n";

        cout << "Input number in range [0, " << size - 1 << "] = ";
        size_t number;
        cin >> number;
        PrintIndexesAboveConst(size, number);

        const auto changedArray = SecondElementChanged(myArray, size);
        ArrayPrint(changedArray, size, "\nThe changed array is:\n");

        delete[] myArray;
        delete[] changedArray;

        cout << endl;
        return 0;
    }
    catch (out_of_range&)
    {
        cout << "You entered wrong choice!";
        return 1;
    }
   
}

size_t FirstNegativeElement(const int* array, const size_t size)
{
    if (array == nullptr) 
        return size;

    size_t index = 0;
    while(index < size && array[index] >= 0)
    {
        index++;
    }
    return index;
}

size_t MaxNegativeElement(const int* array, const size_t size)
{
    if (array == nullptr)
        return size;

    auto maxElementIndex = FirstNegativeElement(array, size);
    for(size_t index = maxElementIndex + 1; index < size; index++)
    {
        if (array[index] < 0 && array[index] > array[maxElementIndex])
            maxElementIndex = index;
    }
    return maxElementIndex;
}

int* ArrayCopy(const int* array, const size_t size)
{
    if (array == nullptr)
        return nullptr;

    const auto target = new int[size];
    for (size_t index = 0; index < size; index ++)
    {
        target[index] = array[index];
    }
    return target;
}

int* SecondElementChanged(const int* array, const size_t size)
{
    if (array == nullptr)
        return nullptr;

    const auto newArray = ArrayCopy(array, size);
    const auto maxElementIndex = MaxNegativeElement(array, size);

   /* if (maxElementIndex < size)
    {
        cout << "\nMax element is "<< array[maxElementIndex] <<"\n";
    }
    else
    {
        cout << "\nNo max element\n";
    }*/

    const auto secondElementIndex = 1;
    if (size - 1 > secondElementIndex && maxElementIndex < size)
        newArray[secondElementIndex] = newArray[maxElementIndex];
    return newArray;
}

void PrintIndexesAboveConst(const size_t size, const size_t number)
{
    cout << "Indexes above " << number << " are: ";
    for (size_t index = number + 1; index < size; index++)
    {
        cout << index << " ";
    }
}

bool IsOdd(const int element)
{
    return element % 2 != 0;
}

int SumOddValues(const int* array, const size_t size)
{
    if (array == nullptr)
        return 42;

    auto sum = 0;
    for(size_t index = 0; index < size; index++)
    {
        if (IsOdd(array[index]))
            sum += array[index];
    }
    return sum;
}

void ChangeWrongRange(int& min, int& max)
{
    min = -10;
    max = 10;
    cout << "\nYou input wrong range. Right range is ["
        << min << ","
        << max << "]\n";
}

int IntInput(const string& message)
{
    cout << message;
    int temp;
    cin >> temp;
    return temp;
}

void ArrayPrint(const int* array, const size_t size, const string& message)
{
    if (array == nullptr)
    {
        cout << "The array doesn't exist";
        return;
    }

    cout << message;
    for (size_t index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
    cout << "\n";
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    auto* array = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        array[index] = uniformIntDistribution(gen);
    }

    return array;
}

int* FillUserArray(const size_t size, const string& message)
{
    auto* array = new int[size];
    cout << message << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}

bool TryParse(size_t& value)
{
    std::string str;
    std::getline(std::cin, str);
    const auto size = str.size();
    size_t index = 0;
    while (index < size && isdigit(str[index]))
    {
        index++;
    }

    value = std::stoi(str);
    return index >= size;
}