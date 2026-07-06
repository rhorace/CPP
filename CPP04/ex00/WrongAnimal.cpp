/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:32:00 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 14:25:37 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal: " << "WRONG_ANIMAL[" << this  << "] was created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal: " << "WRONG_ANIMAL[" << this  << "] copy constructor called." << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal: " << "WRONG_ANIMAL[" << this << "] Assignment operator called." << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "WrongAnimal: " << "WRONG_ANIMAL[" << this  << "] was destroyed." << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << RED << "WrongAnimal: Gurlf !" << RESET << std::endl;
}
