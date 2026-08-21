/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:03:32 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 10:03:37 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

/* RobotomyRequestForm

   Tente de robotomiser une cible.

   La robotomie possède 50 % de chances de réussir.

   Grade nécessaire pour signer   : 72
   Grade nécessaire pour exécuter : 45 */
class RobotomyRequestForm : public Form
{
	public:

		// Constructeur par défaut.
		RobotomyRequestForm();

		// Constructeur prenant la cible du formulaire.
		RobotomyRequestForm(const std::string &target);

		// Constructeur de recopie.
		RobotomyRequestForm(const RobotomyRequestForm &src);

		// Destructeur.
		virtual ~RobotomyRequestForm();

		// Opérateur d'affectation.
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		/* Exécute une tentative de robotomie.

		  La robotomie a une chance sur deux de réussir. */
		virtual void	execute(Bureaucrat const &executor) const;
};

#endif
