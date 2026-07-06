/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:41:55 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 12:22:34 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		// Le constructeur ne reçoit que le nom
		HumanB(std::string name);
		~HumanB(void);

		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif
