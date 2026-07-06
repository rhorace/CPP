/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:35:15 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:35:19 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	int	N = 9;
	Zombie	*horde = zombieHorde(N, "Tarman");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}	
	
	/* On utilise delete[] et non delete,
	parce qu'on a utilisé : new Zombie[N] */
	delete[] horde;

	return 0;
}
