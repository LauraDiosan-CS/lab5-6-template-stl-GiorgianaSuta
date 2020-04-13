#pragma once
#include "repo.h"
#include "RepoFile.h"

class Service {
private:
	RepoFile<Carte> rep;
public:
	Service();
	Service(RepoFile<Carte>& rep);

	deque<Carte> getAll();
	int getSize();
	void addCarte(char* titlu, char* autor, char* status);
	void deleteCarte(Carte c);
	void updateCarte(Carte& c, Carte & newC);
	int findCarte(Carte c);
	void setRepo(const RepoFile<Carte>&);
	void imprumut(char* titlu, char* autor);
	void returnare(char* titlu);
	deque<Carte> filtrareAutor(char* autor);
	~Service();

};