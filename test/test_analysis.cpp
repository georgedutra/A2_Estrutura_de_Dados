/**
 * Este arquivo 'driver code' é parte secundária do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo ser compilado junto aos arquivos tree.cpp e user.cpp, encontrados na pasta \src\tree e \src\user do projeto,
 * e realiza uma série de testes nas funções ali designadas.
 * 
 * Para rodar esse arquivo executar no prompt de comando:
 * g++ -o test_analysis.exe .\test_analysis.cpp ..\src\tree\tree.cpp ..\src\analysis\analysis.cpp
*/

#include <iostream>
#include <windows.h>
#include "..\src\tree\tree.h"
#include "..\src\analysis\analysis.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

int main()
{

    SetConsoleOutputCP( 65001 ); // Definindo console output como UTF-8

    cout << "===================================================\n"
    << "Início dos Testes\n" 
    <<"===================================================" << endl;

    cout << "Teste da função isComplete:\n"
    <<"Criando uma árvore completa e uma incompleta e verificando se são completas.\n"
    << endl;

    TreeNode* testRoot = newTreeNode(10);
    testRoot = insertTreeNode(testRoot, 7);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 2);
    testRoot = insertTreeNode(testRoot, 8);
    testRoot = insertTreeNode(testRoot, 12);
    testRoot = insertTreeNode(testRoot, 20);
    testRoot = insertTreeNode(testRoot, 1);
    testRoot = insertTreeNode(testRoot, 3);

    cout << "Árvore completa: ";
    traverseInOrder(testRoot);
    cout << endl;

    if (isComplete(testRoot)) cout << "A árvore é completa." << endl;
    else cout << "A árvore não é completa." << endl;

    TreeNode* testRoot2 = newTreeNode(10);
    testRoot = insertTreeNode(testRoot, 7);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 2);
    testRoot = insertTreeNode(testRoot, 8);
    testRoot = insertTreeNode(testRoot, 12);
    testRoot = insertTreeNode(testRoot, 20);
    testRoot = insertTreeNode(testRoot, 1);

    cout << "\nÁrvore incompleta: ";
    traverseInOrder(testRoot2);
    cout << endl;

    if (isComplete(testRoot2)) cout << "A árvore é completa." << endl;
    else cout << "A árvore não é completa." << endl;

    cout << "\n===================================================\n" << endl;
    cout << "Teste da função isPerfect:\n" << endl;
    cout << "Criando uma árvore perfeita e uma imperfeita e verificando se são perfeitas.\n"
    << endl;

    TreeNode* testRoot3 = newTreeNode(10);
    testRoot = insertTreeNode(testRoot, 7);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 2);
    testRoot = insertTreeNode(testRoot, 8);
    testRoot = insertTreeNode(testRoot, 12);
    testRoot = insertTreeNode(testRoot, 20);

    cout << "Árvore perfeita: ";
    traverseInOrder(testRoot3);
    cout << endl;

    if (isPerfect(testRoot3, 3, 1)) cout << "A árvore é perfeita." << endl;
    else cout << "A árvore não é perfeita." << endl;

    TreeNode* testRoot4 = newTreeNode(10);
    testRoot = insertTreeNode(testRoot, 7);
    testRoot = insertTreeNode(testRoot, 15);
    testRoot = insertTreeNode(testRoot, 2);
    testRoot = insertTreeNode(testRoot, 8);
    testRoot = insertTreeNode(testRoot, 12);

    cout << "\nÁrvore imperfeita: ";
    traverseInOrder(testRoot4);
    cout << endl;

    if (isPerfect(testRoot4, 3, 1)) cout << "A árvore é perfeita." << endl;
    else cout << "A árvore não é perfeita." << endl;

    cout << "Teste da função isPerfect:\n" << endl;
    cout << "Criando uma árvore completa e imperfeita e verificando se existe erro.\n"
    << endl;

    cout << "\nÁrvore completa e imperfeita: ";
    traverseInOrder(testRoot);
    cout << endl;

    if (isPerfect(testRoot, 3, 1)) cout << "A árvore é completa e perfeita." << endl;
    else cout << "A árvore é completa e não é perfeita." << endl;

}