#include "account.h"

// Costruttore
Account::Account(std::string email, std::string password, std::string username)
: email(email), password(password), username(username) {}

std::string Account::getEmail() const
{
return this->email;
}

std::string Account::getPassword() const
{
return this->password;
}

std::string Account::getUsername() const
{
return this->username;
}

// Aggiunge un nuovo profilo all'account
void Account::addProfile(Profilo profile)
{
this->profiles.push_back(profile);
}

// Imposta il profilo attivo
void Account::setActiveProfile(Profilo& profile)
{
	activeProfile = profile;
}

// Restituisce il numero di profili associati all'account
unsigned int Account::getNumberOfProfiles()
{
	return profiles.size();
}

Profilo& Account::getProfile(unsigned int index)
{
	return profiles[index];
}

Profilo& Account::getActiveProfile()
{
		return activeProfile;
}

std::string Account::toString() const
{
		return "Nome utente: " + username + "\nNumero di profili: " + std::to_string(profiles.size());
}

const std::vector<Profilo>& Account::getProfiles() const
{
		return profiles;
}

// Verifica se la password inserita è corretta
bool Account::checkPassword(std::string password) const
{
return this->password == password;
}

// Aggiunge un film alla watchlist del profilo attivo
void Account::addFilmToWatchlist(const Film& film)
{
activeProfile.addFilmToWatchlist(film);
}

// Aggiunge una serie alla watchlist del profilo attivo
void Account::addSerieToWatchlist(const Serie& serie)
{
activeProfile.addSerieToWatchlist(serie);
}

// Restituisce la watchlist dei film del profilo attivo
std::vector<Film> Account::getWatchlistFilms() const
{
return activeProfile.getWatchlistFilms();
}

// Restituisce la watchlist delle serie del profilo attivo
std::vector<Serie> Account::getWatchlistSeries() const
{
return activeProfile.getWatchlistSeries();
}

// Implementazione della funzione di login

bool login(const std::string& email, const std::string& password, const std::vector<Account>& accounts) {
	for (const auto& account : accounts) {
		if (account.getEmail() == email && account.getPassword() == password) {
			return true;
		}
	}
	return false;
}

// Implementazione della funzione per il caricamento degli account da file
std::vector<Account> loadAccountsFromFile(const std::string& filename) 
{
	std::vector<Account> accounts;
	std::ifstream file(filename);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string email, password, username;
			if (iss >> email >> password >> username) {
				accounts.emplace_back(email, password, username);
			}
		}
	}
	return accounts;
}

void saveAccountsToFile(std::vector<Account>& accounts, const std::string& fileName)
{
		std::ofstream out;

		out.open(fileName, std::ios_base::out | std::ios_base::trunc);
		// Scrivi gli account nel file
		for (auto& account : accounts)
		{
				// Scrivi l'email, la password e l'username dell'account nel file
				out << account.getEmail() << " " << account.getPassword() << " " << account.getUsername() << " " << account.getNumberOfProfiles() << std::endl;

				// Scrivi i profili dell'account nel file
				for (auto& profile : account.getProfiles())
				{
						out << profile.getName() << std::endl;
						out << profile.getFilms().size() << std::endl;
						// Scrivi i film visti dal profilo nel file
						for (auto film : profile.getFilms())
						{
								out << film.getTitle() << " " << film.getGenre() << " " << film.getDuration() << " " << film.getAverageRating() << std::endl;
						}

						out << profile.getSeries().size() << std::endl;
						// Scrivi le serie viste dal profilo nel file
						for (auto serie : profile.getSeries())
						{
								out << serie.getTitle() << " " << serie.getGenre() << " " << serie.getAverageRating() << std::endl;
						}
				}
		}
		out.close();
}
