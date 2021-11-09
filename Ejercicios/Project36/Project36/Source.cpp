// Mario Quiñones Perez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Alumno.h";

using namespace std;

bool resuelveCaso() {
    // leer los datos de la entrada

    long long int numero;

    cin >> numero;

    if (numero == 0)
        return false;

    puntuacion sol;
    string alumno, correcto, basura;

    getline(cin , basura);

    for (int i = 0; i < numero; i++) {
        getline(cin, alumno);
        getline(cin, correcto);
        if (correcto == "CORRECTO") {
            sol.puntuar(alumno, true);
        }
        else {
            sol.puntuar(alumno, false);
        }
    }

    // escribir sol
    sol.lista_alumnos();

    return true;

}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


    while (resuelveCaso())
        ;


#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}