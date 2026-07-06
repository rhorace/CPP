/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:56:34 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/16 09:33:22 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int					_fixed;     // Valeur stockée en virgule fixe
		static const int	_bits = 8;  // Nombre de bits réservés à la partie fractionnaire

	public:
		// Constructeur par défaut
		Fixed(void);

		// Constructeur de copie
		Fixed(const Fixed &copy);

		// Destructeur
		~Fixed(void);

		/* Opérateur d'affectation
		Utilisé lorsqu'on copie un objet dans un autre objet déjà existant */
		Fixed	&operator=(const Fixed &other);

		// Retourne la valeur brute stockée dans _fixed
		int		getRawBits(void) const;

		// Modifie directement la valeur brute
		void	setRawBits(int const raw);
};

#endif
