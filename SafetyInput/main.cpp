#include <iostream>
#include <exception>
#include <string>

/**
 * \brief
 * \param message
 * \param in
 * \param out
 * \return
 */
int NonSafetyInput(
    const std::string& message,
    std::istream& in = std::cin,
    std::ostream& out = std::cout);

bool TryParse(int& value);

int main()
{
    auto size = 0;
    int value;

    try
    {
        //size = NonSafetyInput("Input array size = ");
        if (TryParse(value))
            std::cout << "TryParse - OK" << std::endl;
        else
            std::cout << "No Ok" << std::endl;

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 2;
    }

   // std::cout << "OK! size = " << size << std::endl;
    return 0;
}

int NonSafetyInput(const std::string& message, std::istream& in, std::ostream& out)
{
    out << message;
    auto value = 0;
    in >> value;

    //in.clear();
    in.seekg(0, std::ios_base::beg);

    std::string buffer;
    in >> buffer;

    const auto parsedValue = std::stoi(buffer);
    if (parsedValue != value)
    {
        throw std::exception("wrong int value");
    }

    return value;
}

bool TryParse(int& value)
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
