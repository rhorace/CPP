/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:31:36 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 14:24:54 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// Animal est abstraite car makeSound() est virtuelle.
	// Donc cette ligne ne marche pas : const Animal *meta = new Animal();

	const Animal		*i = new Cat();
	const Animal		*j = new Dog();

	// Mauvais polymorphisme : WrongAnimal n'a pas de makeSound() virtual.
	const WrongAnimal	*wrong = new WrongCat();

	std::cout << std::endl;

	std::cout << "i(type)    : " << i->getType() << std::endl;
	std::cout << "j(type)    : " << j->getType() << std::endl;
	std::cout << "wrong(type): " << wrong->getType() << std::endl;

	std::cout << std::endl;

	// Grâce au virtual, la bonne fonction est appelée.
	i->makeSound();
	j->makeSound();

	// Ici, comme makeSound() n'a pas virtual dans WrongAnimal,
	// c'est WrongAnimal::makeSound() qui est appelée.
	wrong->makeSound();

	std::cout << std::endl;

	// Grâce au destructeur virtual dans Animal,
	// les destructeurs Cat/Dog puis Animal sont appelés correctement.
	delete i;
	delete j;

	// Comme le destructeur de WrongAnimal n'est pas virtual,
	// WrongCat::~WrongCat() ne sera pas appelé mais juste WrongAnimal::~WrongAnimal.
	delete wrong;

	return (0);
}
