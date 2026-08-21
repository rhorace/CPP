/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:29:01 by rhorace           #+#    #+#             */
/*   Updated: 2026/08/20 09:29:04 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructeur par défaut.
   Le bureaucrate possède le grade le plus faible : 150. */
Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150)
{
}

/* Constructeur de copie.
   Les deux attributs sont initialisés à partir de src. */
Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: _name(src._name), _grade(src._grade)
{
	checkGrade();
}

/* Constructeur avec paramètres.
   checkGrade() vérifie immédiatement si le grade demandé est valide. */
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	checkGrade();
}

// Destructeur.
Bureaucrat::~Bureaucrat()
{
}

/* Opérateur d'affectation.

  _name est const, il ne peut donc pas être modifié.
  On copie uniquement le grade. */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		_grade = src._grade;
	return (*this);
}

// Retourne le nom du bureaucrate.
std::string Bureaucrat::getName() const
{
	return (_name);
}

// Retourne le grade du bureaucrate.
int Bureaucrat::getGrade() const
{
	return (_grade);
}

/* Améliore le grade.

   Comme 1 est le meilleur grade,
   améliorer le grade signifie diminuer sa valeur.

   Exemple : 42 -> 41

   Si le bureaucrate est déjà au grade 1,
   l'opération est impossible. */
void Bureaucrat::incrementGrade()
{
	std::cout << BLUE << "Promotional attempt" << RESET << std::endl;
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

/* Tente de signer un formulaire.

   beSigned() vérifie si le grade du bureaucrate
   est suffisant pour signer le formulaire.

   Si le grade est suffisant, le formulaire est signé.
   Sinon, beSigned() déclenche une exception qui est
   interceptée ici. */
void Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << getName() << GREEN << " signed the " << RESET << f.getName();
		std::cout << " form." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << getName() << RED << " cannot sign the " << RESET << f.getName();
		std::cout << " form because her " << e.what() << std::endl;
	}
}

/* Diminue le grade.

   Comme 150 est le plus mauvais grade,
   diminuer le grade signifie augmenter sa valeur.

   Exemple : 42 -> 43

   Si le bureaucrate est déjà au grade 150,
   l'opération est impossible. */
void Bureaucrat::decrementGrade()
{
	std::cout << BLUE << "Attempted demotion." << RESET << std::endl;
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

/* Vérifie qu'un grade est valide.

   Un grade inférieur à 1 est trop élevé.
   Un grade supérieur à 150 est trop faible. */
void Bureaucrat::checkGrade() const
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

/* Surcharge de l'opérateur <<.

   Permet par exemple : Bureaucrat b("Sophie", 42);

   std::cout << b;
      Affichera : Sophie, bureaucrat grade 42. */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << YELLOW << b.getName() << ", a Grade ";
	os << b.getGrade() << " bureaucrat." << RESET << std::endl;
	return (os);
}

// Message retourné lorsqu'un grade est trop élevé.
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("rank is too high.");
}

// Message retourné lorsqu'un grade est trop faible.
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("rank is too low.");
}

void Bureaucrat::executeForm(Form const & form)
{
	try{
		std::cout << getName() << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch(std::exception& e){
		std::cout << getName() << " could not executes " << form.getName() << " because " << e.what() << std::endl;
	}
}
