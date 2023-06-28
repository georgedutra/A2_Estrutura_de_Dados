#include <iostream>
#include "list.h"

using namespace std;

// Função que cria um nó
struct ListNode* createListNode(int iVal)
{
    struct ListNode* ptrNewNode = new(ListNode);
    ptrNewNode->iData = iVal;
    ptrNewNode->ptrNext = nullptr; 
    ptrNewNode->ptrPrev = nullptr; 

    return ptrNewNode;
}

// Função que insere um nó no início da estrutura lista
void insertFront(struct DoublyList* ptrList, struct ListNode* ptrNewNode)
{
    ptrNewNode->ptrPrev = nullptr;
    ptrNewNode->ptrNext = ptrList->ptrHead;

    if (ptrList->ptrHead == nullptr) ptrList->ptrTail = ptrNewNode;
    else ptrList->ptrHead->ptrPrev = ptrNewNode;

    ptrList->ptrHead = ptrNewNode;
}

// Função que insere um nó no final da estrutura lista
void insertEnd(struct DoublyList* ptrList, struct ListNode* ptrNewNode)
{
    ptrNewNode->ptrNext = nullptr;
    ptrNewNode->ptrPrev = ptrList->ptrTail;

    if (ptrList->ptrHead == nullptr) ptrList->ptrHead = ptrNewNode;  // Se a lista está vazia, o último também é o primeiro
    else ptrList->ptrTail->ptrNext = ptrNewNode;

    ptrList->ptrTail = ptrNewNode;
}

// Função que imprime a estrutura lista
void displayList(struct DoublyList* ptrList)
{
    if (ptrList->ptrHead == nullptr) return;
    if (ptrList->ptrHead->ptrPrev != nullptr) return;

    // Se chegar aqui, a lista é válida e não vazia
    struct ListNode* ptrPrinter = ptrList->ptrHead;

    cout << "Payload: ";
    while (ptrPrinter != nullptr)
    {
        cout << ptrPrinter->iData << " ";
        ptrPrinter = ptrPrinter->ptrNext;
    }
    cout << endl;
}

// Função que apaga o primeiro elemento da estrutura lista
void deleteFirst(struct DoublyList* ptrList)
{
    if (ptrList->ptrHead == nullptr) return;

    struct ListNode* ptrTemp = ptrList->ptrHead;

    ptrList->ptrHead = ptrList->ptrHead->ptrNext; // Atualiza a head
    if (ptrList->ptrHead != nullptr) ptrList->ptrHead->ptrPrev = nullptr; // Se a nova head for um nó, atualiza o prev
    else ptrList->ptrTail = nullptr; // Se for vazia, esvazia a tail também

    delete(ptrTemp);
}

// Função que apaga o último elemento da estrutura lista
void deleteLast(struct DoublyList* ptrList)
{
    if (ptrList->ptrHead == nullptr) return;

    struct ListNode* ptrTemp = ptrList->ptrTail; 
    ptrList->ptrTail = ptrList->ptrTail->ptrPrev; // Atualiza tail

    if (ptrList->ptrTail != nullptr) ptrList->ptrTail->ptrNext = nullptr; // Se a nova tail for um nó, atualiza o next
    else ptrList->ptrHead = nullptr; // Se for vazia, esvazia a head também

    delete(ptrTemp);
}

// Função que recebe um nó de uma lista, e insere um novo logo após o Loc na estrutura
void insertAfter(struct ListNode* ptrLoc, struct ListNode* ptrNewNode)
{
    if (ptrLoc == nullptr) return;

    ptrNewNode->ptrNext = ptrLoc->ptrNext;
    ptrNewNode->ptrPrev = ptrLoc;

    ptrLoc->ptrNext = ptrNewNode;

    // Se havia alguém na frente do ptrLoc, corrige o previous dele
    if (ptrNewNode->ptrNext != nullptr) ptrNewNode->ptrNext->ptrPrev = ptrNewNode;
}

// Função que deleta um nó específico da lista
void deleteNode(struct DoublyList* ptrList, struct ListNode* ptrDelete)
{   
    if (ptrList->ptrHead == nullptr || ptrDelete == nullptr) return;

    if (ptrList->ptrHead == ptrDelete) 
    {
        deleteFirst(ptrList);
        return;
    }
    if (ptrList->ptrTail == ptrDelete) 
    {
        deleteLast(ptrList);
        return;
    }
    
    // Se não for o último nem o primeiro, ele certamente está entre dois Nodes
    ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev; 
    ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    delete(ptrDelete);
}

