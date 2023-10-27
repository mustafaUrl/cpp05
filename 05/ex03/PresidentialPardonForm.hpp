#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string const target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm();
        
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
        
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;
};
