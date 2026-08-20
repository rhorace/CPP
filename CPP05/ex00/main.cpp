/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:29:18 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/20 09:29:21 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	/* TEST 1 : Grade trop faible

	Le constructeur par défaut donne le grade 150.
	decrementGrade() tente de descendre le grade à 151.
	GradeTooLowException doit se declencher */

	std::cout << YELLOW << "TEST 1 : Grade trop faible" << RESET << std::endl;

	Bureaucrat A;

	std::cout << A;

	try
	{
		A.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// Le grade doit toujours être 150 après l'exception.
	std::cout << A;
	std::cout << std::endl;


	/* TEST 2 : Constructeur de copie

	B est construit à partir de A.
	Il possède donc le même nom et le même grade.
	Puis incrementGrade() améliore son grade : 150 -> 149. */

	std::cout << YELLOW << "TEST 2 : Constructeur de copie" << RESET << std::endl;

	try
	{
		Bureaucrat B(A);

		std::cout << B;

		B.incrementGrade();

		std::cout << B;
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;


	/* TEST 3 : Limite haute

	Bobby commence au grade 2.
	Premier increment : 2 -> 1
    Deuxième increment : impossible car 1 est déjà le meilleur grade. */

	std::cout << YELLOW << "TEST 3 : Limite haute" << RESET << std::endl;

	Bureaucrat B("Sophie", 2);
	Bureaucrat C(B);

	std::cout << C;

	try
	{
		C.incrementGrade();
		std::cout << C;

		C.incrementGrade();
		std::cout << C;
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// Le grade doit être a 1 après l'exception.
	std::cout << C;
	std::cout << std::endl;


	/* TEST 4 : Construction avec un grade trop élevé

	Le grade 0 est interdit.
	Le constructeur doit donc lancer une exception. */

	std::cout << YELLOW << "TEST 4 : Construction avec un grade trop élevé (0)" << RESET << std::endl;

	try
	{
		Bureaucrat D("Rodrigue", 0);
		std::cout << D;
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;


	/* TEST 5 : Construction avec un grade trop faible

	Le grade 151 est interdit. */

	std::cout << YELLOW << "TEST 5 : Construction avec un grade trop faible (151)" << RESET << std::endl;

	try
	{
		Bureaucrat E("Ambre", 151);
		std::cout << E;
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
