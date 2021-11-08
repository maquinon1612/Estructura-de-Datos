// Mario Quiñones Pérez
// A60


#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm> 

using namespace std;


////////////////////////////////////////////////////////////////////////
/*MAPAS*/
/*

bool referenciascruzadas() {
    int N;
    cin >> N;
    if (N == 0) return false;
    cin.ignore();

    map<string, vector<int>> refs;


    string linea, palabra;
    for (int i = 1; i <= N; i++) {
        getline(cin , linea);
        stringstream lin(linea);
        while (lin >> palabra) {
            if (palabra.length > 2) {
                for (char& c : palabra) c = tolower(c);
                vector<int>& aparecer = refs[palabra];

                if (aparecer.empty() || aparecer.back() != i) {
                    aparecer.push_back(i);
                }
            }
        }
    }

    for (auto cv : refs) {
        cout << cv.first;
        for (auto numlin : cv.second) {
            cout << ' ' << numlin;
        }
        cout << '\n';
    }
    cout << "---\n";
}






















void caprepetidos() {
    int capitulos, cap;
    cin >> capitulos;

    unordered_map<int, int> emision;

    int maxi = 0;
    int p = 0;
    for (int i = 0; i < capitulos; i++) {
        cin >> cap;
        int& donde = emision[cap];
        if (donde >= p) {
            p = emision[cap] + 1;
        }
        maxi = max(maxi, (i - p + 1));
        donde = i;
    }
    cout << maxi << '\n';
}




















bool elegirdeporte() {
    string deporte, estudiante;
    cin >> deporte;

    if (!cin) return false;

    unordered_map<string, unordered_set<string>> deportes;//por deporte alumno apuntado
    unordered_map<string, string> estudiantes;//por alumno deporte apuntado
    
    deportes.insert({ deporte , {} });//nuevo deporte
    
    
    while (cin >> estudiante , estudiante != string("_FIN_")) {
        if (isupper(estudiante[0])) {
            deporte = estudiante;
            deportes.insert({ deporte , {} });
        }
        else {
            auto [it, nuevo] = estudiante.insert({ estudiante , deporte });
            if (nuevo) deportes[deporte].insert(estudiante);
            else if (it->second != deporte) deportes[it->second].erase(estudiante);
        }
    }

    vector<pair<string, int>> resumen;
    for (auto const& [dep, estuds] : deportes) {
        resumen.push_back({ dep , estuds.size() });
    }

    sort(resumen.begin(), resumen.end(),
        [](pair<string, int> const& a, pair<string, int> const& b) {
            return (a.second > b.second) || (a.second == b.second && a.first < b.first);
        });

    for (auto& par : resumen) 
        cout << par.first << ' ' << par.second << '\n';
    cout << "---\n";
    return true;
}





















struct problema
{
    bool resuelto = false; 
    int fallos = 0;
};

struct equipo
{
    int resueltos = 0;
    int tiempo = 0;
    unordered_map<string, problema> problemas;
};

struct resultado // resultado equipo
{
    string nombre;
    int num_prob; //resueltos 
    int tiempo;
    bool operator<(resultado const& r) const {
        return num_prob > r.num_prob || 
            (num_prob == r.num_prob && tiempo < r.tiempo) ||
            (num_prob == r.num_prob && tiempo == r.tiempo && nombre < r.nombre);
    }
};

void rankingconcurso() {
    string equipo, problema, result;
    int minuto;
    unordered_map<string, equipo> equipos;
    //leemos y procesamos los envios
    while (cin >> equipo, equipo != "FIN") {
        cin >> problema >> minuto >> result;

        auto& inf_eq = equipos[equipo];
        auto& inf_pr = inf_eq.problemas[problema];
        if (!inf_pr.resuelto) {
            if (result == "AC") {// se resolvio
                inf_pr.resuelto = true;
                ++inf_eq.resuletos;
                inf_eq.tiempo += minuto + inf_pr.fallos * 20; // contar penealizacion
            }
            else ++inf_pr; // envio fallido
        }// si esta resuelto ya , ignoramos el envio
    }

    //extraemos resumen de los resultados
    vector<resultado> resultados;
    for (auto const& [eq, inf_eq] : equipos)
        resultados.push_back({ eq, inf_eq.resueltos , inf_eq.tiempo });
    //y lo ordenamos
    sort(resultados.begin(), resultados.end());

    //mostrar
    for (auto const& r : resultados) {
        cout << r.nombre << ' ' << r.num_prob << ' ' << r.tiempo << '\n';
    }
    cout << "---\n";

}


*/







