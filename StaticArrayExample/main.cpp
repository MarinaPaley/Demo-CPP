#include <iostream>
#include <random>
#include <string>

using namespace std;

/**
 * \brief 
 * \param message 
 * \param array 
 * \param size 
 */
void ArrayPrint(const string& message, const int array[], size_t size);

/**
 * \brief 
 * \param array 
 * \param size 
 * \param min 
 * \param max 
 */
void ArrayFill(int array[], size_t size, int min, int max);

void Example1(double& x);

/**
 * \brief 
 * \return 
 */
int main()
{
    const size_t size = 15;
    int staticArray[size];

    cout << "Input minValue of array = ";
    int minValue;
    cin >> minValue;

    cout << "nInput maxValue of array  = ";
    int maxValue;
    cin >> maxValue;

    if (maxValue <= minValue)
    {
        minValue = -10;
        maxValue = 10;
        cout << "\nYou input wrong range. Right range is ["
             << minValue << ","
             << maxValue << "]\n";
    }

    ArrayFill(staticArray, size, minValue, maxValue);

    const string message = "\nGenerated array is:\n";
    ArrayPrint(message, staticArray, size);
    
  /*  double x = 2.0;
    Example1(x);
    cout << x;*/

    cout << endl;
    return 0;
}

void Example1(double& x)
{
    x *= 2;
}

// int* pointer = nullptr;
// create_array(pointer, 10);
void create_array(int*& array, const size_t size)
{
    array = new int[size];
}

// auto pointer = create_array(10);
int* create_array(const size_t size)
{
    return new int[size];
}

void ArrayPrint(const string& message, const int array[], const size_t size)
{
    cout << message;
    for (size_t index = 0; index < size; index++)
    {
        cout << array[index] << " ";
    }
}

void ArrayFill(int array[], const size_t size, const int min, const int max)
{
    //Will be used to obtain a seed for the random number engine
    std::random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    std::mt19937 gen(rd());


    const uniform_int_distribution<> uniformIntDistribution(min, max);
    for (size_t index = 0; index < size; index++)
    {
        array[index] = uniformIntDistribution(gen);
    }
}
