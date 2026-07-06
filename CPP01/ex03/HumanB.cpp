/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:41:34 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:41:38 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	// _weapon(NULL) --> "pas d'arme"
}

HumanB::~HumanB(void) {
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const {
	if (this->_weapon) {
		std::cout << this->_name << " attaque avec : " << this->_weapon->getType() << std::endl;
	}
	else {
		std::cout << this->_name << " attaque à mains nues" << std::endl;
	}
}

