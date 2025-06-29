#ifndef ELETRONICO_H
#define ELETRONICO_H

class eletroDomestico {
private:
    int potencia;
    int quantidade;
    int diasSimulado;
    float horasUsadas;
    float kwh;
    bool possuiStandby;
    float potenciaStandby;

public:
    // Construtor com valores padrão é ótimo para facilitar a criação
    eletroDomestico(int potenciaInput = 0, int quantidadeInput = 0, float horasInput = 0.0f, int diasInput = 0, bool possuiStandbyInput = false, float potenciaStandbyInput = 0.0f);

    // Função que calcula consumo em kWh
    float calcKwh();

    // Getters e setters
    void setKwh(float kwhInput);
    float getKwh() const;
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
