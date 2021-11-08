// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Horas.h"

#include<stdexcept>
#include <algorithm>
#include <vector>

bool resuelveCaso() {

    int trenes, horas, posicion = -1;
    std::vector<Hora> htrenes(1000);
    Hora ho;

    std::cin >> trenes >> horas;
    if (trenes == 0 || horas == 0) return false;

    for (int i = 0; i < trenes; i++) {
        std::cin >> ho;
        htrenes[i] = ho;
    }

    for (int j = 0; j < horas; j++) {
        try {
            std::cin >> ho;

            auto sol = std::upper_bound(htrenes.begin() , htrenes.end() , ho);

            if (sol == htrenes.end()) {
                std::cout << "NO" << '\n';
            }
            else {
                std::cout << *sol;
            }
        }
        catch (std::invalid_argument & ia) {
            std::cout << ia.what() << '\n';
        }
    } 
    std::cout << "---" << '\n';
    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
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