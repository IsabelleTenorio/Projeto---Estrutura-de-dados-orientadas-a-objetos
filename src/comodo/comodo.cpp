#include "comodo.h"

const map<string, double> Comodo::consumoEnergetico = {
    //simulação 
    {"Geladeira", 30.0},
    {"Televisao", 10.0},
    {"Microondas", 15.0}
};

Comodo::Comodo(const string& nome) : nome(nome) {}

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

std::string Comodo:: getNome() const {
    return nome;
}

//precisa de um metodo setNome