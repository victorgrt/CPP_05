#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"

class Intern
{
	private : 
		AForm *_forms[3];
	public : 
	Intern();
	Intern(const Intern& copie);
	~Intern();
	Intern& operator=(const Intern& copie);
	AForm*	makePresident(std::string target);
	AForm*	makeForm(std::string name, std::string target);


	class NotFound : public std::exception {
	public:
		const char *what(void) const throw();
	};
	
	class WrongArgs : public std::exception {
	public:
		const char *what(void) const throw();
	};
};

#endif
