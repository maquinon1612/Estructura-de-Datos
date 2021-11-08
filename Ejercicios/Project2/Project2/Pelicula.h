
# ifndef Pelicula_h
# define Pelicula_h
# include <iostream>
# include <string>
# include <array>
# include <stdexcept>
#include "Horas.h"

class Pelicula {
public:

	Pelicula() :inicio(), duracion(), nombre("") {};

	Pelicula(Hora ini, Hora d, std::string n) : inicio(ini), duracion(d), nombre(n) {};

	Hora get_inicio() const { return inicio; };
	Hora get_duracion() const { return duracion; };
	std::string get_nombre() const { return nombre; }

	// operadores de comparacion
	bool operator < (Pelicula const& p) const {
		if (inicio + duracion < p.inicio + p.duracion) return true;
		else if (inicio + duracion == p.inicio + p.duracion && nombre < p.nombre) return true;
		else return false;
	}

	bool operator == (Pelicula const& p) const {
		return inicio + duracion == p.inicio + p.duracion;
	}

	bool operator <= (Pelicula const& f) const {
		return *this < f || *this == f;
	}

	bool operator > (Pelicula const& f) const {
		return !(*this <= f);
	}

	bool operator >= (Pelicula const& f) const {
		return !(*this < f);
	}

private:
	Hora inicio, duracion;
	std::string nombre;
};

inline std::ostream& operator << (std::ostream& out, Pelicula const& p) {

	out << p.get_inicio() + p.get_duracion() << p.get_nombre() << '\n';
	return out;
}

inline std::istream& operator >> (std::istream& in, Pelicula& p) {
	Hora i, d;
	std::string n;

	in >> i >> d;
	getline(in,n);
	p = Pelicula(i, d, n);
	return in;
}
# endif
