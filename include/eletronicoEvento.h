#ifndef ELETROEVENTO_H
#define ELETROEVENTO_H

#include "eletroDomestico.h"
#include <string>

// Classe eletroEvento representa um eletrodoméstico que é usado por sessões/eventos
// Exemplo: chuveiro, micro-ondas, ferro de passar
class eletroEvento : public eletroDomestico {
private:
    int potencia;              // Potência do aparelho em watts
    int duracaoEventoMin;      // Duração média de cada evento em minutos
    int eventosPorDia;         // Quantas vezes por dia o aparelho é usado
    float kwh;                 // Consumo total em kWh

public:
    // Construtor que inicializa todos os atributos e passa nome, quantidade e dias para a base
    eletroEvento(std::string nomeInput, int potenciaInput, float duracaoEventoInput,
                 int eventosPorDiaInput, int diasInput, int quantidadeInput = 1);

    // Implementação da função polimórfica que calcula o consumo em kWh
    float calcKwh() override;

    // Getters para os atributos privados
    float getKwh() const;
    int getPotencia() const;
    float getDuracaoEvento() const;
    int getEventosPorDia() const;
};

#endif // ELETROEVENTO_H
