//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>  // std::domain_error

template <class T>
class queue {
protected:

    /*
     Nodo que almacena internamente el elemento (de tipo T),
     y un puntero al nodo siguiente, que puede ser nullptr si
     el nodo es el último de la lista enlazada.
     */
    struct Nodo {
        Nodo() : sig(nullptr) {}
        Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
        T elem;
        Nodo* sig;
    };

    // punteros al primer y último elemento
    Nodo* prim;
    Nodo* ult;

    // número de elementos en la cola
    int nelems;

public:

    // constructor: cola vacía
    queue() : prim(nullptr), ult(nullptr), nelems(0) {}

    // destructor
    ~queue() {
        libera();
    }

    // constructor por copia
    queue(queue<T> const& other) {
        copia(other);
    }

    // operador de asignación
    queue<T>& operator=(queue<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // añadir un elemento al final de la cola
    void push(T const& elem) {
        Nodo* nuevo = new Nodo(elem);

        if (ult != nullptr)
            ult->sig = nuevo;
        ult = nuevo;
        if (prim == nullptr) // la cola estaba vacía
            prim = nuevo;
        ++nelems;
    }

    // consultar el primero de la cola
    T const& front() const {
        if (empty())
            throw std::domain_error("la cola vacia no tiene primero");
        return prim->elem;
    }

    // eliminar el primero de la cola
    void pop() {
        if (empty())
            throw std::domain_error("eliminando de una cola vacia");
        Nodo* a_borrar = prim;
        prim = prim->sig;
        if (prim == nullptr) // la cola se ha quedado vacía
            ult = nullptr;
        delete a_borrar;
        --nelems;
    }

    // consultar si la cola está vacía
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tamaño de la cola
    int size() const {
        return nelems;
    }

    void mezclador(queue& other) {
        mezclar(other);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void mezclar(queue<T>& cola) {
        if (prim != nullptr && cola.prim != nullptr) {
            Nodo* act1 = prim;
            Nodo* act2 = cola.prim;
            while (act1 != nullptr && act2 != nullptr) {
                Nodo* sig1 = act1->sig;
                Nodo* sig2 = act2->sig;
                if (sig1 == nullptr) {
                    if (act1->elem < act2->elem) {
                        act1->sig = act2;
                        ult = cola.ult;
                    }
                }
                else if (act1->sig->elem > act2->elem) {
                    act2->sig = act1->sig;
                    act1->sig = act2;
                    sig1 = act2;
                    act2 = sig2;
                }
                else if (act1->elem > act2->elem) {
                    prim = cola.prim;
                    act2->sig = act1;
                    sig1 = act1;
                    act2 = sig2;
                }
                act1 = sig1;
            }
            nelems = nelems + cola.nelems;
            cola.prim = nullptr;
            cola.ult = nullptr;
            cola.nelems = 0;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

protected:

    void libera() {            //O(n)
        while (prim != nullptr) {
            Nodo* a_borrar = prim;
            prim = prim->sig;
            delete a_borrar;
        }
        ult = nullptr;
    }

    // this está sin inicializar
    void copia(queue const& other) {       //O(n)
        if (other.empty()) {
            prim = ult = nullptr;
            nelems = 0;
        }
        else {
            Nodo* act = other.prim; // recorre la cola original
            Nodo* ant = new Nodo(act->elem); // último nodo copiado
            prim = ant;
            while (act->sig != nullptr) {
                act = act->sig;
                ant->sig = new Nodo(act->elem);
                ant = ant->sig;
            }
            ult = ant;
            nelems = other.nelems;
        }
    }
};

#endif // queue_eda_h