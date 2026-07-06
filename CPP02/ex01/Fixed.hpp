/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:58:26 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 09:40:14 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
	private:
		int					_fixed;      // Valeur stockée en virgule fixe
		static const int	_bits = 8;   // Nombre de bits réservés à la partie fractionnaire

	public:
		// Constructeurs
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &copy);

		// Destructeur
		~Fixed(void);

		/* Opérateur d'affectation
		Utilisé lorsqu'on copie un objet dans un autre objet déjà existant */
		Fixed	&operator=(const Fixed &other);

		// Accesseurs à la valeur
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Conversions vers les types classiques
		int		toInt(void) const;
		float	toFloat(void) const;
};

// Surcharge de l'opérateur << pour afficher un Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
