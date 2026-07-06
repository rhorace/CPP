/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:43:07 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 12:22:56 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon(void);
		
		// Définir le type d'arme
		void	setType(const std::string &newType);

		// Donner le type d'arme
		const std::string	&getType(void) const;
};

#endif
