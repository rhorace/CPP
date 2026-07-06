/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:49:54 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/18 16:37:01 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructeur par défaut
ClapTrap::ClapTrap(void) : _name("default"), _hit(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap: " << this->_name << "[" << this  << "] was created." << std::endl;
}

// Constructeur avec nom
ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap: " << this->_name << "[" << this  << "] was created." << std::endl;
}

// Constructeur de copie
ClapTrap::ClapTrap(const ClapTrap &copy) : 	_name(copy._name), _hit(copy._hit), _energy(copy._energy), _damage(copy._damage)
{
	std::cout << "ClapTrap: " << this->_name << "[" << this  << "] copy constructor called." << std::endl;
}

// Opérateur d'assignation
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap: " << this->_name << "[" << this << "] Assignment operator called." << std::endl;

	// Protection contre l'auto-assignation
	if (this != &other)
	{
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}

	return (*this);
}

// Destructeur
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: " << this->_name << "[" << this  << "] was destroyed." << std::endl;
}

/*                              MEMBER FUNCTIONS                              */

// Attaque une cible si le ClapTrap est encore vivant et possède de l'énergie.
void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit > 0 && this->_energy > 0)
	{
		this->_energy--;

		std::cout << GREEN << "ClapTrap: " << this->_name << "[" << this << "] attacked " << target << " and inflicted " << this->_damage << " points of damage." << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "ClapTrap: " << this->_name << "[" << this << "] cannot attack " << target << " ; he does not have enough energy or hit points." << RESET << std::endl;
	}
}

// Fait perdre des points de vie au ClapTrap.
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit > amount)
		this->_hit -= amount;
	else
		this->_hit = 0;

	std::cout << "ClapTrap: " << this->_name << "[" << this << "] sustained " << amount << " points of damage." << std::endl;
}

// Répare le ClapTrap si celui-ci est vivant et possède encore de l'énergie.
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit > 0 && this->_energy > 0)
	{
		this->_energy--;
		this->_hit += amount;

		std::cout << GREEN << "ClapTrap: " << this->_name << "[" << this << "] repaired itself and recovered " << amount << " health points." << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "ClapTrap: " << this->_name << "[" << this << "] cannot repair himself; he does not have enough energy or hit points." << RESET << std::endl;
	}
}
