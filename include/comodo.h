#ifndef COMODO_H
#define COMODO_H

#include <string>
#include <map>

using std::string;
using std::map;

class Comodo {
public:
    Comodo(const string& nome);

    void adicionarEletrodomestico(const string& nomeEletro, double consumo);
    void retirarEletrodomestico(const string& nomeEletro);
    double calcularConsumoTotal() const;

    string getNome() const; // isaac -- adicionei isso pq tava precisando de uma forma de pegar o nome do comodo pra 
                            // poder remover o comodo 

private:
    string nome;
    map<string, double> eletrodomesticos;

    static const map<string, double> consumoEnergetico;
};

//precisa de um metodo setNome
//precisa de um metodo getEletrodomesticos (que exiba os eletrodomesticos do comodo (1 em casa linha))

#endif // COMODO_H
