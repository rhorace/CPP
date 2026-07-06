/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:57:21 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 09:34:37 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Création d'un objet avec le constructeur par défaut
	Fixed	a;

	// Création d'un nouvel objet en copiant a
	Fixed	b(a);

	// Création d'un troisième objet
	Fixed	c;

	// Affectation de b dans c
	c = b;

	// Affichage des valeurs des trois objets
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
