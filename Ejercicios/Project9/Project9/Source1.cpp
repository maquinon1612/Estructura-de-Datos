// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"


class invertircoladoble : public deque<int> {
public:
    void invertir() {
        Nodo* apuntado = fantasma->sig; 
        Nodo* sigi;

        fantasma->sig = fantasma->ant;
        fantasma->ant = apuntado;

        while (apuntado != fantasma) {
            sigi = apuntado->sig;
            apuntado->sig = apuntado->ant;
            apuntado->ant = sigi;
            apuntado = sigi;
        }
    }

    void salida() {
        Nodo* elem = fantasma->sig;

        while (elem != fantasma) {
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
        cola.push_back(a);
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