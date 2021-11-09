#include "Historial.h"

using namespace std;

void Historial::push(Accidente nuevo) {
	if (cont == capacidad) { ampliar(); }
	datos[cont] = nuevo;
	++cont;
}
void Historial::pop() {
	if (cont == 0) { throw 0; }
	--cont;
}
Accidente& Historial::top()const {
	if (cont == 0) { throw 0; }
	return (datos[cont - 1]);
}
void Historial::ampliar() {
	Accidente* nuevos = new Accidente[2 * capacidad];

	for (int i = 0; i < capacidad; ++i) {
		nuevos[i] = datos[i];
	}
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

int Historial::size()const {
	return cont;
}