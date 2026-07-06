/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:30:45 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:30:49 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/* Créer un zombie avec new, donc sur la heap.
Il continue d’exister après la fin de newZombie() */
Zombie	*newZombie(std::string name) {
	Zombie	*newZ = new Zombie(name);
	return newZ;
}

