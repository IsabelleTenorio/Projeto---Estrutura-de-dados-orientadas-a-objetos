#ifndef SISTEMA_H
#define SISTEMA_H

#include "casa.h"

class Sistema {

    private:
    Casa casa;  

    public:
    Sistema();
    void telaInicial();
    void menuPrincipal();

    static int lerInteiroPositivo(const string& mensagem);
    static float lerFloatPositivo(const string& mensagem);
    static bool desejaAdcionar(const int booleano);
    static int lerBooleano(const string& mensagem);


};


#endif