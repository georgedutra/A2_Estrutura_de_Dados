/**
 * Este arquivo 'driver code' é parte secundária do projeto {{ A2_Estrutura_de_Dados }}.
 *
 * Tem como objetivo ser compilado junto aos arquivos tree.cpp e user.cpp, encontrados na pasta \src\tree e \src\user do projeto,
 * e realiza uma série de testes nas funções ali designadas.
 */

#include <iostream>
#include <windows.h>
#include "..\src\tree\tree.h"
#include "..\src\analysis\analysis.h"

#pragma execution_character_set("utf-8")

using namespace std;

int main()
{

     SetConsoleOutputCP(65001); // Definindo console output como UTF-8

     cout << "===================================================\n"
          << "Início dos Testes\n"
          << "===================================================" << endl;

     cout << "Teste da função isComplete:\n"
          << "Criando uma árvore completa e uma incompleta e verificando se são completas.\n"
          << endl;

     TreeNode *testRoot = newTreeNode(10);
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

     if (isComplete(testRoot))
          cout << "A árvore é completa." << endl;
     else
          cout << "A árvore é incompleta." << endl;

     TreeNode *testRoot2 = newTreeNode(10);
     testRoot2 = insertTreeNode(testRoot2, 7);
     testRoot2 = insertTreeNode(testRoot2, 15);
     testRoot2 = insertTreeNode(testRoot2, 2);
     testRoot2 = insertTreeNode(testRoot2, 8);
     testRoot2 = insertTreeNode(testRoot2, 12);
     testRoot2 = insertTreeNode(testRoot2, 20);
     testRoot2 = insertTreeNode(testRoot2, 1);

     cout << "\nÁrvore incompleta: ";
     traverseInOrder(testRoot2);
     cout << endl;

     if (isComplete(testRoot2))
          cout << "A árvore é completa." << endl;
     else
          cout << "A árvore é incompleta." << endl;

     cout << "\n===================================================\n" << endl;
     cout << "Teste da função isPerfect:\n" << endl;
     cout << "Criando uma árvore perfeita e uma imperfeita e verificando se são perfeitas.\n" << endl;

     TreeNode *testRoot3 = newTreeNode(10);
     testRoot3 = insertTreeNode(testRoot3, 7);
     testRoot3 = insertTreeNode(testRoot3, 15);
     testRoot3 = insertTreeNode(testRoot3, 2);
     testRoot3 = insertTreeNode(testRoot3, 8);
     testRoot3 = insertTreeNode(testRoot3, 12);
     testRoot3 = insertTreeNode(testRoot3, 20);

     cout << "Árvore perfeita: ";
     traverseInOrder(testRoot3);
     cout << endl;

     if (isPerfect(testRoot3, 3, 1))
          cout << "A árvore é perfeita." << endl;
     else
          cout << "A árvore é imperfeita." << endl;

     TreeNode *testRoot4 = newTreeNode(10);
     testRoot4 = insertTreeNode(testRoot4, 7);
     testRoot4 = insertTreeNode(testRoot4, 15);
     testRoot4 = insertTreeNode(testRoot4, 2);
     testRoot4 = insertTreeNode(testRoot4, 8);
     testRoot4 = insertTreeNode(testRoot4, 12);

     cout << "\nÁrvore imperfeita: ";
     traverseInOrder(testRoot4);
     cout << endl;

     if (isPerfect(testRoot4, 3, 1))
          cout << "A árvore é perfeita." << endl;
     else
          cout << "A árvore não é perfeita." << endl;

     cout << "Criando uma árvore completa e imperfeita e verificando.\n" << endl;

     cout << "\nÁrvore completa e imperfeita: ";
     traverseInOrder(testRoot);
     cout << endl;

     if (isPerfect(testRoot, 3, 1))
          cout << "A árvore é completa e perfeita." << endl;
     else
          cout << "A árvore é completa e imperfeita." << endl;

     cout << "\n===================================================\n"
          << endl;

     cout << "Teste da função getHeight:\n" << endl;
     cout << "Criando árvores e verificando suas alturas: \n" << endl;

     TreeNode *testRoot5 = newTreeNode(10);
     testRoot5 = insertTreeNode(testRoot5, 7);
     testRoot5 = insertTreeNode(testRoot5, 15);
     testRoot5 = insertTreeNode(testRoot5, 2);
     testRoot5 = insertTreeNode(testRoot5, 8);
     testRoot5 = insertTreeNode(testRoot5, 12);
     testRoot5 = insertTreeNode(testRoot5, 20);

     cout << "Árvore de 2 níveis perfeita: ";
     traverseInOrder(testRoot5);
     cout << endl;

     cout << "Altura real da árvore: 2" << endl;
     cout << "Altura calculada da árvore: " << getHeight(testRoot5) << endl;

     cout << "\n" << endl;

     TreeNode *testRoot6 = newTreeNode(10);

     cout << "Árvore com apenas a raiz: ";
     traverseInOrder(testRoot6);
     cout << endl;

     cout << "Altura real da árvore: 0" << endl;
     cout << "Altura calculada da árvore: " << getHeight(testRoot6) << endl;

     cout << "\n" << endl;

     TreeNode *testRoot7 = newTreeNode(10);
     testRoot7 = insertTreeNode(testRoot7, 7);
     testRoot7 = insertTreeNode(testRoot7, 15);
     testRoot7 = insertTreeNode(testRoot7, 2);
     testRoot7 = insertTreeNode(testRoot7, 8);
     testRoot7 = insertTreeNode(testRoot7, 12);
     testRoot7 = insertTreeNode(testRoot7, 20);
     testRoot7 = insertTreeNode(testRoot7, 1);

     cout << "Árvore de 3 níveis - testando o lado esquerdo: ";
     traverseInOrder(testRoot7);
     cout << endl;

     cout << "Altura real da árvore: 3" << endl;
     cout << "Altura calculada da árvore: " << getHeight(testRoot7) << endl;

     cout << "\n" << endl;

     TreeNode *testRoot8 = newTreeNode(10);
     testRoot8 = insertTreeNode(testRoot8, 7);
     testRoot8 = insertTreeNode(testRoot8, 15);
     testRoot8 = insertTreeNode(testRoot8, 2);
     testRoot8 = insertTreeNode(testRoot8, 8);
     testRoot8 = insertTreeNode(testRoot8, 12);
     testRoot8 = insertTreeNode(testRoot8, 20);
     testRoot8 = insertTreeNode(testRoot8, 1);
     testRoot8 = insertTreeNode(testRoot8, 22);
     testRoot8 = insertTreeNode(testRoot8, 25);

     cout << "Árvore de 4 níveis - testando o lado direito: ";
     traverseInOrder(testRoot8);
     cout << endl;

     cout << "Altura real da árvore: 4" << endl;
     cout << "Altura calculada da árvore: " << getHeight(testRoot8) << endl;

     cout << "\n" << endl;

     cout << "\n===================================================\n" << endl;

     cout << "Teste da função getSize:\n" << endl;
     cout << "Criando árvores e verificando seus tamanhos: \n" << endl;

     TreeNode *testRoot9 = newTreeNode(10);
     testRoot9 = insertTreeNode(testRoot9, 7);
     testRoot9 = insertTreeNode(testRoot9, 15);
     testRoot9 = insertTreeNode(testRoot9, 2);

     cout << "Árvore: ";
     traverseInOrder(testRoot9);
     cout << endl;

     cout << "Tamanho real da árvore: 4" << endl;
     cout << "Tamanho calculado da árvore: " << getSize(testRoot9) << endl;

     cout << "\n" << endl;

     TreeNode *testRoot10 = newTreeNode(10);

     cout << "Árvore: ";
     traverseInOrder(testRoot10);
     cout << endl;

     cout << "Tamanho real da árvore: 1" << endl;
     cout << "Tamanho calculado da árvore: " << getSize(testRoot10) << endl;

     cout << "\n" << endl;

     TreeNode *testRoot11 = newTreeNode(10);
     testRoot11 = insertTreeNode(testRoot11, 7);
     testRoot11 = insertTreeNode(testRoot11, 15);
     testRoot11 = insertTreeNode(testRoot11, 2);
     testRoot11 = insertTreeNode(testRoot11, 8);
     testRoot11 = insertTreeNode(testRoot11, 12);
     testRoot11 = insertTreeNode(testRoot11, 20);
     testRoot11 = insertTreeNode(testRoot11, 1);

     cout << "Árvore: ";
     traverseInOrder(testRoot11);
     cout << endl;

     cout << "Tamanho real da árvore: 8" << endl;
     cout << "Tamanho calculado da árvore: " << getSize(testRoot11) << endl;

     cout << "\n" << endl;

     TreeNode *testRoot12 = newTreeNode(10);
     testRoot12 = insertTreeNode(testRoot12, 7);
     testRoot12 = insertTreeNode(testRoot12, 15);
     testRoot12 = insertTreeNode(testRoot12, 2);
     testRoot12 = insertTreeNode(testRoot12, 8);
     testRoot12 = insertTreeNode(testRoot12, 12);
     testRoot12 = insertTreeNode(testRoot12, 20);
     testRoot12 = insertTreeNode(testRoot12, 1);
     testRoot12 = insertTreeNode(testRoot12, 22);
     testRoot12 = insertTreeNode(testRoot12, 25);

     cout << "Árvore: ";
     traverseInOrder(testRoot12);
     cout << endl;

     cout << "Tamanho real da árvore: 10" << endl;
     cout << "Tamanho calculado da árvore: " << getSize(testRoot12) << endl;

     cout << "\n===================================================\n" << endl;

     cout << "Teste da função printBFS:\n" << endl;
     cout << "Criando árvores e imprimindo-as em ordem BFS: \n" << endl;

     TreeNode *testRoot13 = newTreeNode(10);
     testRoot13 = insertTreeNode(testRoot13, 7);
     testRoot13 = insertTreeNode(testRoot13, 15);
     testRoot13 = insertTreeNode(testRoot13, 2);
     testRoot13 = insertTreeNode(testRoot13, 8);
     testRoot13 = insertTreeNode(testRoot13, 12);
     testRoot13 = insertTreeNode(testRoot13, 20);

     cout << "Árvore perfeita: ";
     traverseInOrder(testRoot13);
     cout << endl;

     cout << "Árvore em ordem BFS: ";
     printBFS(testRoot13);

     cout << "\n" << endl;

     TreeNode *testRoot14 = newTreeNode(10);
     testRoot14 = insertTreeNode(testRoot14, 7);
     testRoot14 = insertTreeNode(testRoot14, 15);
     testRoot14 = insertTreeNode(testRoot14, 2);
     testRoot14 = insertTreeNode(testRoot14, 8);
     testRoot14 = insertTreeNode(testRoot14, 12);
     testRoot14 = insertTreeNode(testRoot14, 20);
     testRoot14 = insertTreeNode(testRoot14, 1);
     testRoot14 = insertTreeNode(testRoot14, 0);
     testRoot14 = insertTreeNode(testRoot14, 22);
     testRoot14 = insertTreeNode(testRoot14, 21);
     testRoot14 = insertTreeNode(testRoot14, 25);

     cout << "Árvore imperfeita: ";
     traverseInOrder(testRoot14);
     cout << endl;

     cout << "Árvore em ordem BFS: ";
     printBFS(testRoot14);

}