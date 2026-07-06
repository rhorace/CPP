/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:36:55 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:36:59 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();

	std::cout << "Cat: " << "CAT[" << this  << "] was created." << std::endl;
}

// Copy constructor (deep copy)
Cat::Cat(const Cat &other) : AAnimal(other)
{
	this->_brain = new Brain(*other._brain);

	std::cout << "Cat: " << "CAT" << this  << "] copy constructor called." << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat: " << "CAT" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
	{
		AAnimal::operator=(other);
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
