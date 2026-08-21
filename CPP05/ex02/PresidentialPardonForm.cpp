/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:02:57 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 10:03:00 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

/* Constructeur par défaut.

  "Default" est utilisé comme cible.
   Grade de signature  : 25
   Grade d'exécution   : 5 */
PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", "Default", false, 25, 5)
{
}

//Constructeur avec une cible.
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: Form("PresidentialPardonForm", target, false, 25, 5)
{
}

/* Constructeur de recopie.

   On utilise directement le constructeur de copie de Form.
   Il se charge de recopier la partie Form de l'objet. */
PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &src)
	: Form(src)
{
}

// Destructeur.
PresidentialPardonForm::~PresidentialPardonForm()
{
}

/* Opérateur d'affectation.

   Cette classe ne possède pas de nouvel attribut.
   On délègue donc la copie à la classe Form. */
PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &src)
{
	if (this != &src)
		Form::operator=(src);
	return (*this);
}

/* Exécute le formulaire.

   validateExecute() vérifie que :
   - le formulaire est signé ;
   - executor possède un grade suffisant. */
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	validateExecute(executor);

	std::cout << getTarget()
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
