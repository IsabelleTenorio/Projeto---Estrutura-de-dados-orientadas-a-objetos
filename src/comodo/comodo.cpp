#include "comodo.h"
#include <iostream>
#include <sstream>
#include "eletronicoGenerico.h"
#include "geladeira.h"
using namespace std;

Comodo::Comodo(const string& nome) : nome(nome) {}

void Comodo::adicionarEletrodomestico(eletroDomestico* eletro) {
    eletrodomesticos[eletro->getNome()] = eletro;
}

void Comodo::retirarEletrodomestico(const string& nomeEletro) {
    auto it = eletrodomesticos.find(nomeEletro);
    if (it != eletrodomesticos.end()){
        delete it->second;
        eletrodomesticos.erase(it);
    }
}

double Comodo::calcularConsumoTotal() const {
    double total = 0.0;
    for (const auto& par : eletrodomesticos) {
        if (par.second == nullptr) {
            continue;
        }
        total += par.second->calcKwh();
    }
    return total;
}

string Comodo::getNome() const {
    return nome;
}

void Comodo::setNome(const string& novoNome) {
    nome = novoNome;
}

eletroDomestico* Comodo::getEletrodomestico(const string& nomeEletro) const {
    auto it = eletrodomesticos.find(nomeEletro);
    if (it != eletrodomesticos.end()){
        return it->second;
    }
    return nullptr;
}

string Comodo::getEletrodomesticosConsumo() const{
    stringstream ss;
    for (const auto& par : eletrodomesticos){
        ss << par.first << ": " << par.second->getKwh() << " kwh\n";
    }
    return ss.str();


}

bool verificarValor(double valorInput) {
    if (valorInput > 0){
        return true;
    }else return false;
}

Comodo::~Comodo(){
    for (auto& par : eletrodomesticos){
        delete par.second;
    }
    eletrodomesticos.clear();
}

/*
Exemplo de como inicializar
eletroDomestico* tv = new eletronicoGenerico("TV", 100, 1, 5.0f, 30, true, 10);
tv->calcKwh();
sala.adicionarEletrodomestico(tv); // <- envia ponteiro para o map
*/