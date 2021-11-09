// Mario Quiñones Perez
// A60



#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

// copia el fichero hashmap_eda.h en hashmap_modificado.h
// y añade ahí la nueva operación (haciendo todos los cambios
// que consideres necesarios para implementar tu solución)
#include "hashmap_modificado.h"


// para asegurarnos de tener listas con más de un elemento
// utilizamos esta función hash que envía todas las claves a
// la posición 0
class Hash_colisionador {
public:
    size_t operator()(int x) const {
        return 0;
    }
};

bool resuelveCaso() {

    int N;
    cin >> N;
    /*
    if (N == 0)
        return false;
    */

    string l = "habia una vez";

    // dos tablas para hacer las pruebas
    unordered_map<int, int> tabla;
    unordered_map<int, int, Hash_colisionador> tabla_colisiones;

    // leemos
    int clave;

    for (int i = 0; i < N; ++i) {
        cin >> clave;
        tabla[clave] = 0;
        tabla_colisiones[clave] = 0;
    }

    // borramos las claves pares
    auto it = tabla.begin();
    while (it != tabla.end()) {
        if (it->clave % 2 == 0)
            it = tabla.erase(it);
        else
            ++it;
    }
    // comprobamos que solamente han quedado claves impares
    for (auto cv : tabla)
        assert(cv.clave % 2 == 1);

    // Y ahora con la tabla con colisiones seguras
    // borramos las claves pares
    auto it_col = tabla_colisiones.begin();
    while (it_col != tabla_colisiones.end()) {
        if (it_col->clave % 2 == 0)
            it_col = tabla_colisiones.erase(it_col);
        else
            ++it_col;
    }
    // comprobamos que solamente han quedado claves impares
    for (auto cv : tabla_colisiones)
        assert(cv.clave % 2 == 1);

    // si hemos llegado hasta aquí, todo ha ido bien
    cout << "TODO BIEN\n";

    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
};
