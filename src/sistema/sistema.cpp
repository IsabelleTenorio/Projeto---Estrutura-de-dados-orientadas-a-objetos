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
#include <limits>


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

int Sistema::lerInteiroPositivo(const string& mensagem) {
    int valor;
    do {
        cout << mensagem;
        cin >> valor;

        if (cin.fail()) {
            cin.clear(); // limpa o erro
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta entrada inválida
            cout << "Entrada inválida. Digite um número inteiro positivo.\n";
            continue;
        }

        if (valor <= 0) {
            cout << "Valor inválido. Digite um número positivo.\n";
        }
    } while (valor <= 0);
    return valor;
}

float Sistema::lerFloatPositivo(const string& mensagem) {
    float valor;
    do {
        cout << mensagem;
        cin >> valor;

        if (cin.fail()) {
            cin.clear(); // limpa o erro
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta entrada inválida
            cout << "Entrada inválida. Digite um número inteiro positivo.\n";
            continue;
        }

        if (valor <= 0.0f) {
            cout << "Valor inválido. Digite um número positivo.\n";
        }
    } while (valor <= 0.0f);
    return valor;
}


bool Sistema::desejaAdcionar(const int booleano){
    return booleano == 1;
}

int Sistema::lerBooleano(const string& mensagem) {
    int valor;
    do {
        cout << mensagem;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Digite 1 para sim ou 0 para não.\n";
            continue;
        }

        if (valor != 0 && valor != 1) {
            cout << "Valor inválido. Digite 1 (sim) ou 0 (não).\n";
        }

    } while (valor != 0 && valor != 1);
    return valor;
}

void Sistema::telaInicial() {
    setlocale(LC_ALL,"pt_BR.UTF-8");
    cout << "Bem-vindo ao sistema de monitoramento de energia!\n";
}


