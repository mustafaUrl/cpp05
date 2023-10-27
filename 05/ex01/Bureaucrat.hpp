#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    std::string const name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const &name, int grade);
    Bureaucrat(Bureaucrat const &copy);
    ~Bureaucrat();
    
    Bureaucrat &operator=(Bureaucrat const &copy);
    
    std::string const &getName() const;
    int const &getGrade() const;
    void incGrade(int value);
    void decGrade(int value);
    void signForm(Form &form);
    
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
}; 

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
