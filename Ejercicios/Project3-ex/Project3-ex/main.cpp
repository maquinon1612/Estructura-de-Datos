
// Mario Quiñones Pérez
// A60

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct datos {
    int diam_max;
    int camino_max_act;
};

datos diametro(bintree <int> const& arbol) {

    datos dato;
    dato.diam_max = 0;
    dato.camino_max_act = 0;
    datos dato1 = dato, ret = dato;
    int diamex;

    if (arbol.empty()) {
        return ret;
    }
    else {
        dato = diametro(arbol.left());
        dato1 = diametro(arbol.right());
        if (arbol.root() % 2 == 0) {
            diamex = dato.camino_max_act + dato1.camino_max_act + 1;
            ret.camino_max_act = max(dato.camino_max_act, dato1.camino_max_act) + 1;
        }
        else {
           diamex = max(dato.camino_max_act, dato1.camino_max_act);
        }
        ret.diam_max = max(max(dato.diam_max, dato1.diam_max), diamex);
        return ret;
    }

}

int caminoPares(bintree<int> arbol) {
   // completar (posiblemente definiendo también otras funciones)
    datos sol;
    sol = diametro(arbol);
    return sol.diam_max;
}

void resuelveCaso() {
   bintree<int> arbol = leerArbol(-1);
   cout << caminoPares(arbol) << '\n';
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
   system("PAUSE");
#endif
   return 0;
}
