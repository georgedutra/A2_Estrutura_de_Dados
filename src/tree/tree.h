#pragma once

/**
 * Este arquivo 'header' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para construção e manipulação de árvores binárias de busca
*/

/**
 * Estrutura de Nó que compõe uma Árvore Binária
 */
struct TreeNode
{
    int iPayload;
    struct TreeNode* ptrLeft;
    struct TreeNode* ptrRight;
};

/**
 * Cria um novo TreeNode sem filhos
 * 
 * @param iData Valor inteiro que será a carga do TreeNode
 * @return Ponteiro para a struct TreeNode criada
*/
struct TreeNode* newTreeNode(int iData);

/**
 * Função recursiva de inserção de nós em árvores binárias de busca
 * 
 * @param currentNode Ponteiro para o nó raiz da árvore a ser modificada
 * @param iData Valor inteiro que será a carga do nó inserido
 * @return Ponteiro para o nó raiz da árvore já modificada, equivalente a `currentNode`
*/
struct TreeNode* insertTreeNode(struct TreeNode* currentNode, int iData);

/**
 * Função que imprime o conteúdo de uma árvore binária usando o método de travessia Pré-Ordem
 * 
 * Imprime primeiro o nó atual, depois os descendentes à esquerda, depois os descendentes à direita
 * 
 * @param ptrStartingNode Nó raiz da árvore ou sub-árvore a partir do qual deve-se imprimir o conteúdo
*/
void traversePreOrder(struct TreeNode* ptrStartingNode);

/**
 * Função que imprime o conteúdo de uma árvore binária usando o método de travessia Em Ordem
 * 
 * Imprime primeiro os descendentes à esquerda, depois o nó atual, depois os descendentes à direita
 * @param ptrStartingNode Nó raiz da árvore ou sub-árvore a partir do qual deve-se imprimir o conteúdo
*/
void traverseInOrder(struct TreeNode* ptrStartingNode);

/**
 * Função que imprime o conteúdo de uma árvore binária usando o método de travessia Pós-Ordem
 * 
 * Imprime primeiro os descendentes à esquerda, depois os descendentes à direita, e depois o nó atual
 * @param ptrStartingNode Nó raiz da árvore ou sub-árvore a partir do qual deve-se imprimir o conteúdo
*/
void traversePostOrder(struct TreeNode* ptrStartingNode);