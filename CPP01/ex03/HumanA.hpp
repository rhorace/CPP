/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:41:45 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 12:22:04 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		// Le constructeur reçoit le nom et une référence vers l'arme
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);

		void	attack(void) const;
};

#endif
