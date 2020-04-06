#include "service.h"
#include <iostream>
using namespace std; 
void Service::addCarte(char* titlu, char* autor, char* status)
{
	Carte carte(titlu, autor, status);
	rep.addCarte(carte);
}
void Service::deleteCarte(Carte carte) {
	this->rep.deleteCarte(carte);
}
void Service::updateCarte(Carte& carte)
{
	this->rep.updateCarte(carte);
}
deque<Carte> Service::getAll() {
	return this->rep.getAll();
}
int Service::getSize() {
	return this->rep.size();
}

void Service::imprumut(char* titlu)
{
	char s[30] = "imprumutata";
	deque<Carte> carti = this->rep.getAll();
	for (int i = 0;i < this->rep.size(); i++) {
		if ((strcmp(carti[i].getTitlu(), titlu) == 0) && (strcmp(carti[i].getStatus(),s ) == 1)) {
			carti[i].setStatus(s);
		}
		if ((strcmp(carti[i].getTitlu(), titlu) == 0) && (strcmp(carti[i].getStatus(), s) == 0)) {
			cout << "Cartea nu este disponibila" << endl;
			cout << "Cartile disponibile de la acelasi autor sunt: " << endl;
			for (int j = 0; j < this->rep.size(); j++)
			{
				if ((strcmp(carti[j].getAutor(), carti[i].getAutor()) == 0) && (strcmp(carti[j].getStatus(), s) == 1)) {
					
					cout << carti[j] << endl;
				}
			}
		}
	else {
		cout << "Cartea nu exista" << endl;
		}
	}
}
int Service::findCarte(Carte carte)
{
	return this->rep.findCarte(carte);
}
Service::~Service()
{

}