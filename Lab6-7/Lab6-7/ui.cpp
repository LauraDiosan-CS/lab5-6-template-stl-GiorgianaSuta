#include "ui.h"
#include <iostream>
#include <string>
#include "functii.h"

using namespace std;

void UI::addCarte() {
	char titlu[100];
	cout << " Titlul este:  " << endl;
	cin >> titlu;
	char autor[100];
	cout << " Autorul este: ";
	cin >> autor;
	char status[100];
	cout << "Statusul  este: " << endl;
	cin >> status;
	this->service.addCarte(titlu, autor, status);
}

void UI::deleteCarte() {
	char titlu[100];
	cout << " Titlul este:  " << endl;
	cin >> titlu;
	char autor[2] = "";
	char status[2] = "";
	Carte carte(titlu, autor, status);
	this->service.deleteCarte(carte);
}
void UI::updateCarte() {
	char* titlunou = new char[100];
	char* autor = new char[100];
	char* status = new char[10];
	cout << " Titlul  este:  " << endl;
	cin >> titlunou;
	cout << " Autorul nou este: ";
	cin >> autor;
	cout << "Statusul nou  este: " << endl;
	cin >> status;
	Carte cartenoua(titlunou, autor, status);
	this->service.updateCarte(cartenoua, cartenoua);
}

void UI::afisare() {
	deque<Carte> carti = service.getAll();
	for (Carte c : carti)
		cout << c << endl;
}
void UI::setService(const Service& s)
{
	service = s;
}
void UI::imprumut() {
	char titlu[100];
	cout << "Dati titlul cartii de imprumutat: " << endl;
	cin >> titlu;
	char autor[100];
	cout << "Dati autorul :" << endl;
	cin >> autor;
	service.imprumut(titlu,autor);

}
void UI::returnare() {
	char titlu[100];
	cout << "Dati titlul cartii pe care vreti sa o returnati: " << endl;
	cin >> titlu;
	service.returnare(titlu);
}
void UI::run() {
	int optiune;
	bool ok = true;
	while (ok == true)
	{
		cout << endl << "Optiunile sunt:" << endl;
		menu();
		cout << "Optiunea este: " << endl;
		cin >> optiune;
		if (optiune == 1) {
			this->addCarte();
			//this->afisare();
		}
		if (optiune == 2)
			this->afisare();
		if (optiune == 3) {
			this->deleteCarte();
			this->afisare();
		}
		if (optiune == 4) {
			this->updateCarte();
			this->afisare();
		}
		if (optiune == 5)
			this->imprumut();
		if (optiune == 6)
		{
			this->returnare();
		}
		if (optiune == 0)
			break;
	}
}