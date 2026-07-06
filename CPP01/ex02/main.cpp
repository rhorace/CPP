/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:39:32 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:39:42 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	// La variable str
	std::string	str = "HI THIS IS BRAIN";

	// stringPTR contient l’adresse de str.
	std::string	*stringPTR = &str;

	// stringREF fait référence à str.
	std::string	&stringREF = str;

	std::cout << "Adresse mémoire de la variable str    : " << &str << std::endl;
	std::cout << "Adresse mémoire détenue par stringPTR : " << stringPTR << std::endl;
	std::cout << "Adresse mémoire détenue par stringREF : " << &stringREF << std::endl;
	/* Ces trois affichages donnent la même adresse */


	std::cout << "Valeur de la variable str    : " << str << std::endl;
	std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur pointée par stringREF : " << stringREF << std::endl;
	/* Ces trois affichages donnent la même valeur */
}

