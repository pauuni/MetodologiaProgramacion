#include "operacions_data.h"

bool terminiValid(Data& diaOriginal, int nDies, Data& dataActual)
{
    diaOriginal.operator+(nDies);

    return dataActual.operator<(diaOriginal);
}