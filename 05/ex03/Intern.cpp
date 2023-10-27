#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
    *this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &copy)
{
    if (this != &copy)
    {
        *this = copy;
    }
    return (*this);
}

  static AForm *createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

static AForm *createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createEmptyForm(std::string)
{
    std::cout << "* Intern said there is no such type of form, isn't he wrong? *" << std::endl;
    return (0);
}


 AForm *Intern::makeForm(std::string const &formName, std::string const &target)
 {
    const static std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    static AForm* (*formCreators[])(std::string) = {createPresidentialPardonForm, createRobotomyRequestForm, createShrubberyCreationForm, createEmptyForm};

    int idx = 0;
    while (idx < 3 && types[idx] != formName)
        idx++;
    return (*formCreators[idx])(target);
}
