
// NOMBRE Y APELLIDOS


#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//orden impota porq no se el stack da fallo si antes en deque ambiguo

#include "lista_eda.h"
#include "queue_eda.h"
#include<stack>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class ListaInsert : public queue<T> {
    using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
    void print(std::ostream& o = std::cout) const {
        Nodo* elem = this->prim;

        while (elem != nullptr) {
            o << elem->elem << " ";
            elem = elem->sig;
        }
        o << '\n';
    }
    // duplicar los nodos de una lista enlazada simple
    void insertar(queue<T>* q, int pos) {
        if (this->prim != nullptr) {
            Nodo* aux = this->prim;
            int i = 0;
            while (aux != nullptr && i < pos - 1) {
                aux = aux->sig;
                i++;
            }
            /////
            q->ult->sig = aux->sig;
            aux->sig = q->prim;
            q->prim = nullptr;
            q->ult = nullptr;
            q->nelems = 0;
            /////
        }
    }
};

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

class invertircolasimple : public queue<int> {
public:
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

class deque2 : public deque<int> {
public:
    void duplicar() {

        auto apuntado = fantasma->sig;
        auto siguiente = apuntado->sig;
        int elem;

        while (apuntado != fantasma) {
            siguiente = apuntado->sig;
            elem = apuntado->elem;
            apuntado->sig = new Nodo(elem, apuntado, siguiente);
            siguiente->ant = apuntado->sig;
            apuntado->sig->sig = siguiente;
            apuntado = siguiente;
            nelems++;
        }

    }

    void const mostrar() const {
        auto apuntado = fantasma->sig;

        while (apuntado != fantasma) {
            std::cout << apuntado->elem << " ";
            apuntado = apuntado->sig;
        }
        std::cout << '\n';
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void suffle(list<T>& l, int i, int k) {

    stack<T> pila;
    auto it = l.begin();

    for (int j = 1; j < i; j++) {
        it++;
    }
    int ciclos = 0;
    while (ciclos < k && it != l.end()) {
        pila.push(it.operator*());
        it = l.erase(it);
        ciclos++;
    }
    while (!pila.empty()) {
        l.insert(it, pila.top());
        pila.pop();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool resuelveCaso() {
    int N;
    cin >> N;
    list<char> l;

    if (N == 0)
        return false;

    char clave;

    for (int j = 0; j < N; ++j) {
        cin >> clave;
        l.push_back(clave);
    }

    l.doblarlista();
    l.print();

    return true;
}

bool mezclalistaenlazadaordenada() {
    // leer los datos de la entrada

    int nelmems, salto;
    list<int> lista;

    std::cin >> nelmems >> salto;

    if (nelmems == 0 && salto == 0) return false;

    for (int i = 1; i <= nelmems; i++) {
        lista.push_back(i);
    }

    auto iter = lista.begin();

    while (lista.size() != 1) {
        int i = 0;
        while (i < salto) {
            i++;
            iter++;
            if (iter == lista.end()) {
                iter = lista.begin();
            }
        }
        iter = lista.erase(iter);
        if (iter == lista.end()) {
            iter = lista.begin();
        }
    }

    std::cout << lista.front();

    return true;
}
/*
int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    //std::ifstream in("casos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    //std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}*/