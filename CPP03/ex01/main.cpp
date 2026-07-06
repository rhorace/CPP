/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:31:15 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/17 17:10:27 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << YELLOW << "--- Créer des robots ---" << RESET << std::endl;
	ScavTrap	robot1("ROBOT_1");
	std::cout << std::endl;

	std::cout << YELLOW << "--- Tests des valeurs initiales ---" << RESET << std::endl;
	std::cout << "Health Point: " << robot1.getHitPoints() << std::endl;
	std::cout << "Energy      : " << robot1.getEnergyPoints() << std::endl;
	std::cout << "Damage      : " << robot1.getAttackDamage() << std::endl;

	std::cout << YELLOW << "\n--- Test des actions de base ---" << RESET << std::endl;
	robot1.attack("MICKEY");
	robot1.takeDamage(6);
	robot1.beRepaired(4);
	robot1.guardGate();

	std::cout << YELLOW << "\n--- Test lorsqu'il n'a plus de points de vie ---" << RESET << std::endl;
	robot1.takeDamage(100);
	robot1.attack("DONALD");
	robot1.beRepaired(10);

	std::cout << YELLOW << "\n--- Test du constructeur de copie et de l'assignation ---" << RESET << std::endl;
	ScavTrap	robot2("ROBOT_2");
	robot2.attack("DAISY");

	ScavTrap	robot1_copy(robot1);
	robot1_copy.attack("DINGO");

	ScavTrap	robot1_assign("ROBOT_3");
	robot1_assign = robot1;
	robot1_assign.attack("ALADDIN");

	std::cout << "\n--- Fin du programme ---" << RESET << std::endl;
	return (0);
}
