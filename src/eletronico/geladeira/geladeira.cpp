#include "geladeira.h"
#include <iostream>
using namespace std;

// Construtor: inicializa a classe base com nome, quantidade e dias, e define os atributos específicos
geladeira::geladeira(std::string nomeInput = "Geladeira", int potenciaInput, int quantidadeInput, int diasInput,
                     float fatorUsoInput)
    : eletroDomestico(nomeInput,quantidadeInput, diasInput),
    potencia(potenciaInput),
    fatorUso(fatorUsoInput),
    kwh(0.0f)
{ }
// Calcula o consumo da geladeira considerando 24h de uso por dia e o fator de uso
float geladeira::calcKwh(){
    kwh = (potencia * 24.0f * fatorUso * diasSimulado * quantidade)/ 1000.0f;
    return kwh;
}

float geladeira::getKwh() const {
    return kwh;
}

int geladeira::getPotencia() const{
    return potencia;
}

float geladeira::getFatorUso() const{
    return fatorUso;
}