struct dicc_data
{
    int valor = 0;
    char simbolo = '-';
};

void diccionario() {

    string clave;
    int valor;

    map<string, dicc_data> palabras;

    //leemos y procesamos los envios
    while (cin >> clave, clave != "\n") {
        cin >> valor;
        auto& dicc_data = palabras[clave];
        dicc_data.valor = valor;
    }

    while (cin >> clave, clave != "\n") {

        cin >> valor;
        auto it = palabras.find(clave);
        if (it != palabras.end()) {
            if (it->second.valor != valor) {
                it->second.simbolo = '*';
            }
        }
        else {
            auto& dicc_data = palabras[clave];
            dicc_data.valor = valor;
            dicc_data.simbolo = '+';
        }

    }

    string mas = "+";
    string menos = "-";
    string por = "*";

    for (auto c : palabras) {
        if (c.second.simbolo == '+') {
            mas = mas + " " + c.first;
        }
        else if (c.second.simbolo == '-') {
            menos = menos + " " + c.first;
        }
        else {
            por = por + " " + c.first;
        }
    }

    cout << mas << endl << menos << endl << por << endl;

}













void eliminar_redundancia() {

    int N;
    int clave;

    unordered_map<int, int> datos;

    //leemos y procesamos los envios
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> clave;
        auto it = datos.find(clave);
        if (it != datos.end()) {
            ++it->second;
        }
        else {
            datos.insert({clave , 1});
        }
    }

    for (auto c : datos) {
        cout << c.first << " " << c.second << endl;
    }

    cout << "---" << endl;

}











void actor() {

    int N;
    int clave;

    unordered_map<string, pair<int , vector<pair<set<string, int>::iterator, int>>>> datos;

    set<string, int> actores;

    

}

//////////////////////////////////////////////////////////////////////////////////
/*CLASES*/

using DNI = string;

class carnet_puntos {

    //para cada conductor , cuantos puntos tiene y donde esta en la lista que le toca
    unordered_map < DNI, pair<int, list<DNI>::iterator>> conductores;

    //para cada numero de puntos , la lista de conductores con esos puntos
    // ordenada colocando primero el q menos tiempo lleva con esos puntos
    vector<list<DNI>> por_puntos;

    list<DNI>::iterator inserta_por_puntos(DNI c, int p) {
        auto& lista = por_puntos[p];
        return lista.insert(lista.begin(), c);
    }

public :
    carnet_puntos() : por_puntos(16) {} // por puntos un vector [0..15]

    void nuevo(DNI conductor) {
        if (conductores.count(conductor) > 0)
            throw domain_error("conductor duplicado");
        conductores.insert({ conductor , {15 , inserta_por_puntos(conductor, 15)} });
    }

    void quitar(DNI conductor, int puntos) {
        auto it = conductores.find(conductor);
        if(it == conductores.end())
            throw domain_error("conductor inexistente");
        auto& par = it->second;
        if (par.first > 0 && puntos > 0){
            por_puntos[par.first].erase(par.second);
            par.first = max(0, par.first - puntos);
            par.second = inserta_por_puntos(conductor, par.first);
        }
    }

    void recuperar(DNI conductor, int puntos) {
        auto it = conductores.find(conductor);
        if (it == conductores.end())
            throw domain_error("conductor inexistente");
        auto& par = it->second;
        if (par.first < 15 && puntos > 0) {
            por_puntos[par.first].erase(par.second);
            par.first = min(15, par.first + puntos);
            par.second = inserta_por_puntos(conductor, par.first);
        }
    }

    int consultar(DNI conductor) const{
        auto it = conductores.find(conductor);
        if (it == conductores.end())
            throw domain_error("conductor inexistente");
        return it->second.first;
    }

