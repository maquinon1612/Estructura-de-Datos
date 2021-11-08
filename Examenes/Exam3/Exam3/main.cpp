
// Mario Quiñones Pérez
// A 60

#include <iostream>     
#include <fstream>
#include <string>
using namespace std;

#include "academia_chino.h"

bool resuelveCaso() {
   string orden;
   cin >> orden;
   if (!cin)
      return false;
   
   string dni;
   int grupo;
   
   academia_chino ac;
   
   while (orden != "FIN") {
      try {
         if (orden == "nuevo_estudiante") {
            cin >> dni >> grupo;
            ac.nuevo_estudiante(dni, grupo);
         } else if (orden == "grupo_estudiante") {
            cin >> dni;
            int grupo = ac.grupo_estudiante(dni);
            cout << dni << " esta en el grupo " << grupo << '\n';
         } else if (orden == "promocionar") {
            cin >> dni;
            ac.promocionar(dni);
         } else if (orden == "graduados") {
            auto graduados = ac.graduados();
            cout << "Lista de graduados:";
            for (string const& s: graduados) {
               cout << ' ' << s;
            }
            cout << '\n';
         } else if (orden == "novato") {
            cin >> grupo;
            string novato = ac.novato(grupo);
            cout << "Novato de " << grupo << ": " << novato << '\n';
         }
      } catch (std::domain_error & e) {
         cout << "ERROR: " << e.what() << '\n';
      }
      
      cin >> orden;
   }
   cout << "---\n";
   
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
   // system("PAUSE");
#endif

   return 0;
}
