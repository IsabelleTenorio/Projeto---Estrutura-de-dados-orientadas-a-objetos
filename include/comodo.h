#ifndef COMODO_H
#define COMODO_H

#include <string>
#include <map>

using namespace std;

class Comodo {
public:
    Comodo(const string& nome);

    void adicionarEletrodomestico(const string& nomeEletro, double consumo); //-- adiciona eletrodoméstico com seu consumo na lista
    void retirarEletrodomestico(const string& nomeEletro); //-- retira eletrodoméstico da lista
    double calcularConsumoTotal() const; //-- calcula o consumo total de energia do cômodo

    string getNome() const; //--pega o nome do cômodo
    void setNome(const string& novoNome); //-- define o nome do cômodo


    //duda: eu nao sabia se queriam uma lista com o consumo ou sem entao ta os dois
    string getEletrodomesticos() const; //-- retorna uma lista de eletrodomésticos no cômodo
    string getEletrodomesticosConsumo() const; //-- retorna uma lista de eletrodomésticos com seus consumos no cômodo

private:
    string nome;
    map<string, double> eletrodomesticos;
};

#endif // COMODO_H