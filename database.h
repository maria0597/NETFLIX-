#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "film.h"
#include "serie.h"
#include "account.h"

class Database 
{
	private:
		std::vector<Film> films;
		std::vector<Serie> series;
		std::vector<Account> accounts;
	
	public:
		// Costruttore
		Database();

		// Aggiungi e rimuovi film
		void addFilm(Film film);
		void removeFilm(Film film);

		// Aggiungi e rimuovi serie
		void addSerie(Serie serie);
		void removeSerie(Serie serie);

		// Restituisce il film con il titolo specificato, se presente nel database
		// Restituisce un puntatore nullo se il film non viene trovato
		Film* findFilm(const std::string& title);

		// Restituisce la serie con il titolo specificato, se presente nel database
		// Restituisce un puntatore nullo se la serie non viene trovata
		Serie* findSerie(const std::string& title);

		// Visualizza il film e la serie più apprezzati al momento
		Film getTopFilm();
		Serie getTopSerie();

		// Richiedi un film o serie simile a quello dato
		Film getSimilarFilm(Film film);
		Serie getSimilarSerie(Serie serie);

	std::vector<Film> getFilms();
	std::vector<Serie> getSerie();

	void addAccount(Account account)
	{
		accounts.push_back(account);
	}
};

#endif // DATABASE_H