// Função que remove um nó e o retorna
struct ListNode* popNode(struct DoublyList* ptrList, struct ListNode* ptrDelete)
{ 
    if (ptrList->ptrHead == nullptr || ptrDelete == nullptr) return nullptr;
    
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    else ptrList->ptrTail = ptrDelete->ptrPrev;

    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    else ptrList->ptrHead = ptrDelete->ptrNext;

    return ptrDelete;
}

// Função para saber o tamanho de uma lista duplamente encadeada
int getLenght(struct DoublyList* ptrList)
{
    int iCounter = 0;
    struct ListNode* ptrTemp = ptrList->ptrHead;
    while (ptrTemp!=nullptr)
    {
        iCounter++;
        ptrTemp = ptrTemp->ptrNext;
    }
    return iCounter;
}

// Função que troca de lugar dois Nodes na estrutura de lista encadeada
void swapNodes(struct DoublyList* ptrList, struct ListNode* ptrNode1, struct ListNode* ptrNode2)
{
    struct ListNode* ptrTemp; 

    // Casos Especiais: 
    
    // Cria indicadoras para saber se os nodes 1 e 2 possuem prev ou next
    bool bPrev1 = true, bPrev2 = true, bNext1 = true, bNext2 = true;
    
    // Se não possuem, significa que são head ou tail da lista
    if (ptrNode1 == ptrList->ptrHead) bPrev1 = false;
    if (ptrNode2 == ptrList->ptrHead) bPrev2 = false;
    if (ptrNode1 == ptrList->ptrTail) bNext1 = false;
    if (ptrNode2 == ptrList->ptrTail) bNext2 = false;

    // Casos em que os Nodes são adjacentes:

    // Se o ptrNode2 é o prev do 1, troca os ponteiros e os indicadores de head/tail, pois queremos que o 1 venha antes do 2
    if (ptrNode2->ptrNext == ptrNode1)
    {
        ptrTemp = ptrNode1;
        ptrNode1 = ptrNode2;
        ptrNode2 = ptrTemp;
        
        if (bPrev2==false) bPrev1 = false;
        bPrev2 = true;

        if (bNext1==false) bNext2 = false;
        bNext1 = true;
    }

    // Se agora o ptrNode1 é prev do 2, faz-se o necessário para trocar Nodes adjacentes
    if (ptrNode1->ptrNext == ptrNode2)
    {
        if (bPrev1 == true) ptrNode1->ptrPrev->ptrNext = ptrNode2;    
        else ptrList->ptrHead = ptrNode2;

        if (bNext2 == true) ptrNode2->ptrNext->ptrPrev = ptrNode1;
        else ptrList->ptrTail = ptrNode1;

        ptrNode1->ptrNext = ptrNode2->ptrNext;
        ptrNode2->ptrPrev = ptrNode1->ptrPrev;

        ptrNode1->ptrPrev = ptrNode2;
        ptrNode2->ptrNext = ptrNode1;
        return;
    }

    // Se chegar aqui, não são adjacentes, e não importa mais a ordem
    // Primeiro altera os nós ao redor dos trocados, se existem
    if (bPrev1 == true) ptrNode1->ptrPrev->ptrNext = ptrNode2;
    if (bNext1 == true) ptrNode1->ptrNext->ptrPrev = ptrNode2;
    
    if (bPrev2 == true) ptrNode2->ptrPrev->ptrNext = ptrNode1;
    if (bNext2 == true) ptrNode2->ptrNext->ptrPrev = ptrNode1;

    // Altera os ponteiros da lista caso sejam head ou tail
    if (bPrev1 == false) ptrList->ptrHead = ptrNode2;
    if (bNext1 == false) ptrList->ptrTail = ptrNode2;

    if (bPrev2 == false) ptrList->ptrHead = ptrNode1;
    if (bNext2 == false) ptrList->ptrTail = ptrNode1;

    // Atualiza os ponteiros dos Nodes trocados
    ptrTemp = ptrNode1->ptrNext;
    ptrNode1->ptrNext = ptrNode2->ptrNext;
    ptrNode2->ptrNext = ptrTemp;

    ptrTemp = ptrNode1->ptrPrev;
    ptrNode1->ptrPrev = ptrNode2->ptrPrev;
    ptrNode2->ptrPrev = ptrTemp;

    return;
}
