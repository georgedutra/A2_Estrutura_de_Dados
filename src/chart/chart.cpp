#include <iostream>
#include <windows.h>
#include <math.h>
#include "../tree/tree.h"
#include "../list/list.h"

#pragma execution_character_set( "utf-8" )

using namespace std;

int iMax(struct DoublyList* ptrList)
{
    int iMax = 0;
    for (struct ListNode* ptrCurrentNode = ptrList -> ptrHead ; ptrCurrentNode != nullptr; ptrCurrentNode = ptrCurrentNode -> ptrNext)
    {
        if (ptrCurrentNode -> iData > iMax)
        {
            iMax = ptrCurrentNode -> iData;
        }
    }
    return iMax;
}

void clearGraphic(char arriGrapich[20][120])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 120; ++j)
        {
            arriGrapich[i][j] = ' ';
        }
    }
}

void calcNodes(struct DoublyList* ptrList, char arriGrapich[20][120], int iMax)
{
    int iSize[20];

    for (int i = 0; i < 20; i++)
    {
        iSize[i] = 0;
    }

    int i = 0;
    for (struct ListNode* ptrCurrentNode = ptrList -> ptrHead ; ptrCurrentNode != nullptr; ptrCurrentNode = ptrCurrentNode -> ptrNext)
    {
        iSize[i] = ptrCurrentNode -> iData;
        i++;
    }

    for (int iColunm = 0; iColunm < 20; iColunm++)
    {
        for (int iLinha = 19; iLinha > 19 - (iSize[iColunm] * 20 / iMax); iLinha--)
        {
            arriGrapich[iLinha][iColunm * 6] = 'O';
        }
    }

}

void drawGrapich(char arriGrapich[20][120], int iLenght)
{
    for (int i = 0; i < (iLenght + 1) * 6; i++)
    {
        cout << "=";
    }
    cout << endl;

    for (int i = 0; i < 20; i++)
    {
        cout << "||  ";
        for (int j = 0; j < iLenght * 6; ++j)
        {
            cout << arriGrapich[i][j];
        }
        cout << "||" << endl;
    }

    for (int i = 0; i < (iLenght + 1) * 6; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void config()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 800, 600, TRUE);
}

void drawFrame(struct DoublyList* ptrList, char arriGrapich[20][120], int iMaxCalc,
                int iLenght, struct ListNode* ptrCurrentNode, struct ListNode* ptrNext)
{
    system("cls");
    clearGraphic(arriGrapich);

    printList(ptrList);
    cout << endl;

    cout << "Testando: " << ptrCurrentNode -> iData << " e " << ptrNext -> iData << endl;

    calcNodes(ptrList, arriGrapich, iMaxCalc);
    
    drawGrapich(arriGrapich, iLenght);

    Sleep(400);  
}

void graphicBubbleSort(struct TreeNode* ptrRoot)
{
    config();

    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);

    int iMaxCalc = iMax(ptrList);
    int iLenght = getLenght(ptrList);

    char arriGrapich[20][120];

    // Desenha antes de começar
    drawFrame(ptrList, arriGrapich, iMaxCalc, iLenght, ptrList->ptrHead, ptrList->ptrHead->ptrNext);

    bool bUnordered;

    struct ListNode* ptrStart = ptrList->ptrHead;
    struct ListNode* ptrEnd = ptrList->ptrTail;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        // Em cada loop externo, partimos do pressuposto de que a lista estará organizada
        bUnordered = false;

        while (ptrStart != ptrEnd && ptrStart->ptrPrev != ptrEnd)
        {
            drawFrame(ptrList, arriGrapich, iMaxCalc, iLenght, ptrStart, ptrStart->ptrNext);
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
    drawFrame(ptrList, arriGrapich, iMaxCalc, iLenght, ptrStart -> ptrPrev, ptrStart);
    deleteDoublyList(ptrList);

}

