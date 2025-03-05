#include "../headers/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(0) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    checkGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        _grade = other._grade;
        checkGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    _grade--;
    checkGrade();
}

void Bureaucrat::decrementGrade()
{
    _grade++;
    checkGrade();
}

void Bureaucrat::checkGrade() const
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << " grade : " << bureaucrat.getGrade();
    return os;
}