#include "Intern.hpp"

Intern::Intern()
{
	for (int i = 0; i < 4; i++)
		this->_forms[i] = NULL;
	// std::cout << GREEN << "Intern par default creer." << RESET << std::endl;
}

Intern::Intern(const Intern& copie)
{	
	for (int i = 0; i < 4; i++)
		this->_forms[i] = NULL;
	*this = copie;
	// std::cout << BLUE << "Intern par copie created." << RESET << std::endl;
}

Intern::~Intern()
{
	for (int i = 0; i < 3; i++)
		delete (this->_forms[i]);
	// std::cout << RED << "Intern executé." << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& copie)
{
	// std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
	if (this != &copie)
		return (*this);
	return (*this);
}

AForm*	Intern::makeForm(std::string name, const std::string target)
{
	this->_forms[0] = new PresidentialPardonForm(target);
	this->_forms[1] = new ShruberryCreationForm(target);
	this->_forms[2] = new RobotomyRequestForm(target);
	
	if (target.empty() || name.empty())
		throw WrongArgs();
	for (int i = 0; i < 3; i++)
	{
		if (name == this->_forms[i]->getName())
		{
			std::cout << BLUE << "Intern created a " << name << " form." << RESET << std::endl;
			return (this->_forms[i]);
		}
	}
	throw NotFound();
}

const char* Intern::NotFound::what() const throw()
{
	return (RED "INTERN ERROR CATCHED => Form Not Found" RESET);
}

const char* Intern::WrongArgs::what() const throw()
{
	return (RED "INTERN ERROR CATCHED => BAD ARGUMENTS" RESET);
}