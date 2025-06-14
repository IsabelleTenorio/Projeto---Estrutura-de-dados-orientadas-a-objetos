#include <vector>
#include "comodo.h"

class Casa{
private:
    std::vector<Comodo> comodos;

public:


    void addComodo(const Comodo& comodo);
    void removeComodo(const std::string& nomeComodo);

    float calcularConsumoTotal() const;


    Comodo& getComodo(const std::string& nome);
    const std::vector<Comodo>& getComodos() const;




    // por enquanto vou deixar assim, mas vou mudar depois

};


