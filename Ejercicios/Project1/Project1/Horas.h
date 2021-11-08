
# ifndef Horas_h
# define Horas_h
# include <iostream>
# include <array>
# include <stdexcept>
# include <iomanip>

using namespace std;

class Hora{
public:

	Hora():hora(23), min(59), seg(59) {};

	Hora(int h, int m, int s) : hora(h), min(m), seg(s) {
		if (h < 0 || h >= 24 || m < 0 || m >=  60 || s < 0 || s >= 60) throw std::invalid_argument("ERROR");
	};

	int get_hora() const { return hora; };
	int get_min() const { return min; };
	int get_seg() const { return seg; };

	
	// operadores de comparacion
	bool operator < (Hora const& h) const {
		if (hora < h.hora) return true;
		else if (hora > h.hora) return false;
		else if (min < h.min) return true;
		else if (min > h.min) return false;
		else if (seg < h.seg) return true;
		else return false;
	}

	bool operator == (Hora const& f) const {
		return hora == f.hora && min == f.min && seg == f.seg;
	}

	bool operator <= (Hora const& f) const {
		return *this < f || *this == f;
	}

	bool operator > (Hora const& f) const {
		return !(*this <= f);
	}

	bool operator >= (Hora const& f) const {
		return !(*this < f);
	}

private:
	int hora, min, seg;
};

inline std::ostream& operator << (std::ostream& out , Hora const& h) {

	out << setfill('0') << setw(2) << h.get_hora() << ":" << setfill('0') << setw(2) << h.get_min() << ":" << setfill('0') << setw(2) << h.get_seg()  << '\n';
	return out;
}

inline std::istream& operator >> (std::istream& in, Hora& ho) {
	int h, m, s;
	char basura;

	in >> h >> basura >> m >> basura >> s;
	ho = Hora(h, m, s);
	return in;
}
# endif
