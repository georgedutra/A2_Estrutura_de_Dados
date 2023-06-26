/**
 * Este arquivo 'driver code' é parte secundária do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo ser compilado junto aos arquivos tree.cpp e user.cpp, encontrados na pasta \src\tree e \src\user do projeto,
 * e realiza uma série de testes nas funções ali designadas.
*/

#include <iostream>
#include <windows.h>
#include "..\src\tree\tree.h"
#include "..\src\user\user.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

int main()
{
    SetConsoleOutputCP( 65001 ); // Definindo console output como UTF-8

    cout << "===================================================\n" 
    << "Início dos Testes\n" 
    <<"===================================================" << endl;

    int iInput = -1;
    TreeNode* ptrTree = nullptr;
    while (iInput != 0)
    {
        cout << "Insira o número correspondente à opção desejada:\n"
        << "0 - Encerrar testes\n"
        << "1 - Teste da função de Criação de Árvore\n"
        << "2 - Teste da função de Inserção de Nó\n"
        << "> ";

        cin >> iInput;
        cout << endl;

        switch (iInput)
        {
            case 1:
                ptrTree = userCreateTree();
                if (ptrTree == nullptr) cout << "Árvore vazia :(" << endl;
                else
                {
                    cout << "\nTravessia Em Ordem da árvore construída:" << endl;
                    traverseInOrder(ptrTree);
                    cout << "\n" << endl;
                }
                break;
            case 2:
                ptrTree = userInsertNode(ptrTree);
                if (ptrTree == nullptr) cout << "Árvore vazia :(" << endl;
                else
                {
                    cout << "Travessia Em Ordem da árvore:" << endl;
                    traverseInOrder(ptrTree);
                    cout << "\n" << endl;
                }
                break;
        }
    }

    cout << "===================================================\n" 
    << "Fim dos Testes\n"
    <<"===================================================" 
    << endl;

    return 0;
}