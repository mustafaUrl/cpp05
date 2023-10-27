#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;
public:
    AForm();
    AForm(std::string const &name, int const gradeToSign, int const gradeToExecute);
    AForm(AForm const &copy);
    ~AForm();

    AForm &operator=(AForm const &copy);

    std::string const &getName() const;
    bool getIsSigned() const;
    int const &getGradeToSign() const;
    int const &getGradeToExecute() const;
    void beSigned(Bureaucrat const &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class AFormAlreadySignedException : public std::exception
    {
        virtual const char *what() const throw();
    };

    class AFormNotSignedException : public std::exception
    {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

