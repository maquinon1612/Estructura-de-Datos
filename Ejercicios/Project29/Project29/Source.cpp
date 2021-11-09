// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct dato{
    int max;
    int min;
    bool sol;
};

template <class T>
dato binbusqueda(bintree <T> const& arbol) {
    dato sol;
    if (arbol.empty() || (arbol.left().empty() && arbol.right().empty())) {
        sol.sol = true;
    }
    else {
        sol.min = arbol.root();
        sol.max = arbol.root();
        bool si = true;
        if (!arbol.right().empty()) {
            dato d = binbusqueda(arbol.right());
            si = si && d.sol && d.min < arbol.root();
            if (si) {
                sol.min = d.min;
            }
        }
        if (!arbol.left().empty()) {
            dato d = binbusqueda(arbol.left());
            si = si && d.sol && d.max < arbol.root();
            if (si) {
                sol.max = d.max;
            }
        }
        sol.sol = si;
    }
    return sol;
}

void resuelveCaso() {
    bintree <int> arbol = leerArbol(-1);
    if (binbusqueda(arbol).sol) {
        cout << "SI" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    
}
int main() {
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
   // auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    //std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}