#include <iostream>
#include "tree.h"

using namespace std;

struct TreeNode* newTreeNode(int iData)
{
    struct TreeNode* newNodePtr = new(TreeNode);
    newNodePtr->iPayload = iData;
    newNodePtr->ptrLeft = nullptr;
    newNodePtr->ptrRight = nullptr;

    return newNodePtr;
}

struct TreeNode* insertTreeNode(struct TreeNode* currentNode, int iData)
{
    // Caso base: se achamos nullptr, retornamos o novo nó
    if (currentNode == nullptr) return newTreeNode(iData); 

    // Se não achamos o local de inserção, navegamos para a sub-árvore ideal para a inserção
    if (iData < currentNode->iPayload) currentNode->ptrLeft = insertTreeNode(currentNode->ptrLeft, iData); 
    else currentNode->ptrRight = insertTreeNode(currentNode->ptrRight, iData);

    // Se estamos num caso não-base, temos que retornar a sub-árvore para os nós superiores, agora modificada pois o nó já foi inserido no caso base
    return currentNode;
}

void traversePreOrder(struct TreeNode* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return; // Caso base

    cout << " " << ptrStartingNode->iPayload;
    traversePreOrder(ptrStartingNode->ptrLeft);
    traversePreOrder(ptrStartingNode->ptrRight);
}

void traverseInOrder(struct TreeNode* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return;

    traverseInOrder(ptrStartingNode->ptrLeft);
    cout << " " << ptrStartingNode->iPayload;
    traverseInOrder(ptrStartingNode->ptrRight);
}

void traversePostOrder(struct TreeNode* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return; 

    traversePostOrder(ptrStartingNode->ptrLeft);
    traversePostOrder(ptrStartingNode->ptrRight);
    cout << " " << ptrStartingNode->iPayload;
}

