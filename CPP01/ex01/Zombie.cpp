/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:35:37 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:35:41 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructeur par défaut
Zombie::Zombie(void) {
	// vide parce que les zombies sont d'abord créés sans nom
}

Zombie::~Zombie(void) {
	std::cout << _name << " est détruit !" << std::endl;
}

// Setter pour nommer les zombies
void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
