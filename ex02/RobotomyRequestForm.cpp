#include "RobotomyRequestForm.hpp"
#include <stdlib.h>     /* srand, rand */

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("/home")
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

/* RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> 
has been robotomized
successfully 50% of the time. Otherwise, informs that 
the robotomy failed*/

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == true && executor.getGrade() < this->getExecG())
	{
		std::cout << BLUE << "🦾🤖🛠️ **Drill noise**" << RESET << std::endl;
		srand(time(0)); 
		int	random = rand();
		std::cout << random << std::endl;
		if (random % 2 == 0)
			std::cout << BLUE << "Target robotomization SUCCESS ! (" << random << ")" << RESET << std::endl;
		else
			std::cout << BLUE << "Target robotomization FAILED ! (" << random << ")" << RESET << std::endl;
	}
	else if (!(executor.getGrade() < this->getExecG()))
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		std::cout << RED << "ERROR : This needs to be signed first !!" << RESET << std::endl;
}