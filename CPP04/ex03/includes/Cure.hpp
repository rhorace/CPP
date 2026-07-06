/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:38:53 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:25:30 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

// 	Cure hérite de AMateria. Elle représente la Materia "cure".
class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &other);
		virtual ~Cure();

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
