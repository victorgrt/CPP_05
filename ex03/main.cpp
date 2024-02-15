#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat general("general", 1);
	Bureaucrat toolow("noobie", 150);
	PresidentialPardonForm president("Obama");
	ShruberryCreationForm tree("/tmp");
	RobotomyRequestForm robot("le correcteur");

	std::cout << "=== ERROR NOT SIGNED ===" << std::endl;
	{
		president.execute(general);
		tree.execute(general);
		robot.execute(general);
	}
	std::cout << "=== ERROR INVALID GRADE ===" << std::endl;
	try
	{
		Bureaucrat toohigh("toogood", 151);
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat toobad("toobad", -1);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n" << GREEN << "=== FORMS SIGNED ===" << RESET << std::endl;
	{
		general.signForm(tree);
		general.signForm(president);
		general.signForm(robot);
	}
	
	std::cout << "=== ERROR BUREAUCRAT GRADE TOO LOW ===" << std::endl;
	try
	{
		president.execute(toolow);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tree.execute(toolow);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		robot.execute(toolow);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n" << GREEN << "=== EXECUTION ===" << RESET << std::endl;
	{
		tree.execute(general);
		robot.execute(general);
		president.execute(general);
	}
	std::cout << "\n" << GREEN << "=== INTERN ERRORS ===" << RESET << std::endl;
	try
	{
		Intern newIntern;
		AForm *rrf;
		rrf = newIntern.makeForm("lol", "le pape");
	}
	catch(Intern::NotFound& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Intern newIntern;
		AForm *rrf;
		rrf = newIntern.makeForm("RobotomyRequestForm", "");
	}
	catch(Intern::WrongArgs& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n" << GREEN << "=== INTERN CREACTION FORM ===" << RESET << std::endl;
	{
		Intern newIntern;
		AForm *rrf;
		rrf = newIntern.makeForm("PresidentialPardonForm", "le pape");
		rrf->execute(general);
		general.signForm(*rrf);
		rrf->execute(general);
	}
	// ShruberryCreationForm formulaire;
	// std::cout << formulaire << std::endl;

	// ShruberryCreationForm formulaire2("/tmp");
	// std::cout << formulaire2 << std::endl;
	// formulaire2.execute();
	// std::cout << YELLOW << "=== CREATION ===" << RESET << std::endl;
	// Bureaucrat noob("noob", 150);
	// ShruberryCreationForm formulaire3("/home/victor/CPP_05/ex02");
	// try
	// {
	// 	std::cout << formulaire3 << std::endl;
	// 	formulaire3.execute(noob);
	// }
	// catch(AForm::GradeTooLowException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// Bureaucrat vivi("victor", 1);
	// formulaire3.execute(vivi);
	// vivi.signForm(formulaire3);
	// formulaire3.execute(vivi);

	// std::cout << "\n\n";
	// RobotomyRequestForm form4("Obama");
	// std::cout << form4 << std::endl;
	// form4.execute(vivi);
	// vivi.signForm(form4);
	// form4.execute(vivi);

	// std::cout << "\n\n";
	// PresidentialPardonForm	president("Donald Duck");
	// std::cout << president << std::endl;
	// president.execute(vivi);
	// vivi.signForm(president);
	// president.execute(vivi);
	
	// std::cout << "\n\n";
	// Intern newIntern;
	// AForm *rrf;

	// rrf = newIntern.makeForm("PresidentialPardonForm", "Obama");
	// rrf->execute(vivi);
	// vivi.signForm(*rrf);
	// rrf->execute(vivi);
	// std::cout << "\n\n";

	return (0);
}