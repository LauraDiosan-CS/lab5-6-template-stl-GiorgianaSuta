#include <iostream>
#include <string.h>
#include "carte.h"

using namespace std;

Carte::Carte() {
	titlu = NULL;
	autor = NULL;
	status = NULL;
}

Carte::Carte(const char* titlu, const char* autor, const char* status)
{
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	this->autor = new char[strlen(autor) + 1];
	strcpy_s(this->autor, strlen(autor) + 1, autor);
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}
Carte::Carte(const Carte& c)
{
	this->titlu = new char[strlen(c.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(c.titlu), c.titlu);
	this->autor = new char[strlen(c.autor) + 1];
	strcpy_s(this->autor, 1 + strlen(c.autor), c.autor);
	this->status = new char[strlen(c.status) + 1];
	strcpy_s(this->status, 1 + strlen(c.status), c.status);

}
char* Carte::getTitlu() {
	return this->titlu;
}
char* Carte::getAutor() {
	return this->autor;
}
char* Carte::getStatus()
{
	return this->status;
}
void Carte::setTitlu(const char* t)
{
	if (titlu)
		delete[] titlu;
	titlu = new char[strlen(t) + 1];
	strcpy_s(titlu, strlen(t) + 1, t);
}
void Carte::setAutor(const char* a)
{
	if (autor)
		delete[] autor;
	autor = new char[strlen(a) + 1];
	strcpy_s(autor, strlen(a) + 1, a);
}

void Carte::setStatus(const char* s)
{
	if (status)
		delete[] status;
	status = new char[strlen(s) + 1];
	strcpy_s(status, strlen(s) + 1, s);
}

Carte& Carte:: operator=(const Carte& c)
{
	if (this == &c)
		return *this;
	if (titlu) delete[] titlu;
	titlu = new char[strlen(c.titlu) + 1];
	strcpy_s(titlu, strlen(c.titlu) + 1, c.titlu);
	if (autor) delete[] autor;
	autor = new char[strlen(c.autor) + 1];
	strcpy_s(autor, strlen(c.autor) + 1, c.autor);
	if (status) delete[] status;
	status = new char[strlen(c.status) + 1];
	strcpy_s(status, strlen(c.status) + 1, c.status);
	return *this;
}
bool Carte:: operator == (const Carte& c)
{
	if (strcmp(titlu, c.titlu) == 0 && strcmp(autor, c.autor) == 0 && strcmp(status, c.status) == 0)
		return true;
	return false;

}
Carte::~Carte() {
	if (this->titlu != NULL)
		delete[] titlu;
	this->titlu = NULL;
	if (this->autor != NULL)
		delete[] autor;
	this->autor = NULL;
	if (this->status != NULL)
		delete[] status;
	this->status = NULL;
}
ostream& operator<<(ostream& os, const Carte& c)
{
	os << "Carte - " << c.titlu << "-" << c.autor << "-" << c.status;
	return os;
}