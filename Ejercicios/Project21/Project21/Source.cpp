// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

template <class T>
pair<int, int> diametro(bintree <T> arbol) {

    pair<int, int> dato;
    dato.first = 0;
    dato.second = 0;
    pair<int, int> dato1 = dato , ret = dato;

    if (arbol.empty()) {
        return ret;
    }
    else {
        if (!arbol.left().empty()) {
            dato = diametro(arbol.left());
        }
        if (!arbol.right().empty()) {
            dato1 = diametro(arbol.right());
        }
        ret.second = max(dato.second, dato1.second) + 1;
        int diamex = dato.second + dato1.second + 1;
        ret.first = max(max(dato.first, dato1.first), diamex);
        return ret;
    }

}

void resuelveCaso() {
    bintree <char> arbol = leerArbol('.');
    diametro(arbol);
    cout << diametro(arbol).first << '\n';
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}