/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:41:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:41:41 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
	Constructeur.

	On initialise les 4 cases à NULL.
*/
MateriaSource::MateriaSource()
{
	std::cout << RED << "MateriaSource : MATERIA SOURCE [" << this << "] WAS CREATED." << RESET << std::endl << std::endl;

	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

// Constructeur de copie.
MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << BLUE << "MateriaSource : Constructeur de copie" << RESET << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (copy._templates[i])
			_templates[i] = copy._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

/*
	Opérateur d'affectation.

	On supprime d'abord les anciennes Materias,
	puis on clone celles de other.
*/
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << BLUE << "MateriaSource : Opérateur d'affectation" << RESET << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];

			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}
	return (*this);
}

/*
	Destructeur.

	On libère les Materias apprises.
*/
MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource : MATERIA SOURCE [" << this << "] WAS DESTROY." << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

// Fonctions membres
void MateriaSource::learnMateria(AMateria *m)
{
	std::cout << BLUE << "MateriaSource : Learn [" << m << "]" << RESET << std::endl << std::endl;

	if (!m)
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m;
			return ;
		}
	}
}

/*
	Recherche une Materia du type demandé.

	Si elle existe :
		on renvoie une copie grâce à clone()

	Sinon :
		on renvoie NULL.
*/
AMateria *MateriaSource::createMateria(std::string const &type)
{
	std::cout << std::endl << BLUE << "MateriaSource : Create : " << type << RESET << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (_templates[i]
			&& _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	return (NULL);
}
