# Sistema de cálculo de consumo energético
Este projeto foi desenvolvido para a disciplina Estrutura de Dados Orientadas a Objetos do curso de Sistemas de Informação (CIN - UFPE), ministrada pelo professor Francisco Paulo Magalhães, com o objetivo de aplicar conceitos de programação orientada a objetos em C++ aprendidos durantes as aulas, como herança, polimorfismo e encapsulamento.

## Sobre
O objetivo deste projeto é simular o gasto energético de uma casa com diferentes cômodos e eletrodomésticos.

## Funcionalidades
- Menu de instruções inicial.
- Acessar, adicionar (apenas pré-definidos) e excluir cômodos dentro da casa.
- Acessar, adicionar (apenas pré-definidos) e excluir eletrodomésticos dentro de um cômodo (há um menu de instruções secundário para acessar os eletrodomésticos de um cômodo e as informações dele).
- Listar cada cômodo e seu consumo.
- Simular conta de energia.
- Exibir consumo total da casa.
- Exibir consumo de cada cômodo.
- Listar todos os eletrodomésticos de um cômodo e seus consumos.

## Estrutura
.
│── assets
│── CmakeLists.txt
│── index.html
│── include
│   ├── casa.h
│   ├── comodo.h
│   ├── eletroDomestico.h
│   ├── eletronicoEvento.h
│   ├── eletronicoGenerico.h
│   ├── geladeira.h
│   └── sistema.h
│── main.cpp
│── README.md
│── src
│   │── casa
│   │   └── casa.cpp
│   │── comodo
│   │   └── comodo.cpp
│   │── eletronico
│   │   │── eletronicoEvento
│   │   │   └── eletronicoEvento.cpp
│   │   │── eletronicoGenerico.cpp
│   │   │── geladeira
│   │       └── geladeira.cpp
│   └── sistema
│       └── sistema.cpp
│── styles.css


## Conceitos utilizados
### Herança
Este mecanismo foi central para a criação da hierarquia de eletrodomésticos, evitando a repetição de código e estabelecendo uma relação lógica entre os diferentes tipos de aparelhos. Foi criada uma classe base abstrata eletroDomestico, que define características comuns a todos os aparelhos, como nome, quantidade e diasSimulado. As classes eletronicoGenerico, eletroEvento e geladeira herdam de eletroDomestico, especializando o seu comportamento.

### Polimorfismo
No projeto, o polimorfismo foi alcançado através de funções virtuais, permitindo que a classe Comodo tratasse todos os eletrodomésticos de forma uniforme. A classe Comodo armazena ponteiros do tipo eletroDomestico* num map. Ao calcular o consumo total, ela itera sobre essa coleção e chama o método calcKwh() para cada aparelho. Graças ao polimorfismo, a versão correta do método (eletronicoGenerico::calcKwh(), geladeira::calcKwh(), etc.) é executada em tempo de execução, sem que a classe Comodo precise saber o tipo exato de cada objeto.

### Encapsulamento
Todas as classes principais (Casa, Comodo, eletroDomestico) utilizam encapsulamento. Seus atributos são declarados como private ou protected, e o acesso a eles só é permitido através de métodos públicos (Getters e Setters). Protegendo a integridade dos dados e desacoplando as partes do sistema.

### Classes
As classes criadas foram: Sistema, Casa, Comodo, EletroDomestico (abstrata), EletronicoGenerico (derivada de EletroDomestico), EletronicoEvento (derivada de EletroDomestico) e Geladeira (derivada de EletroDomestico). As informações sobre como essas classes foram utilizadas está presente no relatório.

### CRUD
Nosso CRUD consiste em: Create, read e delete, pois é possível criar cômodos e eletrodomésticos, ler suas informações e deletá-los.

## Como usar
### CMake
- Para rodar e compilar este projeto é necessário instalar o CMake

### Configurar o CMake no repositório no VsCode
1. Criar a pasta 'build' (mkdir build).
2. Entrar na pasta 'build' (cd build).
3. Digitar "cmake .." no powershell/terminal do VsCode.
4. Para compilar o código:
   - Sempre estar dentro da pasta 'build' e digitar "cmake --build .".
   - Digitar "./projeto.exe" ou ".\Debug\projeto.exe" a depender de onde o executável está.

## Vídeo de apresentação do projeto
https://youtu.be/1VsHTaUycB4?si=qjyzh-okKwdLbLlK

## Link do git pages
https://isabelletenorio.github.io/Projeto-Estrutura-de-dados-orientadas-a-objetos/

## Link do relatório
https://docs.google.com/document/d/11Xp8X7CykaMIpFoqtpIPjKknTuesOZUoyTd243JmsfI/edit?usp=sharing

## Créditos e autoria
[Eduarda Rodrigues de Moura Santana](https://github.com/dudarmouras) | erms2@cin.ufpe.br

[Isaac Manoel Teixeira da Silva](https://github.com/isaacteixeira06) | imts2@cin.ufpe.br

[Isabelle Tenório Vaz Bezerra](https://github.com/IsabelleTenorio) | itvb@cin.ufpe.br

[Wallace Gabriel da Silva Leão](https://github.com/wallacinhochan) | wgsl@cin.ufpe.b
