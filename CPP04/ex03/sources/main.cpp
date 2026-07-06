/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:41:27 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:55:20 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	/* Création de la source de Materias */
	IMateriaSource *src = new MateriaSource();

	/* Apprentissage des Materias */
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	/* Création du personnage principal */
	ICharacter *me = new Character("me");

	/* Création d'une Ice puis équipement */
	AMateria *tmp;

	tmp = src->createMateria("ice"); //Création d'une materia "Ice" par clonage
	me->equip(tmp); //Je m'équipe de cette materia "Ice" dans le slot0

	/* Création d'une Cure puis équipement */
	tmp = src->createMateria("cure"); //Création d'une materia "Cure" par clonage
	me->equip(tmp); //Je m'équipe de cette materia "Cure" dans le slot1

	std::cout << std::endl;

	/* Création d'un deuxième personnage */
	ICharacter *bob = new Character("bob");
  
	std::cout << std::endl;

	/* Utilisation des Materias */
	me->use(0, *bob); // J'utilise la matéria que se trouve dans mon slot0 (Ice)
	me->use(1, *bob); // J'utilise la matéria que se trouve dans mon slot1 (Cure)

	std::cout << std::endl;

	/* Libération mémoire */
	delete bob;
	delete me;

	std::cout << std::endl;
	
	delete src;

	return (0);
}
