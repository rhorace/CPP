/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:32:14 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/18 16:43:58 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructeur
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;

	std::cout << "ScavTrap: " << this->_name << "[" << this  << "] was created." << std::endl;
}

// Constructeur de copie
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap: " << this->_name << "[" << this  << "] copy constructor called." << std::endl;
}

// Opérateur d'assignation
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap: " << this->_name << "[" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);

	return (*this);
}

// Destructeur
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: " << this->_name << "[" << this  << "] was destroyed." << std::endl;
}

// Attaque
void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit > 0 && this->_energy > 0)
	{
		this->_energy--;
		
		std::cout << GREEN << "ScavTrap: " << this->_name << "[" << this << "] attacked " << target << " and inflicted " << this->_damage << " points of damage." << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "ScavTrap: " << this->_name << "[" << this << "] cannot attack; he does not have enough energy or hit points." << RESET << std::endl;
	}
}

// Mode Gate keeper
void	ScavTrap::guardGate(void)
{
	std::cout << BLUE << "ScavTrap: " << this->_name << "[" << this << "] is now in Gate keeper mode." << RESET << std::endl;
}
