
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

using alumno = string;
class puntuacion {
private:
	map <alumno, int> tabla;
public:
	puntuacion() {}

	void puntuar(alumno const& a , bool correcto) {
		if (correcto) {
			++tabla[a];
		}
		else --tabla[a];
	}
	void borrar(alumno const& a) {
		tabla.erase(a);
	}
	unsigned int cantidad(alumno const& a) const {
		auto it = tabla.find(a);
		if (it == tabla.end())
			return 0;
		else
			return it -> second;
	}
	void lista_alumnos() const {
		for (auto const& par : tabla) {
			if (par.second != 0)
				cout << par.first << ", " << par.second << '\n';
		}
		cout << "---" << '\n';
	}
};