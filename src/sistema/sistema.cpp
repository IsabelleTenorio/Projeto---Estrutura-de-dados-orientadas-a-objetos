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
#include "eletronicoEvento.h"

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
 *      ./projeto.exe  (no Windows PowerShell) ou .\Debug\projeto.exe
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

void Sistema::menuPrincipal() {
    {
    setlocale(LC_ALL,"pt_BR.UTF-8");
    int opcao;
    
    cout << "\n===== Sistema de Consumo Energético =====\n";
    cout << "================ CINergy ================\n\n";
    cout << "Seja bem vindo!";

    float dias = 0;
    do{
    cout << "\nDigite a quantidade de dias que você quer simular: ";
    cin >> dias;
    if (dias < 1){
        cout << "Digite dias validos. ";
    }
    }while (dias<1);

    do {
        cout << "\n===== Sistema de Consumo Energético =====\n";
        cout << "================ CINergy ================\n\n";
        cout << "1. Listar cômodos e consumo\n";
        cout << "2. Exibir consumo total da casa\n";
        cout << "3. Adicionar novo cômodo\n";
        cout << "4. Excluir cômodo\n";
        cout << "5. Acessar cômodo\n";
        cout << "6. Acessar simulador de conta de energia\n";
        cout << "7. Listar o raking de cômodos por Consumo\n";
        cout << "8. Sair\n";
        cout << "\nDigite o número da opção desejada: ";
        cin >> opcao;
        cout << "\n==========================================\n\n";

        switch (opcao) {
            case 1:
                casa.imprimirComodos();
                break;

            case 2: {
                auto consumo = casa.calcularConsumoComodos();  
                cout << "Consumo total da casa: " << consumo.second << " kWh\n";
                break;
            }

            case 3: {
                cout << "=========== Adicionando cômodo ===========\n";
                cout << "Escolha o cômodo que deseja adicionar:\n";
                cout << "1. Banheiro\n2. Cozinha\n3. Quarto\n4. Sala\n5. Iluminação\n6. Lavanderia\n";
                int tipo;
                cin >> tipo;

                Comodo* novoComodo = nullptr;

                switch(tipo) {
                    case 1: {
                        novoComodo = new Comodo("Banheiro");

                        int potencia, quantidade;
                        float minutos;
                        int vezesPorDia;
                        cout << "\n======== Adicionando eletrodomésticos ao cômodo Banheiro ========\n";
                        cout << "Chuveiro:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Minutos por uso: "; cin >> minutos;
                        cout << "Quantas vezes por dia: "; cin >> vezesPorDia;

                        novoComodo->adicionarEletrodomestico(new eletroEvento("Chuveiro", potencia, minutos, vezesPorDia, dias, quantidade));

                        break;
                    }
                    case 2: {
                        novoComodo = new Comodo("Cozinha");
                        int potencia, quantidade;
                        float fatorUso;
                        cout << "\n======== Adicionando eletrodomésticos ao cômodo Cozinha ========\n";
                        cout << "Geladeira:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Fator de uso (ex: 0.8): "; cin >> fatorUso;
                        novoComodo->adicionarEletrodomestico(new geladeira("Geladeira", potencia, quantidade, dias, fatorUso));
                        
                        float horas;
                        bool standby;
                        float standbyPotencia;

                        cout << "Fogão Elétrico:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        cout << "Possui standby (1=sim, 0=não): "; cin >> standby;
                        if (standby) {
                            cout << "Potência standby (W): ";
                            cin >> standbyPotencia;
                        } else standbyPotencia = 0;

                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Fogão Elétrico", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        
                        float minutos;
                        int vezesPorDia;

                        cout << "Micro-ondas:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Minutos por uso: "; cin >> minutos;
                        cout << "Quantas vezes por dia: "; cin >> vezesPorDia;

                        novoComodo->adicionarEletrodomestico(new eletroEvento("Micro-ondas", potencia, minutos, vezesPorDia, dias, quantidade));

                        cout << "Liquidificador:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Minutos por uso: "; cin >> minutos;
                        cout << "Quantas vezes por dia: "; cin >> vezesPorDia;

                        novoComodo->adicionarEletrodomestico(new eletroEvento("Liquidificador", potencia, minutos, vezesPorDia, dias, quantidade));

                        cout << "Cafeteira elétrica:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Minutos por uso: "; cin >> minutos;
                        cout << "Quantas vezes por dia: "; cin >> vezesPorDia;

                        novoComodo->adicionarEletrodomestico(new eletroEvento("Cafeteira elétrica", potencia, minutos, vezesPorDia, dias, quantidade));

                        cout << "Torradeira:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Minutos por uso: "; cin >> minutos;
                        cout << "Quantas vezes por dia: "; cin >> vezesPorDia;

                        novoComodo->adicionarEletrodomestico(new eletroEvento("Torradeira", potencia, minutos, vezesPorDia, dias, quantidade));

                        break;
                    }
                    case 3: {
                        novoComodo = new Comodo("Quarto");
                        int potencia, quantidade;
                        float horas;
                        bool standby;
                        float standbyPotencia;
                        cout << "\n======== Adicionando eletrodomésticos ao cômodo Quarto ========\n";
                        cout << "Ventilador:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ventilador", potencia, quantidade, horas, dias, false, 0));
                        
                        cout << "Computador\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        cout << "Possui standby (1=sim, 0=não): "; cin >> standby;
                        if (standby) {
                            cout << "Potência standby (W): ";
                            cin >> standbyPotencia;
                        } else standbyPotencia = 0;
                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Computador", potencia, quantidade, horas, dias, standby, standbyPotencia ));
                        
                        cout << "Televisor\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        cout << "Possui standby (1=sim, 0=não): "; cin >> standby;
                        if (standby) {
                            cout << "Potência standby (W): ";
                            cin >> standbyPotencia;
                        } else standbyPotencia = 0;
                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Televisor", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        
                        cout << "Ar-condicionado\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ar-condicionado", potencia, quantidade, horas, dias, false, 0));
                        

                        break;
                    }
                    case 4: {
                        novoComodo = new Comodo("Sala");
                        int potencia, quantidade;
                        float horas;
                        bool standby;
                        float standbyPotencia;
                        cout << "\n======== Adicionando eletrodomésticos ao cômodo Sala ========\n";
                        cout << "TV:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        cout << "Possui standby (1=sim, 0=não): "; cin >> standby;
                        if (standby) {
                            cout << "Potência standby (W): ";
                            cin >> standbyPotencia;
                        } else standbyPotencia = 0;

                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("TV", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        
                        cout << "Ar-condicionado:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;

                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ar-condicionado", potencia, quantidade, horas, dias, false, 0));
                        
                        cout << "Ventilador:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;

                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ventilador", potencia, quantidade, horas, dias, false, 0));
                        
                        cout << "Videogame\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        cout << "Possui standby (1=sim, 0=não): "; cin >> standby;
                        if (standby) {
                            cout << "Potência standby (W): ";
                            cin >> standbyPotencia;
                        } else standbyPotencia = 0;

                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Videogame", potencia, quantidade, horas, dias, standby, standbyPotencia));

                        break;
                    }
                    case 5: {
                        novoComodo = new Comodo("Iluminação");
                        int potencia, quantidade, dias;
                        float horas;
                        bool standby;
                        float standbyPotencia;
                        cout << "\n======== Adicionando eletrodomésticos de Iluminação ========\n";
                        cout << "Lampada:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        standby = false; standbyPotencia = 0;
                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Luzes", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        break;

                    }
                    case 6: {
                        novoComodo = new Comodo("Lavanderia");
                        int potencia, quantidade, dias;
                        float horas;
                        bool standby;
                        float standbyPotencia;
                        cout << "\n======== Adicionando eletrodomésticos ao cômodo Lavanderia ========\n";
                        cout << "Máquina de lavar:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Máquina de Lavar", potencia, quantidade, horas, dias, false, 0));

                        cout << "Secadora:\n";
                        cout << "Potência (W): "; cin >> potencia;
                        cout << "Quantidade: "; cin >> quantidade;
                        cout << "Horas por dia: "; cin >> horas;
                        novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Secadora", potencia, quantidade, horas, dias, false, 0));
                        
                        break;

                    }
                    default:
                        cout << "\nOpção inválida.\n";
                        break;
                }

                if (novoComodo != nullptr) {
                    casa.addComodo(novoComodo);
                    cout << "\n... Cômodo e eletrodomésticos adicionados com sucesso!\n";
                }
                break;
            }

            case 4: {
                string nomeComodo;
                if (casa.getComodos().empty()) {
                    cout << "\nNenhum cômodo cadastrado. Adicione um cômodo primeiro.\n";
                    break;
                }
                cout << "=========== Removendo cômodo ===========\n";
                casa.imprimirComodos();
                cout << "Digite o nome do cômodo que você deseja excluir: ";
                cin.ignore();
                getline(cin, nomeComodo);
                casa.removeComodo(nomeComodo);
                cout << "\n... Cômodo removido com sucesso!\n";
                break;
            }

            case 5: {
                string nomeComodo;
                if (casa.getComodos().empty()) {
                    cout << "Nenhum cômodo cadastrado. Adicione um cômodo primeiro.\n";
                    break;
                }
                casa.imprimirComodos();
                cout << "Digite o nome do cômodo que você deseja acessar: ";
                cin.ignore();
                getline(cin, nomeComodo);
                Comodo& comodo = casa.getComodo(nomeComodo);

                int opcaoComodo;
                do {
                    int potencia, quantidade, dias;
                    float horas, standbyPotencia;
                    bool standby;
                    string nomeEletro;

                    cout << "\n=========== Menu do cômodo: " << comodo.getNome() << " ============\n";
                    cout << "1. Exibir eletrodomésticos\n";
                    cout << "2. Exibir consumo do cômodo\n";
                    cout << "3. Remover eletrodoméstico\n";
                    cout << "4. Voltar ao menu principal\n";
                    cout << "Digite o número da opção desejada: ";
                    cin >> opcaoComodo;
                    cout << "\n==========================================\n\n";

                    switch (opcaoComodo) {
                        case 1:
                            cout << comodo.getEletrodomesticosConsumo();
                            break;
                        case 2:
                            cout << "Consumo do cômodo " << comodo.getNome() << ": " << comodo.calcularConsumoTotal() << " kWh\n";
                            break;

                        case 3: {
                            string nomeEletro;
                            cout << "======== Removendo eletrodoméstico ao cômodo " << comodo.getNome() << "========\n";
                            cout << "Digite o nome do eletrodoméstico que voce deseja remover: ";
                            cin.ignore();
                            getline(cin, nomeEletro);
                            comodo.retirarEletrodomestico(nomeEletro);
                            cout << "... Eletrodoméstico removido com sucesso!\n";
                            break;
                        }
                        case 4:
                            cout << "\nVoltando ao menu principal...\n";
                            break;
                        default:
                            cout << "\nOpção inválida! Tente novamente.\n";
                            break;
                    }
                } while (opcaoComodo != 4);
                break;
            }

            case 6: {
                cout << "======== Simulando conta de energia ========\n";
                auto simular_conta = casa.calcularConsumoComodos();
                cout << "Simulação de conta de energia: R$ " << simular_conta.second << "\n";
                break;
            }

            case 7: {
                casa.exibirComodosPorConsumo();
                break;
            }

            case 8:
                cout << "\nEncerrando o programa...\n";
                break;

            default:
                cout << "\nOpção inválida! Tente novamente.\n";
                break;
        }

    } while (opcao != 8);
}
}