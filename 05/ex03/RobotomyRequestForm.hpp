#pragma once 
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string const target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();
        
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
        
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;
};
