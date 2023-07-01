/* Este arquivo cria o menu de interação com o usuário. 
* Ele é responsável por chamar as funções de criação de árvore, leitura de arquivo e análise de árvore. 
*/

#include <iostream>
#include <windows.h>
#include <chrono>
#include "menu.h"
#include "..\tree\tree.h"
#include "..\analysis\analysis.h"
#include "..\user\user.h"
#include "..\list\list.h"
#include "..\chart\chart.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

void menuAnalysis(struct TreeNode* ptrTree)
{ 
    SetConsoleOutputCP( 65001 );
    char cOption;
    // Variáveis para medir o tempo de execução
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();

    // Limpar a tela
    while(true)
    {
        cout << "\033[2J\033[1;1H";

        cout << "========== Menu ==========" << endl;
        cout << "a. Qual a altura da árvore?" << endl;
        cout << "b. Qual é o tamanho da árvore?" << endl;
        cout << "c. Gostaria de inserir um elemento na sua árvore?" << endl;
        cout << "d. Gostaria de deletar um elemento na sua árvore?" << endl;
        cout << "e. Gostaria de buscar o endereço de memória de um elemento da árvore?" << endl; 
        cout << "f. Sua árvore é completa?" << endl;
        cout << "g. Sua árvore é perfeita?" << endl;
        cout << "h. Exiba sua árvore em BFS aqui" << endl;
        cout << "i. Ordene sua árvore com Bubble Sort" << endl;
        cout << "j. Ordene sua árvore com Selection Sort" << endl;
        cout << "k. Ordene sua árvore com Insertion Sort" << endl;
        cout << "l. Ordene sua árvore com Shell Sort" << endl;
        cout << "Para fazer um gráfico, maximize o terminal e escolha uma das opções abaixo:" << endl;
        cout << "É necessário que sua árvore tenha no máximo 20 nós para que o gráfico seja feito!" << endl;
        cout << "m. Faça seu gráfico com Bubble Sort" << endl;
        cout << "n. Faça seu gráfico com Selection Sort" << endl;
        cout << "o. Faça seu gráfico com Insertion Sort" << endl;
        cout << "p. Faça seu gráfico com Shell Sort" << endl;
        cout << "q. Voltar" << endl;
        cout << "==========================" << endl;
        cout << "Escolha uma opção: ";

        cin >> cOption;
        switch(cOption)
        {
            case 'a':
                start = chrono::high_resolution_clock::now();
                cout << "A altura da árvore é: " << getHeight(ptrTree) << endl;
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'b':
                start = chrono::high_resolution_clock::now();
                cout << "O tamanho da árvore é: " << getSize(ptrTree) << endl;
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'c':
                start = chrono::high_resolution_clock::now();
                ptrTree = userInsertNode(ptrTree);
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'd':
                start = chrono::high_resolution_clock::now();
                ptrTree = userDeleteNode(ptrTree);
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'e':
                start = chrono::high_resolution_clock::now();
                cout << userSearchNode(ptrTree)<< endl;
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'f':
                start = chrono::high_resolution_clock::now();
                if (isComplete(ptrTree))
                {
                    cout << "A árvore é completa!" << endl;
                }
                else
                {
                    cout << "A árvore não é completa!" << endl;
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'g':
                start = chrono::high_resolution_clock::now();
                if (isPerfect(ptrTree, getHeight(ptrTree), 0))
                {
                    cout << "A árvore é perfeita!" << endl;
                }
                else
                {
                    cout << "A árvore não é perfeita!" << endl;
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'h':
                start = chrono::high_resolution_clock::now();
                printBFS(ptrTree);
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'i':
                start = chrono::high_resolution_clock::now();
                bubbleSortTree(ptrTree);
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'j':
                start = chrono::high_resolution_clock::now();
                selectionSortTree(ptrTree);
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'k':
                start = chrono::high_resolution_clock::now();
                insertionSortTree(ptrTree);
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'l':
                start = chrono::high_resolution_clock::now();
                shellSortTree(ptrTree);
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case 'm': 
                start = chrono::high_resolution_clock::now();
                if (getSize(ptrTree) > 20)
                {
                    cout << "Sua árvore possui mais de 20 nós. Não é possível fazer o gráfico." << endl;
                }
                else
                {
                    graphicBubbleSort(ptrTree);
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " segundos" << endl;
                break;
            case 'n':
                start = chrono::high_resolution_clock::now();
                if (getSize(ptrTree) > 20)
                {
                    cout << "Sua árvore possui mais de 20 nós. Não é possível fazer o gráfico." << endl;
                }
                else
                {
                    graphicSelectionSort(ptrTree);
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " segundos" << endl;
                break;
            case 'o':
                start = chrono::high_resolution_clock::now();
                if (getSize(ptrTree) > 20)
                {
                    cout << "Sua árvore possui mais de 20 nós. Não é possível fazer o gráfico." << endl;
                }
                else
                {
                    graphicInsertionSort(ptrTree);
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " segundos" << endl;
                break;
            case 'p':
                start = chrono::high_resolution_clock::now();
                if (getSize(ptrTree) > 20)
                {
                    cout << "Sua árvore possui mais de 20 nós. Não é possível fazer o gráfico." << endl;
                }
                else
                {
                    graphicShellSort(ptrTree);
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " segundos" << endl;
                break;
            case 'q':
                cout << "Voltando..." << endl;
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
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();

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
                start = chrono::high_resolution_clock::now();
                if (ptrTree != nullptr)
                {
                    deleteTree(&ptrTree, ptrTree);
                    ptrTree = userReadFile();
                }
                else
                {
                    ptrTree = userReadFile();
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanosegundos" << endl;
                break;
            case '2':
                start = chrono::high_resolution_clock::now();
                if (ptrTree != nullptr)
                {
                    deleteTree(&ptrTree, ptrTree);
                    ptrTree = userCreateTree();
                }
                else
                {
                    ptrTree = userCreateTree();
                }
                end = chrono::high_resolution_clock::now();
                cout << "Tempo de execução: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " segundos" << endl;
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
