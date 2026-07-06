/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:31:28 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:31:31 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "Dog: " << "DOG[" << this  << "] was created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog: " << "DOG[" << this  << "] copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog: " << "DOG[" << this << "] Assignment operator called." << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog: " << "DOG[" << this  << "] was destroyed." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Ouaf ouaf" << std::endl;
}
