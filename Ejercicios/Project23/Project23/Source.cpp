// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

template <class T>
bool genealogico(bintree <T> const&arbol) {

    bool ret = false;

    if (arbol.empty()) {
        return true;
    }
    else {
        if (!arbol.left().empty()) {
            ret = (arbol.left().root() <= (arbol.root() - 18)) && genealogico(arbol.left());
            if (!arbol.right().empty()) {
                ret = ret && (arbol.right().root() <= (arbol.left().root() - 2)) && genealogico(arbol.right());
            }
            else return genealogico(arbol.right());
        }
        else
        return genealogico(arbol.left());
    }

}

template <class T >
int altura(bintree <T > const& arbol) {
    if (arbol.empty()) {
        return 0;
    }
    else {
        int alt_iz = altura(arbol.left());
        int alt_dr = altura(arbol.right());
        return { max(alt_iz , alt_dr) + 1 };
    }
}

void resuelveCaso() {
    bintree <int> arbol = leerArbol(-1);
    if (genealogico(arbol)) {
        cout << "SI " << altura(arbol) << '\n';
    }
    else{
        cout << "NO " << '\n';
    }
}

int main() {
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}