    int cuantos_con_puntos(int puntos) const {
        if (puntos < 0 || puntos > 15)
            throw domain_error("Puntos no validos");
        return (int) por_puntos[puntos].size();
    }

    list<DNI> const& lista_por_puntos(int puntos) const {
        if (puntos < 0 || puntos > 15)
            throw domain_error("Puntos no validos");
        return por_puntos[puntos];
    }

};













using profesor = string;
using alumno = string;

class autoescuela {

    //para cada almuno , profesor y puntuacion
    unordered_map <alumno, pair<profesor, int>> alumnos;

    //para cada profesor , sus alumnos
    unordered_map<profesor, set<alumno>> profesores;


public:

    void alta(alumno const&a , profesor const& p) {
        auto itA = alumnos.find(a);
        if (itA == alumnos.end()) {
            alumnos.insert({ a , {p , 0}});
            profesores[p].insert(a);
        }
        else {
            profesores[itA->second.first].erase(a);
            itA->second.first = p;
            profesores[p].insert(a);
        }
    }

    bool es_alumno(alumno const& a, profesor const& p) {
        auto itA = alumnos.find(a);
        return itA != alumnos.end() && itA->second.first == p;
    }

    int puntuacion(alumno const& a) const {
        auto itA = alumnos.find(a);
        if(itA == alumnos.end()){
            throw domain_error("alumno inexistente");
        }
        else {
            return itA->second.second;
        }
    }

    void actualizar(alumno const& a, int puntos){
        auto itA = alumnos.find(a);
        if (itA == alumnos.end()) {
            throw domain_error("alumno inexistente");
        }
        else {
            itA->second.second += puntos;
        }
    }

    vector<alumno> examen(profesor const& p, int n) const {
        vector<alumno> v;
        auto itP = profesores.find(p);
        if (itP != profesores.end()) {
            for (alumno const& a : itP->second) {
                if (alumnos.at(a).second >= n) {
                    v.push_back(a);
                }
            }
        }
        return v;
    }

    void aprobar(alumno const& a) {
        auto itA = alumnos.find(a);
        if (itA == alumnos.end()) {
            throw domain_error("alumno inexistente");
        }
        else {
            profesores[itA->second.first].erase(a);
            alumnos.erase(itA);
        }
    }

};














using artista = string;
using cancion = string;

class iPud {

    struct infoSong {
        artista autor;
        int duracion;
        list<cancion>::iterator enPlaylist;
        list<cancion>::iterator enRecientes;
    };

    unordered_map<cancion, infoSong> canciones;

    list<cancion> playList;
    int duracionPlaylist;

    list<cancion> recientes; //de mas a menos

public:

    iPud() : duracionPlaylist(0) {}

    void addSong(cancion c, artista a , int D) {
        if (!canciones.insert({ c , {a , D , playList.end() , recientes.end()} }).second) {
            throw invalid_argument("addSong");
        }
    }

    void addToPlaylist(cancion c) {
        auto itc = canciones.find(c);
        if (itc != canciones.end()) {
            infoSong& info = itc->second;
            if (info.enPlaylist == playList.end()) {
                info.enPlaylist = playList.insert(playList.end(), c);
                duracionPlaylist += info.duracion;
            }
        }
        else {
            throw invalid_argument("addToPlaylist");
        }
    }

    cancion current() const {
        if (!playList.empty()) {
            return playList.front();
        }
        else {
            throw invalid_argument("current");
        }
    }

    void play() {
        if (!playList.empty()) {
            string tocando = playList.front();
            playList.pop_front();
            //recuperamos la informacion y la almacenamos
            infoSong& info = canciones[tocando];
            //deja de estar en la playlist
            info.enPlaylist = playList.end();
            //se descuenta duracion
            duracionPlaylist -= info.duracion;
            // si estaba en recientes se elimina
            if (info.enRecientes != recientes.end()) {
                recientes.erase(info.enRecientes);
            }
            //se añade al copmienzo de las recientes
            info.enRecientes = recientes.insert(recientes.begin(), tocando);

        }
    }

