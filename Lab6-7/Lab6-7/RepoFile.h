#pragma once
#include "repo.h"
#include <fstream>
#include <string>
#include <deque>

template<class T>

class RepoFile :public Repo<Carte> {
	char* fileNameIn;
	char* fileNameOut;

public:
	RepoFile();
	RepoFile(const char* fileNameIn, const char* fileNameOut);
	void load_from_file();
	void saveToFile(const char*);
	void addCarte(Carte);
	void deleteCarte(Carte);
	void updateCarte(Carte, Carte);
	void setFileIn(const char* fileNameIn);
	void setFileOut(const char* fileNameOut);
	~RepoFile();
};
template<class T>
RepoFile<T>::RepoFile() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}
template<class T>
RepoFile<T>::RepoFile(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->load_from_file();

}
template<class T>
void RepoFile<T>::setFileIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}
template <class T>
void RepoFile<T>::setFileOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

template<class T>
void RepoFile<T>::load_from_file()
{
	if (this->fileNameIn != NULL)
	{
		this->carti.clear();
		ifstream f(this->fileNameIn);
		T element;
		while (f >> element)
		{
			this->addCarte(element);
		}
		f.close();
	}
}

template<class T>
 void RepoFile<T>::addCarte(Carte c)
{
	Repo<T>::addCarte(c);
	saveToFile(fileNameOut);
}
 template<class T>
 inline void RepoFile<T>::deleteCarte(Carte c)
 {
	 Repo<T>::deleteCarte(c);
	 saveToFile(fileNameOut);
 }
 template<class T>
 inline void RepoFile<T>::updateCarte(Carte c, Carte c1)
 {
	 Repo<T>::updateCarte(c, c1);
	 saveToFile(fileNameOut);
 }
 template<class T>
 void RepoFile<T>::saveToFile(const char* fileNameOut) {
	 if (fileNameOut != NULL)
	 {
		 ofstream f(fileNameOut);
		 for (size_t i = 0; i < this->carti.size(); i++)
		 {
			 f << this->carti[i] << endl;
		 }
		 f.close();
	 }
 }

template<class T>
RepoFile<T>::~RepoFile(){}