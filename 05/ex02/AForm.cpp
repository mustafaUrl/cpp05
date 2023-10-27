#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

AForm::AForm(std::string const &name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{}


AForm &AForm::operator=(AForm const &copy)
{
    if (this != &copy)
        this->isSigned = copy.isSigned;
    return (*this);
}

AForm::~AForm()
{}

std::string const &AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int const &AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int const &AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    else if (this->isSigned)
        throw AForm::AFormAlreadySignedException();
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned)
        throw AForm::AFormNotSignedException();
    else if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
    return ("AForm already signed");
}

const char *AForm::AFormNotSignedException::what() const throw()
{
    return ("AForm not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << form.getName() << " form's grade required to sign it " << form.getGradeToSign() << " and grade required to execute it " << form.getGradeToExecute();
    if (form.getIsSigned())
        out << " and is signed";
    else
        out << " and is not signed";
    return (out);
}


