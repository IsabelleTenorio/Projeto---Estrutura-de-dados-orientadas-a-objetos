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

void Sistema::menuPrincipal() {
    setlocale(LC_ALL,"pt_BR.UTF-8");
    int opcao;

    do {
        cout << "\n===== Sistema de Consumo Energetico =====\n";
        cout << "1. Listar comodos e consumo\n";
        cout << "2. Exibir consumo total da casa\n";
        cout << "3. Adicionar novo cômodo\n";
        cout << "4. Excluir comodo\n";
        cout << "5. Acessar comodo\n";
        cout << "6. Acessar simulador de conta de energia\n";
        cout << "7. Sair\n";
        cout << "Digite o numero da opcao desejada: ";
        cin >> opcao;

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
                string nomeComodo;
                int tipoAdicao;
                cout << "Escolha um comodo para ser adicionado: ";
                cout << "1 - Banheiro \n2 - Cozinha \n3 - Quarto\n 4 - Sala\n 5 - Outro\n";
                cin >> tipoAdicao;
                if (tipoAdicao == 1 || tipoAdicao == 2 || tipoAdicao == 3 || tipoAdicao == 4) {
                    vector<string> comodosEstaticos = {"Banheiro", "Cozinha", "Quarto", "Sala"}; //Vetor com comodos estaticos
                    nomeComodo = comodosEstaticos[tipoAdicao - 1]; //Identifica qual é o nome do comodo dentro do vetor
                    casa.addComodo(Comodo(nomeComodo));
                    cout << "Comodo adicionado com sucesso!\n";
                    cout << "Adicionando eletrodomesticos pre-definidos para o comodo...\n";
                    
                    vector<vector<string>> eletronicosPreDefinidos = {{"Chuveiro", "SecadorDeCabelo", "Lampada"}, {"Geladeira", "MicroOndas", "Fogao", "Liquidificador", "Lampada"}, {"ArCondicionado", "Lampada", "Ventilador"}, {"TV", "Lampada", "Ventilador"}};
                    Comodo nomeComodo(comodosEstaticos[tipoAdicao - 1]); //Matriz de vetores que contém os nomes dos eletrodomesticos básicos de cada comodo
                    for (const auto& eletro : eletronicosPreDefinidos[tipoAdicao - 1]) { //Loop para digitar a potencia de cada eletrodomestico e adiciona-lo no comodo
                        double potencia;
                        cout << "Digite a potencia (kwh) do eletrodomestico " << eletro << ": ";
                        cin >> potencia;
                        if (eletro == "Geladeira") { //Adiciona geladeira, que é um eletrodomestico que funciona diferente
                            geladeira Geladeira("Geladeira", potencia);
                            nomeComodo.adicionarEletrodomestico(eletro, potencia);
                        } else {
                            nomeComodo.adicionarEletrodomestico(eletro, potencia);
                        }
                    }
                    cout << "Eletrodomesticos adicionados com sucesso!\n";

                } else if (tipoAdicao == 5) {
                    cout << "Digite o nome do novo comodo: ";
                    cin.ignore();
                    getline(cin, nomeComodo);
                    casa.addComodo(Comodo(nomeComodo));
                    cout << "Comodo adicionado com sucesso!\n";
                } else {
                    cout << "Opção inválida! Digite novamente uma opção válida: ";
                    cin >> tipoAdicao;
                }
                break;
            }

            case 4: {
                string nomeComodo;
                if (casa.getComodos().empty()) {
                    cout << "Nenhum comodo cadastrado. Adicione um comodo primeiro.\n";
                    break;
                }
                else {
                casa.imprimirComodos();
            
                cout << "Digite o nome do comodo que voce deseja excluir: ";
                cin.ignore();
                getline(cin, nomeComodo); // esse getline é pra casos onde o nome do comodo tem espaços
                casa.removeComodo(nomeComodo);
                cout << "Comodo removido com sucesso!\n";
                break;
            }
        }

            case 5: {
                string nomeComodo;
                if (casa.getComodos().empty()) {
                    cout << "Nenhum comodo cadastrado. Adicione um comodo primeiro.\n";
                    break;
                }
                else {
                casa.imprimirComodos();
            
                cout << "Digite o nome do comodo que voce deseja acessar: ";
                cin.ignore();
                getline(cin, nomeComodo);
                Comodo& comodo = casa.getComodo(nomeComodo);

                int opcaoComodo;
                do {
                    cout << "\n== Menu do comodo: " << comodo.getNome() << " ==\n";
                    cout << "1. Exibir eletrodomesticos\n";
                    cout << "2. Exibir consumo do comodo\n";
                    cout << "3. Adicionar eletrodomestico\n";
                    cout << "4. Remover eletrodomestico\n";
                    cout << "5. Voltar ao menu principal\n";
                    cout << "Digite o numero da opcao desejada: ";
                    cin >> opcaoComodo;

                    switch (opcaoComodo) {
                        case 1: {
                            cout << "Eletrodomesticos no comodo " << comodo.getNome() << ":\n";
                            for (const auto& eletro : comodo.getEletrodomesticosConsumo()) {
                                cout << eletro << endl;
                            }
                            break;
                        }

                        case 2:
                           cout << "Consumo do comodo " << comodo.getNome() << ": " << comodo.calcularConsumoTotal() << " kWh\n";
                            break;

                        case 3: {
                            string nomeEletro;
                            double consumo;
                            cout << "Digite o nome do eletrodomestico: ";
                            cin.ignore();
                            getline(cin, nomeEletro);
                            cout << "Digite o consumo do eletrodomestico (kWh): ";
                            cin >> consumo;
                            comodo.adicionarEletrodomestico(nomeEletro, consumo);
                            cout << "Eletrodomestico adicionado com sucesso!\n";
                            break;
                        }

                        case 4: {
                            string nomeEletro;
                            cout << "Digite o nome do eletrodomestico que voce deseja remover: ";
                            cin.ignore();
                            getline(cin, nomeEletro);
                            comodo.retirarEletrodomestico(nomeEletro);
                            cout << "Eletrodomestico removido com sucesso!\n";
                            break;
                        }

                        case 5:
                            cout << "Voltando ao menu principal...\n";
                            break;

                        default:
                            cout << "Opcao invalida! Tente novamente.\n";
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
                cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcao != 7);
}