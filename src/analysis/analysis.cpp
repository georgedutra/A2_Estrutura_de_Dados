/**
 * Este arquivo 'source' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 *
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para análise de árvores binárias de busca.
 */

#include <iostream>
#include "analysis.h"
#include "..\tree\tree.h"

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
        {return -1;}
    int iLeftHeight = getHeight(ptrTree->ptrLeft);
    int iRightHeight = getHeight(ptrTree->ptrRight);
    if (iLeftHeight > iRightHeight)
        {return iLeftHeight + 1;}
    return iRightHeight + 1;
}

