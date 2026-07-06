/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:33:44 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/05 17:41:20 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cctype>
# include <string>

class Contact
{
private:
	/* Les attributs : variables qui evoluent dans le temps */
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;

	bool		is_alpha(const std::string &input);
	bool		is_digit(const std::string &input);

public:
	/* Les méthodes : actions possibles */	
	Contact(void); // Constructeur appelé à chaque création d'un objet.
	~Contact(void);// Destructeur appelé quand un objet est detruit.

	bool		is_empty(void) const;

	// accesseurs "set" (mettre)
	bool		setFirstname(const std::string &str);
	bool		setLastname(const std::string &str);
	bool		setNickname(const std::string &str);
	bool		setNumber(const std::string &str);
	bool		setSecret(const std::string &str);

	// accesseurs "get" (récupérer)
	std::string	getFirstname(void) const;
	std::string	getLastname(void) const;
	std::string	getNickname(void) const;
	std::string	getNumber(void) const;
	std::string	getSecret(void) const;
};

#endif
