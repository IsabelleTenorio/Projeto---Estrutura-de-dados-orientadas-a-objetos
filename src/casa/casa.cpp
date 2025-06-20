#include "casa.h"
#include <iostream>
#include <iomanip> // pra formatar a saída do float


void Casa::addComodo(const Comodo& comodo) {
    comodos.push_back(comodo); // em termos de python, isso seria como comodos.append(comodo)
}

void Casa::removeComodo(const std::string& nomeComodo) {
    for (auto it = comodos.begin(); it != comodos.end(); ++it) { // percorre o vetor de comodos, o begin() diz respeito ao primeiro elemento do vetor, e o end() ao ultimo elemento
        if (it-> getNome() == nomeComodo) {
            comodos.erase(it);
            return;
        }
    }
}

float Casa::calcularConsumoComodos() const {
    float total = 0.0f;
    for (const auto& comodo : comodos) {
        total += comodo.calcularConsumoTotal();
    }
    return total;
}

Comodo& Casa::getComodo(const std::string& nome) {
    for (auto& comodo : comodos) {
        if (comodo.getNome() == nome) {
            return comodo; 
        }
    }

}

const std::vector<Comodo>& Casa::getComodos() const {
    return comodos; 
}

void Casa::imprimirComodos() const {
    for (const auto& comodo : comodos) {
        std::cout << comodo.getNome() << ": " << std::fixed << std::setprecision(2) << comodo.calcularConsumoTotal() << " kWh" << std::endl;  // lista os nomes dos comodos 1 abaixo do outro com o consumo total de cada um
    }
}

