/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:39:38 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/27 15:14:21 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

/*
	Interface de la source de Materias.

	Elle impose :
	- learnMateria()
	- createMateria()
*/
class IMateriaSource
{
	public:
		virtual ~IMateriaSource();

		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
