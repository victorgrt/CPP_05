#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"

int	main(void)
{
	// ShruberryCreationForm formulaire;
	// std::cout << formulaire << std::endl;

	// ShruberryCreationForm formulaire2("/tmp");
	// std::cout << formulaire2 << std::endl;
	// formulaire2.execute();
	std::cout << YELLOW << "=== CREATION ===" << RESET << std::endl;
	Bureaucrat noob("noob", 150);
	ShruberryCreationForm formulaire3("/home/victor/CPP_05/ex02");
	try
	{
		std::cout << formulaire3 << std::endl;
		formulaire3.execute(noob);
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat vivi("victor", 1);
	formulaire3.execute(vivi);
	vivi.signForm(formulaire3);
	formulaire3.execute(vivi);

	return (0);
}