/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:29:18 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 17:38:00 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();

	std::cout << "Dog: " << "DOG[" << this  << "] was created." << std::endl;
}

// Copy constructor (deep copy)
Dog::Dog(const Dog &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);

	std::cout << "Dog: " << "DOG[" << this  << "] copy constructor called." << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog: " << "DOG[" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;

	std::cout << "Dog: " << "DOG[" << this  << "] was destroyed." << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Ouaf ouaf" << std::endl;
}
