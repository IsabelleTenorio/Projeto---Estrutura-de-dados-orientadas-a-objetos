#include "eletronicoGenerico.h"
#include <string>
#include <iostream>
#include <typeinfo>

// Construtor usando member initializer list é mais eficiente                   quantidade de eletrodomesticos (ex: adicionar 2 geladeiras)
eletronicoGenerico::eletronicoGenerico(std::string nomeInput,int potenciaInput, int quantidadeInput, float horasInput, int diasInput, bool possuiStandbyInput, float potenciaStandbyInput)
    :   eletroDomestico(nomeInput,quantidadeInput, diasInput),
        potencia(potenciaInput),
        horasUsadas(horasInput),
        possuiStandby(possuiStandbyInput),
        potenciaStandby(potenciaStandbyInput)
{ }

float eletronicoGenerico::calcKwh() {
    std::cout << "[DEBUG] calcKwh chamado em tipo: " << typeid(*this).name() << std::endl;    
    std::cout << "      > Entrando em calcKwh() de " << nome << std::endl;
    std::cout << "      > potencia: " << potencia << ", horas: " << horasUsadas
              << ", dias: " << diasSimulado << ", qtd: " << quantidade << std::endl;
    float consumoAtivo = (potencia * horasUsadas * diasSimulado * quantidade) / 1000.0f;
    float consumoStandby = 0.0f;

    if (possuiStandby){
        float horasEmStandby = 24.0f - horasUsadas;
        consumoStandby = (potenciaStandby * horasEmStandby * diasSimulado * quantidade) / 1000.0f;
    }

    this->kwh = consumoAtivo + consumoStandby;
    return this->kwh;
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
