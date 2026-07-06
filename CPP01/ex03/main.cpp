/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:42:23 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:42:34 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/* Les références et les membres const doivent toujours être initialisés dans
 la liste d'initialisation du constructeur.
		une référence doit être liée à un objet dès sa création;
		une référence ne peut pas être « réaffectée » plus tard.
 
 Et même pour les autres membres (std::string, int, etc.),
 la liste d'initialisation est généralement préférée, car elle construit
 directement les objets au lieu de les construire puis de les réaffecter. */

int	main(void) {
	{
		Weapon	club = Weapon("crude spiked club");
		
		// HumanA reçoit une référence vers l’arme, donc Bob a forcément une arme.
		HumanA	bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		
		// HumanB utilise un pointeur, donc Jim peut exister sans arme au départ.
		HumanB	jim("Jim");
		jim.setWeapon(club);

		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

