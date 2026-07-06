/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:31:05 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:31:08 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "Cat: " << "CAT[" << this  << "] was created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat: " << "CAT" << this  << "] copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: " << "CAT" << this << "] Assignment operator called." << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat: " << "CAT[" << this  << "] was destroyed." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Miaou miaou" << std::endl;
}
