#include "Produs.h"
#include <iostream>
#include <string>

int Produs::nextId = 1;

// destructor
Produs::~Produs() {
	if (this->denumire != NULL) {
		delete[] this->denumire;
	}
	if (this->continut != NULL) {
		delete[] this->continut;
	}
}

// constructor fara parametri
Produs::Produs() :idProdus(nextId++) {
	this->denumire = new char[strlen("NA") + 1];
	strcpy_s(this->denumire, strlen("NA") + 1, "NA");
	this->pret = 0.0;
	this->continut = new char[strlen("NA") + 1];
	strcpy_s(this->continut, strlen("NA") + 1, "NA");
	this->inStoc = false;
}

// constructor cu toti parametrii
Produs::Produs(char* denumire, float pret, char* continut, bool inStoc) :idProdus(nextId++) {
	this->denumire = denumire;
	this->pret = pret;
	this->continut = continut;
	this->inStoc = inStoc;
}

// constructorul de copiere
Produs::Produs(const Produs& p) :idProdus(nextId++) {
	if (this != &p)
	{
		if (p.denumire != NULL) {
			delete[]p.denumire;
			denumire = new char[strlen(p.denumire) + 1];
			strcpy_s(denumire, strlen(p.denumire) + 1, p.denumire);
		}
		pret = p.pret;
		inStoc = p.inStoc;
		if (p.continut != NULL) {
			delete[]p.continut;
			continut = new char[strlen(p.continut) + 1];
			strcpy_s(continut, strlen(p.continut) + 1, p.continut);
		}
	}
}

// getteri si setteri
int Produs::getIdProdus() const {
	return this->idProdus;
}

char* Produs::getDenumire() {
	return this->denumire;
}

float Produs::getPret() {
	return this->pret;
}

char* Produs::getContinut() {
	return this->continut;
}

bool Produs::getInStoc() {
	return this->inStoc;
}

void Produs::setDenumire(char* denumire) {
	if (this->denumire != NULL) {
		delete[] this->denumire;
	}
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
}

void Produs::setPret(float pret) {
	this->pret = pret;
}

void Produs::setContinut(char* continut) {
	if (this->continut != NULL) {
		delete[] this->continut;
	}
	this->continut = new char[strlen(continut) + 1];
	strcpy_s(this->continut, strlen(continut) + 1, continut);
}


void Produs::setInStoc(bool inStoc) {
	this->inStoc = inStoc;
}

// operator =
Produs& Produs::operator=(const Produs& p) {
	if (this != &p) {
		//	idProdus = p.idProdus;
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);

		this->pret = p.pret;

		if (this->continut != NULL) {
			delete[] continut;
		}

		this->continut = new char[strlen(p.continut) + 1];
		strcpy_s(this->continut, strlen(p.continut) + 1, p.continut);

		this->inStoc = p.inStoc;
	}

	return *this;
}

istream& operator>>(istream& in, Produs& p) {
	const int MAX_LENGTH = 100; // Adjust the size according to your requirements
	char denumire[MAX_LENGTH]; // Temporary buffer to store input

	float pret;
	char continut[MAX_LENGTH]; // Temporary buffer to store input
	bool inStoc;

	cout << "Denumire: ";
	in >> denumire;

	cout << "Pret: ";
	in >> pret;

	cout << "Continut: ";
	in >> continut;

	cout << "In stoc (1 for true, 0 for false): ";
	in >> inStoc;

	// Set the values read from input to the Produs object
	p.setDenumire(_strdup(denumire));
	p.setPret(pret);
	p.setContinut(_strdup(continut));
	p.setInStoc(inStoc);

	return in;
}

// operator <<
ostream& operator<<(ostream& out, const Produs& p) {
	out << "ID: " << p.getIdProdus() << endl;
	out << "Denumire: " << p.denumire << endl;
	out << "Pret: " << p.pret << endl;
	out << "Continut: " << p.continut << endl;
	out << "Este in stoc(0-NU, 1-DA): " << p.inStoc << endl;
	return out;
}

bool Produs::operator==(const Produs& prod) const {
	return (idProdus == prod.idProdus &&
		denumire == prod.denumire &&
		pret == prod.pret &&
		inStoc == prod.inStoc &&
		strcmp(continut, prod.continut) == 0);
}