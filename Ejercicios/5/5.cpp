/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2020.
   Estructura de Datos.

   E05. Los k elementos mayores.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
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
	/*Con la condici�n del while puedo comparar "Type aux" con el contenido del puntero p_centinela.
	   Al no saber los tipos de cada variable se debe utilizar una forma muy gen�rica de comparaci�n.
	*/
	while (aux != *(Type*)p_centinela) { 
		lista.insert(aux); //La funci�n Insert() tiene una operatividad extendida de insrci�n.
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

   Este problema presenta diferentes complicaciones de cara a su implementaci�n. No es sencillo.
   En primer lugar debemos trabajar con una clase con TEMPLATE debido a que durante la 
   ejecuci�n tenemos dos modalidades de lista, enteros y string.

      SOLUCI�N a cerca de TEMPLATES y Tipos

   Seg�n si la lista es de enteros o strings debemos hacer la comparativa de fin de lista
   con un centinela diferente. Hacer comparaciones de variables sin tipo y otras con tipo
   es algo que se atraganta al compilador de C++. Para solucionar esto podemos usar un
   puntero void* que compare su contenido con una variable Type.

      LISTA ORDENADA Con tama�o Fijo

   Dado que el ejercicio consiste en obtener una salida de los k mayores elementos
   de una lista, es mucho m�s eficiente ir conservando SOLAMENTE los mayores elementos y 
   desechando el resto.

      M�TODOS clave

   M�todo Isertar(): implementa una inserci�n ordenada en la lista de k elementos.
   Si el elemento es menor que los de la lista lo ignora, si no, lo inserta y expulsa al menor.

   M�todo Contains_Search(): sirve para averiguar si el elemento est� repetido, o si se colocar�a
   al principio, final, o en medio de la lista. Lo usa internamente INSERTAR. Usa b�squeda binaria mejorada.


   Se han a�adido otros m�todos de extensi�n de la clase (aunque no se usan) porque lo exige el enunciado.

 */

