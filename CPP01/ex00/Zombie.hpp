/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:31:33 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 12:20:44 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif

