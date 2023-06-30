/* g++ -o menu.exe .\menu.cpp ..\tree\tree.cpp ..\analysis\analysis.cpp ..\user\user.cpp ..\list\list.cpp 
*/


#include <iostream>
#include <windows.h>
#include "menu.h"
#include "..\tree\tree.h"
#include "..\analysis\analysis.h"
#include "..\user\user.h"
#include "..\list\list.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

void menuAnalysis(struct TreeNode* ptrTree)
{ 
    SetConsoleOutputCP( 65001 );
    char cOption;

    // Limpar a tela
    while(true)
    {
        cout << "\033[2J\033[1;1H";

        cout << "========== Menu ==========" << endl;
        cout << "1. Qual a altura da árvore?" << endl;
        cout << "2. Qual é o tamanho da árvore?" << endl;
        cout << "3. Gostaria de inserir um elemento na sua árvore?" << endl;
        cout << "4. Gostaria de deletar um elemento na sua árvore?" << endl;
        cout << "5. Gostaria de buscar o endereço de memória de um elemento da árvore?" << endl;
        cout << "6. Sua árvore é completa?" << endl;
        cout << "7. Sua árvore é perfeita?" << endl;
        cout << "8. Exiba sua árvore em BFS aqui" << endl;
        cout << "9. Sair" << endl;
        cout << "==========================" << endl;
        cout << "Escolha uma opção: ";

        cin >> cOption;
        switch(cOption)
        {
            case '1':
                cout << "A altura da árvore é: " << getHeight(ptrTree) << endl;
                break;
            case '2':
                cout << "O tamanho da árvore é: " << getSize(ptrTree) << endl;
                break;
            case '3':
                ptrTree = userInsertNode(ptrTree);
                break;
            case '4':
                ptrTree = userDeleteNode(ptrTree);
                break;
            case '5':
                userSearchNode(ptrTree);
                break;
            case '6':
                if (isComplete(ptrTree))
                {
                    cout << "A árvore é completa!" << endl;
                }
                else
                {
                    cout << "A árvore não é completa!" << endl;
                }
                break;
            case '7':
                if (isPerfect(ptrTree, getHeight(ptrTree), 0))
                {
                    cout << "A árvore é perfeita!" << endl;
                }
                else
                {
                    cout << "A árvore não é perfeita!" << endl;
                }
                break;
            case '8':
                printBFS(ptrTree);
                break;
            case '9':
                cout << "Saindo..." << endl;
                return;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
        // Pausar a tela
        cout << "Pressione qualquer tecla para continuar...";
        cin.ignore();
        cin.get();
    }
    
    return;
}

void menuConstruction()
{
    char cOption;
    TreeNode* ptrTree = nullptr;
    SetConsoleOutputCP( 65001 );
    while (true) 
    {
        
        // Limpar a tela
        cout << "\033[2J\033[1;1H";

        cout << "========== Menu ==========" << endl;
        cout << "1. Construa sua árvore por arquivo de texto " << endl;
        cout << "2. Construa sua árvore a partir de dados digitados" << endl;
        cout << "3. Gostaria de analisar sua árvore?" << endl;
        cout << "4. Sair" << endl;
        cout << "==========================" << endl;
        cout << "Escolha uma opção: ";

        cin >> cOption;

        switch (cOption) 
        {
            case '1':
                ptrTree = userReadFile();
                break;
            case '2':
                ptrTree = userCreateTree();
                break;
            case '3':
                if (ptrTree == nullptr)
                {
                    cout << "Árvore não construída. Construa uma árvore antes de analisá-la." << endl;
                }
                else
                {
                    menuAnalysis(ptrTree);
                }
                break;
            case '4':
                cout << "Saindo..." << endl;
                return;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    
        // Pausar a tela
        cout << "Pressione qualquer tecla para continuar...";
        cin.ignore();
        cin.get();

    }

    return;

}

int main()
{
    menuConstruction();
    return 0;
}