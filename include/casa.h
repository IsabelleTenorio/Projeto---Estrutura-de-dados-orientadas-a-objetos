#ifndef CASA_H
#define CASA_H
#include <vector>
#include "comodo.h"

using namespace std;

class Casa{
private:
    vector<Comodo*> comodos;

public:

    void addComodo(Comodo* comodo);
    void removeComodo(const string& nomeComodo);
    void imprimirComodos() const;
    void exibirComodosPorConsumo() const;
    std::pair<float, float> calcularConsumoComodos() const;
    const vector<Comodo*>& getComodos() const;
    Comodo& getComodo(const string& nome);
    ~Casa();

};

#endif // CASA_H

