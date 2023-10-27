#include "Intern.hpp"

int main(void)
{
    Intern someRandomIntern;

    AForm *rrf = someRandomIntern.makeForm("robotomy request", "James");
    AForm *prf = someRandomIntern.makeForm("presidential pardon", "mraymun");
    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "file");

    std::cout << someRandomIntern.makeForm("there is no such form", "doesn't matter") << std::endl;

    Bureaucrat president("President", 1);
    Bureaucrat minister("Minister", 70);

    minister.signForm(*rrf);
    president.signForm(*rrf);
    minister.signForm(*prf);
    president.signForm(*prf);
    minister.signForm(*scf);
    president.signForm(*scf);

    minister.executeForm(*rrf);
    president.executeForm(*rrf);
    minister.executeForm(*prf);
    president.executeForm(*prf);
    minister.executeForm(*scf);
    president.executeForm(*scf);
}
