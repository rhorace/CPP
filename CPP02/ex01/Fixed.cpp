/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:58:13 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 09:38:35 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*                               CONSTRUCTEURS                                */

// Initialise la valeur fixe à 0
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
}

// Convertit un entier en représentation fixe
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = n << _bits;
}

// Convertit un float en représentation fixe
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(f * 256);
	//this->_fixed = roundf(f * (1 << _bits));
}

// Construit un nouvel objet à partir d'un autre
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed = copy._fixed;
}

// Destruction de l'objet
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*                            SETTERS & GETTERS                               */

// Copie le contenu d'un objet déjà existant dans l'objet courant
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// Évite l'auto-affectation : a = a;
	if (this != &other)
		this->_fixed = other.getRawBits();

	return (*this);
}

// Modifie directement la valeur
void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

// Retourne la valeur stockée
int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

/*                               CONVERSIONS                                  */

// Convertit la représentation fixe en entier
int Fixed::toInt(void) const
{
	return (this->_fixed >> _bits);
}

// Convertit la représentation fixe en float
float Fixed::toFloat(void) const
{
	return (this->_fixed / 256.0f);
	//return this->_fixed / (float)(1 << _bits);
}

/*                          OPÉRATEUR D'AFFICHAGE                             */

/* Permet d'écrire directement :
   		std::cout << fixed << std::endl;
   L'objet est converti en float avant affichage. */
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
