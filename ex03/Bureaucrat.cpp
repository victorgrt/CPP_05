#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
	setGrade(150);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& copie) : _name(copie.getName())
{
	setGrade(copie.getGrade());
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copie)
{
	if (this != &copie)
	{
		this->setGrade(copie._grade);
	}
	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::inGrade()
{
	setGrade(this->_grade - 1);
}

void	Bureaucrat::deGrade()
{
	setGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (RED "ERROR BUREAUCRAT CATCHED =>  Grade Too LOW !" RESET);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED "ERROR BUREAUCRAT CATCHED => Bureaucrat Grade Too HIGH !" RESET);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& boug) {
    const std::string name = boug.getName();
    os << GREEN << name << " has a grade of " << BLUE << boug.getGrade() << RESET;
    return os;
}

void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
	std::cout << BLUE << this->getName() << " signed the form \"" << form.getName() << "\"." << RESET << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	if (form.getSigned() == true && this->getGrade() < form.getExecG())
		std::cout << BLUE << this->getName() << " executed " << form.getName() << RESET << std::endl;
	else
		std::cout << RED << this->getName() << " cannot execute " << form.getName() << RESET << std::endl;
}