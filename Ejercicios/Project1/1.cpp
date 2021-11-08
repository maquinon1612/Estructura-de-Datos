// Mario Quiñones Pérez
// A 60

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

class Hora {
public:
	Hora() { segundos = 0; minutos = 0; horas = 0; }
	Hora(int h, int m, int s) : horas(h), minutos(m), segundos(s) {
		if (s < 0 || s > 59)  throw  invalid_argument("ERROR");
		if (m < 0 || m > 59)  throw  invalid_argument("ERROR");
		if (h < 0 || h > 23)  throw  invalid_argument("ERROR");
	}

	bool operator< (const Hora& otro)const;

	bool operator== (const Hora& otro)const;

	friend istream& operator>> (istream& stream, Hora& time);

	friend ostream& operator<< (ostream& stream, Hora& time);


private:
	int segundos;
	int minutos;
	int horas;
};

bool Hora::operator< (const Hora& otro)const {

	if (horas < otro.horas) {return true;}

	if (horas > otro.horas) {return false;}

	if (minutos < otro.minutos) { return true; }

	if (minutos > otro.minutos) { return false; }

	if (segundos < otro.segundos) { return true; }

	return false;
}
bool Hora::operator== (const Hora& otro)const {
	return(otro.horas == horas && otro.minutos == minutos && otro.segundos == segundos);
}

istream& operator>> (istream& stream, Hora& time) {
	int h, m, s;

	stream >> h;
	stream.ignore(1);
	stream >> m;
	stream.ignore(1);
	stream >> s;
	
	try {
		time = Hora(h, m, s);
	}
	catch (...) {
		throw;
	}

	return stream;
}

ostream& operator<< (ostream& stream, Hora& time) {

	stream << setfill('0') << setw(2) << time.horas << ":"
		<< setw(2) << time.minutos << ":"
		<< setw(2) << time.segundos;

	return stream;
}

//****------------------------FIN DE LA CLASE------------------------------------------****//

bool resuelveCaso() {
	int trenes, horarios;

	cin >> trenes >> horarios;
	if ((trenes == 0) && (horarios == 0)) { return false; } //Centinela

	vector <Hora> panel;
	Hora aux;

	for (int i = 0; i < trenes; ++i) {
		cin >> aux;
		panel.push_back(aux);
	}
	

	int a, b, c, pos;
	bool encontrado;
	
	for (int i = 0; i < horarios; ++i) {
		try {
			cin >> aux;
			a = 0;
			b = trenes - 1;
			encontrado = false;
			while (a <= b && !encontrado) { // Búsqueda binaria de la posición de tiempo mayor. Es pos.
				c = (a + b) / 2;
				if (panel[c] == aux) { encontrado = true; }
				else {
					if (panel[c] < aux) {
						a = c + 1;
					}
					else {
						b = c - 1;
					}
				}
			}
			if (encontrado) { pos = c; }
			else { pos = a; }

			if (pos < trenes) {
				cout << panel[pos] << "\n";
			}
			else {
				cout << "NO\n";
			}
		}
		catch (invalid_argument& ia){
			cout << ia.what() << "\n";
		}
		
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
   E01. ¿A que hora pasa el próximo tren?

   El programa nos introduce en el uso de las excepciones. Además usamos una sobrecarga
   de los operadores de inserción y extracción para la clase, tienen forma de "funciones amigas".
   Las funciones "friend" no son métodos realmente, por eso al declararlas fuera no hay que
   indicar la clase con ::, sin embargo tienen permisos para entrar en los elementos privados
   de la clase (como los atributos).

*/
