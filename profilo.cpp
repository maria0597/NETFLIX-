#include "profilo.h"
#include <iostream>
#include <algorithm>

// Costruttore che inizializza il nome del profilo
Profilo::Profilo(std::string& name) : name(name) {}

// Aggiunge un film alla watchlist del profilo
void Profilo::addFilmToWatchlist(const Film&film) 
{
	watchlistFilms.push_back(film);
}

// Aggiunge una serie alla watchlist del profilo
void Profilo::addSerieToWatchlist(const Serie& serie)
{
	watchlistSeries.push_back(serie);
}

// Restituisce la watchlist dei film del profilo
std::vector<Film> Profilo::getWatchlistFilms() const
{
	return watchlistFilms;
}

// Restituisce la watchlist delle serie del profilo
std::vector<Serie> Profilo::getWatchlistSeries() const 
{
	return watchlistSeries;
}

// Restituisce il nome del profilo
std::string Profilo::getName() const
{
		return name;
}

// Modifica il rating di un film visto
// Assegna un rating a un film
void Profilo::setFilmRating(Film& film, int rating)
{
	// Verifica che il rating sia valido (compreso tra 1 e 5)
	if (rating < 1 || rating > 5)
	{
		std::cout << "Rating non valido." << std::endl;
		return;
	}
	// Cerca il film nella lista dei film visti
	auto it = std::find(films.begin(), films.end(), film);
	if (it != films.end())
	{
	// Se il film è stato trovato, modifica il rating utilizzando il metodo addRating
		it->addRating(rating);
	}
	else
	{
	// Altrimenti, aggiunge il film alla lista dei film visti e assegna il rating
		films.push_back(film);
		film.addRating(rating);
	}
}

// Aggiunge una valutazione a una serie
void Profilo::setSerieRating(Serie& serie, int rating)
{
	// Verifica che il rating sia valido (compreso tra 1 e 5)
	if (rating < 1 || rating > 5)
	{
	std::cout << "Rating non valido." << std::endl;
	return;
	}
	// Cerca la serie nella lista delle serie viste
	auto it = std::find(series.begin(), series.end(), serie);
	if (it != series.end()) 
	{
	// Se la serie è stata trovata, modifica il rating utilizzando il metodo addRating
	it->addRating(rating);
	}
	else
	{
	// Altrimenti, aggiunge la serie alla lista delle serie viste e assegna il rating
	series.push_back(serie);
	serie.addRating(rating);
	}
}

// Aggiunge un film alla lista dei film visti dall'utente, visualizza un messaggio di avviso se il film è già stato visto e richiede un feedback sulla visione
void Profilo::watchFilm(Film& film) 
{
	// Cerca il film nella lista dei film visti
	auto it = std::find(films.begin(), films.end(), film);
	if (it != films.end())
	{
		// Se il film è già stato visto, visualizza un messaggio di avviso
		std::cout << "Hai già visto questo film!" << std::endl;
		// Non aggiungere il film alla lista dei film visti e saltare il resto del metodo
		return;
	}
	else
			// Altrimenti lo aggiunge alla lista dei film visti
			films.push_back(film);
	// Richiedi un feedback sulla visione del film
	std::cout << "Hai appena visto il film " << film.getTitle() << ". Vuoi lasciare una recensione? (S/N) ";
	char choice;
	std::cin >> choice;

	if (choice == 'S' || choice == 's') 
	{
		int rating;
		std::cout << "Inserisci il tuo voto (da 1 a 5): ";
		std::cin >> rating;
		// Aggiungi il voto al film
		film.addRating(rating);
	}
}

// Aggiunge una serie alla lista delle serie viste dall'utente, visualizza un messaggio di avviso se la serie è già stata vista e richiede un feedback sulla visione
void Profilo::watchSerie(Serie& serie) 
{
	// Cerca la serie nella lista delle serie già viste dall'utente
	auto it = std::find(series.begin(), series.end(), serie);
	if (it != series.end()) 
	{
		// Se la serie è già stata vista, visualizza un messaggio di avviso
		std::cout << "Hai già visto questa serie" << std::endl;
	}
	else 
	{
		// Altrimenti, aggiungi la serie alla lista delle serie viste e chiedi un feedback sulla visione
		series.push_back(serie);
		std::cout << "Hai appena visto la serie " << serie.getTitle() << std::endl;
		std::cout << "Come ti è sembrata? Inserisci il tuo rating (da 1 a 10): ";
		int rating;
		std::cin >> rating;
		// Aggiungi il rating alla serie
		serie.addRating(rating);
	}
}
