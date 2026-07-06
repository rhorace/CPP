/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:38:25 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:38:29 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    // Créer N objets Zombie
	Zombie *zHorde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        std::stringstream ss;
        ss << name << i + 1;      // Tarman1, Tarman2, ...
        zHorde[i].setName(ss.str());
    }

    return zHorde;
}
