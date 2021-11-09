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

    map <string, int> sol , ex;
    string clave = "" , mas = "+ " , menos = "- " , asterisco = "* ";
    bool cambio = false;

    for (int i = 1; i < numero + 1; i++) {
        while (clave != "\n") {
            cin >> clave;
            cin >> dato;
            sol[clave] = dato;
        }

        clave = "c";

        while (clave != "\n") {
            cin >> clave;
            cin >> dato;
            ex[clave] = dato;
            if(sol.count(clave)){
                if (sol[clave] != dato) {
                    asterisco = asterisco + clave + " ";
                    cambio = true;
                }
            }
            else {
                mas = mas + clave + " " ;
                cambio = true;
            }
        }

        for (pair<string, int> c : sol) {
            if (!ex.count(c.first)) {
                menos = menos + clave + " ";
                cambio = true;
            }
        }
    }
    // escribir sol
    cout << mas << '\n' << menos << '\n' << asterisco << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
   // auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
   // std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}