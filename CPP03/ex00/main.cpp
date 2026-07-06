/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:52:14 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/17 15:35:32 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << YELLOW << "--- Création d'un premier ClapTrap ---" << RESET << std::endl;

	// Appelle le constructeur avec nom
	ClapTrap	robot1("ROBOT_1");

	std::cout << YELLOW << "\n--- Test des fonctions de base ---" << RESET << std::endl;

	// Attaque une cible
	robot1.attack("GRINCHEUX");

	// Perd 5 points de vie
	robot1.takeDamage(5);

	// Récupère 3 points de vie
	robot1.beRepaired(3);

	// Perd encore 3 points de vie
	robot1.takeDamage(3);

	std::cout << YELLOW << "\n--- Test lorsqu'il n'a plus de points de vie ---" << RESET << std::endl;

	// Les points de vie tombent à 0
	robot1.takeDamage(10);

	// Ces actions doivent échouer
	robot1.attack("SIMPLET");
	robot1.beRepaired(10);

	std::cout << YELLOW << "\n--- Test du constructeur de copie et de l'assignation ---" << RESET << std::endl;

	// Création d'un deuxième ClapTrap
	ClapTrap	robot2("ROBOT_2");

	robot2.attack("ATCHOUM");

	// Appel du constructeur de copie
	ClapTrap	robot2_copy(robot2);

	robot2_copy.attack("TIMIDE");

	// Création d'un troisième objet
	ClapTrap	robot2_assign("ROBOT_3");

	// Appel de l'opérateur d'assignation
	robot2_assign = robot2;

	robot2_assign.attack("DORMEUR");

	std::cout << YELLOW << "\n--- Fin du programme ---" << RESET << std::endl;

	return (0);
}
