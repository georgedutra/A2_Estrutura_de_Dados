#include <iostream>
#include <math.h>
#include "list.h"

using namespace std;

struct ListNode* createListNode(int iVal)
{
    struct ListNode* ptrNewNode = new(ListNode);
    ptrNewNode->iData = iVal;
    ptrNewNode->ptrNext = nullptr; 
    ptrNewNode->ptrPrev = nullptr; 

    return ptrNewNode;
}

struct DoublyList* createList()
{
    struct DoublyList* newList = new(DoublyList); 
    newList->ptrHead = nullptr;
    newList->ptrTail = nullptr;

    return newList;
}

void insertFront(struct DoublyList* ptrList, struct ListNode* ptrNewNode)
{
    ptrNewNode->ptrPrev = nullptr;
    ptrNewNode->ptrNext = ptrList->ptrHead;

    if (ptrList->ptrHead == nullptr) ptrList->ptrTail = ptrNewNode;
    else ptrList->ptrHead->ptrPrev = ptrNewNode;

    ptrList->ptrHead = ptrNewNode;
}

void insertEnd(struct DoublyList* ptrList, struct ListNode* ptrNewNode)
{
    ptrNewNode->ptrNext = nullptr;
    ptrNewNode->ptrPrev = ptrList->ptrTail;

    if (ptrList->ptrHead == nullptr) ptrList->ptrHead = ptrNewNode;  // Se a lista está vazia, o último também é o primeiro
    else ptrList->ptrTail->ptrNext = ptrNewNode;

    ptrList->ptrTail = ptrNewNode;
}

void printList(struct DoublyList* ptrList)
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

void deleteFirst(struct DoublyList* ptrList)
{
    if (ptrList->ptrHead == nullptr) return;

    struct ListNode* ptrTemp = ptrList->ptrHead;

    ptrList->ptrHead = ptrList->ptrHead->ptrNext; // Atualiza a head
    if (ptrList->ptrHead != nullptr) ptrList->ptrHead->ptrPrev = nullptr; // Se a nova head for um nó, atualiza o prev
    else ptrList->ptrTail = nullptr; // Se for vazia, esvazia a tail também

    delete(ptrTemp);
}

void deleteLast(struct DoublyList* ptrList)
{
    if (ptrList->ptrHead == nullptr) return;

    struct ListNode* ptrTemp = ptrList->ptrTail; 
    ptrList->ptrTail = ptrList->ptrTail->ptrPrev; // Atualiza tail

    if (ptrList->ptrTail != nullptr) ptrList->ptrTail->ptrNext = nullptr; // Se a nova tail for um nó, atualiza o next
    else ptrList->ptrHead = nullptr; // Se for vazia, esvazia a head também

    delete(ptrTemp);
}

void insertAfter(struct DoublyList* ptrList, struct ListNode* ptrLoc, struct ListNode* ptrNewNode)
{
    if (ptrLoc == nullptr) return;

    ptrNewNode->ptrNext = ptrLoc->ptrNext;
    ptrNewNode->ptrPrev = ptrLoc;

    ptrLoc->ptrNext = ptrNewNode;

    // Se havia alguém na frente do ptrLoc, corrige o previous dele
    if (ptrNewNode->ptrNext != nullptr) ptrNewNode->ptrNext->ptrPrev = ptrNewNode;
    else ptrList->ptrTail = ptrNewNode;
}

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

struct ListNode* popNode(struct DoublyList* ptrList, struct ListNode* ptrDelete)
{ 
    if (ptrList->ptrHead == nullptr || ptrDelete == nullptr) return nullptr;
    
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    else ptrList->ptrTail = ptrDelete->ptrPrev;

    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    else ptrList->ptrHead = ptrDelete->ptrNext;

    return ptrDelete;
}

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

void bubbleSort(struct DoublyList* ptrList)
{
    int iLenght = getLenght(ptrList);
    bool bUnordered;

    struct ListNode* ptrStart = ptrList->ptrHead;
    struct ListNode* ptrEnd = ptrList->ptrTail;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        // Em cada loop externo, partimos do pressuposto de que a lista estará organizada
        bUnordered = false;

        while (ptrStart != ptrEnd && ptrStart->ptrPrev != ptrEnd)
        {
            if(ptrStart->iData > ptrStart->ptrNext->iData) 
            {
                swapNodes(ptrList, ptrStart, ptrStart->ptrNext);
                bUnordered = true;
            }
            else ptrStart = ptrStart->ptrNext;
        }

        // Ao fim de um loop externo, se a lista não tinha nada fora de ordem, encerra o sort
        if (bUnordered == false) return;

        // Se não quebramos o loop, otimizamos o algoritmo reduzindo o fim do loop interno, e preparamos o próximo
        if (ptrStart != ptrList->ptrTail) ptrEnd = ptrStart;
        ptrStart = ptrList->ptrHead;
    }
}

