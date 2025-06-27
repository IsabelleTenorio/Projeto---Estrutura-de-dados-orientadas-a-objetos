#ifndef COMODO_H
#define COMODO_H

#include <string>
#include <map>

using std::string;
using std::map;

class Comodo {
private:
    string nomeComodo;
    map<string, double> eletrodomesticos;

    static const map<string, double> consumoEnergetico;

    string setNome(string nomeInput) ; // duda -- serve para setar o nome do comodo

public:
    Comodo(const string& nomeComodo);

    void adicionarEletrodomestico(const string& nomeEletro, double consumo);
    void retirarEletrodomestico(const string& nomeEletro);
    double calcularConsumoTotal() const;

    string getNome() const; // isaac -- adicionei isso pq tava precisando de uma forma de pegar o nome do comodo pra 
                            // poder remover o comodo 
};

//precisa de um metodo getEletrodomesticos (que exiba os eletrodomesticos do comodo (1 em casa linha))

#endif // COMODO_H
