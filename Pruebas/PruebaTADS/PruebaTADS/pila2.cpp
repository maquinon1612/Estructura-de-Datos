/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2020.
   Estructura de Datos.

   E07. Accidente a�reos.

La resoluci�n de este ejercicio no pretende ser la mejor soluci�n
ni la �nica para resolverlo. El objetivo es plantear al estudiante un camino
visible y de f�cil comprensi�n para implementar programas seg�n un esquema
conocido y estandarizado.

Los detalles sobre la elecci�n de la implementaci�n se ofrecen al final del
documento con una peque�a explicaci�n. El programa ha sido verificado y
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
	Accidente aux_accd; //Aqu� guardo el accidente que analizo para reportar la noticia.
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
					stack_hist.pop(); //Elimino el elemento del alto de la lista si tiene menos o igual v�ctimas.
				}
			}


		}
		catch (...) {
			cout << "NO HAY\n"; //Los m�todos top() y pop() me producen excepci�n si la pila est� vac�a.
			encontrado = false;
		}

		if (encontrado) {
			aux_impr = &stack_hist.top(); 
			aux_impr->imprimir_fecha();
			cout << "\n";
		}
		stack_hist.push(aux_accd); //Se introduce en la pila el �ltimo accidente siempre.
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
   E07. Accidente a�reos.

   En este ejercicio la resoluci�n se hace r�pida y eficiente si usamos una estructura
   de tipo pila en vez de tomar todos los elementos de la lista y despu�s buscar aquel
   que cumple la condici�n de v�ctimas (lo que nos provocar�a un coste de computaci�n excesivo).

   Cuando nos llegan accidentes nuevos con muchas v�ctimas vac�an la pila porque los accidentes
   venideros nunca los llegar�an a consultar (si suponemos que se dejase la lista completa).

   Usamos la clase Accidente y la clase Historial (que es de tipo Pila) porque estamos reciclando
   c�digo de ejercicios anteriores con una definici�n similar. Se podr�a hacer con algo menos de c�digo.
   

*/
