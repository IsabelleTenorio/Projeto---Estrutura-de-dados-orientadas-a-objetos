#include <vector>
#include "comodo.h"

using namespace std;

class Casa{
private:
    vector<Comodo> comodos;

public:


    void addComodo(const Comodo& comodo); // adiciona um comodo na lista de comodos (casa)
    void removeComodo(const string& nomeComodo); // remove um comodo da lista
    void imprimirComodos() const; // lista os comodos e seus consumos totais
    float calcularConsumoComodos() const; // calcula o consumo total de todos os comodos
    const vector<Comodo>& getComodos() const; // retorna a lista de comodos
    Comodo& getComodo(const string& nome); // retorna um comodo especifico pelo nome

};


