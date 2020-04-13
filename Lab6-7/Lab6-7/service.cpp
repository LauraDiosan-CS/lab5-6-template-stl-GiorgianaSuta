#include "service.h"
#include <iostream>
#include <string>
using namespace std;
Service::Service() {}
Service::Service(RepoFile<Carte>& repo)
{
	this->rep = repo;
}
void Service::addCarte(char* titlu, char* autor, char* status)
{
	Carte carte(titlu, autor, status);
	rep.addCarte(carte);
}
void Service::deleteCarte(Carte carte) {
	this->rep.deleteCarte(carte);
}
void Service::updateCarte(Carte& carte, Carte & newC)
{
	this->rep.updateCarte(carte, newC);
}
deque<Carte> Service::getAll() {
	deque<Carte> carti = rep.getAll();
	deque<Carte> v(carti.begin(),carti.end());
	return v;
}
int Service::getSize() {
	return this->rep.size();
}

void Service::setRepo(const RepoFile<Carte>& r)
{
	rep = r;
}
int Service::findCarte(Carte carte)
{
	return this->rep.findCarte(carte);
}
deque<Carte> Service::filtrareAutor(char* autor)
{
	deque<Carte> rezultat;
	deque<Carte> carti = rep.getAll();
	char status[20] = "disponibila";
	for (Carte c : carti)
	{
		if ((strcmp(c.getAutor(), autor) == 0) && (strcmp(c.getStatus(), status) == 0))
		{
			rezultat.push_back(c);
		}
	}
	return rezultat;
}
void Service::imprumut(char* titlu, char* autor)
{
	char status[50] = "disponibila";
	Carte c(titlu, autor, status);
	int n = rep.findCarte(c);
	char status2[50] = "imprumutata";
	Carte c2(titlu, autor, status2);
	if (n >= 0 && (strcmp(this->rep.getAll()[n].getStatus(), status)==0))
	{
		rep.updateCarte(c, c2);
		cout << "Cartea a fost imprumutata!";
	}
	else
	{
		deque<Carte> rezultat;
		rezultat = filtrareAutor(autor);
		if (rezultat.size() != 0)
		{
			cout << "Cartile disponibile scrise de acelasi autor sunt: " << endl;
			for (Carte c : rezultat)
				cout << c << " ";
		}
		else
		{
			cout << "Nu exista carti scrise de acest autor" << endl;

		}
	}
}
void Service::returnare(char* titlu)
{
	char status[50] = "imprumutata";
	char status2[50] = "disponibila";
	char autor[2] = "";
	Carte c(titlu, autor, status);
	Carte c2(titlu, autor, status2);
	int n = findCarte(c);
	bool ok = true;
	while (ok == true)
	{
		if (n >= 0 && (strcmp(this->rep.getAll()[n].getStatus(), status) == 0))
		{
			rep.updateCarte(c, c2);
			cout << "Cartea a fost returnata cu succes!" << endl;
			break;
		}
		if (n >= 0 && (strcmp(this->rep.getAll()[n].getStatus(), status2) == 0))
		{
			cout << "Cartea cu titlul: " << titlu << " nu este in prezent imprumutata!" << endl;
			break;
		}
		else {
			cout << "Nu exista nicio carte cu titlul: " << titlu << endl;
			cout << " Dati un alt titlu dd carte: " << endl;
			char titlu1[50];
			cin >> titlu1;

			this->returnare(titlu1);
			ok = false;
		}
	}
	
	
	
}

Service::~Service()
{

}