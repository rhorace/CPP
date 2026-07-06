/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:40:29 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:36:03 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructeur : On initialise les 4 emplacements à NULL.
Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character: " << name << " [" << this << "] was created." << std::endl;

	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

// Constructeur de copie : on clone chaque Materia.
Character::Character(const Character &copy) : _name(copy._name)
{
	std::cout << "Character: Constructeur de copie" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

/*
	Opérateur d'affectation.

	On supprime d'abord les anciennes Materias,
	puis on clone celles de other.
*/
Character &Character::operator=(const Character &other)
{
	std::cout << "Character: Opérateur d'affectation" << std::endl;

	if (this != &other)
	{
		_name = other._name;

		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];

			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

// 	Destructeur : On libère les Materias encore présentes dans l'inventaire.
Character::~Character()
{
	std::cout << "Character: " << "[" << this << "] was destroyed." << std::endl;

	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

// Getter
std::string const &Character::getName() const
{
	return (_name);
}

/*
	Ajoute une Materia dans le premier emplacement libre.
	Si l'inventaire est plein, on ignore simplement la Materia.
*/
void Character::equip(AMateria *m)
{
	if (!m)
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "Character: Matéria [" << m << "] ajoutée dans le slot " << i << std::endl;
			return ;
		}
	}
}

// Retire une Materia de l'inventaire. On ne delete PAS la Materia.
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;

	_inventory[idx] = NULL;
}

// 	Utilise la Materia située à l'indice idx.
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;

	if (_inventory[idx])
		_inventory[idx]->use(target);
}
