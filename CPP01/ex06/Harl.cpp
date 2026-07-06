/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:45:36 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/08 09:45:41 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	
}

Harl::~Harl(void) {
	
}

void	Harl::debug(void) {
	std::cout << "DEBUG : Détection du matériel terminée. Initialisation des périphériques.";
}

void	Harl::info(void) {
	std::cout << "INFO : Service réseau démarré avec succès.";
}

void	Harl::warning(void) {
	std::cout << "WARNING : Tentative de connexion refusée après plusieurs échecs d'authentification.";
}

void	Harl::error(void) {
	std::cout << "ERROR : Le noyau a rencontré une erreur critique. Arrêt du système recommandé.";
}

void	Harl::complain(std::string level) {
	// Tableau des noms des niveaux.
	std::string	levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	// Tableau des adresses des méthodes correspondantes.
	void (Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {		
		if (level == levels[i]) {
			// Appelle, sur l’objet courant this, la fonction membre stockée dans functions[i].
			(this->*functions[i])();
			std::cout << std::endl;
			return;
		}
	}
	std::cout << "Niveau invalide." << std::endl;
}

