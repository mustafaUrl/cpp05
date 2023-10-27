#pragma once
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &copy);
        ~Intern();

        Intern &operator=(Intern const &copy);

        AForm *makeForm(std::string const &formName, std::string const &target);
};
