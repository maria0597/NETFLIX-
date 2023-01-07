#ifndef FILM_H
# define FILM_H

# include <string>
# include <vector>

class Film 
{
	private:
		std::string title;
		std::string genre;
		int duration;
		std::vector<double> ratings;
	public:

		// Costruttore di default 
		Film() {}

		// Costruttore
		Film(std::string title, std::string genre, int duration);

		// Restituisce il titolo del film
		std::string getTitle() const;

		// Restituisce il genere del film
		std::string getGenre();

		// Restituisce la durata del film in minuti
		int getDuration();

		// Aggiunge un voto al film
		void addRating(double rating);
		std::vector<double>& getRatings();

		// Restituisce la media dei voti del film
		double getAverageRating();

		// Operatori di confronto
		bool operator==(const Film& other) const;
		bool operator!=(const Film& other) const;

		// Costruttore di copia
		Film(const Film& other);

		// Operatore di assegnamento
		Film& operator=(const Film& other);
};

#endif // FILM_H
