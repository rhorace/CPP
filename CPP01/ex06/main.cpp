/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:45:58 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 12:24:35 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	std::string	levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	Harl		harl;
	std::string	lvl = av[1];
	int			lvlIdx = -1;

	for (int i = 0; i < 4; i++) {
		if (lvl == levels[i]) {
			lvlIdx = i;
			break;
		}
	}
	switch (lvlIdx)
	{
	case 0:
		harl.complain("DEBUG");
		 // fall through
	case 1:
		harl.complain("INFO");
		 // fall through
	case 2:
		harl.complain("WARNING");
		 // fall through
	case 3:
		harl.complain("ERROR");
		break;
	default: // S'exécute si lvlIdx est resté à -1
		std::cout << "[ Le niveau demandé est inconnu ! ]"
					<< std::endl;
		break;
	}
	return 0;
}

