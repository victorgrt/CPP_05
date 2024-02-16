#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

/*• ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.*/
#include "AForm.hpp"
#include <iostream>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"

class ShruberryCreationForm : public AForm
{
	private :
		std::string _target;
	public : 
	ShruberryCreationForm();
	ShruberryCreationForm(std::string target);
	ShruberryCreationForm(const ShruberryCreationForm& copie);
	~ShruberryCreationForm();
	ShruberryCreationForm& operator=(const ShruberryCreationForm& copie);

	std::string	getTarget() const;
	void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& os, const ShruberryCreationForm& file);

#endif
