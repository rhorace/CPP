/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:31:04 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:31:10 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/* Le zombie est créé sur la stack. Il est détruit
automatiquement à la fin de la fonction randomChump(). */
void	randomChump(std::string name) {
	Zombie	myZombie(name);
	myZombie.announce();
}

