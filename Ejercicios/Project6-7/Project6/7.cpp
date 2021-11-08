// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "7h.h"

using namespace std;

void resuelveCaso() {

    Accidente a;
    stack<Accidente> pila;
    stack<Accidente> extra;

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        int h = 0;
        cin >> a;

        while (!pila.empty()) {
            if (pila.top() > a) {
                cout << pila.top();
                break;
            }
            extra.push(pila.top());
            pila.pop();
            h++;
        }

        if (pila.empty()) {
            cout << "NO HAY" << '\n';
        }

        for (int j = 0; j < h; j++) {
            pila.push(extra.top());
            extra.pop();
        }

        pila.push(a);
    }
    cout << "---" << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}