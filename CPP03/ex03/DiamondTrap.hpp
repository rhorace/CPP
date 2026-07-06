/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:45:13 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/23 14:45:16 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// DiamondTrap hérite de ScavTrap et FragTrap.
// ScavTrap et FragTrap doivent hériter de ClapTrap en virtual public.
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	// Nom propre à DiamondTrap
	std::string	_name;

public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap(void);

	// DiamondTrap doit utiliser attack() de ScavTrap
	void	attack(const std::string &target);

	// Affiche le nom DiamondTrap et le nom ClapTrap
	void	whoAmI(void);
};

#endif
