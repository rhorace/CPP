/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:27:45 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/20 11:27:48 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// Sophie possède le grade 20.
	Bureaucrat A("Sophie", 20);

	/* Blue nécessite le grade 30 pour être signé.
	   Sophie pourra donc le signer car 20 est meilleur que 30. */
	Form form1("Blue", 30, 40);

	/* Red nécessite le grade 10 pour être signé.
	   Sophie ne pourra pas le signer car son grade est seulement 20. */
	Form form2("Red", 10, 15);

	std::cout << form1;
	std::cout << form2;
	std::cout << std::endl;

	std::cout << A;
	std::cout << std::endl;

	// Sophie essaie de signer les deux formulaires.
	A.signForm(form1);
	A.signForm(form2);

	std::cout << std::endl;

	// Ambre possède un excellent grade : 2.
	Bureaucrat B("Ambre", 2);

	std::cout << B;
	std::cout << std::endl;

	// Ambre possède un grade suffisant pour les deux formulaires.
	B.signForm(form1);
	B.signForm(form2);

	std::cout << std::endl;

	// On affiche l'état final des formulaires.
	std::cout << form1;
	std::cout << form2;

	return (0);
}
