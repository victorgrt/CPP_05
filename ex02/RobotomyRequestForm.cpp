#include "RobotomyRequestForm.hpp"
#include <stdlib.h>     /* srand, rand */

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("victor")
{
	std::cout << GREEN << "Constructeur par défaut called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GREEN << "Constructeur par défaut called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copie) : AForm(copie), _target(copie.getTarget())
{
	std::cout << BLUE << "Constructeur par copie called." << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "Destructeur called." << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copie)
{
	if (this != &copie)
		return (*this);
	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == true && executor.getGrade() < this->getExecG())
	{
		std::cout << BLUE << "***🦾🤖🛠️ Drilling noise 🛠️🤖🦾***" << RESET << std::endl;
		srand(time(0)); 
		int	random = rand();
		if (random % 2 == 0)
			std::cout << BLUE << this->getTarget() << " robotomization " << MAGENTA << "SUCCES" << BLUE << " ! (" << random << ")" << RESET << std::endl;
		else
			std::cout << BLUE << this->getTarget() << " robotomization " << MAGENTA << "FAILED" << BLUE << " ! (" << random << ")" << RESET << std::endl;
	}
	else if (!(executor.getGrade() < this->getExecG()))
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		std::cout << RED << "ERROR : This needs to be signed first !!" << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& file)
{
    const std::string name = file.getName();
	std::string tmp;
	if (file.getSigned() == true)
		tmp = "true";
	else
		tmp = "false";
	os << GREEN << "File# - " << name << " data : target [" << file.getTarget() <<  "], signed[" << tmp << "], signature_lvl[" << file.getSignG() << "], execution_lvl[" << file.getExecG() << "]." << RESET;
	return os;
}