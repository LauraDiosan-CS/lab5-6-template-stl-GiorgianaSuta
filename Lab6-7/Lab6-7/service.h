#pragma once
#include "RepoFile.h"
#include "repo.h"


class Service {
private:
	
	Repo<Carte> rep;
public:
	deque<Carte> getAll();
	int getSize();
	void addCarte(char* titlu, char* autor, char* status);
	void deleteCarte(Carte c);
	void updateCarte(Carte& c);
	
	int findCarte(Carte c);
	void imprumut(char*);
	~Service();

};