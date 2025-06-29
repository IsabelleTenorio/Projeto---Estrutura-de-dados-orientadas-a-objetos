#include "eletronico.h"

// Construtor usando member initializer list é mais eficiente
eletroDomestico::eletroDomestico(int potenciaInput, int quantidadeInput, float horasInput, int diasInput, bool possuiStandbyInput, float potenciaStandbyInput)
    : potencia(potenciaInput),
      quantidade(quantidadeInput),
      horasUsadas(horasInput),
      diasSimulado(diasInput),
      possuiStandby(possuiStandbyInput),
      potenciaStandby(potenciaStandbyInput),
      kwh(0.0f)
{ }

float eletroDomestico::calcKwh() {
    float consumoAtivo = (potencia * horasUsadas * diasSimulado * quantidade) / 1000.0f;
    float consumoStandby = 0.0f;

    if (possuiStandby){
        float horasEmStandby = 24.0f - horasUsadas;
        consumoStandby = (potenciaStandby * horasEmStandby * diasSimulado * quantidade) / 1000.0f;
    }

    kwh = consumoAtivo + consumoStandby;
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

void eletroDomestico::setStandby(bool possuiStandbyInput, float potenciaStandbyInput){
    possuiStandby = possuiStandbyInput;
    potenciaStandby = potenciaStandbyInput;
}

bool eletroDomestico::getPossuiStandby() const {
    return possuiStandby;
}

float eletroDomestico::getPotenciaStandby() const {
    return potenciaStandby;
}
