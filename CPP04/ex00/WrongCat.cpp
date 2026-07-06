/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:32:24 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:32:27 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout << "WrongCat: " << "WRONG_CAT[" << this  << "] was created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "ClapTrap: " << "WRONG_CAT[" << this  << "] copy constructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat: " << "WRONG_CAT[" << this << "] Assignment operator called." << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: " << "WRONG_CAT[" << this  << "] was destroyed." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong miaou" << std::endl;
}
