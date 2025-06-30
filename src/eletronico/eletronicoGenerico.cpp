#include "eletronicoGenerico.h"
#include <string>

// Construtor usando member initializer list é mais eficiente
eletronicoGenerico::eletronicoGenerico(std::string nomeInput,int potenciaInput, int quantidadeInput, float horasInput, int diasInput, bool possuiStandbyInput, float potenciaStandbyInput)
    :   eletroDomestico(nomeInput,quantidadeInput, diasInput),
        potencia(potenciaInput),
        horasUsadas(horasInput),
        possuiStandby(possuiStandbyInput),
        potenciaStandby(potenciaStandbyInput),
        kwh(0.0f)
{ }

float eletronicoGenerico::calcKwh() {
    float consumoAtivo = (potencia * horasUsadas * diasSimulado * quantidade) / 1000.0f;
    float consumoStandby = 0.0f;

    if (possuiStandby){
        float horasEmStandby = 24.0f - horasUsadas;
        consumoStandby = (potenciaStandby * horasEmStandby * diasSimulado * quantidade) / 1000.0f;
    }

    kwh = consumoAtivo + consumoStandby;
    return kwh;
}

void eletronicoGenerico::setKwh(float kwhInput) {
    kwh = kwhInput;
}

float eletronicoGenerico::getKwh() const {
    return kwh;
}

int eletronicoGenerico::getPotencia() const {
    return potencia;
}

int eletronicoGenerico::getQuantidade() const {
    return quantidade;
}

float eletronicoGenerico::getHorasUsadas() const {
    return horasUsadas;
}

int eletronicoGenerico::getDiasSimulado() const {
    return diasSimulado;
}

void eletronicoGenerico::setStandby(bool possuiStandbyInput, float potenciaStandbyInput){
    possuiStandby = possuiStandbyInput;
    potenciaStandby = potenciaStandbyInput;
}

bool eletronicoGenerico::getPossuiStandby() const {
    return possuiStandby;
}

float eletronicoGenerico::getPotenciaStandby() const {
    return potenciaStandby;
}
