#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << MAGENTA << "=== CREATION ===" << RESET << std::endl;
	Form formulaire("formulaire #1", 50, 49);
	std::cout << formulaire << std::endl;
	std::cout << MAGENTA << "=== TOO HIGH ===" << RESET << std::endl;
	try
	{
		Form tooBig("formulaire #2", 159, 15);
		// Form tooBig2("formulaire #3", 15, 159);
		std::cout << "SKIPPED A CAUSE DE DU CATCH " << std::endl; 
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << MAGENTA << "=== TOO LOW ===" << RESET << std::endl;
	try
	{
		Form toolow("formulaire #4", 130, 0);
		// Form toolow2("formulaire #5", -10, 130);
		std::cout << "SKIPPED A CAUSE DE DU CATCH " << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << MAGENTA << "=== SIGNATURE ===" << RESET << std::endl;
	try
	{
		Form	lll("formalux", 30, 40);
		std::cout << lll << std::endl;
		Bureaucrat vivi("victor", 20);
		lll.beSigned(vivi);
		vivi.signForm(lll);
		std::cout << lll << std::endl;
		vivi.setGrade(150);
		lll.beSigned(vivi);
		vivi.signForm(lll);
		std::cout << "SKIPPED A CAUSE DE DU CATCH " << lll << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << MAGENTA << "=== FREE ===" << RESET << std::endl;
	
}