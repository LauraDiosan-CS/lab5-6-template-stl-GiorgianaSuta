#include <iostream>
#include "Carte.h"

#include "repo.h"

using namespace std;

void menu() {
	cout << "1. Adauga produs" << endl;
	cout << "2. Afisarea produse " << endl;
	cout << "0. Exit" << endl;
}

int main() {
	//test();
	Repo<Carte> rep;
	bool gata = false;
	while (!gata)
	{
		cout << endl;
		cout << "Optiuni:" << endl;
		cout << "1. Adauga carte" << endl;
		cout << "2. Afisare carti " << endl;
		cout << "0. Exit!" << endl;
		cout << "Introduceti opiunea:" << endl;
		int optiune;
		cin >> optiune;
		if (optiune == 1)
		{
			char titlu[100];
			cout << " Ttilul este:  " << endl;
			cin >> titlu;
			char autor[100];
			cout << " Autorul este: ";
			cin >> autor;
			char status[100];
			cout << "Statusul  este: " << endl;
			cin >> status;
			Carte c1(titlu, autor, status);
			rep.addCarte(c1);
		}
		if (optiune == 2)
		{
			int n = rep.size();
			deque<Carte> carti = rep.getAll();
			for (int i = 0; i < n; i++)
				cout << carti[i] << endl;
		}
		if (optiune == 0)
		{
			gata = true;
			cout << "Bye bye";
		}
	}
}