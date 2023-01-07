#ifndef ACCOUNT_H
# define ACCOUNT_H

# include <string>
# include <iostream>
# include <vector>
# include <algorithm>
# include <fstream>
#include <sstream>
# include "profilo.h"

class Account 
{
public:
	// Costruttore
	Account(std::string email, std::string password, std::string username);

	// Aggiunge un nuovo profilo all'account
	void addProfile(Profilo profile);

	// Imposta il profilo attivo
	//void setActiveProfile(Profilo profile);

	// Restituisce il numero di profili associati all'account
	unsigned int getNumberOfProfiles();

	// Restituisce il profilo attivo
	Profilo& getActiveProfile();

	// Restituisce l'email dell'account
	std::string getEmail() const;

	// Restituisce la password dell'account
	std::string getPassword() const;

	std::string getUsername() const;

	// Verifica se la password inserita è corretta
	bool checkPassword(std::string password) const;

	// Aggiunge un film alla watchlist del profilo attivo
	void addFilmToWatchlist(const Film& film);

	// Aggiunge una serie alla watchlist del profilo attivo
	void addSerieToWatchlist(const Serie& serie);

	// Restituisce la watchlist dei film del profilo attivo
	std::vector<Film> getWatchlistFilms() const;

	// Restituisce la watchlist delle serie del profilo attivo
	std::vector<Serie> getWatchlistSeries() const;

	std::string toString() const;

	const std::vector<Profilo>& getProfiles() const;

		// Restituisce il profilo in base all'indice
	Profilo& getProfile(unsigned int index);

	void setActiveProfile(Profilo& profile);

private:
	std::string email;
	std::string password;
	std::string username;
	std::vector<Profilo> profiles;
	Profilo activeProfile;
};

void saveAccountsToFile(std::vector<Account>& accounts, const std::string& fileName);

// Funzione di login che riceve in ingresso le credenziali dell'utente e verifica se esistono nella lista di account
bool login(const std::string& email, const std::string& password, const std::vector<Account>& accounts);

// Carica gli account dal file di testo specificato
std::vector<Account> loadAccountsFromFile(const std::string& filename);

#endif
