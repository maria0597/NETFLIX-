#include <algorithm>
#include <numeric>
#include "film.h"

// Costruttore
Film::Film(std::string title, std::string genre, int duration) : title(title), genre(genre), duration(duration) {}

// Restituisce il titolo del film
std::string Film::getTitle() const
{
	return title;
}

// Restituisce il genere del film
std::string Film::getGenre()  
{
	return genre;
}

// Restituisce la durata del film in minuti
int Film::getDuration() 
{
	return duration;
}

// Aggiunge un voto al film
void Film::addRating(double rating) 
{
	ratings.push_back(rating);
}

std::vector<double>& Film::getRatings() 
{
	return ratings;
}

// Restituisce la media dei voti del film
double Film::getAverageRating() 
{
	// Se il film non ha voti, restituisce 0
	if (ratings.empty()) {
		return 0;
	}
	// Somma tutti i voti
	int sum = 0;
	for (int r : ratings) {
		sum += r;
	}
	// Restituisce la media
	return static_cast<double>(sum) / ratings.size();
}

bool Film::operator==(const Film& other) const
{
	// Confronta il titolo, il genere e il numero di stagioni della serie
	return title == other.title && genre == other.genre && duration == other.duration;
}

bool Film::operator!=(const Film& other) const
{
	return !(*this == other);
}

// Costruttore di copia
Film::Film(const Film& other) 
{
// Copia il titolo, il genere e il voto del film
	title = other.title;
	genre = other.genre;
	ratings = other.ratings;
}

Film& Film::operator=(const Film& other) 
{
	// Controlla che l'oggetto non venga assegnato a se stesso
	if (this == &other) 
		return *this;
	// Copia il titolo, il genere, il numero di stagioni e il vettore dei voti
	title = other.title;
	genre = other.genre;
	duration = other.duration;
	ratings = other.ratings;

	return *this;
}
