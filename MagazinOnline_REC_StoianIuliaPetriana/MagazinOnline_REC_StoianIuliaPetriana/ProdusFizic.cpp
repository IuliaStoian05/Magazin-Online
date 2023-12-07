#include "Produs.h"
#include "ProdusFizic.h"
#include <iostream>
#include <string>

using namespace std;


ProdusFizic::~ProdusFizic() {
	if (this->dimensiuni != NULL) {
		delete[]this->dimensiuni;
	}
}

// constructor fara parametrii
ProdusFizic::ProdusFizic() :Produs() {
	this->greutateKg = 0;
	this->dimensiuni = NULL;
}

ProdusFizic::ProdusFizic(string denumire, float pret, char* continut, bool inStoc, float greutateKg, float* dimensiuni) :Produs(denumire, pret, continut, inStoc) {
	this->greutateKg = greutateKg;
	this->dimensiuni = new float[3];
	for (int i = 0; i < 3; i++) {
		this->dimensiuni[i] = dimensiuni[i];
	}
}

//constructor de copiere
ProdusFizic::ProdusFizic(const ProdusFizic& pr) :Produs(pr) {
	if (this != &pr) {
		this->greutateKg = pr.greutateKg;
		this->dimensiuni = new float[3];
		for (int i = 0; i < 3; i++) {
			this->dimensiuni[i] = pr.dimensiuni[i];
		}
	}
}

/*
ProdusFizic::ProdusFizic(const Produs& p) :Produs(p) {
	if (this != &p) {
		//delete[] this->continut;
		
		this->greutateKg = 0;
		this->dimensiuni = NULL;
	}
}
*/

// getteri si setteri
float ProdusFizic::getGreutateKg() {
	return this->greutateKg;
}

float* ProdusFizic::getDimensiuni() {
	return this->dimensiuni;
}

void ProdusFizic::setGreutateKg(float greutateKg) {
	this->greutateKg = greutateKg;
}

void ProdusFizic::setDimensiuni(float* dimensiuni) {
	this->dimensiuni = new float[3];
	for (int i = 0; i < 3; i++) {
		this->dimensiuni[i] = dimensiuni[i];
	}
}


// operator = 
ProdusFizic& ProdusFizic::operator=(const ProdusFizic& pr) {
	if (this->dimensiuni != NULL) {
		delete[]this->dimensiuni;
	}
	Produs::operator=(pr);
	this->greutateKg = pr.greutateKg;
	this->dimensiuni = new float[3];
	for (int i = 0; i < 3; i++) {
		this->dimensiuni[i] = pr.dimensiuni[i];
	}
	return *this;
}

// operator <<
ostream& operator<<(ostream& out, const ProdusFizic& pr)
{	
	out << (Produs&)pr;
	out << "Greutate(Kg): "<<pr.greutateKg << endl;
	out << "Dimensiuni (L, l, h): ";
	for (int i = 0; i < 3; i++) {
		out << pr.dimensiuni[i] << " cm | ";
	}
	out << endl;
	return out;
}

// operator >>
istream& operator>>(istream& in, ProdusFizic& pr) {
	in >> (Produs&)pr;
	in >> pr.greutateKg;
	delete[]pr.dimensiuni;
	pr.dimensiuni = new float[3];
	for (int i = 0; i < 3; i++) {
		in >> pr.dimensiuni[i];
	}
	return in;
}
