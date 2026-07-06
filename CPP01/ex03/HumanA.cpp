/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:40:20 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:40:23 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	// La liste d'initialisation est utilisée ici !
}

HumanA::~HumanA(void) {
}

void	HumanA::attack(void) const {
	std::cout << this->_name << " attaque avec : " << this->_weapon.getType() << std::endl;
}

