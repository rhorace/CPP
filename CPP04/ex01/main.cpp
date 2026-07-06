/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:29:35 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 14:46:40 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const int	size = 6;
	Animal		*animals[size];

	std::cout << YELLOW << "--- Création d'animaux ---" << RESET;

	// Première moitié : Chiens
	// Seconde moitié : Chats
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << YELLOW << "\n--- Test de sons ---" << RESET << std::endl;

	// Test de polymorphisme :
	// Animal appelle le makeSound() de Dog/Cat.
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	std::cout << YELLOW << "\n--- Test de copie profonde ---" << RESET;

	std::cout << std::endl << GREEN << "Scoubidou" << RESET;
	// Créer un Dog et stocker une idea dans son Brain.
	Dog	scoubidou;
	
	scoubidou.getBrain()->setIdea(0, "Il fait chaud aujourd'hui.");

	{
		std::cout << std::endl << GREEN << "Snoopy" << RESET << std::endl;
		Dog	snoopy = scoubidou;
		
		std::cout << std::endl << "Pensée de Scoubidou : " << scoubidou.getBrain()->getIdea(0) << std::endl;
		std::cout << "Pensée de Snoopy    : " << snoopy.getBrain()->getIdea(0) << std::endl;

		snoopy.getBrain()->setIdea(0, "Je vais me mettre à l'ombre.");

		std::cout << YELLOW << "\nAprès avoir changé la pensée de Snoopy :" << RESET << std::endl;
		std::cout << "Pensée de Scoubidou : " << scoubidou.getBrain()->getIdea(0) << std::endl;
		std::cout << "Pensée de Snoopy    : " << snoopy.getBrain()->getIdea(0) << std::endl << std::endl;

		std::cout << RED << "Snoopy" << RESET << std::endl;
	} // Snoopy est detruit après cette accolade fermante

	// Si la copie était superficielle, Scoubidou aurait pu en être affecté.
	std::cout << YELLOW << "Snoopy a été détruit, mais Scoubidou existe toujours." << RESET << std::endl;
	std::cout << "Pensée de Scoubidou après la destruction de Snoopy : " << scoubidou.getBrain()->getIdea(0) << std::endl;

	std::cout << YELLOW << "\n--- Suppression d'animaux ---" << RESET << std::endl;

	// Comme le destructeur de la classe Animal est virtuel,
	// les destructeurs des classes Dog et Cat sont appelés correctement.
	for (int i = 0; i < size; i++)
		delete animals[i];

	return (0);
}
