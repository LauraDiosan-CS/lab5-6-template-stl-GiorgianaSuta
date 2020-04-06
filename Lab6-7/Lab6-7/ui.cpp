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
	char autor[100];
	cout << " Autorul este: ";
	cin >> autor;
	char status[100];
	cout << "Statusul  este: " << endl;
	cin >> status;
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
	this->service.updateCarte(cartenoua);
}

void UI::afisare() {
	int n = this->service.getSize();
	deque<Carte> carti = this->service.getAll();
	for (int i = 0; i < n; i++)
		cout << carti[i] << endl;
}
void UI::imprumutat() {
	char* titlu = new char[100];
	cout << " Titlul  cartii de imprumutat este:  " << endl;
	cin >> titlu;
	this->service.imprumut(titlu);
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
			this->afisare();
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
		{
			this->imprumutat();
			
		}
		if (optiune == 0)
			break;
	}
}