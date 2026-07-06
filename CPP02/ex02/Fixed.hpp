/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:59:27 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 09:43:16 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		int					_fixed;
		static const int	_bits = 8;

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &copy);
		~Fixed(void);

		Fixed	&operator=(const Fixed &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		// Opérateurs de comparaison
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// Opérateurs arithmétiques
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// Pré-incrémentation / décrémentation
		Fixed	&operator++(void);
		Fixed	&operator--(void);

		// Post-incrémentation / décrémentation
		Fixed	operator++(int);
		Fixed	operator--(int);

		// Fonctions min / max
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &value);

#endif
