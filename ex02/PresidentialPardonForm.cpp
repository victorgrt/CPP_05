#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("victor")
{
	std::cout << GREEN << "Constructeur par défaut called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GREEN << "Constructeur par défaut called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copie) : AForm(copie), _target(copie.getTarget())
{
	(void) copie;
	std::cout << BLUE << "Constructeur par copie called." << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "Destructeur called." << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copie)
{
	(void) copie;
	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == true && executor.getGrade() < this->getExecG())
	{
		std::cout << BLUE << "👨‍⚖️ Zaphod Beeblebrox : \"" << this->getTarget() << " je te pardonne fils <3\" 👨‍⚖️" << RESET << std::endl;
	}
	else if (!(executor.getGrade() < this->getExecG()))
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
		std::cout << RED << "ERROR : This needs to be signed first !!" << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& file)
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