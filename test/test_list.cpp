/**
 * Este arquivo 'driver code' é parte secundária do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo ser compilado junto ao arquivo tree.cpp, encontrado na pasta \src\tree do projeto,
 * e realiza uma série de testes nas funções ali designadas.
*/

#include <iostream>
#include <windows.h>
#include "..\src\list\list.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

int main()
{
    SetConsoleOutputCP( 65001 ); // Definindo console output como UTF-8

    cout << "===================================================\n" 
    << "Início dos Testes\n" 
    <<"===================================================" << endl;

    cout << "Teste das funções create, inserts, e printList:\n"
    <<"Criando uma lista contendo o nó 0\n" 
    << endl;

    DoublyList* testList = createList();
    insertEnd(testList, createListNode(0));

    printList(testList);

    cout << "\nInserindo o nó 5 no início\n" << endl; 

    insertFront(testList, createListNode(5));
    printList(testList);

    cout << "\nInserindo o nó 10 no final\n" << endl; 

    insertEnd(testList, createListNode(10));
    printList(testList);

    cout << "\nInserindo o nó 42 após o 0\n" << endl; 

    insertAfter(testList, testList->ptrHead->ptrNext, createListNode(42));
    printList(testList);

    cout << "===================================================\n"
    << "Teste das funções delete:\n"
    <<"Deletando o nó 0 (meio da lista)\n"
    << endl;

    deleteNode(testList, testList->ptrHead->ptrNext);
    printList(testList);

    cout <<"\nDeletando o último nó\n" << endl;

    deleteLast(testList);
    printList(testList);

    cout <<"\nDeletando o primeiro nó\n" << endl;

    deleteFirst(testList);
    printList(testList);
    
    cout << "===================================================\n"
    << "Teste das funções popNode e swapNodes:\n"
    << "Inserindo mais nós na lista\n"
    << endl;

    insertEnd(testList, createListNode(0));
    insertEnd(testList, createListNode(10));
    insertEnd(testList, createListNode(7));
    insertEnd(testList, createListNode(666));
    insertEnd(testList, createListNode(13));
    insertEnd(testList, createListNode(17));
    insertEnd(testList, createListNode(999));
    insertEnd(testList, createListNode(-1));

    printList(testList);

    cout <<"\nPegando o nó 17\n" << endl;

    ListNode* ptrNode = popNode(testList, testList->ptrHead->ptrNext->ptrNext->ptrNext->ptrNext->ptrNext->ptrNext);
    cout << "Nó removido: " << ptrNode->iData << endl;
    printList(testList);

    cout <<"\nTrocando nós 666 e 999\n" << endl;

    swapNodes(testList, testList->ptrHead->ptrNext->ptrNext->ptrNext->ptrNext, testList->ptrHead->ptrNext->ptrNext->ptrNext->ptrNext->ptrNext->ptrNext);
    printList(testList);

    cout << "===================================================\n"
    << "Teste dos algoritmos de sorting:\n";

    // Criando 3 cópias da lista
    DoublyList* testList2 = createList();
    DoublyList* testList3 = createList();
    DoublyList* testList4 = createList();

    ListNode* ptrTemp = testList->ptrHead;

    while (ptrTemp != nullptr)
    {
        insertEnd(testList2, createListNode(ptrTemp->iData));
        insertEnd(testList3, createListNode(ptrTemp->iData));
        insertEnd(testList4, createListNode(ptrTemp->iData));

        ptrTemp = ptrTemp->ptrNext;
    }

    cout << "Bubble Sorting" << endl;
    bubbleSort(testList);
    printList(testList);
    cout << endl;

    cout << "Selection Sorting" << endl;
    selectionSort(testList2, testList2->ptrHead);
    printList(testList2);
    cout << endl;

    cout << "Insertion Sorting" << endl;
    insertionSort(testList3);
    printList(testList3);
    cout << endl;

    cout << "Shell Sorting" << endl;
    shellSort(testList4, getLenght(testList4));
    printList(testList4);
    cout << endl;

    cout << "===================================================\n" 
    << "Fim dos Testes\n"
    <<"===================================================\n"
    << "Presione enter para sair.";
    cin.get();

    return 0;
}
