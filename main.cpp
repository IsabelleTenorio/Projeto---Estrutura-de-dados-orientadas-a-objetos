#include "sistema.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL,"pt_BR.UTF-8");
    Sistema meuSistema;
    meuSistema.telaInicial();
    meuSistema.menuPrincipal();
    return 0;
}