/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:43:15 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:43:19 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	// Constructeur avec nom
	FragTrap(std::string name);

	// Constructeur de copie
	FragTrap(const FragTrap &copy);

	// Opérateur d'assignation
	FragTrap &operator=(const FragTrap &other);

	// Destructeur
	~FragTrap(void);

	// FragTrap possède sa propre attaque
	void	attack(const std::string &target);

	// Fonction demandée par le sujet
	void	highFivesGuys(void);
};

#endif
