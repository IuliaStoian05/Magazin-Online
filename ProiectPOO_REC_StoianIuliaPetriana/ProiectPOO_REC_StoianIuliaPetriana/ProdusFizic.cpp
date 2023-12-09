#include "Produs.h"
#include "ProdusFizic.h"
#include <iostream>
#include <string>

using namespace std;

// constructor fara parametrii
ProdusFizic::ProdusFizic() :Produs() {
	this->greutateKg = 0;
	this->lungime = 0;
	this->latime = 0;
	this->inaltime = 0;
}

ProdusFizic::ProdusFizic(char* denumire, float pret, char* continut, bool inStoc, float greutateKg, float lungime, float latime, float inaltime) {
	this->greutateKg = greutateKg;
	this->lungime = lungime;
	this->latime = latime;
	this->inaltime = inaltime;
}

//constructor de copiere
ProdusFizic::ProdusFizic(const ProdusFizic& pr) :Produs(pr) {
	if (this != &pr) {
		this->greutateKg = pr.greutateKg;
		this->lungime = pr.lungime;
		this->latime = pr.latime;
		this->inaltime = pr.inaltime;
	}
}
	// getteri si setteri
	float ProdusFizic::getGreutateKg() {
		return this->greutateKg;
	}

	float ProdusFizic::getLungime() {
		return this->lungime;
	}

	float ProdusFizic::getLatime() {
		return this->latime;
	}

	float ProdusFizic::getInaltime() {
		return this->inaltime;
	}

	void ProdusFizic::setGreutateKg(float greutateKg) {
		this->greutateKg = greutateKg;
	}

	void ProdusFizic::setLungime(float lungime) {
		this->lungime = lungime;
	}

	void ProdusFizic::setLatime(float latime) {
		this->latime = latime;
	}

	void ProdusFizic::setInaltime(float inaltime) {
		this->inaltime = inaltime;
	}

	// operator = 
	ProdusFizic& ProdusFizic::operator=(const ProdusFizic& pr) {
		
		Produs::operator=(pr);
		this->greutateKg = pr.greutateKg;
		this->lungime = pr.lungime;
		this->latime = pr.latime;
		this->inaltime = pr.inaltime;
		return *this;
	}

	// operator <<
	ostream& operator<<(ostream& out, const ProdusFizic& pr)
	{
		out << (Produs&)pr;
		out << "Greutate(Kg): " << pr.greutateKg << endl;
		out << "Lungime: " << pr.lungime << endl;
		out << "Latime: " << pr.latime << endl;
		out << "Inaltime: " << pr.inaltime << endl;
		out << endl;
		return out;
	}

	// operator >>
	istream& operator>>(istream& in, ProdusFizic& pr) {
		in >> (Produs&)pr;
		cout << "Greutate: ";
		in >> pr.greutateKg;
		cout << endl;
		cout << "Lungime: ";
		in >> pr.lungime;
		cout << endl; 
		cout << "Latime: ";
		in >> pr.latime;
		cout << endl; 
		cout << "Inaltime: ";
		in >> pr.inaltime;
		cout << endl;
		
		return in;
	}
