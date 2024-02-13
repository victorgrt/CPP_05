#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"

class Bureaucrat
{
	private : 
		const std::string _name;
		int	_grade;

	public : 
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& copie);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& copie);

	const std::string getName() const;
	int	getGrade() const;
	void	setGrade(int grade);
	void	setName(const std::string name) const;


	void	inGrade();
	void	deGrade();

	//exception
	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat	& fixed);


#endif
