/**
 * Este arquivo 'source' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 *
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para análise de árvores binárias de busca.
 */

#include <iostream>
#include "analysis.h"
#include "..\tree\tree.h"
#include <math.h>

using namespace std;

bool isComplete(struct TreeNode *ptrTree)
{
    if (ptrTree == nullptr)
        return true;
    if (ptrTree->ptrLeft == nullptr && ptrTree->ptrRight == nullptr)
        return true;
    if (ptrTree->ptrLeft != nullptr && ptrTree->ptrRight != nullptr)
    {
        return isComplete(ptrTree->ptrLeft) && isComplete(ptrTree->ptrRight);
    }
    return false;
}

bool isPerfect(struct TreeNode *ptrTree, int iHeight, int iActualLevel)
{
    if (ptrTree == nullptr)
        return true;
    if (ptrTree->ptrLeft == nullptr && ptrTree->ptrRight == nullptr)
    {
        if (iHeight == iActualLevel)
            return true;
        return false;
    }
    if (ptrTree->ptrLeft != nullptr && ptrTree->ptrRight != nullptr)
    {
        return isPerfect(ptrTree->ptrLeft, iHeight, iActualLevel + 1) &&
               isPerfect(ptrTree->ptrRight, iHeight, iActualLevel + 1);
    }
    return false;
}

int getHeight(struct TreeNode *ptrTree)
{
    if (ptrTree == nullptr)
    {
        return -1;
    }
    int iLeftHeight = getHeight(ptrTree->ptrLeft);
    int iRightHeight = getHeight(ptrTree->ptrRight);
    if (iLeftHeight > iRightHeight)
    {
        return iLeftHeight + 1;
    }
    return iRightHeight + 1;
}

int getSize(struct TreeNode *ptrTree)
{
    if (ptrTree == nullptr)
    {
        return 0;
    }
    return getSize(ptrTree->ptrLeft) + getSize(ptrTree->ptrRight) + 1;
}

void printBFS(struct TreeNode *ptrTree)
{
    int iHeight = getHeight(ptrTree);
    int iNumberMaxOfNodes = (pow(2, iHeight + 1) - 1);
    // array que armazena os ponteiros para os nós da árvore
    struct TreeNode *arrptrTreeNodes[iNumberMaxOfNodes];
    arrptrTreeNodes[0] = ptrTree;
    int iCurrentNode = 1;

    cout << ptrTree -> iPayload << " ";

    for (int iCurrentHeight = 0; iCurrentHeight < iHeight; iCurrentHeight++)
    {
        //Percorre os nós do nível atual como se a árvore fosse perfeita. O nó atual do 
        //nível começa em 2 elevado a altura atual - 1 e portanto acaba antes do próximo nível 
        for (int iLevelNode = (pow(2, iCurrentHeight) - 1); iLevelNode < (pow(2, iCurrentHeight + 1) - 1); iLevelNode++)
        { 
            //Se o nó atual não for nulo, tenta imprimir os filhos dele e armazená-los no array
            if (arrptrTreeNodes[iLevelNode]  != nullptr)
            {
                if (arrptrTreeNodes[iLevelNode] -> ptrLeft  != nullptr)
                {
                    cout << arrptrTreeNodes[iLevelNode]-> ptrLeft ->iPayload << " ";
                    arrptrTreeNodes[iCurrentNode] = arrptrTreeNodes[iLevelNode]->ptrLeft;
                }
                else
                {
                    arrptrTreeNodes[iCurrentNode] = nullptr;
                }
                if (arrptrTreeNodes[iLevelNode] -> ptrRight  != nullptr)
                {
                    cout << arrptrTreeNodes[iLevelNode]-> ptrRight ->iPayload << " ";
                    arrptrTreeNodes[iCurrentNode + 1] = arrptrTreeNodes[iLevelNode]->ptrRight;
                }
                else
                {
                    arrptrTreeNodes[iCurrentNode + 1] = nullptr;
                }
            }
            else
            {
                arrptrTreeNodes[iCurrentNode] = nullptr;
                arrptrTreeNodes[iCurrentNode + 1] = nullptr;
            }
            iCurrentNode += 2;
        }
    }

    cout << endl;
    
}