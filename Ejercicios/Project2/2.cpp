/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2020.
   Estructura de Datos.

   E02. Una tarde de sábado

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

//------*****---------- CLASE HORA -------------------------*********---------// 

class Hora {
public:
	Hora() { segundos = 0; minutos = 0; horas = 0; } // Constructor por defecto
	Hora(int h, int m, int s) : horas(h), minutos(m), segundos(s) {}  //Constructor con parámetros;

	//Sobrecargas
	bool operator< (const Hora& otro)const;
	bool operator> (const Hora& otro)const;
	bool operator== (const Hora& otro)const;
	Hora operator+ (const Hora& otro)const;
	friend istream& operator>> (istream& stream, Hora& time);
	friend ostream& operator<< (ostream& stream, Hora& time);


private:
	int segundos;
	int minutos;
	int horas;
};

bool Hora::operator< (const Hora& otro)const {

	if (horas < otro.horas) { return true; }
	if (horas > otro.horas) { return false; }

	if (minutos < otro.minutos) { return true; }
	if (minutos > otro.minutos) { return false; }

	if (segundos < otro.segundos) { return true; }

	return false;
}
bool Hora::operator> (const Hora& otro)const {
	if (horas > otro.horas) { return true; }
	if (horas < otro.horas) { return false; }

	if (minutos > otro.minutos) { return true; }
	if (minutos < otro.minutos) { return false; }

	if (segundos > otro.segundos) { return true; }

	return false;
}

bool Hora::operator== (const Hora& otro)const {
	return(otro.horas == horas && otro.minutos == minutos && otro.segundos == segundos);
}

Hora Hora::operator+ (const Hora& otro)const { //Operador de suma
	Hora aux;
	aux.segundos = segundos + otro.segundos;
	if (aux.segundos > 59) {
		aux.minutos++;
		aux.segundos = aux.segundos - 60;
	}
	aux.minutos = aux.minutos + minutos + otro.minutos;
	if (aux.minutos > 59) {
		aux.horas++;
		aux.minutos = aux.minutos - 60;
	}
	aux.horas = aux.horas + horas + otro.horas;

	assert(horas < 24);

	return aux;
}



istream& operator>> (istream& stream, Hora& time) {
	int h, m, s;

	stream >> h;
	stream.ignore(1);
	stream >> m;
	stream.ignore(1);
	stream >> s;

	time = Hora(h, m, s);

	return stream;
}

ostream& operator<< (ostream& stream, Hora& time) {

	stream << setfill('0') << setw(2) << time.horas << ":"
		<< setw(2) << time.minutos << ":"
		<< setw(2) << time.segundos;

	return stream;
}

//------*****---------- CLASE HORA -------------------------*********---------// 

//------*****---------- CLASE PELÍCULA -------------------------*********---------// 

class Pelicula {
public:
	Pelicula() :comienzo(), durac(), titulo(""){} //Constructor por defecto
	Hora get_fin_peli()const { return comienzo + durac; };

	bool operator<(Pelicula& otro)const;
	void put_pelicula(istream& stream);
	void print_fin_peli(ostream& stream)const;

private:
	Hora comienzo;
	Hora durac;
	string titulo;
};
bool Pelicula::operator<(Pelicula& otro)const {
	Hora hora1, hora2;

	hora1 = this->get_fin_peli();
	hora2 = otro.get_fin_peli();
	if (hora1 < hora2) { return true; }
	if (hora1 > hora2) { return false; }

	if (this->titulo > otro.titulo) { return false; }

	return true;
}
void Pelicula::put_pelicula(istream& stream) {
	stream >> comienzo >> durac;
	stream.ignore(1);
	getline(stream, titulo);
}

void Pelicula::print_fin_peli(ostream& stream)const {
	Hora  aux = this->get_fin_peli();
	stream << aux << " " << titulo << "\n";
}

//------*****---------- CLASE PELÍCULA -------------------------*********---------// 


bool resuelveCaso() {
	int pelis;
	cin >> pelis;

	if (pelis == 0) { return false; } //Centinela

	vector <Pelicula> cartel;
	Pelicula aux;

	for (int i = 0; i < pelis; ++i) {
		aux.put_pelicula(cin);
		cartel.push_back(aux);
	}

	sort(cartel.begin(), cartel.end());

	for (int i = 0; i < pelis; ++i) {
		cartel[i].print_fin_peli(cout);
	}

	cout << "---\n";
	return true;
}

int main() {
	
	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	
	while (resuelveCaso()) {

	}
	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}

/*
   E02. Una tarde de sábado

   Es una continuación del ejercicio E01. Tomamos la clase Hora y se la incluimos a otra clase.
   Aprovechamos los insertores de Hora para realizar la función put_película.
   Para poder usar la función de librería sort (que ordena de menor a mayor) se debe definir
   el operador "<" en la clase que hay en los elementos de la lista.

*/
