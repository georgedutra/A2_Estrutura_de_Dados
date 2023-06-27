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
        << "3 - Teste da função de Remoção de Nó\n"
        << "4 - Teste da função de Busca de Endereço de Memória\n"
        << "5 - Teste da função de Leitura de Arquivo\n"
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

            case 3:
                ptrTree = userDeleteNode(ptrTree);
                if (ptrTree == nullptr) cout << "Árvore vazia :(" << endl;
                else
                {
                    cout << "Travessia Em Ordem da árvore:" << endl;
                    traverseInOrder(ptrTree);
                    cout << "\n" << endl;
                }
                break;

            case 4:
                {
                TreeNode* ptrNode = userSearchNode(ptrTree);
                if (ptrTree == nullptr) cout << "Árvore vazia :(\n" << endl;
                else if (ptrNode == nullptr) cout << "Valor não encontrado na árvore.\n" << endl;
                else cout << "Valor encontrado no endereço de memória: " << ptrNode << "\n" << endl;
                }
                break;

            case 5:
                ptrTree = userReadFile();
    
                if (ptrTree == nullptr) cout << "Árvore vazia :(\n" << endl;
                else
                {
                    cout << "Travessia Em Ordem da árvore criada:" << endl;
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