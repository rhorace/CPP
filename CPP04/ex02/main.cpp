/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:37:37 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:37:40 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	const int	size = 4;
	AAnimal		*animals[size];

	// AAnimal animal;
	// Impossible car AAnimal est abstraite. 	

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

	scoubidou.getBrain()->setIdea(0, "Je crois que je vais aller taquiner un chat.");

	{
		std::cout << std::endl << GREEN << "Snoopy" << RESET << std::endl;
		Dog	snoopy = scoubidou;

		std::cout << std::endl << "Pensée de Scoubidou : " << scoubidou.getBrain()->getIdea(0) << std::endl;
		std::cout << "Pensée de Snoopy    : " << snoopy.getBrain()->getIdea(0) << std::endl;

		snoopy.getBrain()->setIdea(0, "Je pense que je vais plutôt aller me reposer.");

		std::cout << YELLOW << "\nAprès avoir changé la pensée de Snoopy :" << RESET << std::endl;
		std::cout << "Pensée de Scoubidou : " << scoubidou.getBrain()->getIdea(0) << std::endl;
		std::cout << "Pensée de Snoopy    : " << snoopy.getBrain()->getIdea(0) << std::endl << std::endl;

		std::cout << RED << "Snoopy" << RESET << std::endl;
	} // Snoopy est detruit après cette accolade fermante

	// Si la copie était superficielle, Scoubidou aurait pu en être affecté.
	std::cout << YELLOW << "Snoopy a été détruit, mais Scoubidou existe toujours." << RESET << std::endl;
	std::cout << "Pensée de Scoubidou après la destruction de Snoopy : " << scoubidou.getBrain()->getIdea(0) << std::endl;

	std::cout << YELLOW << "\n--- Suppression d'animaux ---" << RESET << std::endl;

	// Comme le destructeur de AAnimal est virtuel,
	// les destructeurs sont appelés dans le bon ordre :
	// ~Brain() -> ~Cat() / ~Dog() -> ~AAnimal()
	for (int i = 0; i < size; i++)
		delete animals[i];

	return (0);
}
