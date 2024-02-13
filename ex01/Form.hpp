#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"

class Bureaucrat;

class Form
{
	private :
		const std::string _fname;
		bool		_signed;
		const int	_sign_grade;
		const int	_exec_grade;

	public : 
		Form();
		Form(std::string newname, int slevel, int elevel);
		Form(const Form& copie);
		~Form();
		Form& operator=(const Form& copie);

		void	setGrade(int grade);
		const std::string	getName() const;
		int	getExecG() const;
		int	getSignG() const;
		bool getSigned() const;

		void	beSigned(Bureaucrat &boug);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& file);

#endif
