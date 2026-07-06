/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:38:31 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:25:05 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

/*
	AMateria est une classe abstraite.

	Elle représente une Materia générique.
	On ne peut pas créer directement une AMateria car clone() est virtual.
*/
class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		std::string const	&getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void	use(ICharacter &target);
};

#endif
