#include <iostream>

class DivideByZeroException
{
};

class NegativeValueException
{
};

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
    {
        throw DivideByZeroException();
    }
    if (miles < 0 || gallons < 0)
    {
        throw NegativeValueException();
    }

    return static_cast<double>(miles) / gallons;
}

int main(void)
{

    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter the miles driven: ";
    std::cin >> miles;

    std::cout << "Enter the gallons used: ";
    std::cin >> gallons;

    try
    {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (const DivideByZeroException &ex)
    {
        std::cerr << "Sorry, you can't divide by zero." << std::endl;
    }
    catch (const NegativeValueException &ex)
    {
        std::cerr << "Sorry, one of your parameters is negative." << std::endl;
    }

    std::cout << "Bye" << std::endl;

    return 0;
}

/*
    Best practice:
        throw an object not a primitive type
        throw an object by value
        catch an object by reference or const reference
*/