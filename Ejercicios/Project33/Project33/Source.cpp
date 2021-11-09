// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

template <class T>
std::vector<pair<int, T>> nivel(bintree <T> arbol) {
    std::vector<pair<int, T>> levels;
    int n;
    bool fin = false;
    if (!arbol.empty()) {
        pair<int, T> par;
        par = (n, arbol.root());
        cout << arbol.root();
        while (!fin) {
            Link sig = pendientes.front();
            pendientes.pop();
            levels.push_back(sig->elem);
            if (sig->left != nullptr)
                pendientes.push(sig->left);
            if (sig->right != nullptr)
                pendientes.push(sig->right);
        }
    }
    return levels;
}

void resuelveCaso() {
    bintree <int> arbol = leerArbol(-1);
    frontera(arbol);
    cout << '\n';
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