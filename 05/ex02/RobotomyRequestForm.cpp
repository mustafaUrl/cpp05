#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), target(copy.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
    }
    return (*this);
}

std::string const &RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "* drilling noises *" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomization of " << this->target << " failed." << std::endl;
}
