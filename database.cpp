#include "database.h"
#include <algorithm>

// Costruttore
Database::Database() {}

// Aggiungi film
void Database::addFilm(Film film) 
{
	films.push_back(film);
}

// Rimuovi film
void Database::removeFilm(Film film) 
{
	// Per rimuovere un elemento da un vettore in C++, puoi utilizzare la funzione erase
	// La funzione std::remove prende come argomento un puntatore a un array e restituisce un iteratore al primo elemento che non corrisponde al valore da rimuovere. Tuttavia, stai passando un iteratore al vettore di film o serie come argomento, il che non è corretto.
	//films.erase(std::remove(films.begin(), films.end(), film), films.end());
	auto it = std::find(films.begin(), films.end(), film);
	if (it != films.end()) 
	{
		films.erase(it);
	}
}

// Aggiungi serie
void Database::addSerie(Serie serie) 
{
	series.push_back(serie);
}

// Rimuovi serie
void Database::removeSerie(Serie serie) 
{
	series.erase(std::remove(series.begin(), series.end(), serie), series.end());
}

// Definizione di Database::getFilms()
std::vector<Film> Database::getFilms() 
{
// Restituisce il vettore dei film
	return films;
}

// Definizione di Database::getSerie()
std::vector<Serie> Database::getSerie() 
{
// Restituisce il vettore delle serie
	return series;
}

Film* Database::findFilm(const std::string& title)
{
  // Cerca il film con il titolo specificato nella lista di film
  auto it = std::find_if(films.begin(), films.end(), [&](const Film& f) { return f.getTitle() == title; });

  // Se il film è stato trovato, restituisce il puntatore al film
  if (it != films.end())
	return &(*it);

  // Se il film non è stato trovato, restituisce nullptr
  return nullptr;
}

Serie* Database::findSerie(const std::string& title)
{
  // Cerca la serie con il titolo specificato nella lista di serie
  auto it = std::find_if(series.begin(), series.end(), [&](const Serie& s) { return s.getTitle() == title; });

  // Se la serie è stata trovata, restituisce il puntatore alla serie
  if (it != series.end())
	return &(*it);

  // Se la serie non è stata trovata, restituisce nullptr
  return nullptr;
}


// Restituisce il film più apprezzato
Film Database::getTopFilm() 
{
	// Ordina i film in base al loro voto medio e restituire il primo elemento del vettore
	std::sort(films.begin(), films.end(), [](Film& f1, Film& f2) 
	{
		return f1.getAverageRating() > f2.getAverageRating();
	});
	return films.front();
}

// Restituisce la serie più apprezzata
Serie Database::getTopSerie() 
{
	// Ordina le serie in base al loro voto medio e restituire il primo elemento del vettore
	std::sort(series.begin(), series.end(), [](Serie& s1, Serie& s2) 
	{
		return s1.getAverageRating() > s2.getAverageRating();
	});
	return series.front();
}

Film Database::getSimilarFilm(Film film) 
{
	// funzione che confronta due film e restituisce true se sono simili, ad esempio se hanno lo stesso genere
	auto isSimilar = [&film](Film& f) 
	{
		return f.getGenre() == film.getGenre();
	};
	// Utilizza la funzione find_if per cercare il primo film simile
	auto it = std::find_if(films.begin(), films.end(), isSimilar);
	// Se viene trovato, restituisci il film successivo, altrimenti restituisci il primo film del database
	return it != films.end() ? *(++it) : films[0];
}

// Restituisce una serie simile a quella data
//funzione che confronta due serie e restituisce true se sono simili, ad esempio se hanno lo stesso genere
Serie Database::getSimilarSerie(Serie serie) 
{
	// Iteriamo attraverso le serie del database
	for (auto& s : series) 
	{
		// Se la serie corrente ha lo stesso genere di quella data, la restituiamo
		if (s.getGenre() == serie.getGenre()) 
		{
			return s;
		}
	}
	// Se non abbiamo trovato alcuna serie simile, restituiamo una serie vuota
	return Serie();
}
