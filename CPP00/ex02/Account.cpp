/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhorace <rhorace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:55:24 by rhorace           #+#    #+#             */
/*   Updated: 2026/06/05 17:44:42 by rhorace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/* VARIABLES STATIQUES
 *
 * Ces variables sont partagées par TOUS les objets Account.
 * Elles représentent l'état global de la banque. */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* CONSTRUCTEUR
 *
 * Création d'un nouveau compte.
 *
 * Chaque compte possède :
 * - un index unique
 * - un montant initial
 * - un compteur de dépôts
 * - un compteur de retraits
 *
 * Les statistiques globales de la banque sont également mises à jour. */
Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();

	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created"
			  << std::endl;
}

/* DESTRUCTEUR
 *
 * Affiche la fermeture du compte. */
Account::~Account(void)
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed"
			  << std::endl;
}

/* TIMESTAMP
 *
 * Fonction privée utilisée pour afficher la date et l'heure courantes.
 *
 * Format : 
 * [YYYYMMDD_HHMMSS] */
void Account::_displayTimestamp(void)
{
	char buffer[20];

	std::time_t currentTime = std::time(NULL);

	std::strftime(
		buffer,
		sizeof(buffer),
		"[%Y%m%d_%H%M%S] ",
		std::localtime(&currentTime));

	std::cout << buffer;
}

/* INFORMATIONS GLOBALES
 *
 * Affiche l'état global de la banque :
 * - nombre de comptes
 * - montant total
 * - nombre total de dépôts
 * - nombre total de retraits */
void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}

/* ÉTAT D'UN COMPTE
 *
 * Affiche les informations d'un compte particulier. */
void Account::displayStatus(void) const
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

/* DÉPÔT
 *
 * Effectue un dépôt sur le compte.
 *
 * Met à jour :
 * - le solde du compte
 * - le nombre de dépôts du compte
 * - le montant total détenu par la banque
 * - le nombre total de dépôts  */
void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount
			  << ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

/* RETRAIT
 *
 * Tente d'effectuer un retrait.
 *
 * Si le solde est insuffisant :
 * - le retrait est refusé
 * - aucun compteur n'est modifié
 *
 * Retour :
 * - true  -> retrait effectué
 * - false -> retrait refusé */
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;

	if (withdrawal > Account::checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}

	std::cout << ";withdrawal:" << withdrawal;

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << ";amount:" << this->_amount
			  << ";nb_withdrawals:" << this->_nbWithdrawals
			  << std::endl;

	return (true);
}

/* CONSULTATION DU SOLDE
 *
 * Retourne le montant actuellement disponible sur le compte. */
int Account::checkAmount(void) const
{
	return (this->_amount);
}

/* GETTERS STATIQUES
 *
 * Ces fonctions permettent d'accéder aux statistiques globales
 * de la banque. */
int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
