// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "lista_eda.h"

bool mezclalistaenlazadaordenada() {
    // leer los datos de la entrada

    int nelmems ,salto;
    list<int> lista;

    std::cin >> nelmems >> salto;

    if (nelmems == 0 && salto == 0) return false;

    for (int i = 1; i <= nelmems; i++) {
        lista.push_back(i);
    }

    auto iter = lista.begin();
    
    while (lista.size() != 1) {
        int i = 0;
        while (i < salto) {
            i++;
            iter++;
            if (iter == lista.end()) {
                iter = lista.begin();
            }
        }
        iter = lista.erase(iter);
        if (iter == lista.end()) {
            iter = lista.begin();
        }
    }

    std::cout << lista.front();

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    //std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}