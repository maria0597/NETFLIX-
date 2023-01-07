#include "netflix.h"

int main()
{
	Database db;
	//std::vector<Account> accounts;
	Account* activeAccount = nullptr; // Account attivo inizialmente nullptr
	std::vector<Account> accounts = loadAccountsFromFile("accounts.txt");

	// Crea i film
	Film film1("film1", "comico", 120);
	Film film2("film2", "comico", 110);
	Film film3("film3", "azione", 115);
	Film film4("film4", "comico", 119);
	Film film5("film5", "azione", 190);
	Film film6("film6", "thriller", 60);
	Film film7("film7", "Genere film 3", 130);
	Film film8("film8", "fantasy", 110);
	Film film9("film9", "thriller", 120);
	Film film10("film10", "thriller", 130);

	// Aggiungi i film al database
	db.addFilm(film1);
	db.addFilm(film2);
	db.addFilm(film3);
	db.addFilm(film4);
	db.addFilm(film5);
	db.addFilm(film6);
	db.addFilm(film7);
	db.addFilm(film8);
	db.addFilm(film9);
	db.addFilm(film10);

	// Crea le serie TV
	Serie serie1("serie1", "fantasy", 5);
	Serie serie2("serie2", "comico", 3);
	Serie serie3("serie3", "fantasy", 6);
	Serie serie4("serie4", "fantasy", 2);
	Serie serie5("serie5", "thriller", 4);
	Serie serie6("serie6", "thriller", 7);
	Serie serie7("serie7", "azione", 9);
	Serie serie8("serie8", "comico", 1);
	Serie serie9("serie9", "comico", 3);
	Serie serie10("serie10", "azione", 2);

	// Aggiungi le serie TV al database
	db.addSerie(serie1);
	db.addSerie(serie2);
	db.addSerie(serie3);
	db.addSerie(serie4);
	db.addSerie(serie5);
	db.addSerie(serie6);
	db.addSerie(serie7);
	db.addSerie(serie8);
	db.addSerie(serie9);
	db.addSerie(serie10);

	// Continua a chiedere all'utente di scegliere tra creare un nuovo account o effettuare il login
	// finché non decide di uscire
	bool loggedIn = false;
	bool createdAccount = false;
	while (!loggedIn && !createdAccount) {
	std::cout << BOLDYELLOW << "Vuoi creare un nuovo account o effettuare il login con un account esistente? (c/l/n) " << RESET;
	char input;
	std::cin >> input;
	if (input == 'l') 
	{
	  // Effettua il login
		std::string email;
		std::string password;
		std::cout << CYAN << "Inserisci email: " << RESET;
		std::cin >> email;
		std::cout << CYAN << "Inserisci password: " << RESET;
		std::cin >> password;

	  // Esegue il login con le credenziali inserite dall'utente
		if (loggedIn = login(email, password, accounts)) 
		{
			std::cout << GREEN << "Login effettuato con successo!" << RESET << std::endl;

			// Salva l'account attivo in un puntatore
			for (auto& account : accounts) {
			  if (account.getEmail() == email && account.getPassword() == password) {
				activeAccount = &account;
				break;
			  }
			}
	 	 } 
		else 
		{
			std::cout << RED << "Nome utente o password errati, riprova." << RESET << std::endl;
			continue;
	  	}
	} 
	else if (input == 'n') 
	{
	  break;
	} 
	else if (input == 'c') 
	{
	  // L'utente vuole creare un nuovo account
	  std::string email, password, username;
	  std::cout << BOLDMAGENTA << "Crea un nuovo account" << RESET << std::endl;
	  std::cout << CYAN << "Inserisci l'indirizzo email: " << RESET;
	  std::cin >> email;
	  std::cout << CYAN << "Inserisci la password: " << RESET;
	  std::cin >> password;
	  std::cout << CYAN << "Inserisci l'username': " << RESET;
	  std::cin >> username;
	  Account account(email, password, username);

	  // Crea i profili per l'account
	  std::vector<Profilo> profiles;
	  for (int i = 0; i < 4; i++) {
		std::cout << CYAN << "Inserisci il nome del nuovo profilo: " << RESET;
		std::string newProfileName;
		std::cin >> newProfileName;
		Profilo newProfile(newProfileName);
		account.addProfile(newProfile);
		profiles.push_back(newProfile);
	  }
		// Aggiungi l'account appena creato al vettore accounts
		accounts.push_back(account);

		// Salva il vettore accounts nel file
		saveAccountsToFile(accounts, "accounts.txt");
				// Chiedi all'utente se vuole creare altri profili
			while (true) 
			{
				std::cout << YELLOW << "Vuoi creare un altro profilo per questo account? (s/n) " << RESET;
				char input;
				std::cin >> input;
				if (input == 'n') 
				{
				// L'utente ha deciso di uscire
					break;
				} 
				else if (input == 's') 
				{
				// L'utente vuole creare un altro profilo
				if (account.getNumberOfProfiles() < 4)
				{
					std::cout << CYAN << "Inserisci il nome del nuovo profilo: " << RESET;
					std::string newProfileName;
					std::cin >> newProfileName;
					Profilo newProfile(newProfileName);
					account.addProfile(newProfile);
					profiles.push_back(newProfile);
					}
				else
				{
					std::cout << RED << "Hai già raggiunto il massimo numero di profili per questo account" << RESET << std::endl;
				}
			}
		}
		db.addAccount(account);
		saveAccountsToFile(accounts, "accounts.txt");
		std::cout << GREEN << "Account creato con successo!" << RESET << std::endl;
		}
	}

// Seleziona il profilo attivo
while (true)
{
	std::cout << BLUE << "Seleziona il profilo attivo:"  << RESET << std::endl;
	for (unsigned int i = 0; i < activeAccount->getNumberOfProfiles(); i++)
	{
		std::cout << i+1 << ". " << activeAccount->getProfile(i).getName() << std::endl;
	}
	int profileSelection;
	std::cin >> profileSelection;
	if (std::cin.fail() || profileSelection < 1 || profileSelection > activeAccount->getNumberOfProfiles())
	{
		std::cout << RED << "Selezione non valida, riprova." << std::endl;
		std::cin.clear(); // pulisce il flag di errore di cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // elimina l'input non valido dallo stream
	}
	else
	{
		activeAccount->setActiveProfile(activeAccount->getProfile(profileSelection - 1));
		break;
	}
}

// Una volta che l'utente ha selezionato un profilo valido, possiamo uscire dal loop

	// Mostra il menu principale
	while (true)
	{
		std::cout << BOLDYELLOW << "Menu:" << RESET << std::endl;
		std::cout << GREEN << "1. Aggiungi un film" << RESET << std::endl;
		std::cout << GREEN << "2. Aggiungi una serie" << RESET << std::endl;
		std::cout << GREEN << "3. Cerca un film" << RESET << std::endl;
		std::cout << GREEN << "4. Cerca una serie" << RESET << std::endl;
		std::cout << GREEN << "5. Valuta film o serie" << RESET << std::endl;
		std::cout << GREEN << "6. Visualizza il film più apprezzato al momento" << RESET << std::endl;
		std::cout << GREEN << "7. Visualizza la serie più apprezzata al momento" << RESET << std::endl;
		std::cout << GREEN << "8. Cerca un film simile" << RESET << std::endl;
		std::cout << GREEN << "9. Cerca una serie simile" << RESET << std::endl;
		std::cout << GREEN << "10. Esci" << RESET << std::endl;
		std::cout << GREEN << "Inserisci la tua scelta: " << RESET;

		// Legge la scelta dell'utente
    	int choice;
    	std::cin >> choice;

		switch (choice){
		case 1:	
		{
			// Aggiungi un film
			std::string title;
			std::string genre;
			int duration;
			std::cout << CYAN << "Inserisci il titolo del film: " << RESET;
			std::cin >> title;
			std::cout << CYAN << "Inserisci il genere del film: " << RESET;
			std::cin >> genre;
			std::cout << CYAN << "Inserisci la durata del film (in minuti): " << RESET;
			std::cin >> duration;
			db.addFilm(Film(title, genre, duration));
			break;
		}
		case 2:
		{
			// Aggiungi una serie
			std::string title;
			std::string genre;
			int numSeasons;
			std::cout << CYAN << "Inserisci il titolo della serie: " << RESET;
			std::cin >> title;
			std::cout << CYAN << "Inserisci il genere della serie: " << RESET;
			std::cin >> genre;
			std::cout << CYAN << "Inserisci il numero di stagioni della serie: " << RESET;
			std::cin >> numSeasons;
			Serie newSerie(title, genre, numSeasons);
			db.addSerie(newSerie);
			break;
		}
		case 3:
		{
			// L'utente ha scelto l'opzione "Cerca film"
			std::cout << CYAN << "Inserisci il titolo del film da cercare: " << RESET;
			std::string title;
			std::cin >> title;

			// Cerca il film nel database
			Film* film = db.findFilm(title);
			if (film == nullptr) {
			std::cout << CYAN << "Film non trovato!" << std::endl << RESET;
			} else {
			// Chiedi all'utente se vuole vedere il film
			std::cout << CYAN << "Vuoi vedere il film " << film->getTitle() << "? (S/N) " << RESET;
			char watchChoice;
			std::cin >> watchChoice;
			if (watchChoice == 'S' || watchChoice == 's') {
			// Chiamo il metodo watchFilm del profilo dell'account attivo
			activeAccount->getProfile(0).watchFilm(*film);
			}
		}
		break;
		}
		case 4:
		{
			// L'utente ha scelto l'opzione "Cerca serie"
			std::cout << CYAN << "Inserisci il titolo della serie da cercare: " << RESET;
			std::string title;
			std::cin >> title;

			// Cerca la serie nel database
			Serie* serie = db.findSerie(title);
			if (serie == nullptr) {
			std::cout << CYAN << "Serie non trovata!" << std::endl << RESET;
			} else {
			// Chiedi all'utente se vuole vedere la serie
			std::cout << CYAN << "Vuoi vvedere la serie " << serie->getTitle() << "? (S/N) " << RESET;
			char input;
			std::cin >> input;
			if (input == 'S' || input == 's') {
			// L'utente vuole vedere la serie
			activeAccount->getProfile(0).watchSerie(*serie);
			}
		}
		break;
		}
		case 5:
		{
			std::cout <<BOLDYELLOW << "Vuoi valutare un film o una serie? (f/s) " << RESET;
  			char input;
  			std::cin >> input;
  			if (input == 'f') 
			{
				// Chiede all'utente il nome del film da valutare
				std::cout << CYAN << "Inserisci il nome del film: " << RESET;
				std::string filmName;
				std::cin >> filmName;
				// Cerca il film nel database
				Film* film = db.findFilm(filmName);
				if (!film) 
				{
				  std::cout << RED << "Film non trovato." << std::endl << RESET;
				  return 1;
				}
				// Chiede all'utente il rating da assegnare al film
				std::cout << CYAN << "Inserisci il tuo rating (da 1 a 5): " << RESET;
				int rating;
				std::cin >> rating;
				// Assegna il rating al film
				activeAccount->getActiveProfile().setFilmRating(*film, rating);
  				}
				else if (input == 's') 
				{
				// Chiede all'utente il nome della serie da valutare
				std::cout << CYAN << "Inserisci il nome della serie: " << RESET;
				std::string serieName;
				std::cin >> serieName;
				// Cerca la serie nel database
				Serie* serie = db.findSerie(serieName);
				if (!serie) 
				{
				  std::cout << RED << "Serie non trovata." << std::endl << RESET;
	  				return 1 ; 
				}
				// Chiede all'utente il rating da assegnare alla serie
				std::cout << CYAN << "Inserisci il tuo rating (da 1 a 5): " << RESET;
				int rating;
				std::cin >> rating;
				// Assegna il rating alla serie
				activeAccount->getActiveProfile().setSerieRating(*serie, rating);
				break;
			}
		}
		// L'utente vuole visualizzare il film più apprezzato al momento
			case 6: 
			{
				Film topFilm = db.getTopFilm();
				std::cout << BOLDMAGENTA << "Il film più apprezzato al momento è: " << topFilm.getTitle() << RESET << std::endl;
				break;
			}

		// L'utente vuole visualizzare la serie più apprezzata al momento
			case 7: 
			{
				Serie topSerie = db.getTopSerie();
				std::cout << BOLDMAGENTA << "La serie più apprezzata al momento è: " << topSerie.getTitle() << RESET << std::endl;
				break;
			}
		// L'utente vuole cercare un film simile a un altro film
			case 8:  
			{
				std::cout << GREEN << "Inserisci il titolo del film di riferimento: " << RESET;
				std::string title;
				std::cin >> title;

				// Trova il film con il titolo specificato
				Film film;	
				bool found = false;
				for (auto& f : db.getFilms()) 
				{
					if (f.getTitle() == title) 
					{
						film = f;
						found = true;
						break;
					}	
				}
				if (found) 
				{
					Film similarFilm = db.getSimilarFilm(film);
					std::cout << BOLDMAGENTA << "Il film consigliato è: " << similarFilm.getTitle() << RESET << std::endl;
				} 
				else 
				{
					std::cout << RED << "Film non trovato" << RESET << std::endl;
					break;
				}
				break;
			}
		// L'utente vuole cercare una serie simile a un'altra serie
			case 9: 
			{
				std::cout << GREEN << "Inserisci il titolo della serie di riferimento: " << RESET;
				std::string title;
				std::cin >> title;

				Serie serie;
				bool found = false;
				for  (auto& s : db.getSerie()) 
				{
					if (s.getTitle() == title) 
					{
						serie = s;
						found = true;
						break;
					}
				}
				if (found) 
				{
					Serie similarSerie = db.getSimilarSerie(serie);
					std::cout << BOLDMAGENTA << "La serie consigliata è: " << similarSerie.getTitle() << RESET << std::endl;
				}
				else 
				{
					std::cout << RED << "Serie non trovata" << RESET << std::endl;
					break;
				}
				break;
			}
		// L'utente vuole uscire
			case 10:  
			{
				std::cout << BOLDYELLOW << "Arrivederci!" << RESET << std::endl;
				return 0;
			}

/*Il main continua con il default case dello switch, 
che stampa un messaggio di errore per indicare che 
l'opzione scelta dall'utente non è valida. Quindi, 
il programma esce dallo switch e torna all'inizio del ciclo while. 
Il ciclo while continuerà a ripetersi finché l'utente non sceglierà 
l'opzione "Esci" (case 6), al quale punto il programma terminerà l'esecuzione 
e ritornerà il valore 0 a indicare che il programma è stato eseguito con successo.*/
			default:
            std::cout << "Scelta non valida, riprova." << std::endl;
            break;
		}
	}
}