/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42paris.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:20:27 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 10:21:07 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
	Bureaucrat A("Dwight", 20);
	ShrubberyCreationForm form1("Trees");
	std::cout << A;
	A.signForm(form1);
	A.executeForm(form1);
	std::cout << std::endl;

	Bureaucrat B("Jim", 46);
	RobotomyRequestForm form2("Andrew");
	std::cout << B;
	B.signForm(form2);
	B.executeForm(form2);
	A.executeForm(form2);
	std::cout << std::endl;

	Bureaucrat C("Michael", 2);
	PresidentialPardonForm form3("Pam");
	std::cout << C;
	B.signForm(form3);
	C.signForm(form3);
	C.executeForm(form3);

	return 0;
}
