/**
 * Este arquivo 'source' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo guardar as definições das funções necessárias para construção e manipulação de árvores binárias de busca.
*/

#include <iostream>
#include <string>
#include "..\tree\tree.h"
#include "user.h"

using namespace std;

struct TreeNode* userCreateTree()
{
    string strInput = "0";

    cout << "------------------------------------------------\n"
    << "Iniciando construtor de árvore binária de busca.\n" 
    << "------------------------------------------------\n" << endl;
    
    cout << "Insira o primeiro valor da árvore: ";
    cin >> strInput;
    cout << endl;

    // Se o usuário digita algo que não seja um número inteiro no primeiro input
    if (strInput.empty() || strInput.find_first_not_of("-0123456789") != string::npos)
    {
        cout << "Input inválido. Abortando construção." << endl;
        return nullptr;
    }
    
    struct TreeNode* newTree = nullptr;
    
    cout << "Continue digitando números inteiros (um por vez) para inseri-los na árvore, ou digite texto não-numérico para encerrar a construção." << endl;

    // Enquanto o usuário continuar digitando números
    while (!strInput.empty() && strInput.find_first_not_of("-0123456789") == string::npos)
    {
        newTree = insertTreeNode(newTree, stoi(strInput));
        cout << "> ";
        cin >> strInput;
        cout << endl;
    }
    cout << "Texto detectado! Encerrando construtor." << endl;

    return newTree;
}

struct TreeNode* userInsertNode(struct TreeNode* ptrTree)
{
    string strInput;

    cout << "Digite o número que deseja inserir na árvore:\n> ";
    cin >> strInput;
    cout << endl;

    if (strInput.empty() || strInput.find_first_not_of("-0123456789") != string::npos)
    {
        cout << "Valor inserido inválido. Abortando operação." << endl;
        return ptrTree;
    }

    return insertTreeNode(ptrTree, stoi(strInput));
}

struct TreeNode* userDeleteNode(struct TreeNode* ptrTree)
{
    string strInput;

    cout << "Digite o número que deseja remover da árvore:\n> ";
    cin >> strInput;
    cout << endl;

    if (strInput.empty() || strInput.find_first_not_of("-0123456789") != string::npos)
    {
        cout << "Valor inserido inválido. Abortando operação." << endl;
        return ptrTree;
    }

    return deleteTreeNode(ptrTree, stoi(strInput));
}

