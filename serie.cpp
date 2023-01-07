#include "serie.h"
#include <algorithm>
#include <numeric>

// Costruttore
Serie::Serie(std::string title, std::string genre, int numberOfSeasons) : title(title), genre(genre), numberOfSeasons(numberOfSeasons), ratings() {}

// Restituisce il titolo della serie
std::string Serie::getTitle() const
{
	return title;
}

// Restituisce il genere della serie
std::string Serie::getGenre() 
{
	return genre;
}

// Aggiunge un voto alla serie
void Serie::addRating(double rating) 
{
	ratings.push_back(rating);
}

int Serie::getSeasons() 
{
	// Restituisce il numero di stagioni della serie
	return numberOfSeasons;
}

std::vector<double>& Serie::getRatings() 
{
	return ratings;
}

// Restituisce il voto medio della serie
double Serie::getAverageRating() 
{
	if (ratings.empty()) 
	{
		return 0;
	}
	// Utilizza la funzione accumulate per calcolare la somma di tutti i voti
	// e divide il risultato per il numero di voti
	return std::accumulate(ratings.begin(), ratings.end(), 0.0) / ratings.size();
}
/*
bool Serie::operator==(Serie& other) const
{
	if (this->title == other.title)
		return true;
	return false;
}

bool Serie::operator!=(Serie& other) const
{
	if (this->title != other.title)
		return true;
	return false;
}
*/
bool Serie::operator==(const Serie& other) const 
{
	// Confronta il titolo, il genere e il numero di stagioni della serie
	return title == other.title && genre == other.genre && numberOfSeasons == other.numberOfSeasons;
}

bool Serie::operator!=(const Serie& other) const
{
	return !(*this == other);
}

// Costruttore di copia
Serie::Serie(const Serie& other) 
{
// Copia il titolo, il genere e il voto del film
	title = other.title;
	genre = other.genre;
	numberOfSeasons = other.numberOfSeasons;
	ratings = other.ratings;
}

Serie& Serie::operator=(const Serie& other) 
{
	// Controlla che l'oggetto non venga assegnato a se stesso
	if (this == &other) 
		return *this;
	// Copia il titolo, il genere, il numero di stagioni e il vettore dei voti
	title = other.title;
	genre = other.genre;
	numberOfSeasons = other.numberOfSeasons;
	ratings = other.ratings;

	return *this;
}
