/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:43:04 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:43:07 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructeur avec nom
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	// FragTrap possède des valeurs différentes de ClapTrap
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;

	std::cout << "FragTrap: " << this->_name << "[" << this  << "] was created." << std::endl;
}

// Constructeur de copie
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap: " << this->_name << "[" << this  << "] copy constructor called." << std::endl;
}

// Opérateur d'assignation
FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap: " << this->_name << "[" << this << "] Assignment operator called." << std::endl;

	// Protection contre l'auto-assignation
	if (this != &other)
	{
		// On réutilise l'opérateur d'assignation de ClapTrap
		ClapTrap::operator=(other);
	}
	return (*this);
}

// Destructeur
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: " << this->_name << "[" << this  << "] was destroyed." << std::endl;
}

/* ------------------------------- FUNCTIONS -------------------------------- */

// FragTrap possède son propre message d'attaque
void	FragTrap::attack(const std::string &target)
{
	// Un robot mort ou sans énergie ne peut pas attaquer
	if (this->_hit > 0 && this->_energy > 0)
	{
		this->_energy--;
		std::cout << GREEN << "FragTrap: YES " << this->_name << "[" << this << "] was able to launch an attack against " << target << " and inflicted " << this->_damage << " points of damage." << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "FragTrap: WTF " << this->_name << "[" << this << "] can no longer attack." << RESET << std::endl;
	}
}

// Fonction spéciale de FragTrap
void	FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << "FragTrap: " << this->_name << "[" << this << "] said: 'High five, guys! Anyone?'" << RESET << std::endl;
}
