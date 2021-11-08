
// NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#include "lista_eda.h"


bool resuelveCaso() {
    int N , dato;
    list<int> lista;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dato;
        lista.push_back(dato);
    }

    lista.estremece();
    lista.print();

    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    //std::ifstream in("casos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    //std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}