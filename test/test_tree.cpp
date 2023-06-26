/**
 * Este arquivo 'driver code' é parte secundária do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo ser compilado junto ao arquivo tree.cpp, encontrado na pasta \src\tree do projeto,
 * e realiza uma série de testes nas funções ali designadas.
*/

#include <iostream>
#include <windows.h>
#include "..\src\tree\tree.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

int main()
{
    SetConsoleOutputCP( 65001 ); // Definindo console output como UTF-8

    cout << "===================================================\n" 
    << "Início dos Testes\n"
    <<"===================================================\n"
    << "Teste das Funções newTree e newTreeNode:\n"
    <<"Criando uma árvore com um único nó contendo o número 10 e imprimindo seu conteúdo.\n" 
    << endl;

    BinaryTree* testTree = newTree();
    testTree->ptrRoot = newTreeNode(10);
    cout << "Conteúdo do nó gerado: " << testTree->ptrRoot->iPayload << endl;
    
    delete(testTree->ptrRoot);
    testTree->ptrRoot = nullptr;

    cout << "===================================================\n"
    << "Teste das funções insertTreeNode e Traverse:\n"
    << "Inserindo os nós 7, 10, 15 e 1 numa árvore vazia, nessa ordem.\n"
    << endl;

    testTree->ptrRoot = insertTreeNode(testTree->ptrRoot, 7);
    insertTreeNode(testTree->ptrRoot, 10);
    insertTreeNode(testTree->ptrRoot, 15);
    insertTreeNode(testTree->ptrRoot, 1);

    cout << testTree->ptrRoot->iPayload << testTree->ptrRoot->ptrLeft->iPayload
    << testTree->ptrRoot->ptrRight->iPayload << testTree->ptrRoot->ptrRight->ptrRight->iPayload << endl;

    cout << "===================================================\n" 
    << "Fim dos Testes\n"
    <<"===================================================\n"
    << "Presione `enter` para sair.";
    cin.get();

    return 0;
}