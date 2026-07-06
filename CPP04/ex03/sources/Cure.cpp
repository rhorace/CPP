/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:40:43 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:36:34 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructeur par défaut.
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure     : Matéria [" << this << "] was created." << std::endl;
}

// 	Constructeur de copie.
Cure::Cure(const Cure &copy) : AMateria(copy)
{
	std::cout << "Cure     : Matéria [" << this << "] Constructeur de copie" << std::endl;
}

// Opérateur d'affectation.
Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure     : Opérateur d'affectation" << std::endl;

	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

// 	Destructeur.
Cure::~Cure()
{
	std::cout << "Cure     : Matéria [" << this << "] was destroyed." << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << "Cure     : Matéria [" << this << "] was cloned." << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "\033[33m" << "* heals " << target.getName() << "'s wounds *" << "\033[0m" << std::endl;
}
