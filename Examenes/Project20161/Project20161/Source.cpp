
// NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#include "deque_eda.h"

bool resuelveCaso() {
    int N, M;
    char pos , ini , fin;
    cin >> N >> M;
    deque<char> uno , dos;

    if (N == 0)
        return false;

    char clave;

    for (int j = 0; j < N; ++j) {
        cin >> clave;
        uno.push_back(clave);
    }

    for (int j = 0; j < M; ++j) {
        cin >> clave;
        dos.push_back(clave);
    }

    cin >> pos >> ini >> fin;

    uno.splice(dos , pos , ini ,fin);

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