    int totalTime() {
        return duracionPlaylist;
    }

    list<cancion> recent(int n) {
        list<cancion> l;
        for (cancion& c : recientes) {
            l.push_back(c);
            if (l.size() == n) break;
        }
        return l;
    }

    void deleteSong(cancion c) {
        auto itc = canciones.find(c);
        if (itc == canciones.end()) {
            throw domain_error("deleteSong");
        }
        else {
            infoSong& info = itc->second;
            if (info.enPlaylist != playList.end()) {
                playList.erase(info.enPlaylist);
                duracionPlaylist -= info.duracion;
            }
            if (info.enRecientes != recientes.end()) {
                recientes.erase(info.enRecientes);
            }
            canciones.erase(itc);
        }
    }

};












using medico = string;
using paciente = string;

class consultorio {

    struct fecha
    {
        int dia;
        int hora;
        int min;
        bool operator<(fecha const& f) const {
            return dia < f.dia ||
                (dia == f.dia && hora < f.hora) ||
                (dia == f.dia && hora == f.hora && min < f.min);
        }
    };

    //para cada almuno , profesor y puntuacion
    unordered_map <medico, map<fecha , paciente>> medicos;

public:

    void nuevoMedico(medico const& m) {
        auto itA = medicos.find(m);
        if (itA == medicos.end()) {
            medicos[m];
        }
    }

    void pideConsulta(paciente const& p,medico const& m, fecha const& f) {
        auto itM = medicos.find(m);
        if (itM == medicos.end()) {
            throw domain_error("medico inexistente");
        }
        else {
            auto itF = itM->second.find(f);
            if (itF != itM->second.end()) {
                throw domain_error("fecha ocupada");
            }
            else {
                itM->second.insert({ f, p });
            }
        }
    }

    paciente siguientePaciente(medico const& m) const {
        auto itM = medicos.find(m);
        if (itM == medicos.end()) {
            throw domain_error("medico inexistente");
        }
        else {
            if (itM->second.empty()) {
                throw domain_error("No hay pacientes");
            }
            else {
                return itM->second.begin()->second;
            }
        }
    }

    void atiendeConsulta(medico const& m) {
        auto itM = medicos.find(m);
        if (itM == medicos.end()) {
            throw domain_error("medico inexistente");
        }
        else {
            if (itM->second.empty()) {
                throw domain_error("No hay pacientes");
            }
            else {
                itM->second.erase(itM->second.begin());
            }
        }
    }

    list<paciente> listaPacientes(medico const& m, int d) const {
        list<paciente> l;
        auto itM = medicos.find(m);
        if (itM != medicos.end()){
            for (auto const& a : itM->second) {
                if (a.first.dia == d) {
                    l.push_back(a.second);
                }
            }
        }
        return l;
    }

};











using libro = string;

class venta {

    struct datos 
    {
        int numero;
        int ventas;
    };

    //ejemplares , ventas
    unordered_map <libro, datos> ejemplares;

    vector<list<libro>> ventas;

public:

    venta() : ventas(16) {}

    void nuevoLibro(int n, libro const& l) {
        auto itL = ejemplares.find(l);
        if (itL == ejemplares.end()) {
            ejemplares.insert({ l, { n,0} });
        }
        else {
            itL->second.numero += n;
        }
    }

    void comprar(libro const& l) {
        auto itL = ejemplares.find(l);
        if (itL == ejemplares.end()) {
            throw invalid_argument("libro inexistente");
        }
        else {
            if (itL->second.numero <= 0) {
                throw out_of_range("No hay ejemplares");
            }
            else {
                --itL->second.numero;
                ++itL->second.ventas; //mas una venta
                ventas[itL->second.ventas];
                ventas[itL->second.ventas].push_front(itL->first);
                if (itL->second.ventas > 1) {
                    auto it = ventas[itL->second.ventas - 1].begin();
                    while (it != ventas[itL->second.ventas - 1].end()) {
                        if (it.operator*() == itL->first) {
                            ventas[itL->second.ventas - 1].erase(it);
                            break;
                        }
                        it++;
                    }
                }
            }
        }
    }

