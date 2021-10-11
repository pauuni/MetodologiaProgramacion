
#include "Espectacle.h"
#define SIZE 5
class LlistatEspectacles
{
public:
	LlistatEspectacles() { espectaclesAlta = 0; }
	bool afegeixEspectacle(const Espectacle& e);
	int compraEntrades(string nom, string dia, int nEntrades, float& preu);
private:
	Espectacle privEspectaculos[SIZE];
	int espectaclesAlta;
};

