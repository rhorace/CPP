/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:59:18 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 09:43:02 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)
{
}

Fixed::Fixed(const int n)
{
	// Un entier est converti en valeur fixe en le décalant de 8 bits.
	this->_fixed = n << _bits;
}

Fixed::Fixed(const float f)
{
	// On multiplie par 256, puis on arrondit pour garder la précision.
	this->_fixed = roundf(f * (1 << _bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed(void)
{
}

// SETTERS & GETTERS
Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_fixed = other._fixed;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

// FUNCTIONS
int	Fixed::toInt(void) const
{
	// On retire la partie décimale en redécalant vers la droite.
	return (this->_fixed >> _bits);
}

float	Fixed::toFloat(void) const
{
	// On divise par 256 pour retrouver la valeur flottante.
	return ((float)this->_fixed / (1 << _bits));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}

/*                         OPÉRATEURS DE COMPARAISON                          */

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_fixed > other._fixed);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_fixed < other._fixed);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixed >= other._fixed);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixed <= other._fixed);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_fixed == other._fixed);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixed != other._fixed);
}

/*                         OPÉRATEURS ARITHMÉTIQUES                           */

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	// Sécurité pour éviter une division par zéro.
	if (other._fixed == 0)
		return (Fixed(0));
	return (Fixed(this->toFloat() / other.toFloat()));
}

/*                    INCRÉMENTATION / DÉCRÉMENTATION                         */

Fixed	&Fixed::operator++(void)
{
	// Pré-incrémentation : on modifie l'objet puis on le retourne.
	this->_fixed++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	// Post-incrémentation : on sauvegarde l'ancien état.
	Fixed	tmp(*this);

	this->_fixed++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_fixed--;
	return (tmp);
}

/*                                MIN / MAX                                    */

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
