#include "AForm.hpp"

AForm::AForm() : _fname("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	// std::cout << GREEN << "Formulaire par défaut créer." << RESET << std::endl;
}

AForm::AForm(std::string newname, int sign_grade, int exec_grade) : _fname(newname), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (exec_grade < 1 || sign_grade < 1)
		throw AForm::GradeTooLowException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooHighException();
	this->_signed = false;
}

AForm::AForm(const AForm& copie) : _fname(copie.getName()), _signed(false), _sign_grade(copie.getSignG()), _exec_grade(copie.getExecG())
{
	// std::cout << BLUE << "Formulaire copied from " << copie.getName() << RESET << std::endl;
}

AForm::~AForm()
{
	// std::cout << RED << this->getName() << " detruit par le feu." << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& copie)
{
	if (this != &copie)
		return (*this);
// 	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
	return (*this);
}

bool	AForm::getSigned() const
{
	if (this->_signed == true)
		return (true);
	else
		return (false);
}

const std::string	AForm::getName() const
{
	return (this->_fname);
}

int	AForm::getSignG() const
{
	return (this->_sign_grade);
}

int	AForm::getExecG() const
{
	return (this->_exec_grade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return (RED "AFORM ERROR CATCHED => AForm Grade Too LOW !" RESET);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return (RED "AFORM ERROR CATCHED => AForm Grade Too HIGH !" RESET);
}

void	AForm::beSigned(Bureaucrat &boug)
{
	if (this->_sign_grade > boug.getGrade())
	{
		this->_signed = true;
		std::cout << YELLOW << this->_fname << " can be signed by " << boug.getName() << ". Value set to true." << RESET << std::endl; 
	}
	else
	{
		this->_signed = false;
		std::cout << YELLOW << this->_fname << " canNOT be signed by " << boug.getName() << " because his grade is too high. Value set to false." << RESET << std::endl; 
		throw AForm::GradeTooHighException();
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& file) {
    const std::string name = file.getName();
	std::string tmp;
	if (file.getSigned() == true)
		tmp = "true";
	else
		tmp = "false";
	os << GREEN << "File - " << name << " - data : signed[" << tmp << "], signature_lvl[" << file.getSignG() << "], execution_lvl[" << file.getExecG() << "]." << RESET;
	return os;
}