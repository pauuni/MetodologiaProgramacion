
class NombreRacional
{
public:
    int test = 0;
    NombreRacional() {
        numerador = 0; denominador = 0;
    }
    NombreRacional(int num, int den) {
        numerador = num;
        denominador = den;
    }
    void setNumerador(int num) {
        numerador = num;
    }
    int getNumerador() const {
        return numerador;
    }
    void setDenominador(int den) {
        denominador = den;
    }
    int getDenominador() const {
        return denominador;
    }


    void simplifica() {
        int maximComu;
        maximComu = mcd(numerador, denominador);
        setNumerador(maximComu == 0 ? maximComu : numerador / maximComu);
        setDenominador(maximComu == 0 ? denominador : denominador / maximComu);
    }
    NombreRacional ResetNumRacional();
    NombreRacional AritmeticaBasica(char operacio, const NombreRacional& b);
    NombreRacional suma(const NombreRacional& b);
    NombreRacional multiplica(const NombreRacional& b);
    NombreRacional resta(const NombreRacional& b);
    NombreRacional divideix(const NombreRacional& b);
private:
    int numerador, denominador;
    bool esValid()const {
        return denominador != 0;
    }
    int mcd(int a, int b) {
        return (b == 0) ? a : mcd(b, a % b);
    }

};

