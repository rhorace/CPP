/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:27:22 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/20 11:27:25 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructeur par défaut.
   Le formulaire est créé non signé avec les grades les plus faibles. */
Form::Form()
	: _name("Default"),
	  _isSigned(false),
	  _gradeToSign(150),
	  _gradeToExec(150)
{
}

/* Constructeur avec paramètres.
   Un formulaire est toujours créé non signé. */
Form::Form(const std::string name,
	const int gradeToSign,
	const int gradeToExec)
	: _name(name),
	  _isSigned(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExec(gradeToExec)
{
	checkGrade();
}

/* Constructeur de recopie.
   Toutes les caractéristiques du formulaire sont copiées. */
Form::Form(const Form& src)
	: _name(src._name),
	  _isSigned(src._isSigned),
	  _gradeToSign(src._gradeToSign),
	  _gradeToExec(src._gradeToExec)
{
}

// Destructeur.
Form::~Form()
{
}

/* Opérateur d'affectation.
   Les attributs const ne peuvent pas être modifiés.
   Seul l'état signé/non signé peut donc être copié. */
Form& Form::operator=(const Form& src)
{
	if (this != &src)
		_isSigned = src._isSigned;
	return (*this);
}

// Retourne le nom du formulaire.
std::string Form::getName() const
{
	return (_name);
}

// Retourne true si le formulaire est signé.
bool Form::getIsSigned() const
{
	return (_isSigned);
}

// Retourne le grade nécessaire pour signer le formulaire.
int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

// Retourne le grade nécessaire pour exécuter le formulaire.
int Form::getGradeToExec() const
{
	return (_gradeToExec);
}

/* Vérifie si le bureaucrate possède un grade suffisant pour signer le formulaire.

   20 < 30 : le bureaucrate peut signer. */
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/* Vérifie que les grades du formulaire sont valides.

   Un grade inférieur à 1 est trop élevé.
   Un grade supérieur à 150 est trop faible. */
void Form::checkGrade() const
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();

	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

// Message retourné lorsqu'un grade est supérieur à la limite autorisée.
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Le grade est trop élevé.");
}

// Message retourné lorsqu'un grade est inférieur à la limite autorisée.
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Le grade est trop bas.");
}

/* Permet d'afficher directement un formulaire.

   Exemple :
   std::cout << form; */
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form \"" << form.getName() << "\"";

	if (form.getIsSigned())
		os << " is signed.";
	else
		os << " is not signed.";

	os << " Required grade to sign is "
		<< form.getGradeToSign()
		<< " and to execute is "
		<< form.getGradeToExec()
		<< "."
		<< std::endl;

	return (os);
}
