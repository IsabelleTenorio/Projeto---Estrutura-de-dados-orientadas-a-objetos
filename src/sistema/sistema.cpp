#include "sistema.h"
#include <iostream>
#include <locale.h>
#include <vector>
#include "geladeira.h"
#include "comodo.h"
#include "eletronicoGenerico.h"
#include "casa.h"
#include <string>
#include "eletroDomestico.h"

using namespace std;

/*
 * Este projeto usa CMake para configurar e compilar o código.
 *
 * Fluxo típico para compilar e executar:
 *
 * 1. Criar a pasta 'build' (se ainda não existir).
 * 2. Entrar na pasta build e rodar(cd build):
 *      cmake ..
 *    Esse comando lê o CMakeLists.txt e gera os arquivos necessários para build.
 *    Deve ser executado sempre que modificar o CMakeLists.txt.
 *
 * 3. Para compilar o código, rodar dentro da pasta build:
 *      cmake --build .
 *    Isso compila o código fonte e gera o executável.
 *
 * 4. Para executar o programa, rodar o executável gerado:
 *      ./projeto.exe  (no Windows PowerShell)
 *
 * Você só precisa recompilar (passo 3) quando mudar o código fonte.
 * Para rodar várias vezes, basta executar o executável.
 *
 * Obs:
 * - A pasta 'build' não deve ser incluída no controle de versão (ex: GitHub).
 * - Quem clonar o projeto deve criar a pasta build, rodar cmake e compilar.
 */


Sistema::Sistema() {}


void Sistema::telaInicial() {
    setlocale(LC_ALL,"pt_BR.UTF-8");
    cout << "Bem-vindo ao sistema de monitoramento de energia!\n";
}



void Sistema::testarSistema(){

/*
 * Criação e uso dos cômodos no sistema:
 *
 * 1. Cada cômodo é representado pela classe `Comodo`, que armazena um nome 
 *    (ex: "Sala", "Quarto") e uma coleção de eletrodomésticos associados a ele.
 *
 * 2. Para criar um cômodo, usamos o construtor da classe `Comodo` passando o nome:
 *      Comodo* sala = new Comodo("Sala");
 *
 * 3. Eletrodomésticos são criados dinamicamente, como objetos de subclasses de 
 *    `eletroDomestico` (ex: `eletronicoGenerico`, `geladeira`), e depois adicionados
 *    ao cômodo usando o método:
 *      sala->adicionarEletrodomestico(eletro);
 *    Isso registra o eletrodoméstico no mapa interno do cômodo, usando o nome como chave.
 *
 * 4. A classe `Casa` mantém uma lista de ponteiros para `Comodo`, representando todos
 *    os cômodos da casa. Para adicionar um cômodo à casa, chamamos:
 *      casa.addComodo(sala);
 *
 * 5. O sistema usa polimorfismo para calcular o consumo total de cada cômodo. Quando
 *    pedimos para o cômodo calcular seu consumo (`sala->calcularConsumoTotal()`), 
 *    ele percorre todos os eletrodomésticos registrados e chama o método `calcKwh()` 
 *    apropriado para cada tipo, somando tudo.
 *
 * 6. Ao final, a `Casa` consegue calcular o consumo total da residência somando o 
 *    consumo de todos os cômodos.
 *
 * 7. Importante: como usamos alocação dinâmica (`new`), a casa e os cômodos são 
 *    responsáveis por liberar a memória com `delete` para evitar vazamentos.
 *
 * Resumo:
 * - Criamos cômodos dinamicamente com `new Comodo("Nome")`.
 * - Criamos eletrodomésticos e adicionamos aos cômodos.
 * - Adicionamos os cômodos à casa.
 * - Calculamos consumo chamando métodos polimórficos que somam os consumos.
 * - Gerenciamos memória deletando os objetos criados.
 */

    cout << "\n=== INÍCIO DO TESTE DO SISTEMA ===\n";

    // Cria cômodos dinamicamente
    Comodo* sala = new Comodo("Sala");
    Comodo* quarto = new Comodo("Quarto");
    Comodo* cozinha = new Comodo("Cozinha");

    // Cria eletrodomésticos de diferentes tipos
    eletronicoGenerico* tv = new eletronicoGenerico("TV", 120, 1, 5.0, 30);
    eletronicoGenerico* ventilador = new eletronicoGenerico("Ventilador", 80, 1, 8.0, 30);
    geladeira* gela = new geladeira("Geladeira", 300, 1, 30, 0.8);
    eletronicoGenerico* microondas = new eletronicoGenerico("Micro-ondas", 1100, 1, 0.5, 30);
    eletronicoGenerico* computador = new eletronicoGenerico("Computador", 250, 1, 6.0, 30, true, 5);

    // Adiciona eletrodomésticos aos cômodos
    sala->adicionarEletrodomestico(tv);
    sala->adicionarEletrodomestico(ventilador);
    sala->adicionarEletrodomestico(computador);

    quarto->adicionarEletrodomestico(gela);

    cozinha->adicionarEletrodomestico(microondas);

    // Adiciona cômodos à casa
    casa.addComodo(sala);
    casa.addComodo(quarto);
    casa.addComodo(cozinha);

    // Imprime os cômodos e consumos detalhados
    casa.imprimirComodos();

    // Mostra consumos individuais detalhados
    cout << "\nConsumos detalhados por eletrodoméstico:\n";
    for (const auto& comodoPtr : casa.getComodos()) {
        cout << "No cômodo " << comodoPtr->getNome() << ":\n";
        cout << comodoPtr->getEletrodomesticosConsumo();
    }

    auto resultado = casa.calcularConsumoComodos();
    cout << "\nConsumo total da casa: " << resultado.first << " kWh\n";
    cout << "Simulação de conta: R$ " << resultado.second << "\n";

    cout << "=== FIM DO TESTE ===\n";

    // A casa e os cômodos serão responsáveis por deletar os objetos alocados.
}

