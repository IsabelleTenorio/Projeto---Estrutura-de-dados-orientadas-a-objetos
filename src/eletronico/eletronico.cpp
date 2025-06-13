#include <iostream>

using namespace std;

class eletroDomestico {
    public:

    int potencia, quantidade, diasSimulado;
    float horasUsadas, kwh;


    void constru_eletroDomestico(int potenciaInput = 1, int quantidaInput = 1, float horasInput = 1, float diasInput = 1 ) {

        potencia = potenciaInput;
        quantidade = quantidaInput;
        horasUsadas = horasInput;
        diasSimulado = diasInput;

    };


    float calcKwh() {

        kwh = (potencia * horasUsadas * diasSimulado * quantidade)/1000 ;

        return kwh;
    }


    int setKwh(float kwhInput) {

        kwh = kwhInput;

    }


    float getKwh() {
        return kwh;
    }


    int getPotencia() {
        return potencia;
    }


    int getQuantidade() {
        return quantidade;
    }


    float getHorasUsadas() {
        return horasUsadas;
    }

    private:


};