#ifndef GELADEIRA_H
#define GELADEIRA_H
#include "eletronico.h"
using namespace std;

class geladeira : public eletroDomestico {
public:
    geladeira(int potenciaInput = 1, int quantidadeInput = 1, int diasInput = 1);
    
};

#endif