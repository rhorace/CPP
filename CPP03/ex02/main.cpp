/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:44:09 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:44:12 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << YELLOW << "--- Créer des robots ---" << RESET << std::endl;

	ScavTrap	robot1("SCAVTRAP_1");
	FragTrap	robot2("FRAGTRAP_1");
	std::cout << std::endl;

	std::cout << YELLOW << "--- Tests des valeurs initiales ---" << RESET << std::endl;

	// FragTrap doit avoir 100 points de vie
	std::cout << "[FRAGTRAP_1] Initial HP    : " << robot2.getHitPoints() << std::endl;

	// FragTrap doit avoir 100 points d'énergie
	std::cout << "[FRAGTRAP_1] Initial Energy: " << robot2.getEnergyPoints() << std::endl;

	// FragTrap doit avoir 30 points de dégâts
	std::cout << "[FRAGTRAP_1] Initial Damage: " << robot2.getAttackDamage() << std::endl;

	std::cout << YELLOW << "\n--- Test des actions de base ---" << RESET << std::endl;	
	robot2.attack("MICKEY");	// FragTrap attaque une cible	
	robot2.takeDamage(6);		// FragTrap subit des dégâts	
	robot2.beRepaired(4);		// FragTrap se répare	
	robot2.highFivesGuys();	// Fonction spéciale de FragTrap

	std::cout << YELLOW << "\n--- Test lorsqu'il n'a plus de points de vie ---" << RESET << std::endl;

	std::cout << "✅ FragTrap health points before damage: " << robot2.getHitPoints() << std::endl;

	// On inflige assez de dégâts pour mettre les HP à 0
	robot2.takeDamage(100);

	std::cout << "❌ FragTrap health points after damage: " << robot2.getHitPoints() << std::endl;

	// Ces actions doivent échouer si FragTrap est mort
	robot2.attack("DONALD");
	robot2.beRepaired(10);

	std::cout << YELLOW << "\n--- Test du constructeur de copie et de l'assignation ---" << RESET << std::endl;
	
	// Création d'un FragTrap normal
	FragTrap	robot3("FRAGTRAP_2");
	robot3.attack("DAISY");

	std::cout << YELLOW << "\n--- Test du constructeur de copie ---" << RESET << std::endl;
	FragTrap	robot3_copy(robot3);
	robot3_copy.attack("DINGO");

	std::cout << YELLOW << "\n--- Test de l'opérateur d'assignation ---" << RESET << std::endl;
	FragTrap	robot3_assign("FRAGTRAP_3");
	robot3_assign = robot3;
	robot3_assign.attack("ALADDIN");

	std::cout << YELLOW << "\n--- Fin du programme ---" << RESET << std::endl;
	return (0);
}
