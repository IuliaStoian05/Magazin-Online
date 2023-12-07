#include "Produs.h"
#include <iostream>
#include <string>


int Produs::nextId = 1;


	// destructor
	Produs::~Produs() {
		if (this->continut != NULL) {
			delete[] this->continut;
		}
	}

	// constructor fara parametri
	Produs::Produs():idProdus(nextId++) {
		this->denumire = "NA";
		this->pret = 0.0f;
		this->continut = new char[strlen("NA") + 1];
		strcpy_s(this->continut, strlen("NA") + 1, "NA");
		this->inStoc = false;
	}

	// constructor cu 1 parametru
	Produs::Produs(string denumire): idProdus(nextId++) {
		this->denumire = denumire;
		this->pret = 0.0F;
		this->continut = new char[strlen("NA") + 1];
		strcpy_s(this->continut, strlen("NA") + 1, "NA");
		this->inStoc = false;
	}

	// constructor cu 2 parametri
	Produs::Produs(string denumire, float pret) :idProdus(nextId++) {
		this->denumire = denumire;
		this->pret = pret;
		this->continut = new char[strlen("NA") + 1];
		strcpy_s(this->continut, strlen("NA") + 1, "NA");
		this->inStoc = false;
	}

	// constructor cu 3 parametri
	Produs::Produs(string denumire, float pret, char* continut) :idProdus(nextId++) {
		this->denumire = denumire;
		this->pret = pret;
		this->continut = continut;
		this->inStoc = false;
	}


	// constructor cu toti parametrii
	Produs::Produs(string denumire, float pret, char* continut, bool inStoc) :idProdus(nextId++) {
		this->denumire = denumire;
		this->pret = pret;
		this->continut = continut;
		this->inStoc = inStoc;
	}

	// constructorul de copiere
	Produs::Produs(const Produs& p):idProdus(nextId++) {
		if (this != &p)
		{
			
			denumire = p.denumire;
			pret = p.pret;
			inStoc = p.inStoc;
			if (p.continut != nullptr) {
				continut = new char[strlen(p.continut) + 1];
				strcpy_s(continut, strlen(p.continut) + 1, p.continut);
			}
			else {
				continut = nullptr; 
			}
		}
	}

	// getteri si setteri
	int Produs::getIdProdus() const {
		return this->idProdus;
	}

	string Produs::getDenumire() {
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

	void Produs::setDenumire(string denumire) {
		this->denumire = denumire;
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
				denumire = p.denumire;
				pret = p.pret;

				if (continut != nullptr) {
						delete[] continut;
						continut = nullptr; 
				}

				continut = new char[strlen(p.continut) + 1];
				strcpy_s(continut, strlen(p.continut) + 1, p.continut);

				inStoc = p.inStoc;
			}
		
		return *this;
	}

	// operator ==
	bool Produs::operator==(const Produs& other) const {
		return (this->denumire == other.denumire &&
			this->pret == other.pret &&
			strcmp(this->continut, other.continut) == 0 && 
			this->inStoc == other.inStoc);
	}

	// operator >>
	istream& operator>>(istream& in, Produs& p) {
		cout << "ID: " << p.getIdProdus();
		cout << "Denumire: ";
		in >> p.denumire;
		cout << "\nPret: ";
		in >> p.pret;
		cout << "\nContinut: ";
		delete[]p.continut;
		string auxiliar;
		getline(in, auxiliar);
		p.continut = new char[auxiliar.size() + 1];
		strcpy_s(p.continut, auxiliar.size() + 1, auxiliar.c_str());
		cout << "\nEste in stoc? ";
		in >> p.inStoc;
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



