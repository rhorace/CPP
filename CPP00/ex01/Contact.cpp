/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:33:21 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/05 17:39:57 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructeur
Contact::Contact(void) {
}

// Destructeur
Contact::~Contact(void) {
}

/* ----------------------------- UTILS ----------------------------------*/

bool	Contact::is_alpha(const std::string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isalpha(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

bool	Contact::is_digit(const std::string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

bool	Contact::is_empty(void) const {
	return this->_firstname.empty();
}

/* ----------------------------- SETTERS ----------------------------------*/

bool	Contact::setFirstname(const std::string& str) {
	if (!str.empty() && this->is_alpha(str)) {
		this->_firstname = str;
		return true;
	}
	return false;
}

bool	Contact::setLastname(const std::string& str) {
	if (!str.empty() && this->is_alpha(str)) {
		this->_lastname = str;
		return true;
	}
	return false;
}

bool	Contact::setNickname(const std::string& str) {
	if (!str.empty() && this->is_alpha(str)) {
		this->_nickname = str;
		return true;
	}
	return false;
}

bool	Contact::setNumber(const std::string& str) {
	if (!str.empty() && this->is_digit(str)) {
		this->_number = str;
		return true;
	}
	return false;
}

bool	Contact::setSecret(const std::string& str) {
	if (!str.empty()) {
		this->_secret = str;
		return true;
	}
	return false;
}

/* ----------------------------- GETTERS ----------------------------------*/

std::string	Contact::getFirstname(void) const {
	return this->_firstname;
}

std::string	Contact::getLastname(void) const {
	return this->_lastname;
}

std::string	Contact::getNickname(void) const {
	return this->_nickname;
}

std::string	Contact::getNumber(void) const {
	return this->_number;
}

std::string	Contact::getSecret(void) const {
	return this->_secret;
}
