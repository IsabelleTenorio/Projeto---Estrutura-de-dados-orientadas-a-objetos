#include <vector>
#include "comodo.h"

class Casa{
private:
    std::vector<Comodo> comodos;

public:


    void addComodo(const Comodo& comodo);
    void removeComodo(const std::string& nomeComodo);
    void imprimirComodos() const;
    float calcularConsumoComodos() const;
    const std::vector<Comodo>& getComodos() const;
    Comodo& getComodo(const std::string& nome);

};


