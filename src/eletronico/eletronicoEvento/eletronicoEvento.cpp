#include "eletronicoEvento.h"
#include <string>

// Construtor: chama o construtor da classe base e inicializa os atributos específicos
eletroEvento::eletroEvento(std::string nomeInput, int potenciaInput, float duracaoEventoInput, 
                           int eventosPorDiaInput, int diasInput, int quantidadeInput)
    : eletroDomestico(nomeInput, quantidadeInput, diasInput),
      potencia(potenciaInput),
      duracaoEventoMin(duracaoEventoInput),
      eventosPorDia(eventosPorDiaInput)
{
    nome = "Eletro por Evento"; // Aqui você pode definir um nome mais genérico ou manter o nomeInput
}

// Calcula o consumo de energia com base em eventos (sessões curtas de uso)
// Fórmula: (potência × duração × eventos/dia × dias × quantidade) ÷ 1000
float eletroEvento::calcKwh() {
    float duracaoHoras = duracaoEventoMin / 60.0f; // Converte minutos para horas
    this->kwh = (potencia * duracaoHoras * eventosPorDia * diasSimulado * quantidade) / 1000.0f;
    return this->kwh;
}

// Getters: funções que retornam os valores dos atributos privados

int eletroEvento::getPotencia() const {
    return potencia;
}

float eletroEvento::getDuracaoEvento() const {
    return duracaoEventoMin;
}

int eletroEvento::getEventosPorDia() const {
    return eventosPorDia;
}
