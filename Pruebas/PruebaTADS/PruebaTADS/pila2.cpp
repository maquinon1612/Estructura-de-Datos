/*
CARLOS SÁNCHEZ. Profesor Academia MACH. 2020.
   Estructura de Datos.

   E07. Accidente aéreos.

La resolución de este ejercicio no pretende ser la mejor solución
ni la única para resolverlo. El objetivo es plantear al estudiante un camino
visible y de fácil comprensión para implementar programas según un esquema
conocido y estandarizado.

Los detalles sobre la elección de la implementación se ofrecen al final del
documento con una pequeña explicación. El programa ha sido verificado y
aceptado por el juez.
*/


#include "Accidente.h"
#include "Historial.h"
#include <iostream>
#include <fstream>

using namespace std;

bool resuelveCaso() {
	int numFechas;
	bool encontrado;

	cin >> numFechas;
	if (!cin) { return false; }
	cin.ignore();

	string aux_str;
	Accidente* aux_impr; //Este puntero nos localiza el elemento del top de la lista para comparar.
	Accidente aux_accd; //Aquí guardo el accidente que analizo para reportar la noticia.
	Historial stack_hist;

	for (int i = 0; i < numFechas; ++i) {
		encontrado = false;
		getline(cin, aux_str);
		aux_accd.put_accidente(aux_str);
		try {
			while (!encontrado) {
				aux_impr = &stack_hist.top();
				if (aux_accd.get_victims() < aux_impr->get_victims()) {
					encontrado = true;
				}
				else {
					stack_hist.pop(); //Elimino el elemento del alto de la lista si tiene menos o igual víctimas.
				}
			}


		}
		catch (...) {
			cout << "NO HAY\n"; //Los métodos top() y pop() me producen excepción si la pila está vacía.
			encontrado = false;
		}

		if (encontrado) {
			aux_impr = &stack_hist.top(); 
			aux_impr->imprimir_fecha();
			cout << "\n";
		}
		stack_hist.push(aux_accd); //Se introduce en la pila el último accidente siempre.
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
   E07. Accidente aéreos.

   En este ejercicio la resolución se hace rápida y eficiente si usamos una estructura
   de tipo pila en vez de tomar todos los elementos de la lista y después buscar aquel
   que cumple la condición de víctimas (lo que nos provocaría un coste de computación excesivo).

   Cuando nos llegan accidentes nuevos con muchas víctimas vacían la pila porque los accidentes
   venideros nunca los llegarían a consultar (si suponemos que se dejase la lista completa).

   Usamos la clase Accidente y la clase Historial (que es de tipo Pila) porque estamos reciclando
   código de ejercicios anteriores con una definición similar. Se podría hacer con algo menos de código.
   

*/
