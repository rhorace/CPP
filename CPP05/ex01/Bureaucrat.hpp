/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:29:10 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/20 09:29:13 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class Form;

class Bureaucrat
{
	public:

		/* Constructeur par défaut :
		   crée un bureaucrate nommé "Default" avec le grade 150. */
		Bureaucrat();

		/* Constructeur de copie :
		   crée un nouveau Bureaucrat à partir d'un autre. */
		Bureaucrat(const Bureaucrat& src);

		/* Constructeur avec paramètres.
		   Le nom est passé par référence constante pour éviter une copie inutile. */
		Bureaucrat(const std::string& name, int grade);

		// Destructeur.
		~Bureaucrat();

		/* Opérateur d'affectation.
		   Seul le grade peut être copié car _name est const. */
		Bureaucrat& operator=(const Bureaucrat& src);

		// Getters permettant de consulter les attributs.
		std::string	getName() const;
		int			getGrade() const;

		/* Améliore le grade.
		   1 est le meilleur grade. */
		void		incrementGrade();

		/* Diminue le grade.
		   150 est le plus mauvais grade. */
		void		decrementGrade();

		void		signForm(Form&) const;

		// Exception levée lorsqu'on tente de dépasser le grade 1.
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Exception levée lorsqu'on tente de dépasser le grade 150.
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		// Le nom ne peut plus être modifié après la construction.
		const std::string	_name;

		/* Le grade doit toujours être compris entre 1 et 150.
		   1   = meilleur grade
		   150 = plus mauvais grade */
		int					_grade;

		// Vérifie que le grade est compris entre 1 et 150.
		void				checkGrade() const;
};

/* Surcharge de << pour pouvoir écrire :
   std::cout << bureaucrat; */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
