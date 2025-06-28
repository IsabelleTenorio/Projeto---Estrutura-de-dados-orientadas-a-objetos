#include "casa.h"
#include <iostream>
#include <iomanip> // pra formatar a saída do float


void Casa::addComodo(const Comodo& comodo) {
    comodos.push_back(comodo); // em termos de python, isso seria como comodos.append(comodo)
}

void Casa::removeComodo(const std::string& nomeComodo) {
    for (int i = 0; i < comodos.size(); ++i) { // o i começa em 0 e vai até o tamanho do vetor - 1
        if (comodos[i].getNome() == nomeComodo) { // verifica se o nome do comodo no vetor é igual ao nome passado como argumento
            comodos.erase(comodos.begin() + i); // remove o comodo do vetor
            return; 
        }
    }
}

float Casa::calcularConsumoComodos() const {
    float total = 0.0f;
    for (const auto& comodo : comodos) {  // percorre cada comodo no vetor e calcula o consumo total dele, e adiciona ao consumo total da casa
        total += comodo.calcularConsumoTotal();
    }
    return total;
}

Comodo& Casa::getComodo(const std::string& nome) { // retorna um comodo especifico pelo nome, vou colocar isso dentro de um try catch dps
    // try
    // {
        
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    for (auto& comodo : comodos) {
        if (comodo.getNome() == nome) {
            return comodo; 
        }
    }

}

const std::vector<Comodo>& Casa::getComodos() const { // retorna a lista de comodos
    return comodos; 
}

void Casa::imprimirComodos() const { // lista os comodos e seus consumos totais
    for (const auto& comodo : comodos) {
        std::cout << comodo.getNome() << ": " << std::fixed << std::setprecision(2) << comodo.calcularConsumoTotal() << " kWh" << std::endl;  // lista os nomes dos comodos 1 abaixo do outro com o consumo total de cada um
    } // o fixed e o setprecision são pra formatar a saida do float, mostrando sempre duas casas decimais
}

