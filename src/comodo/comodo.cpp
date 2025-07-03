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
    std::cout << ">> Entrando em calcularConsumoTotal()" << std::endl;
    for (const auto& par : eletrodomesticos) {
    std::cout << "   - Calculando: " << par.first << std::endl;
    if (par.second == nullptr) {
        std::cout << "   [ERRO] Ponteiro nulo para " << par.first << std::endl;
        continue;
    }

    if (dynamic_cast<eletronicoGenerico*>(par.second)) {
        std::cout << "   [DEBUG] É um eletronicoGenerico" << std::endl;
    } else if (dynamic_cast<geladeira*>(par.second)) {
        std::cout << "   [DEBUG] É uma geladeira" << std::endl;
    } else {
        std::cout << "   [DEBUG] É um eletroDomestico genérico ou outro tipo" << std::endl;
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