/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:35:48 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 12:21:28 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		// Constructeur par défaut
		Zombie(void);
		// Destructeur
		~Zombie(void);
		// Annoncement
		void	announce(void);
		// Nommer après la création
		void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
