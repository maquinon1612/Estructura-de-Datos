// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Pelicula.h"



bool resuelveCaso() {

    int num_peliculas;
    std::vector<Pelicula> pelicula[100];
    Pelicula p;
    bool done = false;

    std::cin >> num_peliculas;
    if (num_peliculas == 0) return false;

    for (int i = 0; i < num_peliculas; i++) {
        try {
            std::cin >> p;
            pelicula->push_back(p);
        }
        catch (std::invalid_argument & ia) {
            std::cout << ia.what() << '\n';
        }
    }

    std::sort(pelicula->begin, pelicula->end);

    for (int i = 0; i < num_peliculas; i++) {
        std::cout << pelicula->at(i);
    }
   
    std::cout << "---" << '\n';
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}