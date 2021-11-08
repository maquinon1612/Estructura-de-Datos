
//Mario Quiñones Pérez (A60)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO
//Para este ejercicio lo que he hecho para resolverlo es crear tres punteros,(ACTUAL) uno al elemento actual que estamos tratando ,(SIGUIENTE) el segundo al siguiente elemento a tratar
//para poder volver a ese elemento sin importar que le ocurra al actual ,(MENOR)y el ultimo puntero al ultimo nodo que fue estrictamente menor que el pivote , para saber
//donde insertar el siguiente elemento de la lista que sea menor que dicho pivote

//Primero se inicializa el actual como el siguiente al fantasma y el puntero para colocar los menores que el pivote en el fantasma para colocar tras el . El bucle 
//recorre el la cola por completo hasta encontrar el primer elemento que sea estrictamente menor que el pivote . Cuando lo encuentra , lo coloca tras el elemento 
// que apunta MENOR y cambia MENOR para que este apunte al elemento colocado , ACTUAL pasa al siguiente elemento marcado por SIGUIENTE y se continua la ejecucion 
//hasta que ACTUAL apunta al fantasma, lo que significa que se recorrio por completo la cola

//El coste es de O(n) siendo n el numero de elementos de la cola ya que se recorre el puntero ACTUAL todos los elementos y los cambios de punteros necesarios para
//colocar el elemento si este es menor que el pivote son constantes, por eso no aumentan el coste de la funcion.


#include <iostream>               
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class ListaParticion : public deque<int> {
public:
   void print(std::ostream& o = std::cout) const {
       Nodo* elem = fantasma->sig;

       while (elem != fantasma) {
           std::cout << elem->elem << " ";
           elem = elem->sig;
       }
   }
   
   // produce la partición de la lista respecto al privote
   void particion(int pivote) {
       Nodo* actual = fantasma->sig; 
       Nodo* siguiente;
       Nodo* menor = fantasma; //apunta al ultimo elemento encontrado estrictamente menor que el pivote
       //empieza en fantasma para poder evitar una comparacion aparte del primer elemento y asi tratar 
       //todos los elementos por igual

       while (actual != fantasma) {
           siguiente = actual->sig;
           //si es menor que el pivote se coloca delante del elemento que apunta menor
           if (actual->elem < pivote) {
               //se unen los nodos siguiente y anterior del elemento actual
               actual->ant->sig = actual->sig;
               actual->sig->ant = actual->ant;
               //se coloca el elemento en la posicion que le corresponde (tras menor)
               actual->ant = menor;
               menor->sig->ant = actual;
               actual->sig = menor->sig;
               menor->sig = actual;
               //el ultimo elemento encontrado estrictamente menor que el pivote pasa a ser el que hemos colocado, por tanto actual pasa a ser menor
               menor = actual;
           }
           actual = siguiente;
       }

   }
};



/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, ListaParticion const& a) {
   a.print(o);
   return o;
}

bool resuelveCaso() {
   int N, pivote;
   cin >> N >> pivote;
   if (!cin)
      return 0;
   
   ListaParticion lista;
   // leemos la lista de la entrada
   int elem;
   for (int i = 0; i < N; ++i) {
      cin >> elem;
      lista.push_back(elem);
   }
   
   
   lista.particion(pivote);
   
   cout << lista << '\n';
   
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   // system("PAUSE");
#endif
   return 0;
}
