#ifndef PRODUSFIZIC_H
#define PRODUSFIZIC_H
#include "Produs.h"
#include <iostream>
#include <string>

using namespace std;

class ProdusFizic :
    public Produs
{
protected:
	float greutateKg;
	float lungime;
	float latime;
	float inaltime;

public:

	// constructor fara parametrii
	ProdusFizic();

	ProdusFizic(char* denumire, float pret, char* continut, bool inStoc, float greutateKg, float lungime, float latime, float inaltime);

	//constructor de copiere
	ProdusFizic(const ProdusFizic& pr);

	// getteri si setteri
	float getGreutateKg();

	float getLungime();

	float getLatime();

	float getInaltime();

	void setGreutateKg(float greutateKg);

	void setLungime(float lungime);

	void setLatime(float latime);

	void setInaltime(float inaltime);

	// operator = 
	ProdusFizic& operator=(const ProdusFizic& pr);

	// operator <<
	friend ostream& operator<<(ostream& out, const ProdusFizic& pr);

	// operator >>
	friend istream& operator>>(istream& in, ProdusFizic& pr);
};

#endif PRODUSFIZIC_H