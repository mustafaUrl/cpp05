#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat test("Bill", 0);
        std::cout << test << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat test("Jonh", 999);
        std::cout << test << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat normal("James", 75);
    std::cout << normal << std::endl;
    normal.decGrade(75);
    std::cout << normal << std::endl;
    normal.incGrade(149);
    std::cout << normal << std::endl;
    try
    {
        normal.incGrade(10);
        std::cout << normal;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
