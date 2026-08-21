/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:03:51 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/21 10:03:54 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* Constructeur par défaut.

   Grade de signature : 145
   Grade d'exécution  : 137 */
ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", "Default", false, 145, 137)
{
}

// Constructeur avec une cible.
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: Form("ShrubberyCreationForm", target, false, 145, 137)
{
}

// Constructeur de recopie.
ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &src)
	: Form(src)
{
}

// Destructeur.
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/* Opérateur d'affectation.

   Comme cette classe ne possède aucun attribut supplémentaire,
   on utilise l'opérateur d'affectation de Form. */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm &src)
{
	if (this != &src)
		Form::operator=(src);
	return (*this);
}

/* Exécute le formulaire.

   Le fichier créé porte le nom :

       <target>_shrubbery

   Exemple :

       target = "home"

   donnera :

       home_shrubbery */
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	outfile;

	// Vérifie d'abord que le formulaire peut être exécuté.
	validateExecute(executor);

	// Création du fichier correspondant à la cible.
	outfile.open((getTarget() + "_shrubbery").c_str());

	// Vérifie que le fichier a correctement été ouvert.
	if (!outfile.is_open())
		throw std::runtime_error("Unable to create shrubbery file");

	// Écriture de l'arbre ASCII dans le fichier.
	outfile
		<< "               ,@@@@@@@,\n"
		<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o\n"
		<< "   ,%&%%&&%&&%,@@@@@@@/@@@88888888/88'\n"
		<< "   %&&%/ %&%%&&@@@ V /@@' `8888 `/88'\n"
		<< "   `&% |` /%&'    |.|         |'|8'\n"
		<< "       |o|        | |         | |\n"
		<< "       |.|        | |         | |\n"
		<< "       / .__//_/_/  |___//___/. |__//__/_\n";

	// Fermeture explicite du fichier.
	outfile.close();
}
