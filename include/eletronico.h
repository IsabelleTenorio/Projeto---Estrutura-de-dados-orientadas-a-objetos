#ifndef ELETRONICO_H
#define ELETRONICO_H

using namespace std;

class eletroDomestico {
private:
    int potencia;
    int quantidade;
    int diasSimulado;
    float horasUsadas;
    float kwh;

public:
    eletroDomestico(int potenciaInput = 1, int quantidadeInput = 1, float horasInput = 1, int diasInput = 1);

    float calcKwh();
    void setKwh(float kwhInput);

    float getKwh() const;
    int getPotencia() const;
    int getQuantidade() const;
    float getHorasUsadas() const;
    int getDiasSimulado() const;
};

#endif
