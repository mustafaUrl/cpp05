#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

Form::Form(std::string const &name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{}


Form &Form::operator=(Form const &copy)
{
    if (this != &copy)
        this->isSigned = copy.isSigned;
    return (*this);
}

Form::~Form()
{}

std::string const &Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int const &Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int const &Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    else if (this->isSigned)
        throw Form::FormAlreadySignedException();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return ("Form already signed");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
    out << form.getName() << " form's grade required to sign it " << form.getGradeToSign() << " and grade required to execute it " << form.getGradeToExecute();
    if (form.getIsSigned())
        out << " and is signed";
    else
        out << " and is not signed";
    return (out);
}
