/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:37:28 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/05 17:43:51 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <limits>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
private:
	/* Les attributs : variables qui evoluent dans le temps */
	Contact	_contacts[8];
	int		_contactIndex;

public:
	/* Les méthodes : actions possibles */	
	PhoneBook(void); // Constructeur appelé à chaque création d'un objet.
	~PhoneBook(void);// Destructeur appelé quand un objet est detruit.

	void	addContact(void);
	void	searchContact(void) const;
};

#endif
