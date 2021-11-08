// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;


template <class T>
bool frontera(bintree <T> const& arbol) {
    if (arbol.empty()) {
        return true;
    }
    else {
        bool b1 = frontera(arbol.left()), b2 = frontera(arbol.right());
        if (b1 && b2) {
            cout << arbol.root() << " ";
        }
        return false;
    }
}

void resuelveCaso() {
    bintree <int> arbol = leerArbol(-1);
    frontera(arbol);
    cout << '\n';
}
int main() {
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf());
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