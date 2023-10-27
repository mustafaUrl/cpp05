#include "Form.hpp"

int main(void)
{
    try
    {
        Form test("Form 18C", 0, 0);
        std::cout << test << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Form test("Form 17C", 151, 151);
        std::cout << test << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Form form20a("Form 20A", 91, 95);
    Form form20b("Form 20B", 85, 85);
    Form form20c("Form 20C", 90, 75);
    Form form20d("Form 20D", 101, 101);
    Bureaucrat signer("James", 90);
    std::cout << std::endl << signer << std::endl;
    std::cout << form20a << std::endl;
    signer.signForm(form20a);
    signer.signForm(form20a);
    std::cout << form20a << std::endl << form20b << std::endl;
    signer.signForm(form20b);
    std::cout << form20b << std::endl << form20c << std::endl;
    signer.signForm(form20c);
    std::cout << form20c << std::endl << form20d << std::endl;
    signer.signForm(form20d);
    std::cout << form20d << std::endl;
}
