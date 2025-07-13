#ifndef CASA_H
#define CASA_H
#include <vector>
#include "comodo.h"

using namespace std;

class Casa{
private:
    vector<Comodo*> comodos; // casa se torna um vector de comodos, pois não seria tão interessante trabalhar com cópias de comodos, pois os mesmos
                             // são estruturas complexas

public:

    void addComodo(Comodo* comodo);
    void removeComodo(const string& nomeComodo);
    void imprimirComodos() const;
    void exibirComodosPorConsumo() const;
    std::pair<float, float> calcularConsumoComodos() const;
    const vector<Comodo*>& getComodos() const;
    bool temComodo(const std::string& nome) const;
    Comodo& getComodo(const string& nome);
    ~Casa();

};

#endif // CASA_H

