/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:39:47 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/25 11:39:53 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

/*
	MateriaSource implémente IMateriaSource.

	Elle contient 4 modèles de Materias.
*/
class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_templates[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &other);
		virtual ~MateriaSource();

		/* Fonctions membres */
		virtual void		learnMateria(AMateria *m);
		virtual AMateria	*createMateria(std::string const &type);
};

#endif
