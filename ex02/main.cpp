#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << YELLOW << "=== CREATION ===" << RESET << std::endl;
	Bureaucrat vivi("victor", 1);
	Bureaucrat noob("noob", 150);
	ShruberryCreationForm formulaire3("/tmp");
	RobotomyRequestForm form4("Obama");
	PresidentialPardonForm	president("Donald Duck");
	std::cout << "\n" << formulaire3 << "\n" << form4 << "\n" << president << std::endl;
	std::cout << YELLOW << "=== ERROR BAD GRADES ===" << RESET << std::endl;
	try
	{
		Bureaucrat test("test", -1);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat test("test", 22000);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << YELLOW << "=== ERROR GRADE TOO HIGH ===" << RESET << std::endl;
	try
	{
		formulaire3.execute(noob);
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << YELLOW << "=== CANT SIGN ===" << RESET << std::endl;
	try
	{
		formulaire3.beSigned(noob);
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		form4.beSigned(noob);
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		president.beSigned(noob);
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << YELLOW << "=== ERROR FORM NOT SIGNED ===" << RESET << std::endl;
	{
		formulaire3.execute(vivi);
		form4.execute(vivi);
		president.execute(vivi);
	}
	std::cout << YELLOW << "=== SIGNATURE ===" << RESET << std::endl;
	{
		vivi.signForm(president);
		vivi.signForm(form4);
		vivi.signForm(formulaire3);
	}
	std::cout << YELLOW << "=== EXECUTION ===" << RESET << std::endl;
	{
		vivi.executeForm(president);
		vivi.executeForm(form4);
		vivi.executeForm(formulaire3);
		std::cout << "\n";
		president.execute(vivi);
		form4.execute(vivi);
		formulaire3.execute(vivi);
	}
	std::cout << RED << "=== DESTRUCTION ===" << RESET << std::endl;
	return (0);
}