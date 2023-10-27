#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    PresidentialPardonForm pp_form("mraymun");
    ShrubberyCreationForm sc_form("file");
    RobotomyRequestForm rr_form("bedolaga");

    Bureaucrat zafod("Zafod Beeblebrox", 1);
    Bureaucrat james("James", 44);
    Bureaucrat jonh("Jonh", 70);

    std::cout << pp_form << std::endl << sc_form << std::endl << rr_form << std::endl;
    std::cout << zafod << std::endl << james << std::endl << jonh << std::endl << std::endl;

    std::cout << std::endl << "PresidentialPardonForm test: " << std::endl;
    james.signForm(pp_form);
    james.executeForm(pp_form);
    jonh.signForm(pp_form);
    jonh.executeForm(pp_form);
    zafod.signForm(pp_form);
    zafod.executeForm(pp_form);

    std::cout << std::endl << "RobotomyRequestForm test: " << std::endl;
    jonh.signForm(rr_form);
    jonh.executeForm(rr_form);
    james.signForm(rr_form);
    james.executeForm(rr_form);

    std::cout << std::endl << "ShrubberyCreationForm test: " << std::endl;
    james.signForm(sc_form);
    james.executeForm(sc_form);
}
