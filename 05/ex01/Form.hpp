#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;
public:
    Form();
    Form(std::string const &name, int const gradeToSign, int const gradeToExecute);
    Form(Form const &copy);
    ~Form();

    Form &operator=(Form const &copy);

    std::string const &getName() const;
    bool getIsSigned() const;
    int const &getGradeToSign() const;
    int const &getGradeToExecute() const;
    void beSigned(Bureaucrat const &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class FormAlreadySignedException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

