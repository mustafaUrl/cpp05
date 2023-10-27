#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm();
       
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
    
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;

};
