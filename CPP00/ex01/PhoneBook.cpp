/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:37:16 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/05 17:42:49 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructeur
PhoneBook::PhoneBook(void)
{
	this->_contactIndex = 0;
}

// Destructeur
PhoneBook::~PhoneBook(void)
{
}

// Tronque pour 10 caractères MAX
static std::string	charMax(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	return (str);
}

void	PhoneBook::addContact(void)
{
	Contact		newContact;
	std::string	input;

	while (true)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (newContact.setFirstname(input))
			break;
		std::cout << "Invalid first name." << std::endl;
	}

	while (true)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (newContact.setLastname(input))
			break;
		std::cout << "Invalid last name." << std::endl;
	}

	while (true)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (newContact.setNickname(input))
			break;
		std::cout << "Invalid nickname." << std::endl;
	}

	while (true)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (newContact.setNumber(input))
			break;
		std::cout << "Invalid phone number." << std::endl;
	}

	while (true)
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (newContact.setSecret(input))
			break;
		std::cout << "Secret cannot be empty." << std::endl;
	}

	this->_contacts[this->_contactIndex] = newContact;
	this->_contactIndex = (this->_contactIndex + 1) % 8;

	std::cout << "Contact saved." << std::endl;
}

void	PhoneBook::searchContact(void) const
{
	std::string	input;
	int			index;

	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10)
			<< charMax(this->_contacts[i].getFirstname());
		std::cout << "|" << std::setw(10)
			<< charMax(this->_contacts[i].getLastname());
		std::cout << "|" << std::setw(10)
			<< charMax(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}

	std::cout << "|----------|----------|----------|----------|" << std::endl;

	std::cout << "Enter index: ";
	std::getline(std::cin, input);

	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	index = input[0] - '0';

	if (this->_contacts[index].is_empty())
	{
		std::cout << "Empty contact." << std::endl;
		return ;
	}

	std::cout << "First name: "
		<< this->_contacts[index].getFirstname() << std::endl;
	std::cout << "Last name: "
		<< this->_contacts[index].getLastname() << std::endl;
	std::cout << "Nickname: "
		<< this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: "
		<< this->_contacts[index].getNumber() << std::endl;
	std::cout << "Darkest secret: "
		<< this->_contacts[index].getSecret() << std::endl;
}
