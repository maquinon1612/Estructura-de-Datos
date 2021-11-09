// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "bintree_eda.h"

using namespace std;
template <class T>
int nodos(bintree <T> const& arbol) {
    if (arbol.empty()) {
        return 0;
    }
    else {
        return { nodos(arbol.left()) + nodos(arbol.right()) + 1 };
    }
}

template <class T>
bool hojas(bintree <T> const& arbol, int& hoja) {
    if (arbol.empty()) {
        return true;
    }
    else {
        bool b1 = hojas(arbol.left(), hoja), b2 = hojas(arbol.right(), hoja);
        if (b1 && b2) {
            hoja++;
        }
        return false;
    }
}

template <class T >
T min(bintree <T> const& arbol) {
    if (arbol.left().empty() && arbol.right().empty()) {
        return arbol.root();
    }
    else {
        T minimo = arbol.root();
        if (!arbol.left().empty()) {
            T auxIz = min(arbol.left());
            minimo = min(minimo, auxIz);
        }
        if (!arbol.right().empty()) {
            T auxDr = min(arbol.right());
            minimo = min(minimo, auxDr);
        }
        return minimo
    }
}

bool resuelveCaso() {
    if (!std::cin)
       return false;

    char dato;
    cin >> dato;
    if (dato == 'N') {
        bintree <int> arbol = leerArbol(-1);
        cout << min(arbol) << '\n';
    }
    else if (dato == 'P') {
        string p = "#";
        bintree <string> arbol = leerArbol(p);
        cout << min(arbol) << '\n';
    }

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


    while (resuelveCaso())
        ;


 #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}