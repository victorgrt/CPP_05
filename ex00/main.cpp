#include "Bureaucrat.hpp"

 int main()
{
	Bureaucrat Roger("Roger", 1);
	Bureaucrat Louis("Louis", 150);
	std::cout << YELLOW << "\n=== CREATION OF THE OFFICE ===" << RESET << std::endl;
	{
		Bureaucrat defaultBureaucrat;
		std::cout << defaultBureaucrat.getGrade() << std::endl;
		std::cout << defaultBureaucrat.getName() << std::endl;

		Bureaucrat Louis("louis", 69);
		std::cout << Louis << std::endl;

		Bureaucrat copied = Louis;
		std::cout << "here : " << copied << std::endl;
	}
	std::cout << YELLOW << "\n=== NORMAL ===" << RESET << std::endl;
	{
		Bureaucrat Noob("noob", 148);
		Noob.deGrade();
		std::cout << Noob << std::endl;
		Noob.deGrade();
		std::cout << Noob << std::endl;

		Bureaucrat Pro("pro", 5);
		std::cout << Pro << std::endl;
		for (int i = 0; i < 4; i++)
		{
			Pro.inGrade();
			std::cout << Pro << std::endl;
		}
	}
	std::cout << YELLOW << "\n=== GRADE TOO LOW ===" << RESET << std::endl;
	try {
		// Bureaucrat("Minus", -1);
		std::cout << Roger << std::endl;
		Roger.inGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << YELLOW << "\n=== GRADE TOO HIGH ===" << RESET << std::endl;
	try
	{
		// Bureaucrat("Maxus", 151);
		std::cout << Louis << std::endl;
		Louis.deGrade(); //too high donc stop ici
		std::cout << Louis << std::endl;
		Louis.deGrade();
		std::cout << Louis << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << YELLOW << "\n=== FREE ===" << RESET << std::endl;
	return 0;
}
