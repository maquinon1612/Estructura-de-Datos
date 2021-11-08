// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

bool resuelveCaso() {

    string frase;
    bool equilibrada = true;
    stack<char> pila;

    if (!std::cin)
        return false;

    getline(cin, frase);

    for (char c : frase) {
            if (c == '(' || c == '[' || c == '{') {
                equilibrada = false;
                pila.push(c);
            }
            else if (c == ')') {
                if (!pila.empty() && pila.top() == '(') {
                    equilibrada = true;
                    pila.pop();
                }
                else {
                    equilibrada = false;
                }
            }
            else if (c == ']') {
                if (!pila.empty() && pila.top() == '[') {
                    pila.pop();
                    equilibrada = true;
                }
                else {
                    equilibrada = false;
                }
            }
            else if (c == '}') {
                if (!pila.empty() && pila.top() == '{') {
                    pila.pop();
                    equilibrada = true;
                }
                else {
                    equilibrada = false;
                }
            }
    }
    
    if (frase.size() != 0) {
        if (equilibrada && pila.empty()) {
            cout << "SI" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

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
