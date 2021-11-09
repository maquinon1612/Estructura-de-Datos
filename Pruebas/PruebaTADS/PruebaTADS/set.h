#ifndef set_h
#define set_h


//****----------------------COMIENZO DE LA CLASE--------------------------------------------****// 
template <class Type>
class Set {
public:
	Set(int tam = TAM_INICIAL); // Constructor por defecto, con capacidad por defecto de 8.
	Set(const Set& otro); // Constructor por copia
	~Set(); // destructor

	void operator=(const Set& otro); //operador de asignación
	void insert(Type elem);
	void erase(Type elem);

	bool contains_search(Type elem, int& pos) const;

	bool empty() const;
	int size() const;

	//Nuevos métodos
	Type get_elem_min()const;
	Type get_elem_pos(int pos)const;
	void erase_min();

private:
	const static int TAM_INICIAL = 8;
	int contador; // Indica elementos rellenos del array.
	int capacidad; // Indica capacidad total en el HEAP del array.
	Type* datos; //Array en el HEAP de elementos TYPE, tendrá tamaño [capacidad]

	// Métodos Privados
	void ampliar();
	void libera();
	void copia(const Set& otro); // Copia un Set completo.
};

// Constructor con parámetros
template <class Type>
Set<Type>::Set(int tam) : contador(0), capacidad(tam) {
	datos = new Type[capacidad];
}

// Copia de lista completa
template <class Type>
void Set<Type>::copia(const Set<Type>& otro) {
	capacidad = otro.capacidad;
	contador = otro.contador;
	datos = new Type[capacidad]; // Con el new Nuevo nos aseguramos de que no apuntan a la misma memoria.
	for (int i = 0; i < contador; ++i) {
		datos[i] = otro.datos[i];  // Al copiar dato a dato tenemos dos copias en el HEAP completamente distintas.
	}
}

// Constructor por copia 
template <class Type>
Set<Type>::Set(const Set<Type>& otro) {
	copia(otro);  //Simplemente invoca la copia de lista "otro".
}

// Liberación de una lista
template <class Type>
void Set<Type>::libera() {
	delete[] datos;
}

// Destructor
template <class Type>
Set<Type>::~Set() {
	libera();
}

// Ampliar la capacidad de la lista con x2 Tamaño
template <class Type>
void Set<Type>::ampliar() {
	Type* nuevos = new Type[2 * capacidad];

	for (int i = 0; i < capacidad; ++i) {
		nuevos[i] = datos[i];
	}
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

// Operador de asignación 
template <class Type>
void Set<Type>::operator=(const Set<Type>& otro) {
	if (this != &otro) { // Si son punteros distintos se realiza la copia.
		libera();
		copia(otro); // Se liberó y se copia de nuevo para tener dos copias diferentes funcionales.
	}
}

template <class Type>
void Set<Type>::insert(Type elem) {
	int pos = 0;

	if (!contains_search(elem, pos)) {
		if (contador < capacidad) {
			//Queremos insertar en "pos" con desplazamiento a derecha.
			for (int i = contador; i > pos; --i) {
				datos[i] = datos[i - 1];
			}
			datos[pos] = elem;
			++contador;
		}
		else {
			//ampliar(); NO SE USA //No quiero aumentar en este problema. Ya tiene el tamaño necesario.

			// Al estar la lista llena miro a ver si quiero introducir el elemento o no. Que sé que no está repetido.
			if (pos > 0) { //Entonces inserto porque no es el más pequeño.
				--pos;
				for (int i = 0; i < pos; ++i) {
					datos[i] = datos[i+1];
				}
				datos[pos] = elem;
			}

		}
		

	}
}


// Es una función que me dice si el elemento está en la lista, me devuelve dónde está o dónde debería ir.
// Sirve de algoritmo de inserción ordenada.
template <class Type>
bool Set<Type>::contains_search(Type elem, int& pos) const { 

	int a, b, c;
	bool encontrado = false;
	a = 0;
	b = contador - 1;

	if (elem > datos[b]) {
		pos = contador;
	}
	else if (elem < datos[0]) {
		pos = 0;
	}
	else {// Búsqueda binaria mejorada.
		while (!encontrado && a <= b) {
			c = (a + b) / 2;
			if (datos[c] == elem) { encontrado = true; }
			else {
				if (datos[c] > elem) {
					b = c - 1;
				}
				else {
					a = c + 1;
				}
			}
		}
		if (encontrado) { pos = c; }
		else { pos = a; }

	}
	return encontrado;
}
template <class Type>
void Set<Type>::erase(Type elem) {
	int pos = 0;
	if (contains_search(elem, pos)) {
		for (int i = pos; i < contador; ++i) { //Reordeno la lista al borrar. Desplazo izquierda.
			datos[i] = datos[i + 1];
		}
		--contador;
	}
	else {
		throw "ERROR:El elemento no esta";
	}	
}



template <class Type>
bool Set<Type>::empty() const {
	return (contador == 0);
}

template <class Type>
int Set<Type>::size() const {
	return contador;
}

//  --------        Nuevas Funciones de la clase SET  ---------------------------------

template <class Type>
Type Set<Type>::get_elem_min() const {
	if (contador == 0) {
		throw "ERROR: La lista no tiene elementos";
	}

	return datos[0];
}

template <class Type>
Type Set<Type>::get_elem_pos(int pos) const {
	if (contador == 0) {
		throw "ERROR: La lista no tiene elementos";
	}
	if (pos >= contador || pos < 0) {
		throw "ERROR: posicion fuera de lista";
	}

	return datos[pos];
}

template <class Type>
void Set<Type>::erase_min() {
	if (contador == 0) {
		throw "ERROR: La lista no tiene elementos";
	}
	for (int i = 0; i < contador; ++i) { //Reordeno la lista al borrar. Desplazo izquierda.
		datos[i] = datos[i + 1];
	}
	--contador;
}
//****------------------------FIN DE LA CLASE------------------------------------------****//

#endif 