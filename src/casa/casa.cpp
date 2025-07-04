#include "casa.h"
#include <iostream>
#include <iomanip> // pra formatar a saída do float
#include <algorithm>
#include <vector>


void Casa::addComodo(Comodo* comodo) {
    comodos.push_back(comodo); // em termos de python, isso seria como comodos.append(comodo)
}

void Casa::removeComodo(const std::string& nomeComodo) {
    for (size_t i = 0; i < comodos.size(); ++i) {
        if (comodos[i]->getNome() == nomeComodo) {
            delete comodos[i];
            comodos.erase(comodos.begin() + i); 
            return; 
        }
    }
}

std::pair<float, float> Casa::calcularConsumoComodos() const {
    float total = 0.0f;
    float simular_conta;
    for (const auto& comodo : comodos) {
        total += comodo->calcularConsumoTotal();
    }
    simular_conta = total * 0.706f; // supondo que o custo por kWh seja 0.706 em Recife atualmente
    return {total, simular_conta};
}

Comodo& Casa::getComodo(const std::string& nome) {
    for (auto& comodo : comodos) {
        if (comodo->getNome() == nome) {
            return *comodo; 
        }

    }
    throw std::runtime_error("Comodo nao encontrado: " + nome);

}

bool Casa::temComodo(const std::string& nome) const {
    for (const auto& comodo : comodos) {
        if (comodo->getNome() == nome) {
            return true;
        }
    }
    return false;
}


const std::vector<Comodo*>& Casa::getComodos() const {
    return comodos; 
}

void Casa::imprimirComodos() const {
    for (const auto& comodo : comodos) {
        std::cout << comodo->getNome() << ": " << std::fixed << std::setprecision(2)
                  << comodo->calcularConsumoTotal() << " kWh" << std::endl;
    }
}

void Casa::exibirComodosPorConsumo() const {
    vector<pair<string, float>> consumoComodos;

    for (const auto& comodo : comodos) {
        consumoComodos.emplace_back(comodo->getNome(), comodo->calcularConsumoTotal());
    }

    sort(consumoComodos.begin(), consumoComodos.end(),
         [](const pair<string, float>& a, const pair<string, float>& b) {
             return a.second > b.second; // ordem decrescente
         });

    cout << "\n--- Ranking de Cômodos por Consumo ---\n";
    for (const auto& par : consumoComodos) {
        cout << par.first << ": " << par.second << " kWh\n";
    }
}



Casa::~Casa() {
    for (auto comodo : comodos) {
        delete comodo;
    }
    comodos.clear();
}