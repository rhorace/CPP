/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:46:06 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:46:11 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << YELLOW << "--- Tests de construction ---" << RESET << std::endl;
	DiamondTrap robot1("ROBOT_1");
	
	std::cout << YELLOW << "\n--- Statistiques de test ---" << RESET << std::endl;

	// DiamondTrap doit avoir :
	// HP     : 100 -> valeur de FragTrap
	// Energy : 50  -> valeur de ScavTrap
	// Damage : 30  -> valeur de FragTrap
	std::cout << "HP: " << robot1.getHitPoints() << std::endl;
	std::cout << "Energy: " << robot1.getEnergyPoints() << std::endl;
	std::cout << "Damage: " << robot1.getAttackDamage() << std::endl;
	
	std::cout << YELLOW << "\n--- Fonctions de test ---" << RESET << std::endl;

	// DiamondTrap utilise l'attaque de ScavTrap
	robot1.attack("MICKEY");

	// Fonctions héritées de ClapTrap
	robot1.beRepaired(10);
	robot1.takeDamage(20);
	std::cout << std::endl;

	// Affiche le nom DiamondTrap + le nom ClapTrap
	robot1.whoAmI();
	
	// Fonctions héritées de ScavTrap et FragTrap
	robot1.guardGate();
	robot1.highFivesGuys();
	
	std::cout << YELLOW << "\n--- Test de destruction ---" << RESET << std::endl;

	return (0);
}
