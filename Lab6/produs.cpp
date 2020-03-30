#include <iostream>
#include <string.h>
#include "Produs.h"

using namespace std;

Produs::Produs() {
	cod = NULL;
	nume = NULL;
	pret = 0;
}

Produs::Produs(const char* cod, const char* nume, int pret)
{
	this->cod = new char[strlen(cod) + 1];
	strcpy_s(this->cod, strlen(cod) + 1, cod);
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->pret = pret;
}
Produs::Produs(const Produs& p)
{
	this->cod = new char[strlen(p.cod) + 1];
	strcpy_s(this->cod, 1 + strlen(p.cod), p.cod);
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(p.nume), p.nume);
	this->pret = p.pret;

}
char* Produs::getNume() {
	return this->nume;
}
char* Produs::getCod() {
	return this->cod;
}
int Produs::getPret()
{
	return this->pret;
}
void Produs::setNume(const char* n)
{
	if (nume)
		delete[] nume;
	nume = new char[strlen(n) + 1];
	strcpy_s(nume, strlen(n) + 1, n);
}
void Produs::setCod(const char* c)
{
	if (cod)
		delete[] cod;
	cod = new char[strlen(c) + 1];
	strcpy_s(cod, strlen(c) + 1, c);
}

void Produs::setPret(int pret) {
	this->pret = pret;
}

Produs& Produs:: operator=(const Produs& p)
{
	if (this == &p)
		return *this;
	if (nume) delete[] nume;
	nume = new char[strlen(p.nume) + 1];
	strcpy_s(nume, strlen(p.nume) + 1, p.nume);
	if (cod) delete[] cod;
	cod = new char[strlen(p.cod) + 1];
	strcpy_s(cod, strlen(p.cod) + 1, p.cod);
	pret = p.pret;
	return *this;
}
bool Produs:: operator == (const Produs& p)
{
	if (strcmp(nume, p.nume) == 0 && strcmp(cod, p.cod) == 0 && pret == p.pret)
		return true;
	return false;

}
Produs::~Produs() {
	if (this->nume != NULL)
		delete[] nume;
	this->nume = NULL;
	if (this->cod != NULL)
		delete[] cod;
	this->cod = NULL;
	pret = 0;
}
ostream& operator<<(ostream& os, const Produs& p)
{
	os << "Produs - " << p.cod << "-" << p.nume << "-" << p.pret;
	return os;
}