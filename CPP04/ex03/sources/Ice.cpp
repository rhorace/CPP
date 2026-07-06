/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:40:54 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:36:43 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructeur par défaut.
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice      : Matéria [" << this << "] was created." << std::endl;
}

// 	Constructeur de copie.
Ice::Ice(const Ice &copy) : AMateria(copy)
{
	std::cout << "Ice      : Matéria [" << this << "] Constructeur de copie" << std::endl;
}

// Opérateur d'affectation.
Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice     : Opérateur d'affectation" << std::endl;

	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

// 	Destructeur.
Ice::~Ice()
{
	std::cout << "Ice      : Matéria [" << this << "] was destroyed." << std::endl;
}

AMateria *Ice::clone() const
{
	std::cout << "Ice      : Matéria [" << this << "] was cloned." << std::endl;
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "\033[33m" << "* shoots an ice bolt at " << target.getName() << " *" << "\033[0m" << std::endl;
}
