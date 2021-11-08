//Mario Quiñones Pérez

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO

// Creo un unorder map ya que no es necesario que los datos esten ordenados 
// Para cada aviso que sera la clave en el mapa la añado a su vector de string las horas que quedaran en el mismo orden en las que nos las dieron
// Por Cada caso que se nos pida mostrar comprovamos si existen suficientes en el el vector correspondiente , y si los hay lo escrimos por pantalla
// el elemento del mapa de la clave que nos pidan que este en la posicion dada para su vector de strings

//El orden de las operaciones es de orden constante en el caso de añadir los elementos ya que el operador[] al insertar de orden constante y el push 
//back tambien lo es y constante tambien en el caso de buscar un elemento concreto ya que la funcion de buscar del operador [] de unorder_map es 
//constante por tener los elementos distribuidos de una forma uniforme y la clase vector el operador [] es constante tambien


bool resuelveCaso() {
    int N , M;
    cin >> N;
    if (!cin)
        return false;
    cin >> M;

    string aviso , momento;
    unordered_map<string, vector<string>> avisos;

    for (int i = 0; i < N; i++) {
        cin >> aviso >> momento;
        avisos[aviso].push_back(momento);
    }

    int dato;

    for (int i = 0; i < M; i++) {
        cin >> aviso >> dato;
        int tam = avisos[aviso].size();
        if (tam <= dato - 1) {
            cout << "--";
        }
        else {
            cout << avisos[aviso][dato - 1];
        }
        cout << " ";
    }

    cout << endl;

    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
