#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
	setGrade(150);
	std::cout << GREEN << "Default Bureaucrat created (default name and grade 150)." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	setGrade(grade);
	std::cout << GREEN << this->getName() << " succesfully arrived at the office with a grade of " << this->getGrade() << "." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copie) : _name(copie.getName())
{
	setGrade(copie.getGrade());
	std::cout << BLUE << "Constructeur par copie called." << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << this->getName() << " left the office in a hurry..." << RESET << std::endl;
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
	return (RED "Grade Too Low !" RESET);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED "Grade Too High !" RESET);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& boug) {
    const std::string name = boug.getName();
    os << GREEN << name << " has a grade of " << BLUE << boug.getGrade() << RESET;
    return os;
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
	std::cout << BLUE << this->getName() << " signed the form \"" << form.getName() << "\"." << RESET << std::endl;
}