#include "Data.h"
#include <iostream>

using namespace std;

void Data::llegeix()
{
	cout << "Entra el dia: ";
	cin >> m_dia;
	cout << "Entra el mes: ";
	cin >> m_mes;
	cout << "Entra l'any: ";
	cin >> m_any;
}
bool getTraspasYear(int any) {
    if (any % 400 == 0) {
        return true;
    }
    else if ((any % 4 == 0)&&(any % 100 == 0)) {
        return false;
    }
    else if (any % 4 == 0) { return true; }

}

bool Data::dataValida() const
{
    bool isTraspas = getTraspasYear(m_any);

    if (((m_mes == 4) || (m_mes == 2)) && (m_dia > 30)) {
        return false;
    } else if (m_mes == 2 && !isTraspas && m_dia > 28) {
        return false;
    } else if (m_any < 0 || m_mes > 12 || m_mes < 1 || m_dia < 1 || m_dia > 31 || (m_mes == 2 && isTraspas && m_dia > 29)) {
        return false;
    }
    return true;
}
int getDiesMes(int mes, bool isTraspas) {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) return 31;
    else if (mes == 2)
        if (isTraspas) return 29;
        else return 28;
    else return 30;
}



Data Data::operator+(int nDies)
{
    Data retornable;
        bool traspas = getTraspasYear(m_any); //aqui sabemos si es any de traspas o no
        int diasDelAny = traspas ? 366 : 365;       //aqui guardamos en variable el numero de dias del anyo acorde a lo anterior
        int diesMes = getDiesMes(m_mes, traspas);
        int x;


        if (nDies == 0) { return retornable; }

        while (nDies >= 31) {
            diesMes = getDiesMes(m_mes, traspas);    //,miras dias mes
            x = diesMes - m_dia;                      //calculas lo que te queda para llegar a fin de mes, el dia maximo del mes - el dia en el que ya estas 31-10=21
            m_dia += (x + 1);                         //actualizas tu dia de forma precisa para acabar en el dia 1 del mes siguiente. ej: 10+22=32 lo que equivale a 1 del mes siguiente
            nDies -= (x + 1);                                   //actualizamos ndies lo mismo que sumamos a dias lo mismo que restamos a ndies. nDies=31-(21+1)=9

            if (m_dia > diesMes) { m_mes++; } // 2
            m_dia -= diesMes; // Confirmamos y actualizamos el dia de forma que se quede como el dia 1 del mes siguiente 32-31=1
            if (m_mes == 13) {    //unas lineas para considerar el caso hipotetico de que debamos sumar año
                m_mes = 1;
                m_any++;
            }

        }
        if (nDies > 0) {
            diesMes = getDiesMes(m_mes, traspas);
            x = diesMes - m_dia;
            if (nDies < x) {
                m_dia += nDies;
            }
            else {

                m_dia += nDies;

                m_dia - x;
                if (m_dia != diesMes) {
                    m_mes++;
                }
            }


        }
        return retornable;
    
}

bool comparaDates(int data1,int  data2) {
    return data1 > data2; // 2016 > 2017
}

bool Data::operator<(Data datilla) {
   //asumimos de momento que datilla grande es condicion de true
    //data2 es datilla. Se dice que esta bien si datilla ES MENOR que la que te vine. 

    if (datilla.m_any < m_any || datilla.m_any > m_any) {
        return comparaDates(datilla.m_any, m_any);
    }
    else if (datilla.m_mes < m_mes || datilla.m_mes > m_mes) {
        return comparaDates(datilla.m_mes,m_mes);
    }
    else if (datilla.m_dia < m_dia || datilla.m_dia > m_dia) {
        return comparaDates(datilla.m_dia, m_dia);
    }
    else {
        return false;
    }

   /* if (datilla.m_any > m_any) {
        return true;
    }
        else if (datilla.m_any < m_any) {
            return false;
          }
            else {
                
                    if (datilla.m_mes > m_mes) {
                        return true;
                    }
                    else if (datilla.m_mes < m_mes) {
                        return false;
                    }
                    else {


                            if (datilla.m_dia > m_dia) {
                                return true;
                            }
                            else if (datilla.m_any < m_dia) {
                                return false;
                            }
                            else {
                                return false;
                            }

                    }
            }*/
}
bool Data::operator==(Data datilla) {
    return true;
}


