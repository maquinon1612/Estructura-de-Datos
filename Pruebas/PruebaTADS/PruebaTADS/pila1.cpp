/*
CARLOS S�NCHEZ. Profesor Academia MACH. 2020.
   Estructura de Datos.

   E06. Par�ntesis equilibrados.

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
#include <vector>
#include <fstream>

using namespace std;

//****----------------------COMIENZO DE LA CLASE--------------------------------------------****//
class Stack {
public:
	Stack(int tam=TAM_BASIC):cont(0),capacidad(tam),datos(new char[tam]){}
	~Stack() { delete[] datos; }

	void push(char c);
	void pop();
	char top()const;
	int size()const;

private:
	const static int TAM_BASIC = 20;
	int cont; // Para contar la cantidad de elementos apilados
	int capacidad; // Nos indica el tama�o neto total de la Pila
	char* datos; //Es un puntero que nos lleva al vector din�mico
	//M�todo privado
	void ampliar();
};

void Stack::push(char c) {
	if (cont == capacidad) { ampliar(); }
	datos[cont] = c;
	++cont;
}
void Stack::pop() {
	if (cont == 0) { throw 0; }
	--cont;
}
char Stack::top()const {
	if (cont == 0) { throw 0; }
	return (datos[cont-1]);
}
void Stack::ampliar() {
	char* nuevos = new char[2*capacidad];

	for (int i = 0; i < capacidad; ++i) {
		nuevos[i] = datos[i];
	}
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

int Stack::size()const {
	return cont;
}


//****------------------------FIN DE LA CLASE------------------------------------------****//

bool resuelveCaso() {
	vector<char> cadena;
	char c;
	int tam;

	cin.get(c);
	while (cin) {
		cadena.push_back(c);
		if (c == '\n') break;
		cin.get(c);
	}
	tam = cadena.size();
	if (!cin && tam == 0 ) { return false; }

	bool equil = true;
	int i = 0;
	Stack pila;
	try {
		while (i < tam && equil) {
			c = cadena[i];
			if (c == '(' || c == '[' || c == '{') { pila.push(c); }
			else if (c == ')') {
				if (pila.top() == '(') { pila.pop(); }
				else { equil = false; }
			}
			else if (c == ']') {
				if (pila.top() == '[') { pila.pop(); }
				else { equil = false; }
			}
			else if (c == '}') {
				if (pila.top() == '{') { pila.pop(); }
				else { equil = false; }
			}
			++i;
		}

	}
	catch (...) {
		equil = false;
	}
	
	if (equil && (pila.size() != 0)) { equil = false; }

	if (equil) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
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
   E06. Par�ntesis equilibrados.

   Es un ejercicio b�sico de uso de Pilas. La Pila es un TAD lineal que tiene una funcionalidad
   limitada de acceso. First In Last Out.
   La implementamos con un vector din�mico donde apilamos los par�ntesis que abren, y desapilamos
   cuando aparece un par�ntesis que cierra. Si el tipo de caracter no coincide con el que deber�a
   cerrar se sale del bucle o tambi�n si se intenta desapilar una pila vac�a (en este caso te expulsa
   la excepci�n lanzada por pop() ).
   

*/