void Sistema::menuPrincipal() {
    {
    setlocale(LC_ALL,"pt_BR.UTF-8");
    int opcao;

    float dias = Sistema::lerFloatPositivo("Quantidade de dias: ");

    do {
        cout << "\n===== Sistema de Consumo Energético =====\n";
        cout << "1. Listar cômodos e consumo\n";
        cout << "2. Exibir consumo total da casa\n";
        cout << "3. Adicionar novo cômodo\n";
        cout << "4. Excluir cômodo\n";
        cout << "5. Acessar cômodo\n";
        cout << "6. Acessar simulador de conta de energia\n";
        cout << "7 Listar o raking de cômodos por Consumo\n";
        cout << "8. Sair\n";
        cout << "\nDigite o número da opção desejada: ";
        cin >> opcao;

        if (cin.fail()) {
        cin.clear(); // limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora entrada inválida
        cout << "Entrada inválida! Por favor, digite um número entre 1 e 8.\n";
        continue;
    }

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
                
                cout << "Escolha o cômodo que deseja adicionar:\n";
                cout << "1. Banheiro\n2. Cozinha\n3. Quarto\n4. Sala\n5. Iluminação\n6. Lavandeiria\n7. Voltar ao Menu Principal\n";
                int tipo;

                cin >> tipo;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida! Digite um número válido para o tipo de cômodo.\n";
                    break;
}


                Comodo* novoComodo = nullptr;

                switch(tipo) {
                    case 1: {
                        if (casa.temComodo("Banheiro")) {
                            cout << "Já existe um cômodo chamado Banheiro. Não é possível adicionar novamente.\n";
                            break;
                        }
                        int booleanoInput;
                        novoComodo = new Comodo("Banheiro");
                        booleanoInput = Sistema::lerBooleano("Deseja  adcionar Chuveiro[1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)){
                        cout << "Chuveiro\n";
                        int potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                        int quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                        float minutos = Sistema::lerFloatPositivo("Minutos por uso: ");
                        int vezesPorDia = Sistema::lerInteiroPositivo("Quantas vezes por dia: ");

                        novoComodo->adicionarEletrodomestico(new eletroEvento("Chuveiro", potencia, minutos, vezesPorDia, dias, quantidade));
                        }
                        break;

                    }
                    case 2: {
                        if (casa.temComodo("Cozinha")) {
                            cout << "Já existe um cômodo chamado Cozinha. Não é possível adicionar novamente.\n";
                            break;
                        }
                        novoComodo = new Comodo("Cozinha");

                        int potencia = 0, quantidade = 0;
                        float horas = 0.0f;
                        bool standby;
                        float standbyPotencia = 0.0f;
                        float fatorUso;
                        float minutos = 0.0f;
                        int vezesPorDia = 0;
                        int booleanoInput;
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Geladeira [1 = sim, 0 = não]: ");;

                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Geladeira:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            fatorUso = Sistema::lerFloatPositivo("Fator de uso (ex: 0.8): ");
                            novoComodo->adicionarEletrodomestico(new geladeira("Geladeira", potencia, quantidade, dias, fatorUso));
                        }

                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Fogão Elétrico [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Fogão Elétrico:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            cout << "Possui standby (1=sim, 0=não): ";
                            cin >> standby;
                            standbyPotencia = standby ? Sistema::lerFloatPositivo("Potência standby (W): ") : 0;
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Fogão Elétrico", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        }

                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Micro-ondas [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Micro-ondas:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            minutos = Sistema::lerFloatPositivo("Minutos por uso: ");
                            vezesPorDia = Sistema::lerInteiroPositivo("Quantas vezes por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletroEvento("Micro-ondas", potencia, minutos, vezesPorDia, dias, quantidade));
                        }

                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Liquidificador [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Liquidificador:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            minutos = Sistema::lerFloatPositivo("Minutos por uso: ");
                            vezesPorDia = Sistema::lerInteiroPositivo("Quantas vezes por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletroEvento("Liquidificador", potencia, minutos, vezesPorDia, dias, quantidade));
                        }

                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Cafeteira elétrica [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Cafeteira elétrica:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            minutos = Sistema::lerFloatPositivo("Minutos por uso: ");
                            vezesPorDia = Sistema::lerInteiroPositivo("Quantas vezes por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletroEvento("Cafeteira elétrica", potencia, minutos, vezesPorDia, dias, quantidade));
                        }

                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Torradeira [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Torradeira:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            minutos = Sistema::lerFloatPositivo("Minutos por uso: ");
                            vezesPorDia = Sistema::lerInteiroPositivo("Quantas vezes por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletroEvento("Torradeira", potencia, minutos, vezesPorDia, dias, quantidade));
                        }

                        break;
                        
                    }
                    case 3: {
                        if (casa.temComodo("Quarto")) {
                            cout << "Já existe um cômodo chamado Quarto. Não é possível adicionar novamente.\n";
                            break;
                        }

                        novoComodo = new Comodo("Quarto");

                        int potencia = 0, quantidade = 0;
                        float horas = 0.0f;
                        int booleanoInput;
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Ventilador [1 = sim, 0 = não]: ");

                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Ventilador:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ventilador", potencia, quantidade, horas, dias, false, 0));
                        }

                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Ar-condicionado [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Ar-condicionado:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ar-condicionado", potencia, quantidade, horas, dias, false, 0));
                        }
                        break;
                    }
                    case 4: {
                       if (casa.temComodo("Sala")) {
                            cout << "Já existe um cômodo chamado Sala. Não é possível adicionar novamente.\n";
                            break;
                        }

                        novoComodo = new Comodo("Sala");

                        int potencia, quantidade;
                        float horas;
                        bool standby;
                        float standbyPotencia;
                        int booleanoInput;

                        // === TV ===
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar TV [1 = sim, 0 = não]:  ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "TV:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            cout << "Possui standby (1=sim, 0=não): ";
                            cin >> standby;
                            standbyPotencia = standby ? Sistema::lerFloatPositivo("Potência standby (W): ") : 0;
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("TV", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        }

                        // === Ar-condicionado ===
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Ar-condicionado [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Ar-condicionado:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ar-condicionado", potencia, quantidade, horas, dias, false, 0));
                        }

                        // === Ventilador ===
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Ventilador [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Ventilador:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Ventilador", potencia, quantidade, horas, dias, false, 0));
                        }

                        // === Videogame ===
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Videogame [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Videogame:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            cout << "Possui standby (1=sim, 0=não): ";
                            cin >> standby;
                            standbyPotencia = standby ? Sistema::lerFloatPositivo("Potência standby (W): ") : 0;
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Videogame", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        }

                        break;
                    }
                    case 6: {
                        if (casa.temComodo("Lavanderia")) {
                            cout << "Já existe um cômodo chamado Lavanderia. Não é possível adicionar novamente.\n";
                            break;
                        }

                        novoComodo = new Comodo("Lavanderia");

                        int potencia, quantidade;
                        float horas;
                        bool standby = false;
                        float standbyPotencia = 0;
                        int booleanoInput;

                        // === Máquina de lavar ===
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Máquina de Lavar [1 = sim, 0 = não]:");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Máquina de lavar:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Máquina de Lavar", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        }

                        // === Secadora ===
                        booleanoInput = Sistema::lerBooleano("Deseja adicionar Secadora [1 = sim, 0 = não]: ");
                        if (Sistema::desejaAdcionar(booleanoInput)) {
                            cout << "Secadora:\n";
                            potencia = Sistema::lerInteiroPositivo("Potência (W): ");
                            quantidade = Sistema::lerInteiroPositivo("Quantidade: ");
                            horas = Sistema::lerFloatPositivo("Horas por dia: ");
                            novoComodo->adicionarEletrodomestico(new eletronicoGenerico("Secadora", potencia, quantidade, horas, dias, standby, standbyPotencia));
                        }

                        break;

                    }
                    case 7: {
                        cout << "Voltando ao Menu Principal\n";
                        break;
                    }
                    default:
                        cout << "Opção inválida.\n";
                        break;
                }

                if (novoComodo != nullptr) {
                    casa.addComodo(novoComodo);
                    cout << "\nCômodo e eletrodomésticos adicionados com sucesso!\n";
                }
                break;
            }

            case 4: {
                string nomeComodo;
                if (casa.getComodos().empty()) {
                    cout << "Nenhum cômodo cadastrado. Adicione um cômodo primeiro.\n";
                    break;
                }
                casa.imprimirComodos();
                cout << "Digite o nome do cômodo que você deseja excluir: ";
                cin.ignore();
                getline(cin, nomeComodo);
                casa.removeComodo(nomeComodo);
                cout << "Cômodo removido com sucesso!\n";
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
                    cout << "\n== Menu do cômodo: " << comodo.getNome() << " ==\n";
                    cout << "1. Exibir eletrodomésticos\n";
                    cout << "2. Exibir consumo do cômodo\n";
                    cout << "3. Adicionar eletrodoméstico\n";
                    cout << "4. Remover eletrodoméstico\n";
                    cout << "5. Voltar ao menu principal\n";
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
                        case 3:
                            cout << "Adição manual desativada neste modo.\n";
                            break;
                        case 4: {
                            string nomeEletro;
                            comodo.getEletrodomesticosConsumo();
                            cout << "=======================================" << endl;
                            cout << "Digite o nome do eletrodoméstico que voce deseja remover: ";
                            cin.ignore();
                            getline(cin, nomeEletro);
                            comodo.retirarEletrodomestico(nomeEletro);
                            cout << "Eletrodoméstico removido com sucesso!\n";
                            break;
                        }
                        case 5:
                            cout << "Voltando ao menu principal...\n";
                            break;
                        default:
                            cout << "Opção inválida! Tente novamente.\n";
                            break;
                    }
                } while (opcaoComodo != 5);
                break;
            }

            case 6: {
                auto simular_conta = casa.calcularConsumoComodos();
                cout << "Simulação de conta de energia: R$ " << simular_conta.first << "\n";
                break;
            }

            case 7: {
                casa.exibirComodosPorConsumo();
                break;
            }

            case 8:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }

    } while (opcao != 8);
}
}