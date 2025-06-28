#include "sistema.h"
#include <iostream>

void Sistema::telaInicial() {
    std::cout << "Bem-vindo ao sistema de monitoramento de energia!\n";
}

void Sistema::menuPrincipal() {
    int opcao;

    do {
        std::cout << "\n===== Sistema de Consumo Energetico =====\n";
        std::cout << "1. Listar comodos e consumo\n";
        std::cout << "2. Exibir consumo total da casa\n";
        std::cout << "3. Adicionar novo comodo\n";
        std::cout << "4. Excluir comodo\n";
        std::cout << "5. Acessar comodo\n";
        std::cout << "6. Sair\n";
        std::cout << "Digite o numero da opcao desejada: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                casa.imprimirComodos();
                break;

            case 2:
                std::cout << "Consumo total da casa: " << casa.calcularConsumoComodos() << " kWh\n";
                break;

            case 3: {
                std::string nomeComodo;
                std::cout << "Digite o nome do novo comodo: ";
                std::cin.ignore();
                std::getline(std::cin, nomeComodo);
                casa.addComodo(Comodo(nomeComodo));
                std::cout << "Comodo adicionado com sucesso!\n";
                break;
            }

            case 4: {
                std::string nomeComodo;
                if (casa.getComodos().empty()) {
                    std::cout << "Nenhum comodo cadastrado. Adicione um comodo primeiro.\n";
                    break;
                }
                else {
                casa.imprimirComodos();
            
                std::cout << "Digite o nome do comodo que voce deseja excluir: ";
                std::cin.ignore();
                std::getline(std::cin, nomeComodo); // esse getline é pra casos onde o nome do comodo tem espaços
                casa.removeComodo(nomeComodo);
                std::cout << "Comodo removido com sucesso!\n";
                break;
            }
        }

            case 5: 
                menuComodo();
                break;
            
        
            case 6:
                std::cout << "Encerrando o programa...\n";
                break;

            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcao != 6);
}

void Sistema::menuComodo() {
    std::string nomeComodo;
    if (casa.getComodos().empty()) {
        std::cout << "Nenhum comodo cadastrado. Adicione um comodo primeiro.\n";
    }
    else {
    casa.imprimirComodos();

    std::cout << "Digite o nome do comodo que voce deseja acessar: ";
    std::cin.ignore();
    std::getline(std::cin, nomeComodo);
    Comodo& comodo = casa.getComodo(nomeComodo);

    int opcaoComodo;
    do {
        std::cout << "\n== Menu do comodo: " << comodo.getNome() << " ==\n";
        std::cout << "1. Exibir eletrodomesticos\n";
        std::cout << "2. Exibir consumo do comodo\n";
        std::cout << "3. Adicionar eletrodomestico\n";
        std::cout << "4. Remover eletrodomestico\n";
        std::cout << "5. Voltar ao menu principal\n";
        std::cout << "Digite o numero da opcao desejada: ";
        std::cin >> opcaoComodo;

        switch (opcaoComodo) {
            case 1: {
                std::cout << "Eletrodomesticos no comodo " << comodo.getNome() << ":\n";
                for (const auto& eletro : comodo.getEletrodomesticos()) {
                    std::cout << eletro << std::endl;
                }
                break;
            }

            case 2:
                std::cout << "Consumo do comodo " << comodo.getNome() << ": " << comodo.calcularConsumoTotal() << " kWh\n";
                break;

            case 3: {
                std::string nomeEletro;
                double consumo;
                std::cout << "Digite o nome do eletrodomestico: ";
                std::cin.ignore();
                std::getline(std::cin, nomeEletro);
                std::cout << "Digite o consumo do eletrodomestico (kWh): ";
                std::cin >> consumo;
                comodo.adicionarEletrodomestico(nomeEletro, consumo);
                std::cout << "Eletrodomestico adicionado com sucesso!\n";
                break;
            }

            case 4: {
                std::string nomeEletro;
                std::cout << "Digite o nome do eletrodomestico que voce deseja remover: ";
                std::cin.ignore();
                std::getline(std::cin, nomeEletro);
                comodo.retirarEletrodomestico(nomeEletro);
                std::cout << "Eletrodomestico removido com sucesso!\n";
                break;
            }

            case 5:
                std::cout << "Voltando ao menu principal...\n";
                break;

            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcaoComodo != 5);
}
}

