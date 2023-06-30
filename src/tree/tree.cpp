/**
 * Este arquivo 'source' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo guardar as definições das funções necessárias para construção e manipulação de árvores binárias de busca.
*/

#include <iostream>
#include "tree.h"
#include "../list/list.h"

using namespace std;

struct TreeNode* newTreeNode(int iData)
{
    struct TreeNode* newNodePtr = new(TreeNode);
    newNodePtr->iPayload = iData;
    newNodePtr->ptrLeft = nullptr;
    newNodePtr->ptrRight = nullptr;

    return newNodePtr;
}

struct TreeNode* insertTreeNode(struct TreeNode* ptrCurrentNode, int iData)
{
    // Caso base: se achamos nullptr, retornamos o novo nó
    if (ptrCurrentNode == nullptr) return newTreeNode(iData); 

    // Se não achamos o local de inserção, navegamos para a sub-árvore ideal para a inserção
    if (iData < ptrCurrentNode->iPayload) ptrCurrentNode->ptrLeft = insertTreeNode(ptrCurrentNode->ptrLeft, iData); 
    else ptrCurrentNode->ptrRight = insertTreeNode(ptrCurrentNode->ptrRight, iData);

    // Se estamos num caso não-base, temos que retornar a sub-árvore para os nós superiores, agora modificada pois o nó já foi inserido no caso base
    return ptrCurrentNode;
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

struct TreeNode* searchNode(struct TreeNode* ptrCurrentNode, int iData)
{
    if (ptrCurrentNode == nullptr) return nullptr; // Caso Base

    else if (ptrCurrentNode->iPayload == iData) return ptrCurrentNode; // Se encontrarmos o nó procurado

    else if (iData < ptrCurrentNode->iPayload) return searchNode(ptrCurrentNode->ptrLeft, iData);
    return searchNode(ptrCurrentNode->ptrRight, iData);
}

struct TreeNode* bestSubstitute(struct TreeNode* ptrNode)
{
    struct TreeNode* ptrTemp = ptrNode->ptrRight;

    // Se de cara já achamos o melhor substituto, já podemos retorná-lo
    if (ptrTemp->ptrLeft == nullptr) return ptrTemp;

    // Caso contrário, procuramos pelo pai do melhor substituto
    while(ptrTemp->ptrLeft->ptrLeft != nullptr) ptrTemp = ptrTemp->ptrLeft;
    struct TreeNode* ptrSubstitute = ptrTemp->ptrLeft;

    // Devemos consertar a árvore antes de retornar o substituto
    ptrTemp->ptrLeft = ptrSubstitute->ptrRight;
    return ptrSubstitute;
}

struct TreeNode* deleteTreeNode(struct TreeNode* ptrCurrentNode, int iData)
{
    if (ptrCurrentNode == nullptr) return ptrCurrentNode; // Caso base 1: nó desejado não encontrado

    if (iData < ptrCurrentNode->iPayload) ptrCurrentNode->ptrLeft = deleteTreeNode(ptrCurrentNode->ptrLeft, iData);
    else if (iData > ptrCurrentNode->iPayload) ptrCurrentNode->ptrRight = deleteTreeNode(ptrCurrentNode->ptrRight, iData);

    else // Caso base 2: ptrCurrentNode é o nó a ser deletado
    {  
        struct TreeNode* ptrTemp = nullptr;

        if (ptrCurrentNode->ptrLeft == nullptr) // Quando o nó deletado só tem filhos à direita ou nenhum filho
        {
            ptrTemp = ptrCurrentNode->ptrRight; // Salvamos os filhos do nó deletado
            delete(ptrCurrentNode); // Deletamos o nó
            
            return ptrTemp; // Reconectamos a árvore
        }
        else if (ptrCurrentNode->ptrRight == nullptr) // Quando o nó deletado só tem filhos à esquerda
        {
            ptrTemp = ptrCurrentNode->ptrLeft; // Salvamos os filhos do nó deletado
            delete(ptrCurrentNode); // Deletamos o nó
            
            return ptrTemp; // Reconectamos a árvore
        }

        /* Caso difícil: o nó tem dois filhos
        Procuramos e preparamos o melhor substituto para o nó deletado */
        ptrTemp = bestSubstitute(ptrCurrentNode); 
        ptrTemp->ptrLeft = ptrCurrentNode->ptrLeft;
        if (ptrTemp != ptrCurrentNode->ptrRight) ptrTemp->ptrRight = ptrCurrentNode->ptrRight; 
        // O if acima evita um possível loop

        delete(ptrCurrentNode); // Deleta o nó
        return ptrTemp; // Reconecta a árvore
    }

    return ptrCurrentNode; // Retorna a árvore modificada
}   

void treeToDoublyList(struct DoublyList* ptrList, struct TreeNode* ptrNode)
{
    if (ptrNode == nullptr) return;

    struct ListNode* ptrListNode = createListNode(ptrNode -> iPayload);
    insertEnd(ptrList, ptrListNode);
    treeToDoublyList(ptrList, ptrNode->ptrLeft);
    treeToDoublyList(ptrList, ptrNode->ptrRight);
}

void bubbleSortTree(struct TreeNode* ptrRoot)
{
    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);
    bubbleSort(ptrList);
    printList(ptrList);
    deleteDoublyList(ptrList);
}

void selectionSortTree(struct TreeNode* ptrRoot)
{
    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);
    selectionSort(ptrList, ptrList -> ptrHead);
    printList(ptrList);
    deleteDoublyList(ptrList);
}


void insertionSortTree(struct TreeNode* ptrRoot)
{
    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);
    insertionSort(ptrList);
    printList(ptrList);
    deleteDoublyList(ptrList);
}


void shellSortTree(struct TreeNode* ptrRoot)
{
    struct DoublyList* ptrList = createList();
    treeToDoublyList(ptrList, ptrRoot);
    shellSort(ptrList, getLenght(ptrList));
    printList(ptrList);
    deleteDoublyList(ptrList);
}