void selectionSort(struct DoublyList* ptrList, struct ListNode* ptrHead)
{
    if (ptrHead->ptrNext == nullptr) return; // Caso Base
    
    struct ListNode* ptrInner;
    struct ListNode* ptrTemp;

    for (ptrInner = ptrHead->ptrNext; ptrInner != nullptr; ptrInner = ptrInner->ptrNext)
    {
        if (ptrHead->iData > ptrInner->iData) // Se algum nó no meio é menor que a head, trocamos os dois
        {
            swapNodes(ptrList, ptrHead, ptrInner);

            // Após a troca, é necessário rearranjar os ponteiros
            ptrTemp = ptrInner;
            ptrInner = ptrHead;
            ptrHead = ptrTemp;
        }
    }
    // Chama o sort para a próxima sub-lista
    selectionSort(ptrList, ptrHead->ptrNext); 
}

void insertionSort(struct DoublyList* ptrList)
{
    struct ListNode* ptrOuter = ptrList->ptrHead->ptrNext; // Ponteiro do nó que será removido em cada iteração
    struct ListNode* ptrInner; // Ponteiro que procura onde inserir o nó
    struct ListNode* ptrTemp; // Ponteiro que guarda o nó removido

    while (ptrOuter != nullptr)
    {
        ptrInner = ptrOuter;
        ptrOuter = ptrOuter->ptrNext;
        ptrTemp = popNode(ptrList, ptrInner);

        while (ptrInner->ptrPrev != nullptr) // Procura onde inserir o temp
        {
            if (ptrInner->ptrPrev->iData <= ptrTemp->iData) break;
            ptrInner = ptrInner->ptrPrev;
        }
        if (ptrInner == ptrList->ptrHead) insertFront(ptrList, ptrTemp);
        else insertAfter(ptrList, ptrInner->ptrPrev, ptrTemp);
    }
}

void shellSort(DoublyList* ptrList, int iLenght)
{
    struct ListNode* ptrOuter; 
    struct ListNode* ptrInner; 
    struct ListNode* ptrTemp;

    for (int iCount = 2; trunc(iLenght/iCount) >= 1; iCount = iCount*2) // Para cada incremento, começando do maior, indo até 1
    {
        int iInc = trunc(iLenght/iCount); // Calcula o incremento

        for (int iSubList = 0; iSubList < iInc; iSubList++) // Para cada "sublista" dentro da lista original 
        {
            ptrOuter = ptrList->ptrHead; // Reseta o ptrOuter
            for (int iWalk = 0; iWalk < iSubList + iInc; iWalk++) ptrOuter = ptrOuter->ptrNext; // Caminha para o segundo elemento da sublista
            
            // Imagine que estamos fazendo um insertion sort, mas cada nó não olha para o anterior, e sim para o nó que está 'iInc' passos atrás
            for (int iOuterLoop = iSubList + iInc; iOuterLoop < iLenght; iOuterLoop += iInc) // Loop externo
            {
                ptrInner = ptrOuter; // Reseta o ptrInner
                for (int iWalk = 0; iWalk < iInc && ptrOuter != nullptr; iWalk++) ptrOuter = ptrOuter->ptrNext; // Outer caminha 'iInc' nós para frente

                ptrTemp = ptrInner; // Esse é o nó que "sai" da parte desordenada, e quer entrar na parte ordenada 

                for (int iInnerLoop = iOuterLoop; iInnerLoop > iSubList; iInnerLoop -= iInc) // Loop Interno
                {
                    for (int iWalk = 0; iWalk < iInc; iWalk++) ptrInner = ptrInner->ptrPrev; // Inner caminha 'iInc' passos para trás
                    if (ptrInner->iData <= ptrTemp->iData) break; // Se essa sublista está ordenada, quebra o loop interno

                    swapNodes(ptrList, ptrInner, ptrTemp); // Caso contrário, trocamos o temp com o nó que está 'iInc' passos atrás dele 
                    ptrInner = ptrTemp; // E resetamos Inner para o próximo passo
                }
            }
        }
    }
}