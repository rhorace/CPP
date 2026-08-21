/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:27:31 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/20 11:27:34 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	public:

		// Constructeur par défaut
		Form();

		// Constructeur avec paramètres
		Form(const std::string name, const int gradeToSign, const int gradeToExec);

		// Constructeur de recopie
		Form(const Form& src);

		// Destructeur
		~Form();

		// Opérateur d'affectation
		Form& operator=(const Form& src);

		// Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		// Permet à un bureaucrate de signer le formulaire
		void		beSigned(const Bureaucrat& bureaucrat);

		// Exception : grade trop élevé numériquement trop petit
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		// Exception : grade trop faible numériquement trop grand
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		virtual void execute(Bureaucrat const & executor) const = 0;

	private:

		// Nom du formulaire, non modifiable après construction
		const std::string	_name;

		// Indique si le formulaire a été signé
		bool				_isSigned;

		// Grade minimum nécessaire pour signer
		const int			_gradeToSign;

		// Grade minimum nécessaire pour exécuter
		const int			_gradeToExec;

		// Vérifie que les grades sont compris entre 1 et 150
		void				checkGrade() const;
};

// Affichage d'un formulaire avec std::cout
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
