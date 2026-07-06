/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:35:36 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:35:41 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << std::endl << "AAnimal: " << "AANIMAL[" << this  << "] was created." << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
	std::cout << "AAnimal: " << "AANIMAL[" << this  << "] copy constructor called." << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal: " << "AANIMAL[" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
		this->_type = other._type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal: " << "AANIMAL[" << this  << "] was destroyed." << std::endl << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
