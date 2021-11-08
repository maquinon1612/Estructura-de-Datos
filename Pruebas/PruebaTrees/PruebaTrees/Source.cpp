// Mario Quiñones Pérez
// A60


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
#include "set_eda.h"

using namespace std;


////////////////////////////////////////////////////////////////////////

/*NORMALES*/

template <class T>
bool frontera(bintree <T> const& arbol) {
    if (arbol.empty()) {
        return true;
    }
    else {
        bool b1 = frontera(arbol.left()), b2 = frontera(arbol.right());
        if (b1 && b2) {
            cout << arbol.root() << " ";
        }
        return false;
    }
}

template <class T>
bool simetrico(bintree <T> const& A , bintree <T> const& B) {
    if (A.empty() && B.empty()) {
        return true;
    }
    else if (A.empty() || B.empty()) {
        return false;
    }
    else {
        return simetrico(A.right() , B.left()) && simetrico(A.left() , B.right());
    }
}

struct datos
{
    int navegables;
    int anterior;
};

datos navegables(bintree <int> const& arbol) {

    datos ret = {0,0} , izq , der;

    if (arbol.empty()) {
        return ret;
    }
    else {
        izq = navegables(arbol.left());
        der = navegables(arbol.right());

        if (arbol.left().empty() && arbol.right().empty()) {
            ret.anterior++;
        }

        ret.anterior = ret.anterior + izq.anterior + der.anterior - arbol.root();

        if (ret.anterior < 0) {
            ret.anterior = 0;
        }

        if (izq.anterior >= 3){
            ret.navegables++;
        }

        if (der.anterior >= 3) {
            ret.navegables++;
        }

        ret.navegables = ret.navegables + izq.navegables + der.navegables;

        return ret;
    }
}

struct subcom
{
    int maximo;
    int tam;
};

template <class T>
subcom subcompleto(bintree <T> const& arbol) {

    subcom ret = {0, 0}, izq, der;

    if (arbol.empty()) {
        return ret;
    }
    else {
        izq = subcompleto(arbol.left());
        der = subcompleto(arbol.right());

        ret.tam = min(izq.tam, der.tam) + 1;
        ret.maximo = max(max(izq.maximo, der.maximo), ret.tam);

        return ret;
    }
}


////////////////////////////////////////////////////////////////////////

/*ALTURA*/

template <class T>
struct datar
{
    bintree <T> tree;
    int altura;
};

template <class T>
std::vector<datar<T>> perfilizq(bintree <T> const& arbol){
    std::vector<datar<T>> levels;
    datar<T> d;
    if (!arbol.empty()) {
        std::queue<datar<T>> pendientes;
        d = { arbol , 0 };
        pendientes.push(d);
        levels.push_back({arbol , 0});
        while (!pendientes.empty()) {
            datar<T> sig = pendientes.front();
            pendientes.pop();
            if (levels.back().altura < sig.altura) {
                levels.push_back(sig);
            }
            if (!sig.tree.left().empty())
                pendientes.push({ sig.tree.left() , sig.altura + 1 });
            if (!sig.tree.right().empty())
                pendientes.push({sig.tree.right(), sig.altura + 1});
        }
    }
    return levels;
}

struct mul7
{
    bool encontrado;
    int dato;
    int altura;
};

struct datara
{
    bintree <int> tree;
    int altura;
};

bool esPrimo(int numero) {
    // Casos especiales
    if (numero == 0 || numero == 1 || numero == 4) return false;
    for (int x = 2; x < numero / 2; x++) {
        if (numero % x == 0) return false;
    }
    // Si no se pudo dividir por ninguno de los de arriba, sí es primo
    return true;
}

mul7 accesible_mul7(bintree <int> const& arbol) {
    mul7 sol = {false,0,0};
    bool enc = false;
    if (!arbol.empty()) {
        queue<datara> pendientes;
        pendientes.push({ arbol , 1 });
        while (!pendientes.empty() && !enc) {
            bintree <int> sig = pendientes.front().tree;
            int altura = pendientes.front().altura;
            pendientes.pop();
            if (!esPrimo(sig.root())) {
                if (sig.root() % 7 == 0) {
                    sol.dato = sig.root();
                    sol.altura = altura;
                    sol.encontrado = true;
                    enc = true;
                }
                if (!sig.left().empty())
                    pendientes.push({sig.left() , altura + 1 });
                if (!sig.right().empty())
                    pendientes.push({sig.right() , altura + 1 });
            }
        }
    }
    return sol;
}

////////////////////////////////////////////////////////////////////////

/*COMPLETO O SEMI*/

struct comp
{
    bool completo;
    bool semi;
    int alt;
};

