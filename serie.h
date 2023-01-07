#ifndef SERIE_H
# define SERIE_H

# include <string>
# include <vector>

class Serie 
{
	private:
		std::string title;
		std::string genre;
		int numberOfSeasons;
		std::vector<double> ratings;
		
	public:
		// Costruttore di default 
		Serie() {}

		// Costruttore
		Serie(std::string title, std::string genre, int numberOfSeasons);
		
		// Aggiunge un voto alla serie
		void addRating(double rating);

		// Restituisce il voto medio della serie
		double getAverageRating();

		// Restituisce il titolo, il genere e il numero di stagioni della serie
		std::string getTitle() const;
		std::string getGenre();
		int getSeasons();
		std::vector<double>& getRatings();
   
	// Operatori di confronto
	bool operator==(const Serie& other) const;
	bool operator!=(const Serie& other) const;

	// Costruttore di copia
	Serie(const Serie& other);

	// Operatore di assegnamento
	Serie& operator=(const Serie& other);
};

#endif // SERIE_H
