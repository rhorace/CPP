/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:28:57 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 17:35:28 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();

	std::cout << "Cat: " << "CAT[" << this  << "] was created." << std::endl;
}

// Copy constructor (deep copy)
Cat::Cat(const Cat &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);

	std::cout << "Cat: " << "CAT" << this  << "] copy constructor called." << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat: " << "CAT" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;

	std::cout << "Cat: " << "CAT[" << this  << "] was destroyed." << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Miaou miaou" << std::endl;
}
