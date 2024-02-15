#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
	setGrade(150);
	// std::cout << GREEN << "Default Bureaucrat created (default name and grade 150)." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	setGrade(grade);
	// std::cout << GREEN << this->getName() << " succesfully arrived at the office with a grade of " << this->getGrade() << "." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copie) : _name(copie.getName())
{
	setGrade(copie.getGrade());
	// std::cout << BLUE << "Constructeur par copie called." << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << RED << this->getName() << " left the office in a hurry..." << RESET << std::endl;
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

void	Bureaucrat::inGrade() //augmente la note 1 = meilleur
{
	setGrade(this->_grade - 1); //execption
}

void	Bureaucrat::deGrade() //baisse la note 150 = pire
{
	setGrade(this->_grade + 1); //execption
}

//exception
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
    const std::string name = boug.getName(); // Utilisation de la fonction membre toFloat
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