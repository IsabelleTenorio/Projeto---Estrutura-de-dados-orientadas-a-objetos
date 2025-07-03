#ifndef ELETRODOMESTICO_H
#define ELETRODOMESTICO_H

#include <string> // Necessário para usar std::string

// Classe base abstrata que representa um eletrodoméstico genérico
class eletroDomestico {
protected:
    int quantidade;           // Quantidade de aparelhos iguais
    int diasSimulado;         // Quantos dias o consumo será simulado
    std::string nome;         // Nome do eletrodoméstico (ex: "Geladeira")
    float kwh;

public:
    // Construtor da classe base, inicializa os atributos comuns
    eletroDomestico(std::string nomeInput, int quantidadeInput, int diasInput)
        : quantidade(quantidadeInput), diasSimulado(diasInput), nome(nomeInput) {}

    // Destrutor virtual: garante que ao deletar via ponteiro da base,
    // o destrutor correto da subclasse será chamado
    virtual ~eletroDomestico() = default;

    // Método puramente virtual: força todas as subclasses a implementarem calcKwh()
    virtual float calcKwh() = 0;

    // Getter para quantidade de aparelhos
    int getQuantidade() const {
        return quantidade;
    }

    // Getter para dias de simulação
    int getDiasSimulado() const {
        return diasSimulado;
    }

    // Getter para o nome do eletrodoméstico
    std::string getNome() const {
        return nome;
    }

    float getKwh() const{
        return kwh;
    };
};

#endif // ELETRODOMESTICO_H
