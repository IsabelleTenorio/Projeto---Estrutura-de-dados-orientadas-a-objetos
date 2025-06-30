#include "comodo.h"
using namespace std;

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

string Comodo::getNome() const {
    return nome;
}

void Comodo::setNome(const string& novoNome) {
    nome = novoNome;
}

string Comodo::getEletrodomesticosConsumo() const {
    string lista_eletrodomesticos_consumo;
    for (const auto& par : eletrodomesticos) {
        lista_eletrodomesticos_consumo += par.first + ": " + to_string(par.second) + " kWh\n";
    }
    return lista_eletrodomesticos_consumo;
}