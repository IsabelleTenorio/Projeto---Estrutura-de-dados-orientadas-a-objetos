#include "comodo.h"
#include <iostream>
using namespace std;

const map<string, double> Comodo::consumoEnergetico = {
    //simulação 
    {"Geladeira", 30.0},
    {"Televisao", 10.0},
    {"Microondas", 15.0}
};

Comodo::Comodo(const string& nomeComodo) : nomeComodo(nomeComodo) {}

void Comodo::adicionarEletrodomestico(const string& nomeEletro, double consumo) {
    eletrodomesticos[nomeEletro] = consumo;
}

void Comodo::retirarEletrodomestico(const string& nomeEletro) {
    eletrodomesticos.erase(nomeEletro);
}

double Comodo::calcularConsumoTotal() const {
    double total = 0.0;
    for (const auto& par : eletrodomesticos) {
        total += par.second;
    }
    return total;
}

string Comodo::getNome() const {
    return nomeComodo;
}

string Comodo::setNome(string nomeInput) { 
    nomeComodo = nomeInput; // Belle: estava igual ao getNome e tive que tirar o const pq não estava deixando mudar o valor
}
//precisa de um metodo setNome