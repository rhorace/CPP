/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:39:10 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:25:40 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

// 	Ice hérite de AMateria. Elle représente la Materia "ice".
class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &other);
		virtual ~Ice();

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
