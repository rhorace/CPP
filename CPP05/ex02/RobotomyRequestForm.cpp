/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:03:22 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 10:03:26 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Constructeur par défaut.

   Grade de signature : 72
   Grade d'exécution  : 45 */
RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", "Default", false, 72, 45)
{
}

// Constructeur avec une cible.
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: Form("RobotomyRequestForm", target, false, 72, 45)
{
}

// Constructeur de recopie.
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: Form(src)
{
}

// Destructeur.
RobotomyRequestForm::~RobotomyRequestForm()
{
}

/* Opérateur d'affectation.

   Aucun nouvel attribut n'est présent dans cette classe.
   L'affectation est donc déléguée à Form. */
RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &src)
{
	if (this != &src)
		Form::operator=(src);
	return (*this);
}

/* Exécute la tentative de robotomie.

   validateExecute() vérifie d'abord que le formulaire
   peut être exécuté.

   srand() ne doit être appelé qu'une seule fois.
   La variable statique permet d'éviter de réinitialiser
   le générateur à chaque appel de execute(). */
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static bool	seeded = false;

	validateExecute(executor);

	std::cout << "BziiiiiIIII RRRRRRR TTTTTT CRACK" << std::endl;

	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}

	// Une valeur sur deux produit une robotomie réussie.
	if (std::rand() % 2)
	{
		std::cout << getTarget()
			<< " has been robotomized successfully!"
			<< std::endl;
	}
	else
	{
		std::cout << "Oh no! "
			<< getTarget()
			<< " robotomization failed..."
			<< std::endl;
	}
}
