
// NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//orden impota porq no se el stack da fallo si antes en deque ambiguo

#include "lista_eda.h"
#include <stack>


template<class T>
void suffle(list<T>& l, int i, int k) {
    
    stack<T> pila;
    auto it = l.begin();

    for (int j = 1; j < i; j++) {
        it++;
    }
    int ciclos = 0;
    while (ciclos < k && it != l.end()) {
        pila.push(it.operator*());
        it = l.erase(it);
        ciclos++;
    }
    while (!pila.empty()) {
        l.insert(it, pila.top());
        pila.pop();
    }
}

bool resuelveCaso() {
    int N;
    cin >> N;
    list<char> l;

    if (N == 0)
        return false;

    // leemos
    int i, k;

    cin >> i >> k;

    char clave;
    
    for (int j = 0; j < N; ++j) {
        cin >> clave;
        l.push_back(clave);
    }
    
    suffle(l, i, k);
    l.print();

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