/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:04:01 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 10:04:06 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>
# include "AForm.hpp"

/* ShrubberyCreationForm

   Crée un fichier :

       <target>_shrubbery

   contenant un arbre en ASCII.

   Grade nécessaire pour signer   : 145
   Grade nécessaire pour exécuter : 137 */
class ShrubberyCreationForm : public Form
{
	public:

		// Constructeur par défaut.
		ShrubberyCreationForm();

		// Constructeur prenant la cible du formulaire.
		ShrubberyCreationForm(const std::string &target);

		// Constructeur de recopie.
		ShrubberyCreationForm(const ShrubberyCreationForm &src);

		// Destructeur.
		virtual ~ShrubberyCreationForm();

		// Opérateur d'affectation.
		ShrubberyCreationForm &operator=(
			const ShrubberyCreationForm &src);

		/* Crée le fichier <target>_shrubbery
		  et y écrit un arbre en ASCII. */
		virtual void	execute(Bureaucrat const &executor) const;
};

#endif
