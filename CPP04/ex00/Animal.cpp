/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:30:49 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 14:26:17 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal: " << "ANIMAL[" << this  << "] was created." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal: " << "ANIMAL[" << this  << "] copy constructor called." << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal: " << "ANIMAL[" << this << "] Assignment operator called." << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal: " << "ANIMAL[" << this  << "] was destroyed." << std::endl << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << RED << "Animal: Gurlf !" << RESET << std::endl;
}