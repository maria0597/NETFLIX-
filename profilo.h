#ifndef PROFILO_H
# define PROFILO_H

# include "film.h"
# include "serie.h"

class Profilo {
public:
	// Costruttore di default
	Profilo() {}
	
	// Costruttore che inizializza il nome del profilo
	Profilo(std::string& name);

	Profilo(const Profilo& other)
    : name(other.name), films(other.films), series(other.series) {}


	// Restituisce il nome del profilo
	std::string getName() const;

	// Aggiunge un film alla lista dei film visti dall'utente, visualizza un messaggio di avviso se il film è già stato visto e richiede un feedback sulla visione
	void watchFilm(Film& film);

	// Aggiunge una serie alla lista delle serie viste dall'utente, visualizza un messaggio di avviso se la serie è già stata vista e richiede un feedback sulla visione
	void watchSerie(Serie& serie);

	// Modifica il rating di un film visto
	void setFilmRating(Film& film, int rating);

	void setSerieRating(Serie& serie, int rating);

	// Restituisce la lista dei film presenti nella watchlist del profilo
	std::vector<Film> getWatchlistFilms() const;

	// Restituisce la lista delle serie presenti nella watchlist del profilo
	std::vector<Serie> getWatchlistSeries() const;

	void addFilmToWatchlist(const Film&film);
	void addSerieToWatchlist(const Serie& serie);

	const std::vector<Film> getFilms() const { return films; }
	const std::vector<Serie> getSeries() const { return series; }

private:
	std::string name;
	std::vector<Film> films;
	std::vector<Serie> series;
	std::vector<Film> watchlistFilms;
	std::vector<Serie> watchlistSeries;
};

#endif // PROFILO_H
