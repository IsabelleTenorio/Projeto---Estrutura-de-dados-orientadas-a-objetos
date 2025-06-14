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

private:
    string nome;
    map<string, double> eletrodomesticos;

    static const map<string, double> consumoEnergetico;
};

#endif // COMODO_H
