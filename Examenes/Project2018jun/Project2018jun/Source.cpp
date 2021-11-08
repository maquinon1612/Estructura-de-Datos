
// NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#include "queue_eda.h"


bool resuelveCaso() {
    int N, M, dato;
    queue<int> mixer;
    queue<int> amezclar;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> dato;
        mixer.push(dato);
    }

    for (int i = 0; i < M; i++) {
        cin >> dato;
        amezclar.push(dato);
    }

    mixer.mezclador(amezclar);
    //mixer.print();

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