/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:56:12 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 09:31:07 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructeur par défaut
// Initialise la valeur fixe à 0
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

// Constructeur de copie
// Crée un nouvel objet à partir d'un autre objet Fixed
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;

	// Copie directement la valeur du nouvel objet
	*this = copy;
}

// Opérateur d'affectation
// Utilisé lorsqu'on fait : objet1 = objet2;
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// Vérifie que l'objet ne s'affecte pas lui-même
	if (this != &other)
	{
		// Copie la valeur de l'autre objet
		this->_fixed = other.getRawBits();
	}
	return (*this);
}

// Destructeur
// Appelé automatiquement lorsque l'objet est détruit
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Modifie directement la valeur
void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

// Retourne la valeur stockée dans l'objet
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}
