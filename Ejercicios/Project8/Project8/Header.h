
#include "queue_eda.h"

template <class T>
class ListaDuplica : public queue<T> {
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
	void duplica() {
        Nodo* cero;
        Nodo* uno = prim;
        if (prim != nullptr) {
            Nodo* dos = this->prim->sig;
            uno->sig = nullptr;

            while (dos != nullptr) {
                cero = uno;
                uno = dos;
                dos = dos->sig;
                uno->sig = cero;
            }
            this->ult = this->prim;
            this->prim = uno;
        }
	}
};