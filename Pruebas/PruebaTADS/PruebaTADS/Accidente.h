#ifndef Accidente_h
#define Accidente_h
#include <string>

class Accidente {
public:
	Accidente() :dia(0), mes(0), anyo(0), vict(0) {} // Constructor por defecto

	int get_victims()const { return vict; }
	void put_accidente(const std::string& cad);

	void operator= (const Accidente& otro); //Sobrecargas
	bool operator< (const Accidente& otro)const;

	void imprimir_fecha()const;

private:
	int dia;
	int mes;
	int anyo;
	int vict;
};


#endif
