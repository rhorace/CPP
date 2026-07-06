/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:38:43 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:22:00 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

/*
	Chaque personnage possède :
	- un nom
	- un inventaire de 4 Materias
*/
class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(std::string const &name);
		Character(const Character &copy);
		Character &operator=(const Character &other);
		virtual ~Character();

		virtual std::string const	&getName() const;

		virtual void	equip(AMateria *m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter &target);
};

#endif
