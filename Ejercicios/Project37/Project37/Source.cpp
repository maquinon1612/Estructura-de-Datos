// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

using namespace std;

void resuelveCaso() {
    // leer los datos de la entrada
    long long int numero;
    long long int dato;

    cin >> numero;

    map <int, int> sol;
    int tamanio , max = 0 , distancia = 0;

    for (int i = 1; i < numero + 1; i++) {
        cin >> dato;
        tamanio = i - sol[dato] - distancia;
        if (tamanio > max) {
            max = tamanio;
        }
        else if (sol[dato] != 0){
            distancia = sol[dato];
        }
        sol[dato] = i;
    }
    // escribir sol
    cout << max << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}