    bool estaLibro(libro const& l) const {
        auto itL = ejemplares.find(l);
        if (itL == ejemplares.end()) {
            return false;
        }
        else {
            return true;
        }
    }

    void elimLibro(libro const& l) {
        auto itL = ejemplares.find(l);
        if (itL == ejemplares.end()) {
            throw invalid_argument("libro inexistente");
        }
        else {
            
        }
    }

    int numEjemplares(libro const& l) const {
        auto itL = ejemplares.find(l);
        if (itL == ejemplares.end()) {
            throw invalid_argument("libro inexistente");
        }
        else {
            return itL->second.numero;
        }
    }


    list<libro> top10() const {
        list<libro> l;
        for (int i = ventas.size() - 1 ; i >= 0; i--) {
            list<libro> aux;
            auto it = ventas[i].begin();
            while (it != ventas[i].end()) {
                l.push_back(it.operator*());
                it++;
                if (l.size() == 10) {
                    break;
                }
            }
            if (l.size() == 10) {
                break;
            }
        }
        return l;
    }

};











using sector = string;
using plaga = string;

class smart_farming {

    //ejemplares , ventas
    unordered_map <sector, set<plaga>> sectores;

    unordered_map<plaga , unordered_set<sector>> plagas;

public:

    void alta(sector const& s) {
        auto it = sectores.find(s);
        if (it == sectores.end()) {
            sectores.insert({ s,{} });
        }
    }

    void datos(sector const& s, plaga const& p) {
        auto it = sectores.find(s);
        if (it == sectores.end()) {
            throw invalid_argument("sector inexistente");
        }
        else {
            if (it->second.find(p) != it->second.end()) {
                throw out_of_range("Plaga repetida");
            }
            else {
                it->second.insert(p);
                auto itP = plagas.find(p);
                if (itP == plagas.end()) {
                    plagas.insert({ p , {it->first} });
                }
                else {
                    itP->second.insert(it->first);
                }
            }
        }
    }

    vector<sector> fumigar(plaga const& p) {
        auto it = plagas.find(p);
        if (it == plagas.end()) {
             throw invalid_argument("plaga inexistente");
        }
        else {
            vector<sector> v;
            for (sector s : it->second) {
                v.push_back(s);
                auto its = sectores.find(s);
                its->second.erase(its->second.find(p));
            }
            plagas.erase(it);
            return v;
        }
    }

    vector<plaga> plagasi(sector const& s) const{
        auto it = sectores.find(s);
        if (it == sectores.end()){
            throw invalid_argument("sector inexistente");
        }
        else {
            vector<plaga> p;
            for (plaga s : it->second) {
                p.push_back(s);
            }
            return p;
        }
    }

};














using producto = string;
using cliente = string;

class AGoGo {

    //ejemplares , ventas
    unordered_map <producto, pair<int , unordered_set<cliente>>> productos;

    list<pair<int , producto>> ventas;

public:

    AGoGo() : productos() , ventas() {}

    void an_oferta(producto const& p, int num) {
        auto par = productos.insert({ p,{num, {}} });
    }

    void pon_en_espera(cliente const& s, producto const& p) {
        if (productos.count(p) == 0) throw std::domain_error("producto no existente");
        auto it = productos.find(p)->second.second;
        if (it.count(s) == 0) {
            it.insert(s);
        }
        else {
            throw std::domain_error("cliente ya existente");
        }
    }

    void cancelar_espera(cliente const& s, producto const& p) {
        if (productos.count(p) == 0) throw std::domain_error("producto no existente");
        auto it = productos.find(p)->second.second;
        if (it.count(s) != 0) {
            it.erase(s);
        }
        else {
            throw std::domain_error("cliente no existente");
        }
    }

    int num_en_espera(producto const& p) const {
        if (productos.count(p) == 0) throw std::domain_error("producto no existente");
        return productos.find(p)->second.second.size();
    }

