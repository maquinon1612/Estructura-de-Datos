
# ifndef Accidente_h
# define Accidente_h
# include <iostream>
# include <array>
# include <stdexcept>
# include <string>
# include <iomanip>

using namespace std;

class Accidente {
public:

	Accidente() :victimas(0), fecha("") {};

	Accidente(string f, int v) : victimas(v), fecha(f) {};

	string getfecha() const { return fecha; };
	int get_vic() const { return victimas; };


	// operadores de comparacion
	bool operator < (Accidente const& h) const {
		if (victimas < h.victimas) return true;
		else return false;
	}

	bool operator == (Accidente const& f) const {
		return victimas == f.victimas;
	}

	bool operator <= (Accidente const& f) const {
		return *this < f || *this == f;
	}

	bool operator > (Accidente const& f) const {
		return !(*this <= f);
	}

	bool operator >= (Accidente const& f) const {
		return !(*this < f);
	}

private:
	int victimas;
	string fecha;
};

inline std::ostream& operator << (std::ostream& out, Accidente const& h) {

	out << h.getfecha() << '\n';
	return out;
}

inline std::istream& operator >> (std::istream& in, Accidente& ho) {
	int v;
	string f;

	in.get();
	getline(in, f, ' ');
	cout << f;
	in >> v;
	ho = Accidente(f, v);
	return in;
}
# endif
