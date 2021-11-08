/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2020.
   Estructura de Datos.

   E05. Los k elementos mayores.

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
#include "set.h"
#include <fstream>

using namespace std;

template <class Type>
void execute(int num_imprimir, char modo) {
	Set<Type> lista(num_imprimir);
	Type aux;
	long long int CENTINELA_I = -1;
	string CENTINELA_S = "FIN";

	// Defino puntero sin tipo (void*) para que pueda apuntar tanto al centinela String como al Int
	void* p_centinela = &CENTINELA_I; //Inicializo con modo Integers.

	if (modo == 'P') {
		p_centinela = &CENTINELA_S; //Cambio a string si son palabras.
	}

	cin >> aux;
	/*Con la condición del while puedo comparar "Type aux" con el contenido del puntero p_centinela.
	   Al no saber los tipos de cada variable se debe utilizar una forma muy genérica de comparación.
	*/
	while (aux != *(Type*)p_centinela) { 
		lista.insert(aux); //La función Insert() tiene una operatividad extendida de insrción.
		cin >> aux;
	}
	
	for (int i = 0; i < num_imprimir; ++i) {
		cout << lista.get_elem_pos(i) << " ";
	}
	cout << "\n";

}

bool resuelveCaso() {
	char modo;
	cin >> modo;

	if (!cin) { return false; } //Fin de fichero
	int num_imprimir;
	cin >> num_imprimir;
	try {
		if (modo == 'N') {
			execute<long long int>(num_imprimir, modo);
		}
		else {
			execute<string>(num_imprimir, modo);
		}

	}
	catch (...) {

	}


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
   E05. Los k elementos mayores.

   Este problema presenta diferentes complicaciones de cara a su implementación. No es sencillo.
   En primer lugar debemos trabajar con una clase con TEMPLATE debido a que durante la 
   ejecución tenemos dos modalidades de lista, enteros y string.

      SOLUCIÓN a cerca de TEMPLATES y Tipos

   Según si la lista es de enteros o strings debemos hacer la comparativa de fin de lista
   con un centinela diferente. Hacer comparaciones de variables sin tipo y otras con tipo
   es algo que se atraganta al compilador de C++. Para solucionar esto podemos usar un
   puntero void* que compare su contenido con una variable Type.

      LISTA ORDENADA Con tamaño Fijo

   Dado que el ejercicio consiste en obtener una salida de los k mayores elementos
   de una lista, es mucho más eficiente ir conservando SOLAMENTE los mayores elementos y 
   desechando el resto.

      MÉTODOS clave

   Método Isertar(): implementa una inserción ordenada en la lista de k elementos.
   Si el elemento es menor que los de la lista lo ignora, si no, lo inserta y expulsa al menor.

   Método Contains_Search(): sirve para averiguar si el elemento está repetido, o si se colocaría
   al principio, final, o en medio de la lista. Lo usa internamente INSERTAR. Usa búsqueda binaria mejorada.


   Se han añadido otros métodos de extensión de la clase (aunque no se usan) porque lo exige el enunciado.

 */