template <class T>
comp completo_semi(bintree <T> const& arbol) {

    comp ret = {true, true, 0}, izq, der;

    if (arbol.empty()) {
        return ret;
    }
    else {
        izq = completo_semi(arbol.left());
        der = completo_semi(arbol.right());

        if (izq.completo && der.completo) {
            if (izq.alt - 1 == der.alt) {
                ret.completo = false;
                ret.semi = true;
                ret.alt = der.alt + 1;
            }
            else if (izq.alt == der.alt) {
                ret.completo = true;
                ret.semi = true;
                ret.alt = der.alt + 1;
            }
            else{
                ret.completo = false;
                ret.semi = false;
                ret.alt = der.alt;
            }
        }
        else if (!izq.completo && !der.completo) {
            ret.completo = false;
            ret.semi = false;
        }
        else if (!izq.completo && izq.semi && der.completo) {
            ret.completo = false;
            if (izq.alt == der.alt) {
                ret.semi = true;
                ret.alt = izq.alt + 1;
            }
            else {
                ret.semi = false;
            }
        }
        else if (izq.completo && !der.completo && der.semi) {
            ret.completo = false;
            if (izq.alt - 1== der.alt) {
                ret.semi = true;
                ret.alt = der.alt + 1;
            }
            else {
                ret.semi = false;
            }
        }

        return ret;
    }
}

////////////////////////////////////////////////////////////////////////

/*GENERALES*/

int altgen() {
    int dato, altura = 0 , max = 0;
    cin >> dato;
    for (int i = 0; i < dato; i++) {
        altura = altgen();
        if (altura > max) {
            max = altura;
        }
    }
    return max + 1;
}

int precarios(int altura , int const& pre) {
    int dato, num = 0, ret = 0;
    cin >> dato;
    for (int i = 0; i < dato; i++) {
        num = precarios(altura + 1 , pre);
        if (altura >= pre && num == 0) {
            ret++;
        }
        else {
            ret += num;
        }
    }
    return ret;
}

////////////////////////////////////////////////////////////////////////

/*BUSQUEDA*/

template <typename T>
sol<T> es_abbr(bintree<T> const& a) {
    sol<T> res;
    if (a.empty()) {
        res.abb = true;
    }
    else {
        sol<T> iz = es_abbr(a.left());
        sol<T> dr = es_abbr(a.right());

        res.min = a.left().empty() ? a.root() : iz.min;
        res.max = a.right().empty() ? a.root() : dr.max;

        bool ord = (a.left().empty() || iz.max < a.root()) &&
            (a.right().empty() || dr.min > a.root());

        res.abb = iz.abb && dr.abb && ord;
    }
    return res;
}

template <typename T>
bool es_abb(bintree<T> const& a) {
    return es_abbr(a).abb;
}

////////////////////////////////////////////////////////////////////////

/*RECONSTRUCCION*/

bintree <int> reconstruc(vector<int> const& P, vector<int> const& I , int &in , int &pre ,int tope) {
    if (pre == P.size() || tope == I[in]) {
        return {};
    }

    int raiz = P[pre];
    ++pre;

    bintree <int> iz = reconstruc(P, I, in, pre, raiz);
    ++in;
    bintree <int> dr = reconstruc(P, I, in, pre, tope);

    return { iz,raiz,dr };
}

bintree<int> reconstrucbusqueda(vector<int> const& P, int& pre, int ant) {
    if (pre == P.size() || P[pre] > ant) {
        return {};
    }

    int raiz = P[pre];
    ++pre;

    bintree <int> iz = reconstrucbusqueda(P, pre, raiz);
    bintree <int> dr = reconstrucbusqueda(P, pre, ant);

    return { iz,raiz,dr };
}
////////////////////////////////////////////////////////////////////////

/*EXAM*/

struct tSol {
    int num_salvados;
    int caballeros;
};

tSol f(bintree<char> const& a, int monstruos) {
    tSol ret;
    if (a.empty()) return { 0,0 };
    else {
        if (a.root() == 'M') ++monstruos;
        tSol iz = f(a.left(), monstruos);
        tSol dr = f(a.right(), monstruos);

        if (a.root() == 'D') {
            if (monstruos <= iz.caballeros + dr.caballeros) {
                return { iz.num_salvados + dr.num_salvados + 1, iz.caballeros + dr.caballeros };
            }
            else {
                return { iz.num_salvados + dr.num_salvados, iz.caballeros + dr.caballeros };
            }
        }

        else if (a.root() == 'C') {
            return { iz.num_salvados + dr.num_salvados, iz.caballeros + dr.caballeros + 1};
        }

        else{}
        
    }
}

struct renta
{
    int max;
    bool rentable;
};

