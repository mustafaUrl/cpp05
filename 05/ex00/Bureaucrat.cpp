#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
    if (this != &copy)
        this->grade = copy.grade;
    return (*this);
}

std::string const &Bureaucrat::getName() const
{
    return (this->name);
}

int const &Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incGrade(int value)
{
    if (this->grade - value < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade -= value;
}

void Bureaucrat::decGrade(int value)
{
    if (this->grade + value > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade += value;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (out);
}
