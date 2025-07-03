#ifndef ELETRONICO_H
#define ELETRONICO_H

#include "eletroDomestico.h"
#include <string>

class eletronicoGenerico :public eletroDomestico {
private:
    int potencia;
    float horasUsadas;
    bool possuiStandby;
    float potenciaStandby;

public:
    // Construtor com valores padrão é ótimo para facilitar a criação
    eletronicoGenerico(std::string nome,int potenciaInput = 0, int quantidadeInput = 0,
     float horasInput = 0.0f, int diasInput = 0, bool possuiStandbyInput = false,
      float potenciaStandbyInput = 0.0f);

    // Função que calcula consumo em kWh
    float calcKwh() override;

    // Getters e setters
    int getPotencia() const;
    int getQuantidade() const;
    float getHorasUsadas() const;
    int getDiasSimulado() const;

    // Standby
    void setStandby(bool possuiStandbyInput = false, float potenciaStandbyInput = 0.0f);
    bool getPossuiStandby() const;
    float getPotenciaStandby() const;
};

#endif
