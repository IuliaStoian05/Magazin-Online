#include "Comanda.h"
#include "Produs.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//initializare membru static
int Comanda::nrProduse = 0;

// destructor
Comanda::~Comanda() {
	if (this->produse != NULL) {
		delete[]this->produse;
	}
	nrProduse--;
}

// constructor fara parametri
Comanda::Comanda() : idComanda(0), produse(NULL), indexProdusCurent(0) {
	produse = NULL;
	nrProduse++;
}

// constructor cu parametri
Comanda::Comanda(Produs* prod) : idComanda(nrProduse++), produse(prod), indexProdusCurent(indexProdusCurent) {
		produse = new Produs(*produse);
	for (int i = 0; i < indexProdusCurent; ++i) {
		this->produse[i] = produse[i];
	}
}

Comanda::Comanda(int id) : idComanda(id), produse(new Produs[nrProduse]) , indexProdusCurent(indexProdusCurent)
{
	produse = new Produs(*produse);
	for (int i = 0; i < indexProdusCurent; i++) {
		this->produse[i] = produse[i];
	}
}

// constructor de copiere
Comanda::Comanda(const Comanda& c) : idComanda(c.idComanda), indexProdusCurent(c.indexProdusCurent) {
    produse = new Produs[nrProduse];
	for (int i = 0; i < indexProdusCurent; ++i) {
		produse[i] = c.produse[i]; 
	}
}


// operator =
Comanda& Comanda::operator=(const Comanda& c) {
	if (this != &c) {
		delete[] c.produse; 
		indexProdusCurent = c.indexProdusCurent;
		produse = new Produs[nrProduse];
		for (int i = 0; i <= indexProdusCurent; ++i) {
			produse[i] = c.produse[i]; 
		}
	}
	return *this;
}

// getter si setter

int Comanda::getNrProduse() {
	return nrProduse;
}

Produs* Comanda::getProduse() {
	return this->produse;
}

int Comanda::getIdComanda() const { return idComanda; }

void Comanda::setProduse(Produs* produse, int size) {
	if (this->produse != nullptr) {
		delete[] this->produse;
	}

	this->produse = new Produs[size]; 

	for (int i = 0; i < size; ++i) {
		this->produse[i] = produse[i]; 
	}

	nrProduse = size; 
}

int Comanda::getIndexProdusCurent() {
	return this->indexProdusCurent;
}

void Comanda::setIndexProdusCurent(int indexProdusCurent) {
	this->indexProdusCurent = indexProdusCurent;
}

// operatori de citire si afisare
	// operator <<
ostream& operator<<(ostream& out, const Comanda& c) {
	out << "ID Comanda: " << c.idComanda << endl;
	out << "Produse: " << endl;
	for (int i = 0; i < c.indexProdusCurent; ++i) {
		out << c.produse[i] << endl;
	}
	out << endl;
	return out;
}

// operator >>
istream& operator>>(istream& in, Comanda& c) {
	string nume;
	float pret;

	cout << "Produs:" << endl;
	cout << "Denumire: ";
	in >> nume;
	cout << endl;
	cout << "Pret: ";
	in >> pret;

	if (c.getIndexProdusCurent() < c.getNrProduse()) {
		c.getProduse()[c.getIndexProdusCurent()].setDenumire(nume);
		c.getProduse()[c.getIndexProdusCurent()].setPret(pret);
		c.setIndexProdusCurent(c.getIndexProdusCurent() + 1);
	}
	else {
		cout << "Ati depasit nr maxim de produse" << endl;
	}

	return in;
}
// operator +=
Comanda& Comanda::operator+=(const Produs& prod) {
	if (indexProdusCurent < 1000) {
		produse[indexProdusCurent++] = prod;
	}
	else {
		cout << "Ati depasit nr maxim de produse." << endl;
	}
	return *this;
}

// operator -=
Comanda& Comanda::operator-=(const Produs& prod) {
	for (int i = 0; i < indexProdusCurent; ++i) {
		if (&produse[i] == &prod) {
			for (int j = i; j < indexProdusCurent - 1; ++j) {
				produse[j] = produse[j + 1];
			}
			indexProdusCurent--;
			break;
		}
	}
	return *this;
}

// serializare/deserializare fisier binar
// serializare
void Comanda::exportBinar(string numeFisier) {

}

// deserializare
void Comanda::importBinar(string numeFisier) {

}
