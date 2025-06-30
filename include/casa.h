#include <vector>
#include "comodo.h"

using namespace std;

class Casa{
private:
    vector<Comodo> comodos;

public:

    void addComodo(const Comodo& comodo);
    void removeComodo(const string& nomeComodo);
    void imprimirComodos() const;
    std::pair<float, float> calcularConsumoComodos() const;
    const vector<Comodo>& getComodos() const;
    Comodo& getComodo(const string& nome);

};


