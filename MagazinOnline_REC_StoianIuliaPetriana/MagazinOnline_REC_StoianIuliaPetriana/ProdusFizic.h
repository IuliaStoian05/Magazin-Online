#ifndef PRODUSFIZIC_H
#define PRODUSFIZIC_H
#include "Produs.h"
#include <iostream>
#include <string>

using namespace std;

class ProdusFizic : public Produs
{
protected:
	float greutateKg;
	float* dimensiuni; // lungime, latime, inaltime

public:

	//destructor
	~ProdusFizic();

	// constructor fara parametrii
	ProdusFizic();

	ProdusFizic(string denumire, float pret, char* continut, bool inStoc, float greutateKg, float* dimensiuni);

	//constructor de copiere
	ProdusFizic(const ProdusFizic& pr);

//	ProdusFizic(const Produs& p);

	// getteri si setteri
	float getGreutateKg();

	float* getDimensiuni();

	void setGreutateKg(float greutateKg);

	void setDimensiuni(float* dimensiuni);


	// operator = 
	ProdusFizic& operator=(const ProdusFizic& pr);

	// operator <<
	friend ostream& operator<<(ostream& out, const ProdusFizic& pr);

	// operator >>
	friend istream& operator>>(istream& in, ProdusFizic& pr);
};

#endif