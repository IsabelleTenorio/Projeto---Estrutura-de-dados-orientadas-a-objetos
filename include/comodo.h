#ifndef COMODO_H
#define COMODO_H

#include <string>
#include <map>
#include "eletroDomestico.h"

using namespace std;

class Comodo {
public:
    Comodo(const string& nome);

    void adicionarEletrodomestico(eletroDomestico* eletro); //-- adiciona eletrodoméstico com seu consumo na lista
    void retirarEletrodomestico(const string& nomeEletro); //-- retira eletrodoméstico da lista
    double calcularConsumoTotal() const; //-- calcula o consumo total de energia do cômodo

    string getNome() const; //--pega o nome do cômodo
    void setNome(const string& novoNome); //-- define o nome do cômodo
    
    eletroDomestico* getEletrodomestico(const string& nomeEletro) const; //-- retorna uma lista de eletrodomésticos com seus consumos no cômodo
    string getEletrodomesticosConsumo() const;

    ~Comodo();

private:
    string nome;
    map<string, eletroDomestico*> eletrodomesticos;
};

#endif // COMODO_H