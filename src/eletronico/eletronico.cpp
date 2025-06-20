#include "eletronico.h"

eletroDomestico::eletroDomestico(int potenciaInput, int quantidadeInput, float horasInput, int diasInput) {
    potencia = potenciaInput;
    quantidade = quantidadeInput;
    horasUsadas = horasInput;
    diasSimulado = diasInput;
    kwh = 0.0;
}

float eletroDomestico::calcKwh() {
    kwh = (potencia * horasUsadas * diasSimulado * quantidade) / 1000.0;
    return kwh;
}

void eletroDomestico::setKwh(float kwhInput) {
    kwh = kwhInput;
}

float eletroDomestico::getKwh() const {
    return kwh;
}

int eletroDomestico::getPotencia() const {
    return potencia;
}

int eletroDomestico::getQuantidade() const {
    return quantidade;
}

float eletroDomestico::getHorasUsadas() const {
    return horasUsadas;
}

int eletroDomestico::getDiasSimulado() const {
    return diasSimulado;
}
