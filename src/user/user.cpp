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

    cout << "Iniciando construtor de árvore binária de busca." << endl;
    cout << "Insira o primeiro valor da árvore: ";
    cin >> strInput;
    cout << endl;

    // Se o usuário digita algo que não seja um número inteiro no primeiro input
    if (strInput.empty() || strInput.find_first_not_of("-0123456789") != string::npos)
    {
        cout << "Input inválido. Abortanto construção." << endl;
        return nullptr;
    }
    
    while (!strInput.empty() && strInput.find_first_not_of("-0123456789") == string::npos)
    {
        cout << "É um número :)" << endl;
        cout << "Digite um número inteiro para inserir um nó na árvore, ou texto para encerrar a construção:" << endl;
        cin >> strInput;
        cout << endl;
    }
    cout << "Acabou :(";
    return nullptr;
}