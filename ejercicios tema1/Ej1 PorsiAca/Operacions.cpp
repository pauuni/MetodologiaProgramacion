#include "Operacions.h"
#include <map>

void operar(NombreRacional v[], int mida, char operacio, NombreRacional& operand, NombreRacional resultat[])
{
    switch (operacio) {
    case '+':
        for (int i = 0; i < mida; i++) {
            resultat[i] = v[i].suma(operand);
        }
        break;;
    case '*':
        for (int i = 0; i < mida; i++) {
            resultat[i] = v[i].multiplica(operand);
        }
        break;;
    case '-':
        for (int i = 0; i < mida; i++) {
            resultat[i] = v[i].resta(operand);
        }
        break;;
    case '/':
        for (int i = 0; i < mida; i++) {
            resultat[i] = v[i].divideix(operand);
        }
        break;;
    }

}

