#include "sistema.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL,"pt_BR.UTF-8"); //Permite o uso de acentos
    Sistema meuSistema;
    meuSistema.telaInicial();
    meuSistema.testarSistema();
    //meuSistema.menuPrincipal();
    return 0;
}