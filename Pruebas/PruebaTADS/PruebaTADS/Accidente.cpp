#include "Accidente.h"
#include <iomanip>
#include <iostream>

using namespace std;

void Accidente::put_accidente(const string& cad) {
	int fin = cad.size();

	dia = stoi(cad.substr(0, 2));
	mes = stoi(cad.substr(3, 2));
	anyo = stoi(cad.substr(6, 4));
	vict = stoi(cad.substr(11, fin - 11));

}

void Accidente::operator= (const Accidente& otro) {
	dia = otro.dia;
	mes = otro.mes;
	anyo = otro.anyo;
	vict = otro.vict;
}


bool Accidente::operator< (const Accidente& otro)const {

	if (anyo < otro.anyo) { return true; }
	if (anyo > otro.anyo) { return false; }

	if (mes < otro.mes) { return true; }
	if (mes > otro.mes) { return false; }

	if (dia < otro.dia) { return true; }

	return false;
}

void Accidente::imprimir_fecha()const {
	cout << setfill('0') << setw(2) << dia << "/"
		<< setw(2) << mes << "/"
		<< setw(4) << anyo;
}
