#include <vector>
#include "comodo.h"

class Casa{
private:
    std::vector<Comodo> comodos;

public:


    void addComodo(const Comodo& comodo);
    void removeComodo(const std::string& nomeComodo);
    float calcularConsumoComodos() const;
    const std::vector<Comodo>& getComodos() const;
    void imprimirComodos() const;

    Comodo& getComodo(const std::string& nome);

    // por enquanto vou deixar assim, mas vou mudar depois

};


