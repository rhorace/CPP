/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:27:46 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:27:53 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

/* La différence essentielle :

newZombie()
Crée un zombie avec new, donc sur la heap.
Il continue d’exister après la fin de newZombie().
Il devra être détruit manuellement avec : delete heapZombie.

randomChump()
Le zombie ( temporaire ) est créé sur la stack.
Il sera détruit automatiquement à la fin de la fonction randomChump().*/

int	main(void) {
	Zombie *heapZombie = newZombie("Tarman");
	heapZombie->announce();

	randomChump("Bub");

	/*Sinon on aura une fuite mémoire.*/
	delete heapZombie;

	return 0;
}