    void venta(producto const& p ,int num) {
        if (productos.count(p) == 0) throw std::domain_error("producto no existente");
        auto itP = productos.find(p);
        auto it = itP->second.second;
        it.erase(it.begin());
        int valor = itP->second.first;
        itP->second.first -= num;
        if (itP->second.first <= 0) {
            productos.erase(p);
        }
        //////////////////////////////////////////////
        ventas.push_back({ min(num , valor) , p });
        /////////////////////////////////////////////    
    }

    cliente primero_en_espera(producto const& p) const {
        if (productos.count(p) == 0) throw std::domain_error("producto no existente");
        auto it = productos.find(p)->second.second;
        if (it.size() > 0) {
            return it.begin().operator*();
        }
        else {
            throw std::domain_error("lista vacia");
        }
    }

    list<pair<int , producto>> plagasi(sector const& s) const {
        return ventas;
    }

};












class agricultura30 {
private:
    using tsector = std::string;
    using tplaga = std::string;
    // El primer elemento del par es el numero de plantas del sector
    // El map mantiene el nmero de plantas notificadas y no tratadas de esa plaga
    std::unordered_map < tsector, std::pair<int, std::map<tplaga, int>>> tabla_sector;
    std::vector<std::pair<tsector, tplaga>> cola_fumigar;

public:
    agricultura30() {}

    // Alta de un sector con un número de plantas
    void alta(tsector const& id, int n) {
        auto par = tabla_sector.insert({ id,{n,std::map<tplaga, int>()} });
        if (!par.second) { // Ya estaba dado de alta, se modifica el número de plantas
            tabla_sector[id].first += n;
        }
    }

    // Se recibe una notificacion del robot
    void datos(tsector const& id, tplaga const& p, int n) {
        if (tabla_sector.count(id) == 0) throw std::domain_error("Sector no existente");
        if (tabla_sector[id].first < n) throw std::domain_error("Numero de plantas incorrecto");
        // Comprueba si hay bastantes plantas afectadas para fumigar. Comprueba que no este ya aadida al vector
        if (tabla_sector[id].second[p] < tabla_sector[id].first / 4.0 && n >= tabla_sector[id].first / 4.0)
            cola_fumigar.push_back({ id,p });
        // La aade a la tabla
        tabla_sector[id].second[p] = n;
    }

    // Obtiene los sectores y plagas a fumigar
    std::vector<std::pair<tsector, tplaga>> fumigar() {
        std::vector<std::pair<tsector, tplaga>> v;
        for (auto afumigar : cola_fumigar) {
            // Se inicializa el numero de plantas afectadas por la plaga
            tabla_sector[afumigar.first].second[afumigar.second] = 0;
            // Se añade a la salida
            v.push_back(afumigar);
        }
        cola_fumigar.clear();
        return v;
    }

    // Plagas de un sector
    std::vector<std::pair<tplaga, int>> plagas(tsector const& id) {
        std::vector<std::pair<tplaga, int>> v;
        for (auto s : tabla_sector[id].second)
            v.push_back(s);
        return v;
    }
};















// Resuelve un caso de prueba, leyendo de la entrada la
// configuracio?n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string op;
    agricultura30 a30;
    std::cin >> op;
    if (!std::cin)
        return false;
    std::string id; std::string plaga; int n;
    while (op != "FIN") {
        try {
            if (op == "alta") {
                std::cin >> id >> n;
                a30.alta(id, n);
            }
            else if (op == "datos") {
                std::cin >> id >> plaga >> n; // numero de plagas
                a30.datos(id, plaga, n);
            }
            else if (op == "fumigar") {
                std::vector<std::pair<std::string, std::string>> v = a30.fumigar();
                for (auto const& s : v) {
                    std::cout << "Fumigar la plaga " << s.second << " del sector :";
                    std::cout << ' ' << s.first << '\n';
                }
            }
            else if (op == "plagas") {
                std::cin >> id;
                std::vector<std::pair<std::string, int>> v = a30.plagas(id);
                std::cout << "Plagas del sector " << id << " :";
                for (auto const& s : v)
                    std::cout << ' ' << s.first << ' ' << s.second;
                std::cout << '\n';
            }
        }
        catch (std::domain_error & d) {
            std::cout << "ERROR: " << d.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---" << '\n';

    return true;

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