#ifndef GELADEIRA_H
#define GELADEIRA_H

#include "eletroDomestico.h"  // Inclui a classe base
#include <string>

// Classe que representa uma geladeira, herda de eletroDomestico
// foi necessário uma classe própria para geladeira pois ela funciona de forma diferente dos outros eletrodomésticos
class geladeira : public eletroDomestico {
private:
    int potencia;      // Potência da geladeira em watts
    float fatorUso;    // Fator de uso diário (ex: 0.8 representa 80% do tempo ligada)

public:
    // Construtor que inicializa os atributos e passa dados para a classe base
    geladeira(std::string nome, int potenciaInput, int quantidadeInput = 1,
              int diasInput = 1, float fatorUsoInput = 1.0f);

    // Implementa o método polimórfico de cálculo de consumo
    float calcKwh() override;

    // Getters dos atributos privados
    int getPotencia() const;
    float getFatorUso() const;
};

#endif // GELADEIRA_H
