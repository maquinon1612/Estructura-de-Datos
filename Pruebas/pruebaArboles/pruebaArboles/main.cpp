
// Mario Quiñones Pérez (A60)

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO

// En este ejercicio se pide implementar una funcion que determine si es diestro, aunque no lo pone en el enunciado explicitamente he supuesto que si tiene hijo 
// izquierdo y no tiene hijo derecho este no es diestro ya que la suma de el derecho (si solo puede haber enteros positivos mayores que cero en los nodos) sera 0
// y la del izquierdo mayor que cero


// Si el arbol es vacio se considera diestro y se devuelve 0 como la suma de sus nodos ya que no tiene , si un nodo no tiene hijos tambien se le considera diestro y se 
// devuelve la raiz como la suma total de los nodos , si no fuese uno de los casos anteriores , entonces tiene al menos un hijo . Si estamos en este ultimo caso , se
// comprueba que ambos hijos son diestro , si lo son y la suma de los nodos de la derecha es estrictamente mayor que los de la izquierda se devuelve que ese nodo es diestro
// y la suma de los nodos de todo ese subarbol. Si no fuese mayor los de la derecha o alguno de sus hijos no fuera diestro , se devuelve que el subarbol no es diestro 
// y se devuelve la suma de sus nodos aunque en este caso ya no importaria dicha suma.


// El coste de esta funcion es de O(n) siendo n el numero de nodos del arbol , ya que la funcion tiene coste constante en el caso base y en el caso recursivo tiene las 
// siguientes llamdas: f(n/2) + f(n/2) + c , donde f(n/2) representa la mitad de los nodos del arbol(en el caso de un arbol completo) y c es una constante


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"


// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites


struct datos
{
    int suma;
    bool diestro;
};


datos diestro_aux(bintree<int> const& arbol) {
    if (arbol.empty()) { // si el arbol es vacio entonces es diestro
        return {0,true};
    }
    else if (arbol.left().empty() && arbol.right().empty()) { // si es una hoja entonces es diestro
        return {arbol.root() , true};
    }
    else { // almenos un nodo no esta vacio
        datos iz = diestro_aux(arbol.left());
        datos dr = diestro_aux(arbol.right());

        if (iz.diestro && dr.diestro && dr.suma > iz.suma) { // si sus dos hijos son diestros y la suma de los nodos de la derecha es mayor que los de la izquieda es diestro
            return {iz.suma + dr.suma + arbol.root(),true};
        }
        else { 
            return { iz.suma + dr.suma + arbol.root(),false}; // se devuelve false porque no es diestro y sus ancestros tampoco lo seran
        }
    }
}

template <typename T>
bool diestro(bintree<T> const& arbol) {
    return diestro_aux(arbol).diestro;
}


void resuelveCaso() {
   auto arbol = leerArbol(-1);
   if (diestro(arbol))
      cout << "SI\n";
   else
      cout << "NO\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   // system("PAUSE");
#endif
   return 0;
}
