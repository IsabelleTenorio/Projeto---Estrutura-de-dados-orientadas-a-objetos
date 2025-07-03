#include "sistema.h"
#include <iostream>
#include <locale.h>
#include <vector>
#include "geladeira.h"

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

void Sistema::menuPrincipal() {
    setlocale(LC_ALL,"pt_BR.UTF-8");
    int opcao;

    do {
        cout << "\n===== Sistema de Consumo Energético =====\n";
        cout << "1. Listar cômodos e consumo\n";
        cout << "2. Exibir consumo total da casa\n";
        cout << "3. Adicionar novo cômodo\n";
        cout << "4. Excluir cômodo\n";
        cout << "5. Acessar cômodo\n";
        cout << "6. Acessar simulador de conta de energia\n";
        cout << "7. Sair\n";
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
                string nomeComodo; //É possível adicionar cômodos pré-prontos
                int tipoAdicao;
                cout << "Escolha um cômodo para ser adicionado: \n";
                cout << "1 - Banheiro \n2 - Cozinha \n3 - Quarto\n4 - Sala\n5 - Outro\n";
                cout << "\nDigite o número da opção desejada: ";
                cin >> tipoAdicao;
                if (tipoAdicao == 1 || tipoAdicao == 2 || tipoAdicao == 3 || tipoAdicao == 4) {
                    vector<string> comodosEstaticos = {"Banheiro", "Cozinha", "Quarto", "Sala"}; //Vetor com comodos estaticos
                    nomeComodo = comodosEstaticos[tipoAdicao - 1]; //Identifica qual é o nome do comodo dentro do vetor
                    casa.addComodo(Comodo(nomeComodo));
                    cout << "...\nCômodo adicionado com sucesso!\n";
                    cout << "Adicionando eletrodomésticos pré-definidos para o cômodo...\n";
                    
                    vector<vector<string>> eletronicosPreDefinidos = {{"Chuveiro", "SecadorDeCabelo", "Lampada"}, {"Geladeira", "MicroOndas", "Fogao", "Liquidificador", "Lampada"}, {"ArCondicionado", "Lampada", "Ventilador"}, {"TV", "Lampada", "Ventilador"}};
                    Comodo nomeComodo(comodosEstaticos[tipoAdicao - 1]); //Matriz de vetores que contém os nomes dos eletrodomesticos básicos de cada comodo
                    for (const auto& eletro : eletronicosPreDefinidos[tipoAdicao - 1]) { //Loop para digitar a potencia de cada eletrodomestico e adiciona-lo no comodo
                        double potencia;
                        cout << "Digite a potência (kwh) do eletrodoméstico " << eletro << ": ";
                        cin >> potencia;
                        if (eletro == "Geladeira") { //Adiciona geladeira, que é um eletrodomestico que funciona diferente
                            geladeira Geladeira("Geladeira", potencia);
                            nomeComodo.adicionarEletrodomestico(eletro, potencia);
                        } else {
                            nomeComodo.adicionarEletrodomestico(eletro, potencia);
                        }
                    }
                    cout << "...\nEletrodomésticos adicionados com sucesso!\n";

                } else if (tipoAdicao == 5) {
                    cout << "\nDigite o nome do novo cômodo: ";
                    cin.ignore();
                    getline(cin, nomeComodo);
                    casa.addComodo(Comodo(nomeComodo));
                    cout << "...\nCômodo adicionado com sucesso!\n";
                } else {
                    cout << "Opção inválida! Digite novamente uma opção válida: ";
                    cin >> tipoAdicao;
                }
                break;
            }

            case 4: {
                string nomeComodo;
                if (casa.getComodos().empty()) {
                    cout << "Nenhum cômodo cadastrado. Adicione um cômodo primeiro.\n";
                    break;
                }
                else {
                casa.imprimirComodos();
            
                cout << "Digite o nome do cômodo que você deseja excluir: ";
                cin.ignore();
                getline(cin, nomeComodo); // esse getline é pra casos onde o nome do comodo tem espaços
                casa.removeComodo(nomeComodo);
                cout << "Cômodo removido com sucesso!\n";
                break;
            }
        }

            case 5: {
                string nomeComodo;
                if (casa.getComodos().empty()) {
                    cout << "Nenhum cômodo cadastrado. Adicione um cômodo primeiro.\n";
                    break;
                }
                else {
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
                        case 1: {
                            cout << "Eletrodomésticos no cômodo " << comodo.getNome() << ":\n";
                            for (const auto& eletro : comodo.getEletrodomesticosConsumo()) {
                                cout << eletro << endl;
                            }
                            break;
                        }

                        case 2:
                           cout << "Consumo do cômodo " << comodo.getNome() << ": " << comodo.calcularConsumoTotal() << " kWh\n";
                            break;

                        case 3: {
                            string nomeEletro;
                            double consumo;
                            cout << "Digite o nome do eletrodoméstico: ";
                            cin.ignore();
                            getline(cin, nomeEletro);
                            cout << "Digite o consumo do eletrodoméstico (kWh): ";
                            cin >> consumo;
                            comodo.adicionarEletrodomestico(nomeEletro, consumo);
                            cout << "...\nEletrodoméstico adicionado com sucesso!\n";
                            break;
                        }

                        case 4: {
                            string nomeEletro;
                            cout << "Digite o nome do eletrodoméstico que voce deseja remover: ";
                            cin.ignore();
                            getline(cin, nomeEletro);
                            comodo.retirarEletrodomestico(nomeEletro);
                            cout << "...\nEletrodoméstico removido com sucesso!\n";
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
        }

            case 6:
                {
                    auto simular_conta = casa.calcularConsumoComodos();
                    cout << "Simulação de conta de energia: R$ " << simular_conta.first << "\n";
                }
                break;

            case 7:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }

    } while (opcao != 7);
}