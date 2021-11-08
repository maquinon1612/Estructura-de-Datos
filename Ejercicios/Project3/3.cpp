/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2020.
   Estructura de Datos.

   E03. El conjunto de Mandelbrot.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

//****----------------------COMIENZO DE LA CLASE--------------------------------------------****// 

template <class Type>
class Complejo {
public:
	Complejo() :real(0), imag(0) {} //Constructor por defecto con llamada a constructor del subtipo
	Complejo(Type r, Type im) :real(r), imag(im) {}//Constructor con parámetros

	void operator= (const Complejo& c);      //Sobrecargas

	Complejo operator+ (const Complejo& c) const;
	Complejo operator- (const Complejo& c) const;
	Complejo operator* (const Complejo& c) const;

	Type modulo()const;


private:
	Type real;
	Type imag;
};

template <class Type>
void Complejo<Type> ::operator= (const Complejo<Type>& c) {
	real = c.real;
	imag = c.imag;
}

template <class Type>
Complejo<Type> Complejo<Type>::operator+ (const Complejo<Type>& c) const {
	Complejo aux;
	aux.real = real + c.real;
	aux.imag = imag + c.imag;
	return aux;
}

template <class Type>
Complejo<Type> Complejo<Type>::operator- (const Complejo<Type>& c) const {
	Complejo aux;
	aux.real = real - c.real;
	aux.imag = imag - c.imag;
	return aux;
}

template <class Type>
Complejo<Type> Complejo<Type>::operator* (const Complejo<Type>& c) const {
	Complejo aux;
	aux.real = real * c.real - imag * c.imag;
	aux.imag = real * c.imag + imag * c.real;
	return aux;
}

template <class Type>
Type Complejo<Type>::modulo()const {
	Type resul;
	resul = sqrt(real * real + imag * imag);
	return resul;
}

//****------------------------FIN DE LA CLASE------------------------------------------****//

void resuelveCaso() {
	float r, im;
	int iter, i;
	bool converge = true;
	cin >> r >> im >> iter;

	Complejo<float> z(0, 0);
	Complejo<float> c(r, im);

	i = 0;
	while (converge && i < iter) {
		z = (z * z) + c;
		if (z.modulo() > 2) { converge = false; }
		++i;
	}

	if (converge) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
}



int main() {
	
	#ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif
	
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
	
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
	#endif
	
	return 0;

}
/*
   E03. El conjunto de Mandelbrot.

   En este problemas introducimos el uso de Templates. La realización del bucle de
   comprobación es bastante sencilla una vez se han definido los operadores de la clase.
   Sólo hay que tener cuidado con la sintaxis de la clase genérica.
*/