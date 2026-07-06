/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:44:50 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:44:54 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ------------------------- ORTHODOX CANONICAL FORM ------------------------ */

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	// DiamondTrap prend :
	// - les HP de FragTrap
	// - l'énergie de ScavTrap
	// - les dégâts de FragTrap
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 30;

	std::cout << "DiamTrap: " << this->_name << "[" << this << "] was created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap: " << this->_name << "[" << this  << "] copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap: " << this->_name << "[" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
	{
		// Copie la partie ClapTrap
		ClapTrap::operator=(other);

		// Copie le nom propre à DiamondTrap
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap: " << this->_name << "[" << this  << "] was destroyed." << std::endl;
}

/* ------------------------------- FUNCTIONS -------------------------------- */

void	DiamondTrap::attack(const std::string &target)
{
	// DiamondTrap doit utiliser l'attaque de ScavTrap
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << BLUE << "My username on DiamondTrap is " << this->_name << " and my username on ClapTrap is " << ClapTrap::_name << RESET << std::endl;
}
