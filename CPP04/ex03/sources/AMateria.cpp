/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:40:17 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:34:51 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

/*
	Constructeur avec type.

	Exemples :
	- Ice appelle AMateria("ice")
	- Cure appelle AMateria("cure")
*/
AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria : Matéria " << type << "[" << this  << "] was created." << std::endl;
}

// Constructeur de copie. On copie simplement le type de la Materia.
AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	std::cout << "AMateria : Matéria [" << this << "] copy constructor called." << std::endl;
}

// Opérateur d'affectation.
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "Opérateur d'affectation." << std::endl;

	if (this != &other)
		this->_type = other._type;
	return (*this);
}

// Destructeur
AMateria::~AMateria()
{
	std::cout << "AMateria : Matéria [" << this << "] was destroyed." << std::endl;
}

// 	Retourne le type de la Materia.
std::string const	&AMateria::getType() const
{
	return (this->_type);
}

/*
	Fonction use par défaut.

	Ne fait rien.
	Les classes filles Ice et Cure vont gerer cette fonction.
*/
void	AMateria::use(ICharacter &target)
{
	(void)target;
}
