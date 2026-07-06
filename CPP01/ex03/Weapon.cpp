/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:42:56 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:42:59 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	// Liste d'initialisation
}

Weapon::~Weapon(void) {
}

void	Weapon::setType(const std::string &newType) {
	this->_type = newType;
}

const std::string	&Weapon::getType(void) const {
	return this->_type;
}
