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
    <<"===================================================" << endl;

    cout << "Teste da função newTreeNode:\n"
    <<"Criando um nó contendo o número 10 e imprimindo seu conteúdo.\n" 
    << endl;

    TreeNode* testRoot = newTreeNode(10);
    cout << "Conteúdo do nó gerado: " << testRoot->iPayload << endl;
    
    delete(testRoot);
    testRoot = nullptr;

    cout << "===================================================\n"
    << "Teste das funções insertTreeNode e Traverse:\n"
    << "Inserindo os nós 7, 10, 15 e 1 numa árvore vazia, nessa ordem.\n"
    << endl;

    testRoot = insertTreeNode(testRoot, 7);
    testRoot = insertTreeNode(testRoot, 10);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 1);

    cout << "Travessia Pré-Ordem:\n";
    traversePreOrder(testRoot);
    cout << endl;

    cout << "\nTravessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << endl;

    cout << "\nTravessia Pós-Ordem:\n";
    traversePostOrder(testRoot);
    cout << endl;

    cout << "===================================================\n"
    << "Teste da função searchNode:\n"
    << "Buscando o número 7\n"
    << endl;

    cout << "Endereço encontrado: " << searchNode(testRoot, 7) << endl;

    cout << "\nBuscando o número 5 (Não está na árvore)\n" << endl;
    cout << "Endereço encontrado: " << searchNode(testRoot, 5) << endl;

    cout << "===================================================\n"
    << "Teste da função deleteNode:\n";

    cout << "Inserindo mais nós..." << endl;
    testRoot = insertTreeNode(testRoot, 5);
    testRoot = insertTreeNode(testRoot, 4);
    testRoot = insertTreeNode(testRoot, 8);
    testRoot = insertTreeNode(testRoot, 9);
    testRoot = insertTreeNode(testRoot, 15);

    cout << "\nTravessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;
    
    cout << "Deletando o número 20 (não está na árvore)\n"<< endl;
    testRoot = deleteTreeNode(testRoot, 20);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;

    cout << "Deletando o número 9 (folha)\n"<< endl;
    testRoot = deleteTreeNode(testRoot, 9);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;

    cout << "Deletando o número 5 (tem filhos à esquerda)\n"<< endl;
    testRoot = deleteTreeNode(testRoot, 5);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;

    cout << "Deletando o número 1 (tem filhos à direita)\n"<< endl;
    testRoot = deleteTreeNode(testRoot, 1);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;

    cout << "Deletando o número 15 (duplicata)\n"<< endl;
    testRoot = deleteTreeNode(testRoot, 15);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;

    cout << "Deletando o número 10 (tem dois filhos)\n"<< endl;
    testRoot = deleteTreeNode(testRoot, 10);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;

    cout << "Deletando o número 7 (raiz da árvore)\n"<< endl;
    testRoot = deleteTreeNode(testRoot, 7);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);
    cout << "\n" << endl;

    cout << "===================================================\n"
    << "Teste da função deleteTree:\n" << endl;

    cout << "Criando uma árvore\n" << endl;
    testRoot = insertTreeNode(testRoot, 7);
    testRoot = insertTreeNode(testRoot, 10);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 1);
    testRoot = insertTreeNode(testRoot, 5);
    testRoot = insertTreeNode(testRoot, 4);
    testRoot = insertTreeNode(testRoot, 8);
    testRoot = insertTreeNode(testRoot, 9);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 20);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);

    cout << "\n\nDeletando a árvore\n" << endl;
    deleteTree(&testRoot, testRoot);

    cout << "Travessia Em Ordem:\n";
    traverseInOrder(testRoot);

    cout << "===================================================\n"
    << "Fim dos Testes\n"
    <<"===================================================\n"
    << "Presione enter para sair.";
    cin.get();

    return 0;
}
