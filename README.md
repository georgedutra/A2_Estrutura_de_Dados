# Projeto de A2 - Estrutura de Dados

Repositório do trabalho avaliativo da disciplina de Estrutura de Dados. Projeto desenvolvido no terceiro período do curso de Ciência de Dados e Inteligência Artificial, da instituição FGV - EMAp.

## Desenvolvedores

- [George Dutra](https://github.com/georgedutra)
- [Ana Júlia Rita Lima Cardoso](https://github.com/Anajuliarlc)
- [Luís Henrique Domingues Bueno](https://github.com/LuisHDBueno)

## Descrição

O objetivo do projeto é desenvolver um aplicativo de manipulação de árvores binárias de busca. O aplicativo conta com interface ASCII integrada no terminal, e dá ao usuário opções como construir árvores binárias (manualmente ou inserindo um arquivo de texto na pasta \data), manipulá-las, adquirir informação sobre elas, e ainda transformá-las em listas encadeadas para apresentar a implementação de 4 algoritmos básicos de ordenação: Bubble Sort, Selection Sort, Insertion Sort e Shell Sort.

## Detalhes de Compilação e Execução

O projeto foi desenvolvido com C++ 17 (ou superior), e foi separado em duas partes:
- Para fins de teste, acesse a pasta `test` e siga as instruções no README;
- Para a compilação do aplicativo, acesse a pasta `src`, e compile ali o projeto. Por exemplo, com o compilador *g++* instalado, abra o terminal na pasta `src` e execute o comando abaixo:

        g++ -o main.exe main.cpp analysis\analysis.cpp list\list.cpp menu\menu.cpp tree\tree.cpp user\user.cpp chart\chart.cpp
*/

Após compilar, basta executar como administrador o arquivo `main.exe` gerado.
