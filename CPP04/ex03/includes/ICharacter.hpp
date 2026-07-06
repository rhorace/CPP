/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:39:26 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:25:53 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria;

/*
	ICharacter est une interface.

	Elle impose aux classes filles d'avoir :
	- getName()
	- equip()
	- unequip()
	- use()
*/
class ICharacter
{
	public:
		/*
			Destructeur virtuel obligatoire pour une interface.

			Cela permet de faire :
			ICharacter *me = new Character("me");
			delete me;

			Et d'appeler correctement le destructeur de Character.
		*/
		virtual ~ICharacter();

		/* Getter */
		virtual std::string const	&getName() const = 0;

		/* Fonctions membres pures */
		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};

#endif
