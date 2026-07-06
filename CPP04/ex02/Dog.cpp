/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:37:14 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:37:18 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();

	std::cout << "Dog: " << "DOG[" << this  << "] was created." << std::endl;
}

// Copy constructor (deep copy)
Dog::Dog(const Dog &other) : AAnimal(other)
{
	this->_brain = new Brain(*other._brain);

	std::cout << "Dog: " << "DOG[" << this  << "] copy constructor called." << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog: " << "DOG[" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
	{
		AAnimal::operator=(other);
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
