#include <iostream>
#include "Produs.h"
#include "test.h"
#include "repo.h"

using namespace std;

void menu() {
	cout << "1. Adauga produs" << endl;
	cout << "2. Afisarea produse " << endl;
	cout << "0. Exit" << endl;
}

int main() {
	test();
	Repo rep;
	int n = rep.size();
	bool gata = false;
	while (!gata)
	{
		cout << endl;
		cout << "Optiuni:" << endl;
		cout << "1. Adauga produs" << endl;
		cout << "2. Afisare produse " << endl;
		cout << "0. Exit!" << endl;
		cout << "Introduceti opiunea:" << endl;
		int optiune;
		cin >> optiune;
		if (optiune == 1)
		{
			char cod[100];
			cout << " Codul este:  " << endl;
			cin >> cod;
			char nume[100];
			cout << " Numele este: ";
			cin >> nume;
			int pret;
			cout << "Pretul este: " << endl;
			cin >> pret;
			Produs p1(cod, nume, pret);
			rep.addProdus(p1);
		}
		if (optiune == 2)
		{
			vector<Produs> produse = rep.getAll();
			for (Produs p : produse)
				cout << p;
		}
		if (optiune == 0)
		{
			gata = true;
			cout << "Bye bye";
		}
	}
}