void graphicSelectionSort(struct TreeNode* ptrRoot)
{
    config();

    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);

    int iMaxCalc = iMax(ptrList);
    int iLength = getLenght(ptrList);

    char arriGrapich[20][120];

    struct ListNode* ptrOuter;
    struct ListNode* ptrInner;
    struct ListNode* ptrTemp;

    for (ptrOuter = ptrList -> ptrHead; ptrOuter != nullptr; ptrOuter = ptrOuter->ptrNext)
    {
        for (ptrInner = ptrOuter->ptrNext; ptrInner != nullptr; ptrInner = ptrInner->ptrNext)
        {
            drawFrame(ptrList, arriGrapich, iMaxCalc, iLength, ptrOuter, ptrInner);
            if (ptrOuter->iData > ptrInner->iData)
            {
                swapNodes(ptrList, ptrOuter, ptrInner);
                ptrTemp = ptrInner;
                ptrInner = ptrOuter;
                ptrOuter = ptrTemp;
            }
        }
    }
    drawFrame(ptrList, arriGrapich, iMaxCalc, iLength, ptrOuter -> ptrPrev, ptrInner -> ptrPrev);

    deleteDoublyList(ptrList);

}

void drawFramePop(struct DoublyList* ptrList, char arriGrapich[20][120], int iMaxCalc,
                        int iLenght, struct ListNode* ptrCurrentNode, struct ListNode* ptrNext)
{
    system("cls");
    clearGraphic(arriGrapich);

    printList(ptrList);
    cout << endl;

    cout << "No em espera: " << ptrCurrentNode -> iData << endl;
    cout << "Testando: " << ptrNext -> iData << endl;

    calcNodes(ptrList, arriGrapich, iMaxCalc);
    
    drawGrapich(arriGrapich, iLenght);

    Sleep(400);  
}

void drawFrameInsertion(struct DoublyList* ptrList, char arriGrapich[20][120], int iMaxCalc,
                        int iLenght, struct ListNode* ptrCurrentNode, struct ListNode* ptrNext)
{
    system("cls");
    clearGraphic(arriGrapich);

    printList(ptrList);
    cout << endl;

    cout << "Inserido: " << ptrCurrentNode -> iData << endl;
    cout << "Após: " << ptrNext -> iData << endl;

    calcNodes(ptrList, arriGrapich, iMaxCalc);
    
    drawGrapich(arriGrapich, iLenght);

    Sleep(400);  
}

void graphicInsertionSort(struct TreeNode* ptrRoot)
{
    SetConsoleOutputCP( 65001 );
    config();

    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);

    int iMaxCalc = iMax(ptrList);
    int iLength = getLenght(ptrList);

    char arriGrapich[20][120];

    // Desenha antes de começar
    drawFrame(ptrList, arriGrapich, iMaxCalc, iLength, ptrList->ptrHead, ptrList->ptrHead->ptrNext);

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
            drawFramePop(ptrList, arriGrapich, iMaxCalc, iLength, ptrInner, ptrInner -> ptrPrev);
            if (ptrInner->ptrPrev->iData <= ptrTemp->iData) break;
            ptrInner = ptrInner->ptrPrev;
        }
        if (ptrInner == ptrList -> ptrHead)
        {
            insertFront(ptrList, ptrTemp);
            drawFrameInsertion(ptrList, arriGrapich, iMaxCalc, iLength, ptrInner, ptrList -> ptrHead);
        }
        else
        {
            insertAfter(ptrList, ptrInner -> ptrPrev, ptrTemp);
            drawFrameInsertion(ptrList, arriGrapich, iMaxCalc, iLength, ptrInner, ptrInner -> ptrPrev);
        }
    }
    deleteDoublyList(ptrList);

}

void graphicShellSort(struct TreeNode* ptrRoot)
{
    config();

    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);

    int iLenght = getLenght(ptrList);
    int iMaxCalc = iMax(ptrList);

    char arriGrapich[20][120];

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
                    drawFrame(ptrList, arriGrapich, iMaxCalc, iLenght, ptrInner, ptrTemp);
                    if (ptrInner->iData <= ptrTemp->iData) break; // Se essa sublista está ordenada, quebra o loop interno

                    swapNodes(ptrList, ptrInner, ptrTemp); // Caso contrário, trocamos o temp com o nó que está 'iInc' passos atrás dele 
                    ptrInner = ptrTemp; // E resetamos Inner para o próximo passo
                }
            }
        }
    }

    deleteDoublyList(ptrList);

}