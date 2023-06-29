/**
 * Este arquivo 'driver code' é parte secundária do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo ser compilado junto aos arquivos tree.cpp e list.cpp, encontrados nas pastas \src\tree e \src\list do projeto,
 * e realiza uma série de testes nas funções que convertem arvore para lista.
*/

#include <iostream>
#include <windows.h>
#include "..\src\list\list.h"
#include "..\src\tree\tree.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

int main()
{

    
    SetConsoleOutputCP( 65001 ); // Definindo console output como UTF-8

    cout << "===================================================\n"
    << "Início dos Testes\n" 
    <<"===================================================" << endl;

    cout << "Teste da função treetreeToDoublyList:\n"
    <<"Criando uma árvore binário e convertendo ela para lista\n"
    << endl;

    TreeNode* testRoot = newTreeNode(10);
    testRoot = insertTreeNode(testRoot, 7);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 2);
    testRoot = insertTreeNode(testRoot, 8);
    testRoot = insertTreeNode(testRoot, 12);
    testRoot = insertTreeNode(testRoot, 20);

    cout << "Árvore binária: ";
    traverseInOrder(testRoot);
    cout << endl;

    DoublyList* testList = createList();
    treeToDoublyList(testList, testRoot);

    cout << "\nLista duplamente encadeada: ";
    printList(testList);
    cout << endl;

}