renta fun(bintree<int> const& a, int actual) {
    if (a.empty()) {
        return { 0, false };
    }
    else {
        if (actual == 0) {
            renta iz = fun(a.left(), actual + a.root());
            renta dr = fun(a.right(), actual + a.root());
            return { max(iz.max , dr.max) , iz.rentable || dr.rentable };
        }
        if (actual + a.root() > 0) {
            renta iz = fun(a.left(), actual + a.root());
            renta dr = fun(a.right(), actual + a.root());
            return { max(max(iz.max , dr.max), actual + a.root()) , true };
        }
        else {
            return { 0, false };
        }
    }
}

void mejor_renta(bintree<int> const& a, bool& r, int& max) {
    renta ren = fun(a, 0);
    r = ren.rentable;
    max = ren.max;
}

int hojasmask(bintree<int> const& a, int altura,const int& k) {
    if (a.left().empty() && a.right().empty() && altura > k) {
        return 1;
    }
    else {
        int iz = 0 , dr = 0;
        if (!a.left().empty()) {
            iz = hojasmask(a.left(), altura + 1, k);
        }
        if (!a.right().empty()) {
            dr = hojasmask(a.right(), altura + 1, k);
        }

        return iz + dr;
    }
}


struct sint
{
    int sum;
    int total;
};

sint singular(bintree<int> const& a, int sum) {
    if (a.empty()) {
        return {0 , 0};
    }
    else {
        sint iz , dr;
        iz = singular(a.left(), sum + a.root());
        dr = singular(a.right(), sum + a.root());

        if (iz.sum + dr.sum == sum + a.root()) {
            return { iz.sum + dr.sum + a.root() , iz.total + dr.total + 1 };
        }
        else {
            return { iz.sum + dr.sum + a.root() , iz.total + dr.total};
        }
    }
}


int tiempo_Ayudafun(bintree<char> const& a, int altura) {
    if (a.empty()) {
        return 0;
    }
    else {
        int iz = tiempo_Ayudafun(a.left(), altura + 1);
        int dr = tiempo_Ayudafun(a.right(), altura + 1);

        if (a.root() == 'X') {
            int sol = 0;
            if (iz == 0 && dr == 0) {
                return 2 * altura;
            }
            else if (iz == 0 || dr == 0) {
                return max(dr , iz);
            }
            else {
                return dr + iz;
            }
        }
        else {
            return iz + dr;
        }
    }
}

int tiempoAyud(bintree<char> const& a) {
    return tiempo_Ayudafun(a, 0);
}


template <typename T>
struct sol
{
    T min;
    T max;
    bool abb;
};

void resuelveCaso() {
    bintree<int> a = leerArbol(-1);

    /*
    
    




    
    if (!arbol.empty()) {
        if (simetrico(arbol.right(), arbol.left())) {
            cout << "SI";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "SI";
    }








    frontera(arbol);
    cout << '\n';








    datos d;
    d = navegables(arbol);
    cout << d.navegables <<'\n';
    






    cout << subcompleto(arbol).maximo;
    






    std::vector<datar<int>> p = perfilizq(arbol);

    for (datar<int> c : p) {
        cout << c.tree.root();
    }







    mul7 sol = accesible_mul7(arbol);
    if (sol.encontrado) {
        cout << sol.dato << " " << sol.altura;
    }
    else {
        cout << "No hay";
    }
    cout << '\n';







    comp c = completo_semi(arbol);
    if (c.completo) {
        cout << "completo";
    }
    else if (c.semi) {
        cout << "semi";
    }
    else {
        cout << "NADA";
    }








    set<int> arbol;
    int N, dato;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dato;
        arbol.insert(dato);
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dato;
        cout << arbol.lower_bound(dato).second;
    }






    cout << altgen() << '\n';







    int pre;
    cin >> pre;
    cout << precarios(1 , pre) << '\n';











    int N , dato;
    vector<int>  A, B;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dato;
        A.push_back(dato);
    }

    for (int i = 0; i < N; i++) {
        cin >> dato;
        B.push_back(dato);
    }

    int in = 0, pre = 0;

    bintree<int> arbol = reconstruc(A, B, in, pre, -1);
    A = arbol.postorder();

    for (int i : A) {
        cout << i;
    }











     int N, dato;
    vector<int>  A;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dato;
        A.push_back(dato);
    }

    int pre = 0;

    bintree<int> arbol = reconstrucbusqueda(A, pre, 10000);
    A = arbol.postorder();

    for (int i : A) {
        cout << i;
    }







    bool r;
    int max;

    mejor_renta(a, r, max);

    if (r) {
        cout << "si" << max << '\n';
    }
    else {
        cout << "no" << '\n';
    }








    cout << hojasmask(a, 1, k) << '\n';








    sint sol = singular(a, 0);
    cout << sol.total << '\n';







    cout << tiempoAyud(a);







    int clave;
    cin >> clave;

    cout << a.siguiente(clave, -1);
    */
}

int main() {
#ifndef DOMJUDGE
    //std::ifstream in("datos.txt");
    //auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    //std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}