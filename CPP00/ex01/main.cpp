/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:33:58 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/05 17:41:55 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	Agenda;
	std::string	command;

	std::cout << "Here is your telephone directory" << std::endl;

	while (true)
	{
		std::cout << "Enter your choice (ADD, SEARCH or EXIT): ";

		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
			Agenda.addContact();
		else if (command == "SEARCH")
			Agenda.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command." << std::endl;
	}

	return (0);
}
