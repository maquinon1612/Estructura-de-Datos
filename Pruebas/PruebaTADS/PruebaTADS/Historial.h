#ifndef Historial_h
#define Historial_h
#include "Accidente.h"

class Historial {
public:
	Historial(int tam = TAM_BASIC) :cont(0), capacidad(tam), datos(new Accidente[tam]) {}
	~Historial() { delete[] datos; }

	void push(Accidente nuevo);
	void pop();
	Accidente& top()const;
	int size()const;

private:
	const static int TAM_BASIC = 10;
	int cont;
	int capacidad;
	Accidente* datos;
	//Método privado
	void ampliar();
};


#endif