/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:36:35 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:36:39 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain: " << "Brain[" << this  << "] was created." << std::endl;

	// Initialiser toutes les pensées
	for (int i = 0; i < 100; i++)
		_ideas[i] = "Default idea";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain: " << "Brain[" << this  << "] copy constructor called." << std::endl;

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain: " << "Brain[" << this << "] Assignment operator called." << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}

	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain: " << "Brain[" << this  << "] was destroyed." << std::endl;
}

// Renvoie l'idée de l'index donné.
std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (_ideas[index]);

	return ("");
}

// Enregistre une nouvelle idée à l'index donné.
void	Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}
