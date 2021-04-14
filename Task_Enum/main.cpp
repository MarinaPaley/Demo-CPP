#include <iostream>

/**
 * \brief Method an square area calculation.
 * \param width Square width.
 * \return Square area.
 */
double GetSquareArea(const double width);

/**
 * \brief Method an triangle area  calculation.
 * \param a The first side of a triangle.
 * \param b The second side of a triangle.
 * \param c The third side of a triangle.
 * \return Triangle area.
 */
double GetTriangleArea(const double a, const double b, const double c);

/**
 * \brief Type of existing figures
 */
enum class Figures {triangle, square};

/**
 * \brief The enter point to the program
 * \return 0 if success
 */
int main()
{
    std::cout << "Please, choose a figure (triangle = 0, square = 1) = ";
    int choice;
    std::cin >> choice;
    const auto figure = static_cast<Figures>(choice);
    switch (figure)
    {
        case Figures::triangle:
        {
            std::cout << "You've chosen a triangle.\nPlease enter three sides ";
            double a, b, c;
            std::cin >> a >> b >> c;
            const auto area = GetTriangleArea(a, b, c);
            std::cout << "\nThe triangle area is " << area << std::endl;
            break;
        }
        case Figures::square:
        {
            std::cout << "You've chosen a square.\nPlease enter a side = ";
            double width;
            std::cin >> width;
            const auto area = GetSquareArea(width);
            std::cout << "\nThe square area is " << area << std::endl;;
            break;
        }
    }
        
    return 0;
}

double GetSquareArea(const double width)
{
    return width * width;
}

double GetTriangleArea(const double a, const double b, const double c)
{
    const auto semiPerimeter = (a + b + c) / 2;
    return sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter -c));
}