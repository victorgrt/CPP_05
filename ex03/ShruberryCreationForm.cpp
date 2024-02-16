#include "ShruberryCreationForm.hpp"

#include <iostream>
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm() : AForm("ShruberryCreationForm", 145, 137), _target("/home")
{
	// std::cout << GREEN << "[CONSTRUCTEUR] - ShruberryCreationForm created with default target (/home)." << RESET << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(std::string target) : AForm("ShruberryCreationForm", 145, 137), _target(target)
{
	// std::cout << GREEN << "[CONSTRUCTEUR] - SchrubberyCreationForm created with " << target << " as path." << RESET << std::endl;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& copie) : AForm(copie), _target(copie.getTarget())
{
	// std::cout << BLUE << "[CONSTRUCTEUR] - ShruberryCreationForm copié." << RESET << std::endl;
}

ShruberryCreationForm::~ShruberryCreationForm()
{
	// std::cout << RED << "[DESTRUCTEUR] - ShruberryCreationForm détruit." << RESET << std::endl;
}

ShruberryCreationForm& ShruberryCreationForm::operator=(const ShruberryCreationForm& copie)
{
	if (this != &copie)
		return *this;
	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
	return (*this);
}

std::string	ShruberryCreationForm::getTarget() const
{
	return (this->_target);
}

void ShruberryCreationForm::execute(Bureaucrat const & executor) const //add bureaucrate
{
	if (this->getSigned() == true && executor.getGrade() < this->getExecG())
	{
		std::string name = "/ShruberryCreationForm.txt";
		std::string path = this->getTarget() + name;

		std::ofstream myFile(path.c_str());
		std::string	tree = "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n   #o#\\#|#/###\n   #o#\\#|#/###\nejm97  }|{\n";
		myFile << tree;
		std::cout << MAGENTA << "Tree succesfully created at " << path << "." << RESET << std::endl;

		myFile.close();
	}
	else if (!(executor.getGrade() < this->getExecG()))
		throw AForm::GradeTooHighException();
	else if (this->getSigned() == false)
		std::cout << RED << "ERROR : This needs to be signed first!!" << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ShruberryCreationForm& file) {
    const std::string name = file.getName();
	std::string tmp;
	if (file.getSigned() == true)
		tmp = "true";
	else
		tmp = "false";
	os << GREEN << "File# - " << name << " data : target [" << file.getTarget() <<  "], signed[" << tmp << "], signature_lvl[" << file.getSignG() << "], execution_lvl[" << file.getExecG() << "]." << RESET;
	return os;
}