
#include "Racional.h"
#include <iostream>
using namespace std;

NombreRacional NombreRacional::ResetNumRacional() {
	NombreRacional num;
	num.numerador = 0;
	num.denominador = 0;
	return num;
}

NombreRacional NombreRacional::AritmeticaBasica(char operacio, const NombreRacional& b) {
	int num1 = numerador, num2 = denominador, num3 = b.numerador, num4 = b.denominador;
	int temp;
	NombreRacional resultat;
	// seteamos un denominador comun
	if (denominador == 0) {
		return ResetNumRacional();
	}
	temp = denominador * b.denominador;
	num1 = num1 * b.denominador;
	num3 = num3 * denominador;

	resultat.numerador = operacio == '+' ? num1 + num3 : num1 - num3;
	resultat.denominador = temp;

	resultat.simplifica();
	return resultat;
}

NombreRacional NombreRacional::suma(const NombreRacional& b)
{
	return AritmeticaBasica('+', b);
}

NombreRacional NombreRacional::multiplica(const NombreRacional& b)
{
	NombreRacional resultat;
	// seteamos un denominador comun

	if (denominador == 0) {
		return ResetNumRacional();
	}
	else if (numerador == 0) {
			resultat.numerador = 0;
			resultat.denominador = 1;
			return resultat;
		}
	resultat.numerador = numerador * b.numerador;
	resultat.denominador = denominador * b.denominador;

	resultat.simplifica();

	return resultat;


}
NombreRacional NombreRacional::resta(const NombreRacional& b)
{
	return AritmeticaBasica('-', b);
}
NombreRacional NombreRacional::divideix(const NombreRacional& b)
{
	NombreRacional resultat;
	// seteamos un denominador comun

	if (denominador == 0) {
		return ResetNumRacional();
	}
	else if (numerador == 0) {
		resultat.numerador = 0;
		resultat.denominador = 1;
		return resultat;
	}
	resultat.numerador = numerador * b.denominador;
	resultat.denominador = denominador * b.numerador;

	resultat.simplifica();

	return resultat;


}

