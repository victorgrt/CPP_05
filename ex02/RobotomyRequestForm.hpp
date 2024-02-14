#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"

class RobotomyRequestForm : public AForm
{
	private : 
		std::string _target;

	public : 
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copie);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copie);

	void	execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& file);

#endif
