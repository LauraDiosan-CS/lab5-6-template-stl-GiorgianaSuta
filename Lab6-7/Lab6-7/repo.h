#pragma once
#include "Carte.h"
#include <deque>
#include <ostream>
#include <fstream>
using namespace std;
template<class T>
class Repo {
protected:
	deque<T> carti;

public:
	Repo();
	void addCarte(T);
	void deleteCarte(T);
	void updateCarte(T& c, T &newC);
	int findCarte(T);
	deque<T> getAll();
	~Repo();
	int size();
};
template<class T>
Repo<T>::Repo() {

}

template<class T>
void Repo<T>::addCarte(T carte)
{
	this->carti.push_back(carte);
	
}

template<class T>
void Repo<T>::deleteCarte(T carte) {
	deque<Carte>::iterator it;
	it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end()) {
		carti.erase(it);
	}

}

template<class T>
int Repo<T>::findCarte(T carte) {
	for (int i = 0; i < this->size(); i++)
	{
		if (carti[i] == carte)
			return i;
	}
	return -1;
}

template<class T>
void Repo<T>::updateCarte(T& carte, T & newC) {
	deque<Carte>::iterator it;
	it = find(carti.begin(), carti.end(), carte);
	if (it != carti.end())
	{
		(*it) = newC;
	}
	
}

template<class T>
int Repo<T>::size() {
	return carti.size();
}
template<class T>
deque<T> Repo<T>::getAll() {
	return carti;
	return deque<T>();
}



template<class T>
Repo<T>::~Repo() {}
