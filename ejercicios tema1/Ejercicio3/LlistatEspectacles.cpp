#include "LlistatEspectacles.h"
#include <iostream>


bool LlistatEspectacles::afegeixEspectacle(const Espectacle& e)
{
	if(espectaclesAlta==5){return false;}
	privEspectaculos[espectaclesAlta] = e;
	espectaclesAlta++;
	return true;
}

int  LlistatEspectacles::compraEntrades(string nom, string dia, int nEntrades, float& preu)
{
	int i = 0;

	for (i=0; i < SIZE; i++) {

		if ((nom == privEspectaculos[i].getNom()) && (dia == privEspectaculos[i].getDia())) {
		if ((privEspectaculos[i].getEntradesLliures() != 0 && (privEspectaculos[i].getEntradesTotals() >= nEntrades))) {
			privEspectaculos[i].reservaEntrades(nEntrades);
			privEspectaculos[i].setPreu(preu);
			return 0;
		}
		return -1;
	}

 }
	

	return -2;
}



