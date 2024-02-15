#include "Form.hpp"

Form::Form() : _fname("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << GREEN << "Constructeur par défaut called." << RESET << std::endl;
}

Form::Form(std::string newname, int sign_grade, int exec_grade) : _fname(newname), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (exec_grade < 1 || sign_grade < 1)
		throw Form::GradeTooLowException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooHighException();
	this->_signed = false;
}

Form::Form(const Form& copie) : _fname(copie.getName()), _exec_grade(copie.getExecG()), _sign_grade(copie.getSignG()), _signed(copie.getSigned())
{
	std::cout << BLUE << "Form copied from " << copie.getName() << RESET << std::endl;
}

Form::~Form()
{
	std::cout << RED << this->getName() << " detruit par le feu." << RESET << std::endl;
}

Form& Form::operator=(const Form& copie)
{
	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
	return (*this);
}

bool	Form::getSigned() const
{
	if (this->_signed == true)
		return (true);
	else
		return (false);
}

const std::string	Form::getName() const
{
	return (this->_fname);
}

int	Form::getSignG() const
{
	return (this->_sign_grade);
}

int	Form::getExecG() const
{
	return (this->_exec_grade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return (RED "Form Grade Too Low !" RESET);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return (RED "Form Grade Too High !" RESET);
}

void	Form::beSigned(Bureaucrat &boug)
{
	if (this->_sign_grade > boug.getGrade())
	{
		this->_signed = true;
		std::cout << YELLOW << this->_fname << " can be signed by " << boug.getName() << ". Value set to true." << RESET << std::endl; 
	}
	else
	{
		this->_signed = false;
		std::cout << YELLOW << this->_fname << " canNOT be signed by " << boug.getName() << ". Value set to false." << RESET << std::endl; 
		throw Form::GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Form& file) {
    const std::string name = file.getName();
	std::string tmp;
	if (file.getSigned() == true)
		tmp = "true";
	else
		tmp = "false";
	os << GREEN << "File# - " << name << " data : signed[" << tmp << "], signature_lvl[" << file.getSignG() << "], execution_lvl[" << file.getExecG() << "]." << RESET;
	return os;
}