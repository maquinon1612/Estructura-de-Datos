
// Mario Quiñones Pérez

// COMENTARIO SOBRE LA SOLUCIÓN
// NO OLVIDES PONER EL COSTE JUSTIFICADO DE CADA OPERACIÓN JUNTO A ELLA

//Para este ejercicio he utilizado tres tipos de datos un unordered_map para guardar los alumnos con su correspondiente grupo , que utiliza para saber si el alumno existe
//y a que grupo pertenece de forma logaritmica que en el caso de que la funcion hash sea facil decalcular es constante la mayoria de funciones , uso tambien un vector para 
//poder diferenciar por grupo , (cada posicion es un grupo sin contar la 0) dentro de cada posicionhay un unordered_set de alumnos que uso para saber que alumnos estan 
//matriculados en ese curso y uso ese tipo de dato en concreto para poder buscar de forma facil el alumno , si este pertenece al grupo y es novato en tonces esta en la 
//anterior al end(). Por ultimo uso un set de alumnos para los graduados para mantener el orden alfabetico de los mismos y buscar comodamente si un alumno se a graduado o no

#ifndef ACADEMIACHINO
#define ACADEMIACHINO

#include <iostream>     
#include <string>
#include <stdexcept>
#include <algorithm>
#include <unordered_map>
#include<set>
#include<unordered_set>
#include <vector>

using namespace std;

class academia_chino {
  
private:


    using tdni = std::string;
    using tgrupo = int;



    //uso este unordered_map porque no necesito tener a los alumnos ordenados por dni
    //pero necesito saber el grupo al que pertenecen
    unordered_map <tdni, tgrupo> tabla_estudiantes;

    //este vector sirve para buscar por grupo [1...6] mas facilmente , y tiene dentro un
    //unordered_set que permite una busqueda rapida y mantener el orden de entrada para 
    //poder saber de forma constante que alumno fue el ultimo en matricularse
    vector<unordered_set<tdni>> alumpo_por_grupo;

    //uso un set para los graduados para mantener un orden alfabetico de los dni
    set<tdni> graduaciones;

public:
    academia_chino() : alumpo_por_grupo(7) {}

    //O(logn) ya que las operaciones que mas coste tienen es logaritmico y estas son las 
    //funciones find() , insert() y la funcion end() es constante
    void nuevo_estudiante(tdni const& dni,tgrupo const& grupo) {
        if (grupo > 0 && grupo < 7) {
            auto it = tabla_estudiantes.find(dni); //O(1)
            if (it != tabla_estudiantes.end() || //O(1)
                graduaciones.find(dni) != graduaciones.end()) {//O(logn)
                throw domain_error("Estudiante existente");
            }
            else {
                tabla_estudiantes.insert({ dni , grupo }); //O(1)
                alumpo_por_grupo[grupo].insert(dni); //O(1)
            }
        }
        else {
            throw domain_error("Grupo incorrecto");
        }
    }

    // O(logn) ya que realiza funciones de coste logaritmico y el operador[] de los
    //vectores es de coste constante
    void promocionar(tdni const& dni) {
        auto it = tabla_estudiantes.find(dni);// O(1)
        if (graduaciones.find(dni) != graduaciones.end()) {// O(logn)
            throw domain_error("Estudiante ya graduado");
        }
        else if (it == tabla_estudiantes.end()) {// O(1)
            throw domain_error("Estudiante no existente");
        }
        else {
            alumpo_por_grupo[it->second].erase(dni);// O(1)
            if (it->second == 6) {
                tabla_estudiantes.erase(it);// O(1)
                graduaciones.insert(dni);// O(1)
            }
            else {
                ++it->second;
                alumpo_por_grupo[it->second].insert(dni);// O(1)
            }
        }
    }

    // O(1) ya que utiliza la funcion find para encontrar el dni en el
    // mapa y en el unordered_set del elemento vector de graduados que le 
    //corresponde ,que en el caso de que la funcion hash sea facil decalcular 
    //es constante
    int  grupo_estudiante(tdni const& dni) const{
        auto it = tabla_estudiantes.find(dni);
        if (graduaciones.find(dni) != graduaciones.end()) {
            throw domain_error("Estudiante ya graduado");
        }
        else if (it == tabla_estudiantes.end()) {
            throw domain_error("Estudiante no existente");
        }
        else {
            return it->second;
        }
    }

    //O(1) solo devuelve la lista ya creada que esta ordenada
    set<tdni> graduados(){
        return graduaciones;
    }

    //O(n) ya que end() , empty() ,pero los operadores -- y * del iterador pueden
    //ser lineales en el peor caso
    tdni novato(tgrupo const& grupo) const{
        if (grupo > 0 && grupo < 7) {
            if (alumpo_por_grupo[grupo].empty()) {
                throw domain_error("Grupo vacio");
            }
            else {
                auto it = alumpo_por_grupo[grupo].end();
                it--;
                return it.operator*();
            }
        }
        else {
            throw domain_error("Grupo incorrecto");
        }
    }
   
};

#endif
