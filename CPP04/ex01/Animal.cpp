/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:28:13 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 17:59:05 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << std::endl << "Animal: " << "ANIMAL[" << this  << "] was created." << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Animal: " << "ANIMAL[" << this  << "] copy constructor called." << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
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
	std::cout << "Animal: Animal generic sound" << std::endl;
}
