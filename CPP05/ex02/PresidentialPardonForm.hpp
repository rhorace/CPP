/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:03:05 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 10:03:09 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

/* PresidentialPardonForm

   Formulaire permettant de gracier une cible.

   Grade nécessaire pour signer   : 25
   Grade nécessaire pour exécuter : 5 */
class PresidentialPardonForm : public Form
{
	public:

		// Constructeur par défaut.
		PresidentialPardonForm();

		// Constructeur prenant la cible du formulaire.
		PresidentialPardonForm(const std::string &target);

		// Constructeur de recopie.
		PresidentialPardonForm(const PresidentialPardonForm &src);

		// Destructeur.
		virtual ~PresidentialPardonForm();

		// Opérateur d'affectation.
		PresidentialPardonForm &operator=(
			const PresidentialPardonForm &src);

		/* Exécute le formulaire.
		   La cible est graciée par Zaphod Beeblebrox.

		   Lance une exception si :
		   - le formulaire n'est pas signé ;
		   - le grade de l'exécuteur est insuffisant. */
		virtual void	execute(Bureaucrat const &executor) const;
};

#endif
