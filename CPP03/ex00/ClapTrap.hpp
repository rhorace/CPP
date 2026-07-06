/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:51:39 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/17 15:57:50 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

/*
** Classe représentant un ClapTrap.
** Chaque ClapTrap possède :
** - un nom
** - des points de vie (hit points)
** - des points d'énergie
** - une puissance d'attaque
*/
class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_damage;

	public:
		/* ---------- Orthodox Canonical Form ---------- */

		// Constructeur par défaut
		ClapTrap(void);

		// Constructeur avec nom
		ClapTrap(std::string name);

		// Constructeur de copie
		ClapTrap(const ClapTrap &copy);

		// Opérateur d'assignation
		ClapTrap &operator=(const ClapTrap &other);

		// Destructeur
		~ClapTrap(void);

		/* ---------- Fonctions membres ---------- */

		// Attaque une cible et consomme 1 point d'énergie
		void	attack(const std::string &target);

		// Retire des points de vie
		void	takeDamage(unsigned int amount);

		// Rend des points de vie et consomme 1 point d'énergie
		void	beRepaired(unsigned int amount);
};

#endif
