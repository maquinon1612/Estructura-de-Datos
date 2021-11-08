// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"


class invertircolasimple : public queue<int> {
public :
    void invertir() {
        Nodo* cero;
        Nodo* uno = prim;
        if (prim != nullptr) {
            Nodo* dos = prim->sig;
            uno->sig = nullptr;

            while (dos != nullptr) {
                cero = uno;
                uno = dos;
                dos = dos->sig;
                uno->sig = cero;
            }
            ult = prim;
            prim = uno;
        }
    }

    void salida() {
        Nodo* elem = prim;

        while (elem != nullptr) {
            std::cout << elem->elem << " ";
            elem = elem->sig;
        }
        std::cout << '\n';
    }
};



bool resuelveCaso() {
    // leer los datos de la entrada

    int a;
    invertircola cola;

    if (!std::cin)
        return false;
     
    std::cin >> a;

    while (a != 0) {
        cola.push(a);
        std::cin >> a;
    }

    cola.invertir();
    cola.salida();


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}